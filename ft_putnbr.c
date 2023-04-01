/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-gand <mel-gand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 12:40:43 by mel-gand          #+#    #+#             */
/*   Updated: 2023/03/30 21:17:41 by mel-gand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(int c)

{
	write(1, &c, 2);
}

void	ft_putnbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}	
	if (nbr >= 0 && nbr < 10)
		ft_putchar(nbr + '0');
	else if (nbr < 0)
	{
		ft_putchar('-');
		ft_putnbr(nbr * (-1));
	}
	else
	{
		ft_putnbr (nbr / 10);
		ft_putnbr (nbr % 10);
	}	
}
