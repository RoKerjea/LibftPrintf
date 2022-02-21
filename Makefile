SRCS= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c
SRCS:= $(SRCS) ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c
SRCS:= $(SRCS) ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strrchr.c
SRCS:= $(SRCS) ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c
SRCS:= $(SRCS) ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c
SRCS:= $(SRCS) ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c
SRCS:= $(SRCS) ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strchr.c
HEAD	= libftprintf.h
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

clean:		${RM} ${OBJECTS}

fclean:		clean ${RM} ${NAME} 

re:			fclean all

.PHONY:		all ${NAME} clean fclean re