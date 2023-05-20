SRCS = srcs/ft_strlen.asm srcs/ft_strcpy.asm srcs/ft_strcmp.asm srcs/ft_write.asm srcs/ft_read.asm srcs/ft_strdup.asm
OBJS = $(SRCS:.asm=.o)
NAME = libasm.a
CC = nasm
FLAGS = -felf64
RM = rm -f

%.o : %.asm
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
