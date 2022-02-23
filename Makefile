SRCS= ft_printf.c printf_utils.c printf_utils2.c
HEAD	= ft_printf.h
RM		= rm -rf
NAME	= libftprintf.a
CC 		= gcc
OBJECTS	= ${SRCS:.c=.o}
CFLAGS	= -Wall -Werror -Wextra

${NAME}:	${HEAD} ${OBJECTS} 
	ar rc ${NAME} ${OBJECTS}

all:		${NAME}

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:		
	${RM} ${OBJECTS}

fclean:		clean 
	${RM} ${NAME} 

re:			fclean all

.PHONY:		all ${NAME} clean fclean re