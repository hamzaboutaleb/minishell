SRCS = *.c */*/*.c

NAME = minishell


$(NAME): all

all:
	cc *.c */*/*.c -lreadline -g -fsanitize=address -o minishell
