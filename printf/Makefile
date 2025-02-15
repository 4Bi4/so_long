CC = cc
CCFLAGS = -Wall -Werror -Wextra 

NAME = libftprintf.a
INCLUDES = ft_printf.h
SRC = ft_printf.c put_things_1.c put_things_2.c
OBJ = $(SRC:.c=.o)

AR = ar rcs
RM = rm -f

TEST = main.c
EXEC = testprint

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)
fclean: clean
	$(RM) $(NAME) $(EXEC) 

re: fclean all

test: $(NAME)
	$(CC) $(TEST) -L. -lftprintf -o $(EXEC) $(CCFLAGS)

.PHONY: all clean fclean re test
