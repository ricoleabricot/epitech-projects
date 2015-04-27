/*
** display.c for  in /home/gicque_p/project/tek2/unix/PSU_2014_lemipc
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Feb 27 19:52:48 2015 Pierrick Gicquelais
** Last update Sun Mar  8 16:30:54 2015 Pierrick Gicquelais
*/

#include		"display.h"

static void		fill_screen(t_ipc *ipc, SDL_Surface *screen, int *color)
{
  SDL_Surface	*square;
  SDL_Rect      position;
  int		i;
  int		col;

  square = SDL_CreateRGBSurface(SDL_HWSURFACE, 10, 10, 32, 0, 0, 0, 0);
  i = 0;
  while (i < SHM_SIZE)
    {
      col = color[(ipc->map[i] - 1) % 4];
      position.x = (i * 10) % 1000;
      position.y = ((i / 100) * 10) % 1000;
      if (ipc->map[i] != 0)
	SDL_FillRect(square, NULL, SDL_MapRGB(screen->format, col & 0xFF, \
					      (col >> 8) & 0xFF, \
					      (col >> 16) & 0xFF));
      else
      	SDL_FillRect(square, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
      SDL_BlitSurface(square, NULL, screen, &position);
      i++;
    }
  SDL_FreeSurface(square);
}

static void		screen_pause(t_ipc *ipc, SDL_Surface *screen)
{
  SDL_Event	event;
  int		color[4];
  bool		stop;

  color[0] = 0xFF0000;
  color[1] = 0x00FF00;
  color[2] = 0x0000FF;
  color[3] = 0xFFFFFF;
  stop = false;
  while (!stop)
    {
      fill_screen(ipc, screen, color);
      SDL_Flip(screen);
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
	stop = true;
    }
}

static SDL_Surface	*screen_initialization(void)
{
  SDL_Surface		*screen;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "SDL initialization failed\n");
      exit(EXIT_FAILURE);
    }
  if ((screen = \
       SDL_SetVideoMode(1000, 1000, 32, \
			SDL_HWSURFACE | SDL_RESIZABLE | SDL_DOUBLEBUF)) == NULL)
    my_error("SDL_SetVideoMode");
  SDL_WM_SetCaption("LemIPC", NULL);
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
  return (screen);
}

int			main()
{
  SDL_Surface	*screen;
  t_ipc		*ipc;

  srand(time(NULL));
  ipc = ipc_initialization("LemIPC Display", 0);

  usleep(500);
  ipc->map = xshmat(ipc->shm_id, NULL, 0);

  screen = screen_initialization();
  screen_pause(ipc, screen);

  SDL_Quit();
  return (0);
}
