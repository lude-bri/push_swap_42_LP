# result file name
NAME = push_swap
NAME_B = checker

# compiler
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L./ft_vector -lftvector -L./ft_string -lftstring -L./libft -lft
LDFLAGS_B = -L./ft_string -lftstring -L./libft -lft

# path
LIBFT_DIR = ./libft
FT_STRING_DIR = ./ft_string
FT_VECTOR_DIR = ./ft_vector

SRCS = ./src/main.c \
			./src/stack_ab_access.c ./src/stack_ab_push_swap.c \
			./src/stack_ab_rev_rotate.c ./src/stack_ab_rotate.c \
			./src/construct_ab.c ./src/stack_ab_utility.c \
			./src/normalize_int.c ./src/sanity_check.c \
			./src/psa_base.c ./src/psa_base2.c ./src/psa_base3.c \
			./src/psa_quick.c ./src/psa_quick_a.c ./src/psa_quick_b.c \
			./src/push_swap_command.c ./src/push_swap_print_command.c \


SRCS_B = ./bonus/main_bonus.c \
			./bonus/select_query_bonus.c \
			./bonus/normalize_int_bonus.c ./bonus/sanity_check_bonus.c \
			./bonus/construct_ab_bonus.c ./bonus/utility_ab_bonus.c \
			./bonus/manipulate_ab_bonus.c ./bonus/stack_ab_rotate_bonus.c ./bonus/stack_ab_rev_rotate_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

all		: $(NAME)

bonus	: $(NAME_B)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

boj		: ./boj_27657/27657.cc
	c++ -g -std=c++17 $< -o 27657
	rm -rf 27657.dSYM

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_STRING_DIR)
	$(MAKE) -C $(FT_VECTOR_DIR)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(NAME_B) : $(OBJS_B)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(FT_STRING_DIR)
	$(CC) $(OBJS_B) -o $@ $(LDFLAGS_B)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_VECTOR_DIR) clean
	$(MAKE) -C $(FT_STRING_DIR) clean
	rm -f $(OBJS) $(OBJS_B)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_VECTOR_DIR) fclean
	$(MAKE) -C $(FT_STRING_DIR) fclean
	rm -f $(NAME) $(NAME_B)
	rm -f 27657

re:
	make fclean
	make all

gdb: all $(NAME) $(TEMP_PATH)			## Debug w/ gdb
	tmux split-window -h "gdb --tui --args ./$(NAME)"
	tmux resize-pane -L 5
	make get_log

vgdb: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck) & gdb
	tmux split-window -h "valgrind --vgdb-error=0 --log-file=gdb.txt ./$(NAME) $(ARG)"
	make vgdb_pid
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(NAME)"
	tmux resize-pane -U 18
	make get_log

valgrind: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck)
	tmux set-option remain-on-exit on
	tmux split-window -h "valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) $(ARG)"
	tmux split-window -h "gdb --tui --args ./$(NAME)"
	tmux resize-pane -L 5
	make get_log

vgdb: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck) & gdb
	tmux split-window -h "valgrind --vgdb-error=0 --log-file=gdb.txt ./$(NAME) $(ARG)"
	make vgdb_pid
	tmux split-window -v "gdb --tui -x $(TEMP_PATH)/gdb_commands.txt $(NAME)"
	tmux resize-pane -U 18
	make get_log

valgrind: all $(NAME) $(TEMP_PATH)			## Debug w/ valgrind (memcheck)
	tmux set-option remain-on-exit on
	tmux split-window -h "valgrind --leak-check=full --show-leak-kinds=all -s ./$(NAME) $(ARG)"

get_log:
	touch gdb.txt
	@if command -v lnav; then \
		lnav gdb.txt; \
	else \
		tail -f gdb.txt; \
	fi

.PHONY: clean fclean re all bonus
