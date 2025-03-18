SRCS = ft_memset.c ft_bzero.c ft_memcpy.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
ft_strlen.c ft_isalpha.c ft_isdigit.c ft_striteri.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
 ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c
SRCSBONUS =	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c $(SRCS)

OBJ = $(SRCS:%.c=%.o)
OBJBONUS = $(SRCSBONUS:%.c=%.o)
CFLAGS = -Wall -Wextra -Werror
CC = cc
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -crs $@ $^

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJBONUS)
	ar -crs $(NAME) $^

.PHONY: all fclean clean re bonus
