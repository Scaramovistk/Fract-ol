NAME	= fractol

SRCS	= main.c \

OBJS	= ${SRCS:.c=.o}

INCS	= minilibx\

GCC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror

%.o : %.c
			${GCC} ${CFLAGS} -c $< -o ${<:.c=.o} -Imlx

${NAME}:	${OBJS}
			# make -C ./libft
			# cp libft/libft.a
			# ${NAME} ${OBJS}
			$(GCC) $(OBJS) -I ${INCS} -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS}
			make -C ./libft clean

fclean:		clean
			${RM} ${NAME}
			make -C ./libft	fclean

bonus:

re:			fclean all

.PHONY:		all clean fclean bonus re .c.o
