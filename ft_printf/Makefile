SRCS		= ft_printf.c\
		  unsigned_printf.c\
		  hexa_printf.c


OBJS			= ${SRCS:.c=.o}



NAME			= libftprintf.a

CC			= cc

RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror

all:		${NAME} 

.c.o: 
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS} 

clean:	
			${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
