CC			=	cc -I$(INCLUDE) -Wall -Wextra -Werror #-g3 -fsanitize=address 

NAME		=	so_long
INCLUDE		=	include
SRCDIR		=	src/
OBJDIR		=	objs/
SRCS		=	$(SRCDIR)so_long.c $(SRCDIR)map_handle.c $(SRCDIR)map_handle_2.c $(SRCDIR)ft_split.c $(SRCDIR)utils.c
OBJS		=	$(SRCS:$(SRCDIR)%.c=$(OBJDIR)%.o)

MINILIBX	=	minilibx-linux
PRINTF		=	printf

AR			=	ar rcs
RM			=	rm -f

TEST		= test.c
EXEC		= test

all:		$(NAME)

mlx:
			make -C $(MINILIBX)

$(NAME):    $(OBJS)
			make -C printf
			make -C $(MINILIBX)
			$(CC) $(OBJS) -Lprintf -lftprintf -L$(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
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

re:			fclean all

test:		mlx $(TEST)
			$(CC) $(TEST) -L$(MINILIBX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz -o $(EXEC)

.PHONY:        all lib clean fclean re bonus mlx test
