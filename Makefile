SRCS		=		minishell.c lst_func.c parser.c utils.c

LIBFT		=		-I./libft

OBJS		=		$(SRCS:.c=.o)

NAME		=		minishell

CC			=		gcc

CFLAGS		=		

RM			=		rm -rf

all:		$(NAME) $(LIBFT)

$(LIBFT):
			make bonus -C ./libft

$(NAME):	$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -lreadline $(OBJS) libft/libft.a  -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re