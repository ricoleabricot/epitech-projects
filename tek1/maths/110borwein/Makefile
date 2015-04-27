##
## Makefile for 110borwein in /home/gicque_p/rendu/110borwein
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Apr  7 08:47:54 2014 Pierrick Gicquelais
## Last update Fri Apr 18 16:06:08 2014 Pierrick Gicquelais
##

all:		110borwein

110borwein:	main.o
	@-./sl
	@echo "\033[01;31mTCHOUTCHOU !!!!!!\033[0m"
	gcc -W -Wall -Wextra -O3 -o 110borwein main.o -lm

clean:
	rm -rf main.o

fclean:		clean
	rm -rf 110borwein

re:		fclean all

.PHONY:		all clean fclean re
