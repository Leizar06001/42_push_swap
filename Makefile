CC = gcc
CFLAGS = -Werror -Wall -Wextra

NAME = push_swap

SRCS = push_swap.c init_exit.c utils.c ps_cmds.c \
	   simplify_list.c sort_small_lists.c check_fnc.c \
	   sort_bigger_list.c sort_bigger_list_utils.c \
	   opti_output.c opti_output_utils.c ft_split.c

OBJS = $(SRCS:%.c=%.o)

DEPS = push_swap.h

RM = rm -f

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -o $(NAME)  $(CFLAGS)

%.o:%.c $(DEPS)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJS)

re: fclean all
