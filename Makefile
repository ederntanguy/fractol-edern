NAME		=	fract_ol

SRCS		=	main.c color_set.c event.c pos_and_iteration.c refresh.c julia_set.c other_functions.c

OBJS		=	${SRCS:.c=.o}

CC			=	cc
CFLAGS		=	-Ofast -Wall -Werror -Wextra -g
LIBS		=	-Lmlx -lmlx -lXext -lX11

RM			=	rm -f

%.o: %.c
				${CC} ${CFLAGS} -c $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
				rm -f $(OBJS)
fclean:			clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re