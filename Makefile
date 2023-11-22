# Nombre de la biblioteca
NAME = libftprintf.a


#compilador y Opciones de compilacion

CC = gcc
CFLAG = -Werror -Wall -Wextra

SOURCE = ft_printf.c ft_pr_arg1.c ft_pr_arg2.c

# Objetos
OBJ = $(SOURCE:.c=.o)

all: $(NAME)

# Regla Principal
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	
# Regla OBJ
$(OBJ): $(SOURCE)
	$(CC) $(CFLAG) -c $(SOURCE)


# limpieza
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

re: fclean all