NAME	=	philo

SRCS	= 	all/*.c main.c

OBJCT	=	${all:.c=.o}

RM		=	rm -f

CC		=	gcc -Wall -Wextra -Werror -I./mlx

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC)  $(SRCS)  -o $(NAME)

clean :
	${RM} ${OBJCT}

fclean : clean
	${RM} ${NAME}

re : fclean all