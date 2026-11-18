NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putptr.c \
	   ft_puthex.c handler.c

OBJS = $(SRCS:.c=.o)


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : clean
