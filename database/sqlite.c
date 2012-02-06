/*
 * gcc sqlite.c -lsqlite3
 */

#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>

#define DATABASE "/tmp/TEST.db"

sqlite3 *db = NULL;

static int callback(void *unused, int argc, char **argv, char **cols)
{
  for (int i = 0; i < argc; i++)
    printf("%s%s=%s", (i ? ", " : ""), cols[i], argv[i] ? argv[i] : "NULL");
  printf("\n");
  return (0);
}

int main(void)
{
  /* open */
  if (sqlite3_open(DATABASE, &db) != SQLITE_OK)
    {
      fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
      sqlite3_close(db);
      exit(1);
    }
  /* create */
  if (sqlite3_exec(db, "create table test(key integer, value varchar(10));", NULL, NULL, NULL) == SQLITE_OK)
    {
      /* insert */
      if (sqlite3_exec(db, "insert into test values(1, 'one');", callback, NULL, NULL) != SQLITE_OK)
	fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }
  else
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
  /* select */
  if (sqlite3_exec(db, "select * from test;", callback, NULL, NULL) != SQLITE_OK)
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
  /* drop table */
  if (sqlite3_exec(db, "drop table if exists TEST.test;", callback, NULL, NULL) != SQLITE_OK)
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
  /* drop database */
  if (remove(DATABASE))
    fprintf(stderr, "File error: could not drop database %s\n", DATABASE);
  /* close */
  sqlite3_close(db);
  return (0);
}
