##
## Makefile for  in /home/tixado_d/epitech/rendu/PSU_2015_malloc
##
## Made by Dany Tixador
## Login   <tixado_d@epitech.net>
##
## Started on  Wed Feb  3 13:43:51 2016 Dany Tixador
## Last update Sun Feb 14 16:34:42 2016 Dany Tixador
##

CC 	=	gcc

RM	=	@rm -f

CFLAGS	+=	-fPIC -W -Wall -Wextra -Werror

CFLAGS	+= 	-I ./include

LDFLAGS =	-shared -Wl,-soname,$(NAME)

NAME 	=	libmy_malloc.so

SRC	=	./src/malloc.c		\
		./src/realloc.c		\
		./src/free.c		\
		./src/calloc.c		\
		./src/malloc_tools.c	\

OBJ	= 	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):$(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
