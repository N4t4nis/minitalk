# willcard = prend tout les fichiers *.c (variable propre au Makefile)
SRCS_S = server.c
SRCS_C = client.c
# OBJS = variable SRC modifiee avec .o au lieu de .c comme extension
OBJS_S = $(SRCS_S:.c=.o)
OBJS_C = $(SRCS_C:.c=.o)
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
EXEC_server = server
EXEC_client = client
NAME = minitalk

$(NAME) : $(EXEC_server) $(EXEC_client)

$(EXEC_server) : $(OBJS_S)
	make -C libft/
	make -C ft_printf/
	$(CC) $(CFLAGS) -o $@ -g -fsanitize=address $(OBJS_S) $(LIBFT) $(PRINTF) 

$(EXEC_client) : $(OBJS_C)
	$(CC) $(CFLAGS) -o $@ -g -fsanitize=address $(OBJS_C) $(LIBFT) $(PRINTF)

all : $(NAME)

clean : 
	rm -f $(OBJS_S) $(OBJS_C)
	make fclean -C libft/
	make fclean -C ft_printf/

fclean : clean
	rm -f $(EXEC_server) $(EXEC_client)

re : fclean all
