NAME = push_swap
BNS= checker
SOURCES = main.c\
			libft_utils.c\
			sort.c\
			push_swap_utils.c\
			instruction.c\
			libft_utils2.c\
			ft_split.c\
			libft_utils3.c\
			push_swap_utils2.c\
			garbage_collector.c\
			libft_utils4.c \
			which_algo.c\
			sort_3.c\
			parsing.c\
			print_move.c\
			increment.c\
			sort_5.c\
			libft_utils5.c

BONUS_SOURCES = main_bonus.c\
				get_next_line.c\
				get_next_line_utils.c\
				instruction.c\
				parsing.c\
				push_swap_utils2.c\
				libft_utils.c\
				libft_utils2.c\
				libft_utils4.c\
				libft_utils3.c\
				garbage_collector.c\
				ft_split.c\
				push_swap_utils.c\
				bonus_garbage.c\
				libft_utils5.c\
				handle_instruction_bonus.c

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS_SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
#CFLAGS = -fsanitize=address -fno-omit-frame-pointer
HEADER = push_swap.h get_next_line.h

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Compiling..."
	$(CC) $(CFLAGS) $(OBJECTS) -o $@
	@echo "Done!"

bonus:$(BNS)
$(BNS) : $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $@

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -rf $(OBJECTS) $(BONUS_OBJ)

fclean: clean
	rm -rf $(NAME) $(BNS)

re:fclean all
