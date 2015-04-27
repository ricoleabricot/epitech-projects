##
## source.mk for  in /home/gicque_p/project/tek2/unix/PSU_2014_myirc
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Sat Apr  4 12:52:24 2015 Pierrick Gicquelais
## Last update Wed Apr 15 15:42:48 2015 Pierrick Gicquelais
##

S_SRC	+=	src/server/main.c
S_SRC	+=	src/server/init.c
S_SRC	+=	src/server/run.c
S_SRC	+=	src/server/destroy.c
S_SRC	+=	src/server/read.c
S_SRC	+=	src/server/read_file.c
S_SRC	+=	src/server/commands.c
S_SRC	+=	src/server/broadcast.c
S_SRC	+=	src/server/channel_commands.c
S_SRC	+=	src/server/user_commands.c
S_SRC	+=	src/server/nick_commands.c
S_SRC	+=	src/server/password_commands.c
S_SRC	+=	src/server/operator_commands.c
S_SRC	+=	src/server/file_commands.c
S_SRC	+=	src/server/mode_commands.c
S_SRC	+=	src/server/name_commands.c
S_SRC	+=	src/server/other_commands.c
S_SRC	+=	src/server/misc_commands.c
S_SRC	+=	src/server/help_commands.c
S_SRC	+=	src/server/channel.c
S_SRC	+=	src/server/channel_node.c
S_SRC	+=	src/server/channel_complements.c
S_SRC	+=	src/server/user.c
S_SRC	+=	src/server/user_node.c
S_SRC	+=	src/server/user_complements.c
S_SRC	+=	src/server/op.c
S_SRC	+=	src/server/op_node.c
S_SRC	+=	src/server/file.c
S_SRC	+=	src/server/file_node.c
S_SRC	+=	src/server/file_complements.c
S_SRC	+=	src/server/encryption.c
S_SRC	+=	src/server/password.c
S_SRC	+=	$(MISC)

C_SRC	+=	src/client/main.c
C_SRC	+=	src/client/init.c
C_SRC	+=	src/client/run.c
C_SRC	+=	src/client/destroy.c
C_SRC	+=	src/client/read.c
C_SRC	+=	src/client/connection.c
C_SRC	+=	src/client/get_command.c
C_SRC	+=	src/client/protocol.c
C_SRC	+=	src/client/file.c
C_SRC	+=	src/client/no_error.c
C_SRC	+=	src/client/wreturn.c
C_SRC	+=	$(MISC)

MISC	+=	src/misc/usage.c
MISC	+=	src/misc/xsocket.c
MISC	+=	src/misc/xgetprotobyname.c
MISC	+=	src/misc/xbind.c
MISC	+=	src/misc/xlisten.c
MISC	+=	src/misc/xaccept.c
MISC	+=	src/misc/xconnect.c
MISC	+=	src/misc/xmalloc.c
MISC	+=	src/misc/swrite.c
MISC	+=	src/misc/getnextline.c
MISC	+=	src/misc/trim.c
MISC	+=	src/misc/is_reply.c
MISC	+=	src/misc/is_error.c
MISC	+=	src/misc/split_string.c
MISC	+=	src/misc/merror.c
MISC	+=	src/misc/serror.c
