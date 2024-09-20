# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tecker <tecker@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 14:27:53 by tecker            #+#    #+#              #
#    Updated: 2024/09/20 11:31:50 by tecker           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	phonebook

CC				=	c++

# CFLAGS			=	-Wall -Werror -Wextra

SRC_FILES		=	phonebook.cpp \
					contact.cpp	\
					main.cpp

OBJ_DIR			=	./obj

OBJ_FILES		= 	$(SRC_FILES:%.cpp=$(OBJ_DIR)/%.o)

all:	$(NAME)

$(NAME):	$(OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

