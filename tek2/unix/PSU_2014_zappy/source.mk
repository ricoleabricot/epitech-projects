##
## source.mk for Zappy in /home/rousse_3/rendu/Zappy
## 
## Made by rousse_3
## Login   <rousse_3@epitech.net>
## 
## Started on  Mon Jun 15 22:19:56 2015 rousse_3
## Last update Sun Jul  5 21:55:28 2015 Pierrick Gicquelais
##

SRCS_CLIENT		=	src/client/main.cpp
SRCS_CLIENT		+=	src/client/Map.cpp
SRCS_CLIENT		+=	src/client/Item.cpp
SRCS_CLIENT		+=	src/client/Team.cpp
SRCS_CLIENT		+=	src/client/Error.cpp
SRCS_CLIENT		+=	src/client/Player.cpp
SRCS_CLIENT		+=	src/client/Option.cpp
SRCS_CLIENT		+=	src/client/Socket.cpp
SRCS_CLIENT		+=	src/client/Square.cpp
SRCS_CLIENT		+=	src/client/getLevel.cpp
SRCS_CLIENT		+=	src/client/Position.cpp
SRCS_CLIENT		+=	src/client/playerIa.cpp
SRCS_CLIENT		+=	src/client/Inventory.cpp
SRCS_CLIENT		+=	src/client/StateMachine.cpp

SRCS_SERVER		=	src/server/main.c
SRCS_SERVER		+=	src/server/usage.c
SRCS_SERVER		+=	src/server/init.c
SRCS_SERVER		+=	src/server/run.c
SRCS_SERVER		+=	src/server/destroy.c
SRCS_SERVER		+=	src/server/end.c
SRCS_SERVER		+=	src/server/update.c
SRCS_SERVER		+=	src/server/options.c
SRCS_SERVER		+=	src/server/verbose.c
SRCS_SERVER		+=	src/server/read.c
SRCS_SERVER		+=	src/server/write.c
SRCS_SERVER		+=	src/server/connection.c
SRCS_SERVER		+=	src/server/buffer.c
SRCS_SERVER		+=	src/server/egg.c
SRCS_SERVER		+=	src/server/incantation.c
SRCS_SERVER		+=	src/server/broadcast.c
SRCS_SERVER		+=	src/server/broadcast_complements.c
SRCS_SERVER		+=	src/server/commands_client.c
SRCS_SERVER		+=	src/server/commands_graphic.c
SRCS_SERVER		+=	src/server/team.c
SRCS_SERVER		+=	src/server/team_complements.c
SRCS_SERVER		+=	src/server/client.c
SRCS_SERVER		+=	src/server/client_complements.c
SRCS_SERVER		+=	src/server/list.c
SRCS_SERVER		+=	src/server/list_complements.c
SRCS_SERVER		+=	src/server/xmalloc.c
SRCS_SERVER		+=	src/server/xgetprotobyname.c
SRCS_SERVER		+=	src/server/xsocket.c
SRCS_SERVER		+=	src/server/xbind.c
SRCS_SERVER		+=	src/server/xlisten.c
SRCS_SERVER		+=	src/server/xaccept.c
SRCS_SERVER		+=	src/server/xopen.c
SRCS_SERVER		+=	src/server/trim.c
SRCS_SERVER		+=	src/server/split_string.c
SRCS_SERVER		+=	src/server/swrite.c
SRCS_SERVER		+=	src/server/merror.c
SRCS_SERVER		+=	src/server/serror.c
SRCS_SERVER		+=	src/server/map.c
SRCS_SERVER		+=	src/server/map_complements.c
SRCS_SERVER		+=	src/server/player.c
SRCS_SERVER		+=	src/server/player_complements.c
SRCS_SERVER		+=	src/server/generate.c
SRCS_SERVER		+=	src/server/pos.c
SRCS_SERVER		+=	src/server/log.c

SRCS_SERVER		+=	src/server/option/port.c
SRCS_SERVER		+=	src/server/option/map_width.c
SRCS_SERVER		+=	src/server/option/map_height.c
SRCS_SERVER		+=	src/server/option/teams.c
SRCS_SERVER		+=	src/server/option/max_clients.c
SRCS_SERVER		+=	src/server/option/delay.c
SRCS_SERVER		+=	src/server/option/bypass.c
SRCS_SERVER		+=	src/server/option/verbose.c

SRCS_SERVER		+=	src/server/client/speaking.c
SRCS_SERVER		+=	src/server/client/connect_number.c
SRCS_SERVER		+=	src/server/client/expulse.c
SRCS_SERVER		+=	src/server/client/fork.c
SRCS_SERVER		+=	src/server/client/forward.c
SRCS_SERVER		+=	src/server/client/inventory.c
SRCS_SERVER		+=	src/server/client/left.c
SRCS_SERVER		+=	src/server/client/put_obj.c
SRCS_SERVER		+=	src/server/client/right.c
SRCS_SERVER		+=	src/server/client/see.c
SRCS_SERVER		+=	src/server/client/see_get.c
SRCS_SERVER		+=	src/server/client/spell.c
SRCS_SERVER		+=	src/server/client/take_obj.c

SRCS_SERVER		+=	src/server/graphic/graphic_connection.c
SRCS_SERVER		+=	src/server/graphic/map_size.c
SRCS_SERVER		+=	src/server/graphic/case_content.c
SRCS_SERVER		+=	src/server/graphic/map_content.c
SRCS_SERVER		+=	src/server/graphic/teams_name.c
SRCS_SERVER		+=	src/server/graphic/player_position.c
SRCS_SERVER		+=	src/server/graphic/player_inventory.c
SRCS_SERVER		+=	src/server/graphic/player_level.c
SRCS_SERVER		+=	src/server/graphic/player_speaking.c
SRCS_SERVER		+=	src/server/graphic/player_put.c
SRCS_SERVER		+=	src/server/graphic/player_take.c
SRCS_SERVER		+=	src/server/graphic/player_expulse.c
SRCS_SERVER		+=	src/server/graphic/player_dead.c
SRCS_SERVER		+=	src/server/graphic/server_message.c
SRCS_SERVER		+=	src/server/graphic/get_delay.c
SRCS_SERVER		+=	src/server/graphic/set_delay.c
SRCS_SERVER		+=	src/server/graphic/new_connection.c

SRCS_GRAPHIC		=	src/graphic/main.cpp		\
				src/graphic/Xcheck.cpp		\
				src/graphic/Game.cpp		\
				src/graphic/Socket.cpp		\
				src/graphic/Player.cpp		\
				src/graphic/Welcome.cpp		\
				src/graphic/Loading.cpp
