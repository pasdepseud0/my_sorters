##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Compile generator
##

SRC		=	\
			src/two_list.c


TEST	=	\
			tests/test.c

NAME	=	push_swap

NAME2	=	test_sort

OBJ		=	$(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -I include

CRIT	=	--coverage -lcriterion

all: 	$(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	gcc $(OBJ) -o $(NAME) -L lib/my -lmy

clean:
	make clean -C lib/my/
	find . \( -name "#*#" -o -name "*~" -o -name "$(OBJ)" \) -delete

fclean:	clean
	make fclean -C lib/my
	find . \( -name  "vgcore.*" -o -name "*.log" -o -name "*.a" \) -delete
	find . \( -name "*.o" -o -name "$(NAME)" -o -name "$(NAME2)" \) -delete

run_test: all
	gcc -o $(NAME2) $(SRC) $(TEST) $(CRIT) $(CFLAGS)
	./test_swap

debug: CFLAGS += -g

debug: 	re

re:	fclean all
