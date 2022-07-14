/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:41:24 by euyi              #+#    #+#             */
/*   Updated: 2022/07/08 17:59:22 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* This function compares the first (at most) N bytes of s1 and s2.
** It returns 0 if both same. If *s1 < *s2 it returns negative int (*s1 - *s2)
** If *s1 > *s2 it returns positive integer (*s1 - *s2)
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**	   const char str[12] = "mona";
**	   const char str2[12] = "mong";
**
**	   printf("return equals %i", ft_strncmp(str, str2, 4));
**	}
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	s1--;
	s2--;
	while (n > 0)
	{
		s1++;
		s2++;
		n--;
		if (*s1 == '\0' && *s2 == '\0')
			return (0);
		else if (*s1 == '\0')
			return (-21);
		else if (*s2 == '\0')
			return (21);
		else if (*s1 != *s2)
			return ((int)*s1 - (int)*s2);
	}
	return (0);
}
