CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
NAME = libget_next_line.a
SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Colors
#GREEN		= \033[1;32m
#RED			= \033[1;31m
#$(NAME):		

#	@echo "$(GREEN) Compiling Files"
#	@$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all