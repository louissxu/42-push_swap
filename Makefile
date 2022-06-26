NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes
LIBFT_INCLUDES = libft/includes

SRCS_RAW = push_swap.c deque.c dlist.c
SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/,$(SRCS_RAW))

OBJS_RAW = $(SRCS_RAW:.c=.o)
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJS_RAW))

all: $(NAME)

$(NAME): $(OBJS) libft
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -L libft $(OBJS) -lft -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@mkdir -p $(@D)
		@echo "Making $<"
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -c $< -o $@

libft:
		@echo "Making libft"
		$(MAKE) -C libft

clean:
		$(MAKE) clean -C libft
		rm -f $(OBJS)
		rm -df obj

fclean:
		$(MAKE) fclean -C libft
		rm -f $(OBJS) $(NAME)
		rm -df obj

re: fclean all

.PHONY: all libft clean fclean re