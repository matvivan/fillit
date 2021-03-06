/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matvivan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:29:06 by matvivan          #+#    #+#             */
/*   Updated: 2019/09/23 20:03:07 by matvivan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n / 10)
		ft_putnbr(n / 10);
	if (n < 0)
	{
		if (!(n / 10))
			write(1, "-", 1);
		ft_putchar('0' - n % 10);
	}
	else
		ft_putchar('0' + n % 10);
}
