# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 13:24:49 by leaugust          #+#    #+#              #
#    Updated: 2024/11/19 13:24:49 by leaugust         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

SRCS = ./src/

SOURCES =	ft_atoi.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_ifchr.c \
			ft_ifhex.c \
			ft_ifstr.c \
			ft_ifptr.c \
			ft_ifint.c \
			ft_ifudi.c \
			ft_printf.c \
			ft_lstnew.c \
			ft_lstadd_back.c

OBJECTS = ${addprefix ${SRCS}, ${SOURCES:.c=.o}}

ROSE		=	\033[1;38;5;206m
LILA		=	\033[1;38;5;177m
NC			=	\033[0m

all : ${NAME}

${NAME} : ${OBJECTS}
		@echo "${LILA}Création de l'archive ${NAME}...${NC}"
		${AR} ${ARFLAGS} $@ $^
		@echo "${ROSE}${NAME} créé avec succès !${NC}"

${SRCS}%.o : ${SRCS}%.c
		@echo "${LILA}Compilation de $<...${NC}"
		${CC} ${CFLAGS} -I ../includes -o $@ -c $<
		@echo "${ROSE}Fichier objet $@ généré.${NC}"

clean :
		@echo "${LILA}Suppression des fichiers objets...${NC}"
		rm -rf ${OBJECTS} $(NAME)
		@echo "${ROSE}Fichiers objets supprimés.${NC}"

fclean : clean
		@echo "${LILA}Suppression de l'archive ${NAME}...${NC}"
		rm -rf ${NAME}
		@echo "${ROSE}${NAME} supprimé avec succès.${NC}"

re : fclean all

.PHONY: all clean fclean re
