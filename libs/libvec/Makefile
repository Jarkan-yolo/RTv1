# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbernier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/21 03:19:16 by pbernier          #+#    #+#              #
#    Updated: 2017/08/14 22:04:38 by rlecart          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT		=	LIBVEC
NAME		=	libvec.a
OBJDIR		=	objs/
SRCDIR		=	srcs/
SRC			=	ft_double.c \
				ft_double_ssp.c \
				ft_vec3.c \
				ft_vec_ssp.c \
				mtrx4_move.c \
				mtrx4_tools.c
OBJ			=	$(addprefix $(OBJDIR),$(SRC:.c=.o))
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra -I includes/
OPTI		=	-O3
DEBUG		=	-g

WHITE		=	\033[7;49;39m
BLUE		=	\033[7;49;34m
RED			=	\x1B[31m
YELLOW		=	\x1B[33m
GREEN		=	\033[0;49;32m
GREEN_BG	=	\033[1;49;32m
GRAY		=	\033[7;49;90m
NO_COLOR	=	\033[m

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ)
	@printf "\r$(GREEN)[$(PROJECT)] Obj compilation done.                                                  \n"
	@printf "$(YELLOW)[$(PROJECT)] Compiling $(NAME)..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) compiled.                                           \n$(NO_COLOR)"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@printf "$(YELLOW)\r[$(PROJECT)] Compiling $< to $@                                                       \r"
	@$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR):
	@mkdir $(OBJDIR)

clean:
	@printf "$(YELLOW)[$(PROJECT)] Removing obj..."
	@rm -rf $(OBJ)
	@rm -rf $(OBJDIR)
	@printf "\r$(GREEN)[$(PROJECT)] Obj removed.                                                \n$(NO_COLOR)"

fclean: clean
	@printf "$(YELLOW)[$(PROJECT)] Removing $(NAME)..."
	@rm -rf $(NAME)
	@printf "\r$(GREEN)[$(PROJECT)] $(NAME) removed.                                            \n$(NO_COLOR)"

re: fclean all

.PHONY: all clean fclean re
