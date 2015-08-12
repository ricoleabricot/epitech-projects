//
// Xcheck.cpp for  in /home/gicque_p/project/tek2/unix/PSU_2014_zappy
// 
// Made by Pierrick Gicquelais
// Login   <gicque_p@epitech.net>
// 
// Started on  Sun Jul  5 21:52:49 2015 Pierrick Gicquelais
// Last update Sun Jul  5 22:00:47 2015 Pierrick Gicquelais
//

#include	"graphic/Xcheck.hh"

bool		check_XOpen(void)
{
  Display	*disp;

  if ((disp = XOpenDisplay(NULL)) == NULL)
    return (false);
  else
    {
      XCloseDisplay(disp);
      return (true);
    }
}
