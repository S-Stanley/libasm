SRCS = srcs/ft_strlen.asm srcs/ft_strcpy.asm srcs/ft_strcmp.asm
BONUS =
OBJS = $(SRCS:.asm=.o)
OBJSBONUS = $(BONUS:.asm=.o)
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
	$(RM) $(OBJS) $(OBJSBONUS)
fclean: clean
		$(RM) $(NAME)
re: fclean $(NAME)

bonus:	$(OBJS) $(OBJSBONUS)
		ar rc $(NAME) $(OBJS) $(OBJSBONUS)

.PHONY: all clean fclean re bonus
