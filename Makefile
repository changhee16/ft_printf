NAME		= libftprintf.a

CC			= cc
CFLAG		= -Wall -Wextra -Werror

INCLUDES 	= ./ft_printf.h

RM 			= rm -f

AR 			= ar
ARFLAGS 	= rcs

SRCS 		= ft_printf.c ft_printf_func.c
OBJS 		= $(SRCS:.c=.o)

all	: $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
re :
	$(MAKE) clean
	$(MAKE) all

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

.PHONY : all clean fclean re