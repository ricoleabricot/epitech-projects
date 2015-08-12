/*
** options.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Thu Jun 18 12:03:22 2015 Pierrick Gicquelais
** Last update Wed Jul  1 13:57:28 2015 Pierrick Gicquelais
*/

#include	"server/options.h"

static	char	(*g_str[9]) =
{
  PORT,
  WIDTH,
  HEIGHT,
  TEAMS,
  MAX_CLIENTS,
  DELAY,
  BYPASS,
  VERBOSE,
  NULL
};

static	void	(*g_fct[9])(t_server *, int, char **, int *) =
{
  &port,
  &map_width,
  &map_height,
  &teams,
  &max_clients,
  &delay,
  &bypass,
  &verbose,
  NULL
};

void		get_options(t_server *server, int argc, char **argv)
{
  char		*s;
  int		i;
  int		j;

  i = 1;
  while (i < argc)
    {
      j = 0;
      while (g_str[j] && strcmp(g_str[j], argv[i]) != 0)
	j++;

      if (g_str[j] != NULL)
	g_fct[j](server, argc, argv, &i);
      else
	{
	  asprintf(&s, "Unrecognized option: %s", argv[i]);
	  serror(s);
	}
      i++;
    }
}

void		check_options(t_server *server)
{
  if (server->width < 10)
    serror("Map width should be higher than 10 units at least (-x)");

  if (server->height < 10)
    serror("Map height should be higher than 10 units at least (-y)");

  if (server->max_clients < 1)
    serror("Max clients should be higher than 1 client at least (-c)");

  if (server->delay < 1)
    serror("Action delay should be higher than 1 at least (-t)");

  if (server->delay >= 7000000)
    serror("Action delay should be lower than 7000000 at maximum (-t)");

  if (server->teams == NULL)
    serror("There should be at least one name in teams name (-n)");
}
