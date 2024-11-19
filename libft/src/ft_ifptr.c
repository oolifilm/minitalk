/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ifptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 00:53:44 by leaugust          #+#    #+#             */
/*   Updated: 2024/09/16 16:06:56 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ptrlen(uintptr_t value)
{
	size_t	len;

	len = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		value /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

void	ft_ifptr(unsigned long long value, int *output)
{
	if (value == 0)
	{
		(*output) += write(1, "(nil)", 5);
	}
	else
	{
		(*output) += write(1, "0x", 2);
		ft_putptr((uintptr_t)value);
		(*output) += ft_ptrlen((uintptr_t)value);
	}
}
