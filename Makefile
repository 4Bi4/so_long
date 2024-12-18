CC			=	cc -I$(INCLUDE) -g3 #-Wall -Wextra -Werror

NAME		=	so_long
INCLUDE		=	include
SRCS		=	so_long.c
OBJS		=	$(SRCS:%.c=$(OBJDIR)%.o)
MINILIBX	=	minilibx-linux
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
#			make -C $(LIBFT)
			make -C $(MINILIBX)
			$(CC) $(OBJS) -L$(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)%.o: %.c
			mkdir -p $(OBJDIR)
			$(CC) -c $< -o $@

clean:
			$(RM) $(OBJS)
			rm -rf $(OBJDIR)
			make -C  $(MINILIBX) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(EXEC)
			make -C $(MINILIBX) clean

re:			fclean all

test:		mlx $(TEST)
			$(CC) $(TEST) -L$(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(EXEC)

.PHONY:        all lib clean fclean re bonus mlx test
