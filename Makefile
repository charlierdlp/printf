SRCS	= ft_printf.c ft_printf_utils.c ft_print_c.c ft_print_s.c ft_print_d.c ft_print_x.c  ft_print_ux.c ft_print_u.c ft_print_p.c ft_slots.c ft_printf_extras.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra
.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
					make -C ./libft/
					cp libft/libft.a ${NAME}
					ar rc ${NAME} ${OBJS}
					ranlib ${NAME}
all:		${NAME}
clean:
					${RM} ${OBJS}
					make clean -C libft/
fclean:		clean
					${RM} ${NAME}
					make fclean -C libft/
re:					fclean all
.PHONY:		all clean fclean re
