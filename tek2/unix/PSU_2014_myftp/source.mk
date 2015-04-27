##
## source.mk for  in /home/gicque_p/project/tek2/unix/PSU_2014_myftp
## 
## Made by Pierrick Gicquelais
## Login   <gicque_p@epitech.net>
## 
## Started on  Mon Mar  2 11:55:52 2015 Pierrick Gicquelais
## Last update Sat Mar 28 20:29:14 2015 Pierrick Gicquelais
##

S_SRC	+=	src/server/main.c
S_SRC	+=	src/server/init.c
S_SRC	+=	src/server/run.c
S_SRC	+=	src/server/destroy.c
S_SRC	+=	src/server/do_actions.c
S_SRC	+=	src/server/session_actions.c
S_SRC	+=	src/server/manipulation_actions.c
S_SRC	+=	src/server/transfert_actions.c
S_SRC	+=	src/server/miscellaneous_actions.c
S_SRC	+=	src/server/protocol_actions.c
S_SRC	+=	src/server/informational_actions.c
S_SRC	+=	src/server/authentication.c
S_SRC	+=	src/server/user_exists.c
S_SRC	+=	src/server/encryption.c
S_SRC	+=	src/server/session.c
S_SRC	+=	$(MISC)

C_SRC	+=	src/client/main.c
C_SRC	+=	src/client/init.c
C_SRC	+=	src/client/run.c
C_SRC	+=	src/client/destroy.c
C_SRC	+=	src/client/do_actions.c
C_SRC	+=	src/client/protocol.c
C_SRC	+=	src/client/transfert.c
C_SRC	+=	src/client/list.c
C_SRC	+=	src/client/set_user.c
C_SRC	+=	src/client/wreturn.c
C_SRC	+=	$(MISC)

MISC	+=	src/misc/usage.c
MISC	+=	src/misc/xsocket.c
MISC	+=	src/misc/xgetprotobyname.c
MISC	+=	src/misc/xbind.c
MISC	+=	src/misc/xlisten.c
MISC	+=	src/misc/xaccept.c
MISC	+=	src/misc/xconnect.c
MISC	+=	src/misc/xfork.c
MISC	+=	src/misc/xmalloc.c
MISC	+=	src/misc/xchdir.c
MISC	+=	src/misc/xgetcwd.c
MISC	+=	src/misc/xopen.c
MISC	+=	src/misc/swrite.c
MISC	+=	src/misc/getnextline.c
MISC	+=	src/misc/trim.c
MISC	+=	src/misc/split_string.c
MISC	+=	src/misc/is_alphanumeric.c
MISC	+=	src/misc/merror.c
MISC	+=	src/misc/serror.c
