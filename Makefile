SRCS =  $(shell find "." -name "*.c")
OBJS = $(SRCS:.c=.o)
NAME = so_long
CC	= gcc
RM = rm -f
CFLAGS = -lmlx -framework OpenGL -framework AppKit
$(NAME) : ${SRCS}
	@${CC} ${CFLAGS} -o ${NAME} ${SRCS}
all: ${NAME}
clean: 
		@${RM} ${NAME}
fclean: clean
		${RM} ${NAME}
re: fclean all
.PHONY:  all clean fclean