NAME = push_swap
SRCS = actions/put_actions.c \
       actions/reverse_actions.c \
       actions/rotate_actions.c \
       actions/swap_actions.c \
       control/control_utils.c \
       control/control_utils1.c \
       control/control.c \
       control/ft_split.c \
       control/stack_create.c \
       sort/basic_sort.c \
       sort/radix_sort.c \
       sort/sort_utils.c \
       sort/sort.c \
       main.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

OBJS = $(SRCS:.c=.o)
RM = rm -f

all: ${NAME}
${NAME}: ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
