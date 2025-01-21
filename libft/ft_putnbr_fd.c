/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armirono <armirono@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 23:59:51 by armirono          #+#    #+#             */
/*   Updated: 2023/11/13 00:26:05 by armirono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursion(int nbr, int fd1)
{
	char	digit;

	if (nbr > 9 || nbr < -9)
		recursion(nbr / 10, fd1);
	nbr = nbr % 10;
	if (nbr < 0)
		nbr *= -1;
	digit = nbr + 48;
	ft_putchar_fd(digit, fd1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	recursion(n, fd);
}
