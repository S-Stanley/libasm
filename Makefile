SRCS = srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strcmp.s srcs/ft_write.s srcs/ft_read.s srcs/ft_strdup.s
OBJS = $(SRCS:.s=.o)
NAME = libasm.a
CC = nasm
FLAGS = -felf64
RM = rm -f

%.o : %.s
	$(CC) $(FLAGS) $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
all:
	$(NAME)
clean:
	$(RM) $(OBJS)
fclean: clean
		$(RM) $(NAME)
re: fclean $(NAME)

.PHONY: all clean fclean re
