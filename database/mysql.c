/*
 * gcc mysql.c -lmysqlclient
 * gcc mysql.c `mysql_config --cflags --libs`
 */

#include <stdlib.h>
#include <stdio.h>
#include <mysql/mysql.h>

#define DATABASE "drupal"

MYSQL db;

void callback(void)
{
  MYSQL_RES *results = NULL;
  MYSQL_ROW result = NULL;
  int n;

  results = mysql_use_result(&db);
  n = mysql_num_fields(results);
  while ((result = mysql_fetch_row(results)))
    {
      for (int i = 0; i < n; i++)
	printf("%s%s ", (i ? ", " : ""), (result[i] ? result[i] : "NULL"));
      printf("\n");
    }
  mysql_free_result(results);
}

int main(void)
{
  /* init */
  mysql_init(&db);
  mysql_options(&db, MYSQL_READ_DEFAULT_GROUP, "option");
  /* open database */
  if (!mysql_real_connect(&db, "localhost", "drupal", "evolution", DATABASE, 0, NULL, 0))
    {
      fprintf(stderr, "SQL error #%u: %s\n", mysql_errno(&db), mysql_error(&db));
      mysql_close(&db);
      exit(1);
    }
  /* create table */
  if (mysql_query(&db, "CREATE TABLE IF NOT EXISTS test(key INT(10), value VARCHAR(10))"))
    {
      fprintf(stderr, "SQL error #%u: %s\n", mysql_errno(&db), mysql_error(&db));
      mysql_close(&db);
      exit(1);
    }
  /* insert */
  if (mysql_query(&db, "INSERT INTO test (value) VALUES ('test')"))
    fprintf(stderr, "SQL error #%u: %s\n", mysql_errno(&db), mysql_error(&db));
  /* select */
  mysql_query(&db, "SELECT * FROM test");
  callback();
  /* drop table */
  if (mysql_query(&db, "DROP TABLE IF EXISTS test;"))
    fprintf(stderr, "SQL error #%u: %s\n", mysql_errno(&db), mysql_error(&db));
  /* close */
  mysql_close(&db);
  return (0);
}
