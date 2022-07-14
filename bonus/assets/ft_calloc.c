/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:13:53 by euyi              #+#    #+#             */
/*   Updated: 2022/07/11 17:20:28 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*  Calloc function uses two params to determine how it allocates memory
** first param is number of arrays. second is size of each element or array. 
** Then it returns a pointer to the allocated memory.
** This makes Calloc cross-platform compatible at all time. 
**
** Calloc prefills each of the NMEMB element/memory with 0 or '\0'.  
**
** If nmemb or size == 0, then calloc() returns a unique pointer value that 
** can later be passed to free(). TIP: Malloc(0); returns unique rubbish  
**
** If the multiplication of nmemb and size would result in integer overflow, 
** then calloc() returns an  error.
*/
/*	#include <stdio.h>
**	int main(void)
**	{
**		int *ptr;
**
**		ptr = (int *) ft_calloc(2, sizeof(int));
**		printf("%i %i %i %i", ptr[0], ptr[1], ptr[2], ptr[3]); 
**	}
*/

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(num * size);
	ptr = ft_memset(ptr, '\0', num * size);
	return (ptr);
}
