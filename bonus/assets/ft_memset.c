/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 19:44:15 by euyi              #+#    #+#             */
/*   Updated: 2022/07/11 17:20:21 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/* This function has three parameters.
** Void pointer(param 1), Integer(param 2), and Unsigned Integer(param 3)
** The Void pointer(param 1) parameter takes a pointer to a string, then it
** writes the ASCII char representation of the Integer(param 2) argument to 
** each array in Void pointer(param 1) beginning from specified pointer 
** index point, eg, ptr + 3 means begin writing to ptr from ptr[3]. 
** The Unsigned Integer(param 3)parameter sets how many arrays it writes to.
** Then it returns a pointer to the first memory byte.
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**	    char *ptr;
**
**		ptr = (char []){'h', 'e', 'l', 'l', 'o', 'p', 'i', '\0'};    
**	    printf("%s \n", (char *) ft_memset(ptr, 'c', 3));
**	}
*/

void	*ft_memset(void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		((char *)s)[(i)] = c;
		i++;
	}
	return (s);
}
