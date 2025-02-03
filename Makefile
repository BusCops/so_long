NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = get_next_line/get_next_line.c  get_next_line/get_next_line_utils.c \
args_check/args_check1.c args_check/args_check2.c main/so_long.c utils/helper_function.c

OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean all re
.SECONDARY :