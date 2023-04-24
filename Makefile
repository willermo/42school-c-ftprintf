# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: doriani <doriani@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 00:10:23 by doriani           #+#    #+#              #
#    Updated: 2023/04/24 20:13:31 by doriani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############
## Variables ##
###############
NAME		= libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRC_DIR		= ./
LIBFT_DIR	= ./libft/
LIBFT_NAME	= libft.a
SRC_FILES   = ft_printf.c ft_printf_utils.c
SRC_B_FILES = ft_printf_bonus.c ft_printf_utils_bonus.c write_letters_bonus.c  \
              write_numbers_bonus.c write_numbers_utils_bonus.c                \
			  write_pointer_bonus.c
OBJ_FILES	= $(SRC_FILES:.c=.o)
OBJ_B_FILES	= $(SRC_B_FILES:.c=.o)
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))   
OBJS		= $(addprefix $(SRC_DIR), $(OBJ_FILES))
SRCS_B		= $(addprefix $(SRC_DIR), $(SRC_B_FILES))
OBJS_B		= $(addprefix $(SRC_DIR), $(OBJ_B_FILES))
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

#############
## Targets ##
#############
all: $(NAME)

$(NAME): $(OBJS)
	(cd $(LIBFT_DIR) && make)
	@cp $(LIBFT) .
	@mv $(LIBFT_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJS)

%o: %c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(SRCS)

bonus: $(OBJS_B)
	(cd $(LIBFT_DIR) && make)
	@cp $(LIBFT) .
	@mv $(LIBFT_NAME) $(NAME)
	ar -rcs $(NAME) $(OBJS_B)

clean:
	(cd $(LIBFT_DIR) && make clean)
	rm -f $(OBJS) $(OBJS_B)

fclean:
	(cd $(LIBFT_DIR) && make fclean)
	rm -f $(OBJS) $(OBJS_B) $(NAME)

re: fclean all

usage:
	@echo "Usage: make [usage | all | bonus | clean | fclean | re]"
	@echo
	@echo "-- Usage --"
	@echo "\tusage: displays this message"
	@echo
	@echo "-- Library build targets --"
	@echo "\tall: compile the library"
	@echo "\tbonus: compile the library with bonus"
	@echo "\tclean: remove object files"
	@echo "\tfclean: remove object files and library"
	@echo "\tre: fclean and all"