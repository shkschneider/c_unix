NAME	=	libcfree.a

CC	=	gcc

CFLAGS	+=	-I.
CFLAGS	+=	-W -Wall -Wstrict-prototypes
CFLAGS	+=	-pedantic --std=c99 #-ansi
CFLAGS	+=	-fno-strict-aliasing -funroll-loops -O3

LDFLAGS	=	-lc

RM	=	rm -f

SRC	=	cfree.c cfree_check.c cfree_list.c cmalloc.c

OBJ	=	$(SRC:.c=.o)

AR	=	ar -rcu

RANLIB	=	ranlib

$(NAME)	:	all
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

run	:	$(NAME)
	@./$(NAME)
