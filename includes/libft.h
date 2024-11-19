/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 20:47:37 by leaugust          #+#    #+#             */
/*   Updated: 2024/11/19 13:25:08 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <assert.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*LIBFT*/

int					ft_atoi(const char *nptr);

/*LC*/

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_back(t_list **lst, t_list *new);

/*PRINTF*/

int					ft_printf(const char *format, ...);
void				ft_ifchr(char c);
void				ft_ifint(int value, int *output);
int					ft_ifstr(char *value, int *output);
void				ft_ifptr(unsigned long long value, int *output);
void				ft_ifudi(unsigned int value, int *output);
void				ft_ifhex(unsigned int value, const char c, int *output);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);

#endif