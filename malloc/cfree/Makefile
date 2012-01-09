NAME	=	libcfree.a

CC	=	gcc

CFLAGS	+=	-I.
CFLAGS	+=	-W -Wall -Wstrict-prototypes
CFLAGS	+=	-pedantic --std=c99 #-ansi
CFLAGS	+=	-fno-strict-aliasing -funroll-loops -O3

LDFLAGS	=	-lc

RM	=	rm -f

CP	=	cp -r

SRC	=	list.c\
		cmalloc.c crealloc.c cfree.c\
		check.c

INC	=	cfree.h

OBJ	=	$(SRC:.c=.o)

AR	=	ar -rcu

RANLIB	=	ranlib

INC_DIR	=	/usr/include

LIB_DIR	=	/usr/lib

$(NAME)	:	$(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RANLIB) $(NAME)

all	:	$(OBJ)

.c.o	:
	$(CC) -c $< -o $@ $(CFLAGS)

clean	:
	$(RM) $(OBJ)
	$(RM) *~ \#*\#

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean $(NAME)

install	:	$(NAME)
	$(CP) $(INC) $(INC_DIR)
	$(CP) $(NAME) $(LIB_DIR)

uninstall	:
	$(RM) $(INC_DIR)/cfree.h
	$(RM) $(LIB_DIR)/$(NAME)
