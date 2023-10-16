CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42
NAME = libget_next_line.a
SRCS = get_next_line.c get_next_line_utils.c
BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(SRCS:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

$(NAME): $(BONUS_OBJS)
		ar rcs $(NAME) $(BONUS_OBJS)

clean:
		rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -rf $(NAME)

re: fclean all