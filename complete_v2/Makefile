NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRCS = main.c execute_command.c
OBJS = $(SRCS:%.c=%.o)

LIBFT = LIBFT/libft.a
LIBFTDIR = LIBFT/

INCLUDES = pipex.h

LIBFLAGS = -L./$(LIBFTDIR) -lft

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFLAGS) -o $(NAME)

$(LIBFT) : $(LIBFTDIR)
	$(MAKE) -C $(LIBFTDIR)

clean :
	rm -f $(OBJS)
	$(MAKE) clean -C $(LIBFTDIR)

fclean : clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFTDIR)

re : fclean all

.PHONY : clean fclean re all