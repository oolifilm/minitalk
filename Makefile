# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 15:52:32 by leaugust          #+#    #+#              #
#    Updated: 2024/11/12 15:52:32 by leaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
SERVER		=	server
CLIENT		=	client
CCF			=	clang -Wall -Wextra -Werror -g
LIBFT_PATH	=	libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(LIBFT_PATH)$(LIBFT_FILE)

# Sources
SERV_SRC	=	server.c utils.c
CLIE_SRC	=	client.c
SRC_PATH	=	./sources/
SERV_SRCS	=	$(addprefix $(SRC_PATH), $(SERV_SRC))
CLIE_SRCS	=	$(addprefix $(SRC_PATH), $(CLIE_SRC))

# Includes
INC			=	-I ./includes/

# Objects
SERV_OBJS	=	$(SERV_SRCS:.c=.o)
CLIE_OBJS	=	$(CLIE_SRCS:.c=.o)

# Couleurs
ROSE		=	\033[1;38;5;206m
LILA		=	\033[1;38;5;177m
NC			=	\033[0m

# Cibles
all: $(LIBFT_LIB) $(NAME)

$(LIBFT_LIB):
	@echo "$(LILA)COMPILATION DE LIBFT$(NC)"
	@make -sC $(LIBFT_PATH)
	@echo "$(ROSE)LIBFT CRÉÉE $(NC)"

$(NAME): $(SERVER) $(CLIENT)

$(SERVER): $(SERV_OBJS)
	@echo "$(LILA)COMPILATION DE SERVER$(NC)"
	$(CCF) -o $(SERVER) $(SERV_OBJS) $(LIBFT_LIB) $(INC)
	@echo "$(ROSE)SERVER CRÉÉ$(NC)"

$(CLIENT): $(CLIE_OBJS)
	@echo "$(LILA)COMPILATION DE CLIENT$(NC)"
	$(CCF) -o $(CLIENT) $(CLIE_OBJS) $(LIBFT_LIB) $(INC)
	@echo "$(ROSE)CLIENT CRÉÉ$(NC)"

%.o: %.c
	@echo "$(LILA)Compilation de $<...$(NC)"
	$(CCF) -c $< -o $@

clean:
	@echo "$(LILA)SUPPRESSION DES OBJECTS DANS LIBFT$(NC)"
	@make clean -sC $(LIBFT_PATH)
	@echo "$(ROSE)DONE$(NC)"
	@echo "$(LILA)SUPPRESSION DES OBJECTS DE MINITALK$(NC)"
	@rm -f $(SERV_OBJS) $(CLIE_OBJS)
	@echo "$(ROSE)DONE$(NC)"
	@echo "$(LILA)SUPPRESSION DES EXECUTABLES$(NC)"
	@rm -f $(SERVER) $(CLIENT)
	@echo "$(ROSE)EXECUTABLES SUPPRIMÉS$(NC)"
	
fclean: clean
	@echo "$(LILA)SUPPRESSION DES EXÉCUTABLES DE MINITALK$(NC)"
	@rm -f $(SERVER) $(CLIENT)
	@rm -f $(LIBFT_LIB)
	@echo "$(ROSE)DONE$(NC)"

re: fclean all

.PHONY: all clean fclean re
