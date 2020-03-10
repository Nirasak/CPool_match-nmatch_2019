##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	match.c	\
		nmatch.c	\

TESTS	=	tests/test_match.c	\
		tests/test_nmatch.c

OBJ	=	$(SRC:.c=.o)

UNITFLAGS	=	-lcriterion --coverage

EXECTESTS	=	unit_tests

test_run:	$(OBJ)
	$(CC) $(TESTS) $(UNITFLAGS) $(SRC) -o $(EXECTESTS)
	./$(EXECTESTS) && gcovr --exclude tests/ && gcovr --exclude tests/ --branches

clean:
	rm -f $(OBJ)
	rm -f *.gc*

fclean: clean
	rm -f $(EXECTESTS)

re: fclean all

.PHONY:	all clean fclean re
