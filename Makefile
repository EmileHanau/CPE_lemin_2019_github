##
## EPITECH PROJECT, 2020
## lemin
## File description:
## Makefile
##

.PHONY:
	all
	clean
	fclean
	re

SRC	=	src/main.c                      \
	src/extra/my_strcmp.c           \
	src/input_handling.c            \
	src/input_handling2.c		\
        src/printf/my_printf.c          \
        src/printf/my_putchar.c         \
        src/printf/disp_stdarg2.c       \
        src/printf/sum_stdarg.c         \
        src/printf/disp_stdarg.c        \
        src/printf/my_put_nbr.c         \
        src/printf/my_put_nbr_base.c	\
        src/printf/my_putstr.c          \
        src/printf/disp_stdarg3.c       \
        src/printf/disp_stdarg4.c       \
        src/printf/my_getnbr.c          \
        src/printf/my_strlen.c          \
        src/solve.c                     \
        src/graph_handling.c            \
        src/output.c                    \
        src/linked_list_handling.c	\
	src/extra/cut_string.c

OBJ	=	$(SRC:.c=.o)

NAME	=	lem_in

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
