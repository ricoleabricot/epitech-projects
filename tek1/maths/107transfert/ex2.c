/*
** ex2.c for 107transfert in /home/gicque_p/local/maths/107transfert
** 
** Made by Pierrick Gicquelais
** Login   <gicque_p@epitech.net>
** 
** Started on  Fri Mar  7 17:43:55 2014 Pierrick Gicquelais
** Last update Sun Mar  9 19:24:23 2014 Pierrick Gicquelais
*/

#include	"transfert.h"

void		launch_python()
{
  pid_t		pid;

  if ((pid = fork()) == -1)
    env_error();
  else if (pid == 0)
    execlp("./python", "./python", NULL);
  else
    waitpid(pid, 0, WSTOPPED);
}

void		ex2(int argc, char **argv)
{
  char		**tab;
  char		**tab2;
  int		*tab_int;
  int		*tab_int2;
  int		pow;
  int		pow2;
  int		i;

  i = 1;
  if (argc % 2 != 0)
    unpair_error(argc);
  while (argv[i])
    {
      if (argv[i][0] == '\0')
	string_error(i);
      pow = check_string(argv[i]);
      tab = my_str_to_wordtab(argv[i]);
      tab_int = my_reverse_tab_to_int(tab, pow + 1);
      i++;
      if (argv[i][0] == '\0')
	string_error(i);
      pow2 = check_string(argv[i]);
      aff_suscomp(tab_int, pow, pow2, i);
      tab2 = my_str_to_wordtab(argv[i]);
      tab_int2 = my_reverse_tab_to_int(tab2, pow2 + 1);
      i++;
      aff_subcomp(tab_int2, pow2);
      launch_python();
    }
}
