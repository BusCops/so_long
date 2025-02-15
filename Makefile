NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -lXext -lX11 -lm

RM = rm -rf

SRCS = ft_get_next_line/get_next_line.c  ft_get_next_line/get_next_line_utils.c \
utils/helper_function1.c utils/helper_function2.c utils/helper_function3.c \
args_check/args_check1.c args_check/args_check2.c args_check/args_check3.c args_check/args_check4.c args_check/args_check5.c \
main/so_long.c \
so_long_utils/so_long_util1.c so_long_utils/so_long_util2.c so_long_utils/so_long_util3.c
OBJS = ${SRCS:.c=.o}

all: ${NAME}

${NAME} : ${SRCS}
	${CC} ${CFLAGS} ${SRCS} ${MLXFLAGS} -o ${NAME}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : clean fclean all re
.SECONDARY :