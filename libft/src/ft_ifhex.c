/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:52:16 by leaugust          #+#    #+#             */
/*   Updated: 2024/09/11 12:57:20 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_hexlen(unsigned int value)
{
	size_t	len;

	len = 0;
	while (value)
	{
		len++;
		value /= 16;
	}
	return (len);
}

void	ft_puthex(unsigned int n, const char c)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, c);
		ft_puthex(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (c == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (c == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

void	ft_ifhex(unsigned int value, const char c, int *output)
{
	if (value == 0)
		(*output) += (write(1, "0", 1));
	else
	{
		ft_puthex(value, c);
		(*output) += ft_hexlen(value);
	}
}
