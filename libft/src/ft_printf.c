/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaugust <leaugust@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:19:26 by leaugust          #+#    #+#             */
/*   Updated: 2024/09/11 12:56:41 by leaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_type(char c, va_list value, int *output)
{
	if (c == 'c')
	{
		(*output)++;
		ft_ifchr(va_arg(value, int));
	}
	else if (c == 's')
		ft_ifstr(va_arg(value, char *), output);
	else if (c == 'p')
		ft_ifptr(va_arg(value, unsigned long long), output);
	else if (c == 'd' || c == 'i')
		ft_ifint(va_arg(value, int), output);
	else if (c == 'u')
		ft_ifudi(va_arg(value, unsigned int), output);
	else if (c == 'x' || c == 'X')
		ft_ifhex(va_arg(value, unsigned int), c, output);
	else if (c == '%')
	{
		ft_putchar_fd(c, 1);
		(*output)++;
	}
}

int	ft_printf(const char *format, ...)
{
	int		output;
	va_list	args;

	output = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_ifchr(format[0]);
			output++;
		}
		else
			ft_type(*++format, args, &output);
		format++;
	}
	va_end(args);
	return (output);
}
/*
#include <stdio.h>

int	main(void)
{
	char			caractere;
	int				entier;
	unsigned int	entier_non_signe;
	char			*chaine;
	int				*ptr;

	ptr = &entier;
	caractere = 'A';
	entier = -26;
	entier_non_signe = -26;
	chaine = "Bonjour";
	// Imprimer un caractère
	ft_printf("Caractère : %c\n", caractere);
	printf("Caractère : %c\n", caractere);
	// Imprimer un entier signé en base 10
	ft_printf("Entier signé : %d\n", entier);
	printf("Entier signé : %d\n", entier);
	// Imprimer un entier signé en base 10 (alternative)
	ft_printf("Entier signé (alternative) : %i\n", entier);
	printf("Entier signé (alternative) : %i\n", entier);
	// Imprimer un entier non signé en hexadécimal (lettres minuscules)
	ft_printf("Entier non signé en hexadécimal (minuscules) : %x\n",
		entier_non_signe);
	printf("Entier non signé en hexadécimal (minuscules) : %x\n",
		entier_non_signe);
	// Imprimer un entier non signé en hexadécimal (lettres majuscules)
	ft_printf("Entier non signé en hexadécimal (majuscules) : %X\n",
		entier_non_signe);
	printf("Entier non signé en hexadécimal (majuscules) : %X\n",
		entier_non_signe);
	// Imprimer un entier non signé en base 10
	ft_printf("Entier non signé : %u\n", entier_non_signe);
	printf("Entier non signé : %u\n", entier_non_signe);
	// Imprimer un pourcentage littéral
	ft_printf("Imprimer simplement le caractère pourcentage : %%\n");
	printf("Imprimer simplement le caractère pourcentage : %%\n");
	// Imprimer une chaine de caractres
	ft_printf("Chaine de caracteres : %s\n", chaine);
	printf("Chaine de caracteres : %s\n", chaine);
	// Imprimer l'adresse d'un pointeur
	ft_printf("Adresse du pointeur : %p\n", (void *)ptr);
	printf("Adresse du pointeur : %p\n", (void *)ptr);
	// Imprimer
	ft_printf("Imprimer : Rien\n");
	printf("Imprimer : Rien\n");
	return (0);
}
*/