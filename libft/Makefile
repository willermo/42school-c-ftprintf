# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/07 13:53:08 by doriani           #+#    #+#              #
#    Updated: 2023/04/24 10:30:01 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= libft.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= ./
SRC_FILES    = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c\
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c      \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c  \
			  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c  ft_strnstr.c  \
			  ft_atoi.c  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c      \
			  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c     \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c    \
			  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c  ft_lstlast.c         \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c       \
			  ft_lstmap.c get_next_line.c ft_swap.c ft_strrev.c ft_itoa_16.c   \
			  ft_itoa_8.c ft_uitoa.c ft_putchar.c ft_putendl.c ft_putstr.c     \
			  ft_putnbr.c ft_itoa_base.c
OBJ_FILES	= $(SRC_FILES:.c=.o)
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))   
OBJS		= $(addprefix $(SRC_DIR), $(OBJ_FILES))

#############
## Targets ##
#############
all: $(SRCS) $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

usage:
	@echo "Usage: make [usage | all | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Library build targets --"
	@echo "\tall: compile the library"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and library"
	@echo "\tre: fclean and all"
	