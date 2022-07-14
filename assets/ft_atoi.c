/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 21:37:11 by euyi              #+#    #+#             */
/*   Updated: 2022/06/23 15:05:52 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* This function extracts only the integers from the beginning of strings
** The pointer only moves if it sees space characters or an integer
** at the beginning of the string. It skips white spaces but collects the 
** integers. It stops immediately it encounter a character that isn't 
** a number or whitespace. Then it returns the integers it has been
** collecting up till that point. If no integer collected or number is 
** greater or lesser than integer, it returns 0
*/
	// #include <stdio.h>
	// int main(void)
	// {
	// 	char str[] = "   2147483647 499khello111 l1";
	// 	int ret;
	// 	ret = ft_atoi(str);
	// 	printf("%i", ret);
	// }

static long long int	ft_intcol(long long int a, int b)
{
	if (b == 0)
		a *= 10;
	else if (b < 10)
		a = (a * 10) + b;
	return (a);
}

int	ft_atoi(const char *nptr)
{
	long long int	bank;
	int				flag;

	bank = 0;
	flag = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == 32))
		nptr++;
	if (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			flag = 1;
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		bank = ft_intcol(bank, *nptr - '0');
		nptr++;
	}
	if (flag == 1 && bank > 0 && bank <= 2147483648)
		return (bank - (bank + bank));
	else if (bank < -2147483648 || bank > 2147483647)
		bank = 0;
	return ((int)bank);
}
