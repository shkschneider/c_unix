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
		cmalloc.c cfree.c\
		check.c

OBJ	=	$(SRC:.c=.o)

AR	=	ar -rcu

RANLIB	=	ranlib

INC	=	/usr/include

LIB	=	/usr/lib

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
	$(CP) cfree.h $(INC)
	$(CP) $(NAME) $(LIB)

uninstall	:
	$(RM) $(INC)/cfree.h
	$(RM) $(LIB)/$(NAME)
