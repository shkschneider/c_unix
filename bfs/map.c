/* BFS algorithme */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAP_HEIGHT	15
#define MAX		0xffffff

/*
** Faites un loader de map si vous vous ennuyez :p
** o symbolise le depart
** x symbolise l'arrivee
** # represente un obstacle
** ' ' un chemin libre
** Il faut trouver le plus cours chemin entre o et x
**
** Cette implementation ne prend pas en compte les diagonales
*/

static char	**init_map(void)
{
  char		**map;

  map = malloc(sizeof(*map) * (MAP_HEIGHT + 1));
  map[0] = strdup("###############");
  map[1] = strdup("#            x#");
  map[2] = strdup("#  #### ##### #");
  map[3] = strdup("#  ###        #");
  map[4] = strdup("# ###  ########");
  map[5] = strdup("# ####        #");
  map[6] = strdup("#    ######## #");
  map[7] = strdup("## ###        #");
  map[8] = strdup("#   #         #");
  map[9] = strdup("#             #");
  map[10] = strdup("# ## ###      #");
  map[11] = strdup("#             #");
  map[12] = strdup("# ###      ####");
  map[13] = strdup("#  o          #");
  map[14] = strdup("###############");
  map[15] = 0;
  return (map);
}

/*
** On code proprement, donc on free chaque malloc : )
*/
static void	free_map(void **map)
{
  int		c;

  for (c = 0; map[c]; c++)
    free(map[c]);
  free(map);
}

/*
** Fonction pour l'affichage de la map
*/
static void	aff_map(char **map)
{
  int		c;

  for (c = 0; map[c]; c++)
    {
      write(1, map[c], strlen(map[c]));
      write(1, "\n", 1);
    }
}

/*
** Fonction qui regarde si une case est libre autout de la case courante
*/
static char	free_place(int **h_map, int c, int c2)
{
  if (h_map[c][c2 - 1] == -2)
    return (1);
  else if (h_map[c][c2 + 1] == -2)
    return (1);
  else if (h_map[c + 1][c2] == -2)
    return (1);
  else if (h_map[c - 1][c2] == -2)
    return (1);
  return (0);
}

/*
** On copie la map dans un int ** et on associe des coefiscients pour chaque type de case
*/
static int	**cpy_map(char **map, int w, int h)
{
  int		c;
  int		c2;
  int		**h_map;

  h_map = malloc(sizeof(*h_map) * (h + 1));
  for (c = 0 ; c < h ; c++)
    {
      h_map[c] = malloc(sizeof(**h_map) * (w + 1));
      for (c2 = 0 ; c2 < w ; c2++)
	{
	  if (map[c][c2] == '#')
	    h_map[c][c2] = -3;
	  else if (map[c][c2] == ' ')
	    h_map[c][c2] = -2;
	  else if (map[c][c2] == 'x')
	    h_map[c][c2] = -1;
	  else if (map[c][c2] == 'o')
	    h_map[c][c2] = 0;
	}
    }
  h_map[c] = 0;
  return (h_map);
}

/*
** On associe un coefiscient de proximite a chaque point
*/
static int	associate_coef(int **h_map, int c, int c2)
{
  if (h_map[c][c2 - 1] == -2)
    h_map[c][c2 - 1] = h_map[c][c2] + 1;
  if (h_map[c][c2 + 1] == -2)
    h_map[c][c2 + 1] = h_map[c][c2] + 1;
  if (h_map[c - 1][c2] == -2)
    h_map[c - 1][c2] = h_map[c][c2] + 1;
  if (h_map[c + 1][c2] == -2)
    h_map[c + 1][c2] = h_map[c][c2] + 1;
  return (1);
}

/*
** Fonction qui recherche le plus petit coefiscient sur les cases entourant une case
*/
static void	get_smaler(int **map_h, int *c, int *c2)
{
  int		min;
  int		dir_c;
  int		dir_c2;

  min = MAX;
  if (map_h[*c][*c2 - 1] >= 0 && map_h[*c][*c2 - 1] < min)
    {
      min = map_h[*c][*c2 - 1];
      dir_c = *c;
      dir_c2 = *c2 - 1;
    }
  if (map_h[*c][*c2 + 1] >= 0 &&  map_h[*c][*c2 + 1] < min)
    {
      min = map_h[*c][*c2 + 1];
      dir_c = *c;
      dir_c2 = *c2 + 1;
    }
  if (map_h[*c - 1][*c2] >= 0 && map_h[*c - 1][*c2] < min)
    {
      min = map_h[*c - 1][*c2];
      dir_c = *c - 1;
      dir_c2 = *c2;
    }
  if (map_h[*c + 1][*c2] >= 0 && map_h[*c + 1][*c2] < min)
    {
      min = map_h[*c + 1][*c2];
      dir_c = *c + 1;
      dir_c2 = *c2;
    }
  *c = dir_c;
  *c2 = dir_c2;
}

/*
** On recherche le chemin ayant les plus petits coefiscient
*/
static void	put_shorter(int **map_h, char **map, int w, int h)
{
  int		c = 0;
  int		c2 = 0;

  while (c < w && map_h[c][c2] != -1)
    {
      c2 = 0;
      while (c2 < h && map_h[c][c2] != -1)
	c2++;
      if (map_h[c][c2] != -1)
	c++;
    }
  while (map_h[c][c2] != 0)
    {
      get_smaler(map_h, &c, &c2);
      map[c][c2] = 'o';
    }
}

/*
** Fonction qui test on a pas associe de coefiscient a une case joignant l'arrive
*/

static int	is_end(int **h_map, int c, int c2)
{
  if (h_map[c][c2] == -1 &&
      ((h_map[c][c2 - 1] != -3 && h_map[c][c2 - 1] != -2) ||
       (h_map[c][c2 + 1] != -3 && h_map[c][c2 + 1] != -2) ||
       (h_map[c - 1][c2] != -3 && h_map[c - 1][c2] != -2) ||
       (h_map[c + 1][c2] != -3 && h_map[c + 1][c2] != -2)))
    return (1);
  return (0);
}

/*
** On parcourt la map en largeur
*/
static void	bfs(char **map, int w, int h)
{
  int		**h_map;
  int		c;
  int		c2;
  char		end = 1;

  h_map = cpy_map(map, w, h);
  while (end)
    {
      for (c = 0 ; c < h && end ; c++)
	{
	  for (c2 = 0 ; c2 < w && end ; c2++)
	    {
	      if (is_end(h_map, c, c2)) /* On associe un coefiscient pour chaque point different d'un obstacle et de l'arrive */
		end = 0;
	      if (end && h_map[c][c2] != -3 && h_map[c][c2] != -2 && h_map[c][c2] != -1 && free_place(h_map, c, c2))
		end = associate_coef(h_map, c, c2);
	    }
	}
    }
  put_shorter(h_map, map, w, h);
  free_map((void **)h_map);
}

/*
** Un main, what else ? :p
*/
int	main(void)
{
  char	**map;

  map = init_map();
  aff_map(map);
  bfs(map, strlen(map[0]), MAP_HEIGHT);
  aff_map(map);
  free_map((void **)map);
  return (0);
}
