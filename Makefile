NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes
LIBFT_INCLUDES = libft/includes

SRCS_RAW = \
	debug.c \
	deque.c \
	deque1.c \
	dlist.c \
	dlist1.c \
	dlist2.c \
	conversions.c \
	conversions1.c \
	ps_primitives.c \
	ps_primitives1.c \
	ps_primitives2.c \
	ps_derived.c \
	ps_utilities.c \
	ps_sort_2_elements.c \
	ps_sort_3_elements.c \
	ps_sort_4_elements.c \
	ps_sort_5_elements.c \
	ps_sort_100_elements.c \
	ps_sort_500_elements.c \
	ps_sort_radix_sort.c \
	ps_sort_double_radix_sort.c \
	ps_sort_double_radix_sort_improved.c \
	ps_sort_double_radix_sort_improved_with_swaps.c \
	ps_remove_duplicates.c \
	ps_remove_skipped.c \
	ft_math_utilities.c \
	parse_args.c


SRC_DIR = src
SRCS = $(addprefix $(SRC_DIR)/,$(SRCS_RAW))

OBJS_RAW = $(SRCS_RAW:.c=.o)
OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/,$(OBJS_RAW))

SRCS_PUSH_SWAP_RAW = push_swap.c
SRCS_PUSH_SWAP = $(addprefix $(SRC_DIR)/,$(SRCS_PUSH_SWAP_RAW))
OBJS_PUSH_SWAP_RAW = $(SRCS_PUSH_SWAP_RAW:.c=.o)
OBJS_PUSH_SWAP = $(addprefix $(OBJ_DIR)/,$(OBJS_PUSH_SWAP_RAW))

SRCS_CHECKER_RAW = checker.c checker1.c
SRCS_CHECKER = $(addprefix $(SRC_DIR)/,$(SRCS_CHECKER_RAW))
OBJS_CHECKER_RAW = $(SRCS_CHECKER_RAW:.c=.o)
OBJS_CHECKER = $(addprefix $(OBJ_DIR)/,$(OBJS_CHECKER_RAW)) 

all: $(NAME)

# # Compile override for using tester to call python solution
# all:
# 	gcc -Wall -Wextra -Werror test2.c -o push_swap

$(NAME): $(OBJS) $(OBJS_PUSH_SWAP) libft
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -L libft $(OBJS) $(OBJS_PUSH_SWAP) -lft -o $@

checker: $(OBJS) $(OBJS_CHECKER) libft
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -L libft $(OBJS) $(OBJS_CHECKER) -lft -o $@

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		@mkdir -p $(@D)
		@echo "Making $<"
		$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -c $< -o $@

libft:
		@echo "Making libft"
		$(MAKE) -C libft

clean:
		$(MAKE) clean -C libft
		rm -f $(OBJS) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)
		rm -df obj

fclean:
		$(MAKE) fclean -C libft
		rm -f $(OBJS) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(NAME) $(NAME_BONUS)
		rm -df obj

re: fclean all

bonus: $(OBJS) $(OBJS_CHECKER) libft
	$(CC) $(CFLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) -L libft $(OBJS) $(OBJS_CHECKER) -lft -o checker

.PHONY: all libft clean fclean re bonus