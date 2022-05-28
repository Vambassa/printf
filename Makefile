NAME	= libftprintf.a

SRCS	= ./source/*.c ./Libft/*.c

OBJS	= *.o

INCLUDE	= ./include

LIB		= ./Libft

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIB)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(OBJS): $(SRCS) $(INCLUDE)/ft_printf.h
	@$(CC) $(CFLAGS) -c $(SRCS) -I$(INCLUDE)

clean:
	@rm -rf $(OBJS)
	@make fclean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
