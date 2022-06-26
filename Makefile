NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c deque.c dlist.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) libft
		$(CC) $(CFLAGS) -I . -L libft $(OBJS) -lft -o $@

%.o:%.c
		@echo "Making $<"
		$(CC) $(CFLAGS) -c $< -o $@

libft:
		@echo "Making libft"
		$(MAKE) -C libft

clean:
		$(MAKE) clean -C libft
		rm -f $(OBJS)

fclean:
		$(MAKE) fclean -C libft
		rm -f $(OBJS) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re