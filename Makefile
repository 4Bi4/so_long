CC			=	cc -I$(INCLUDE) -g3 -Wall -Wextra -Werror #-fsanitize=address 

NAME		=	so_long
INCLUDE		=	include
SRCS		=	so_long.c map_handle.c map_handle_2.c ft_split.c utils.c
OBJS		=	$(SRCS:%.c=$(OBJDIR)%.o)
MINILIBX	=	minilibx-linux
PRINTF		=	printf
OBJDIR		=	objs/

AR			=	ar rcs
RM			=	rm -f

TEST		= test.c
EXEC		= test

all:		lib mlx $(NAME)

#bonus:		lib mlx $(NAME)

mlx:
			make -C $(MINILIBX)

$(NAME):    $(OBJS)
			make -C printf
			make -C $(MINILIBX)
			$(CC) $(OBJS) -Lprintf -lftprintf -L$(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)%.o: %.c
			mkdir -p $(OBJDIR)
			$(CC) -c $< -o $@

clean:
			$(RM) $(OBJS)
			rm -rf $(OBJDIR)
			make -C	$(PRINTF) clean
			make -C	$(MINILIBX) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(EXEC)
			make -C $(PRINTF) clean
			make -C $(MINILIBX) clean

re:			fclean all

test:		mlx $(TEST)
			$(CC) $(TEST) -L$(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(EXEC)

.PHONY:        all lib clean fclean re bonus mlx test
