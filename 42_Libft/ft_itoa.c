/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egermen <egermen@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 17:29:11 by egermen           #+#    #+#             */
/*   Updated: 2023/10/14 17:29:13 by egermen          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(int n, int fflag)
{
	int	cont;

	cont = 0;
	if (n == 0)
		cont = 1;
	while (n != 0)
	{
		cont++;
		n = n / 10;
	}
	if (fflag < 0)
		cont++;
	return (cont);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		lenn;
	int		sign;
	long	n2;

	n2 = n;
	if (n2 < 0)
		sign = -1;
	else
		sign = 1;
	n2 = sign * n2;
	lenn = ft_len(n2, sign);
	str = (char *)malloc(sizeof(char) * lenn + 1);
	if (!str)
		return (0);
	str[lenn] = '\0';
	while (--lenn >= 0)
	{
		str[lenn] = '0' + (n2 % 10);
		n2 = n2 / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}
