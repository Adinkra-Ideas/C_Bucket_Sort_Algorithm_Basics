/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:24:09 by euyi              #+#    #+#             */
/*   Updated: 2022/07/06 15:02:20 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/push_swap.h"

// *******************************************************************
// This function catches the int '0' that appears either at the 	*
// beginning of linear arrays, or precedeed by either spaces,	   *
// '+' or '-' at the beginning of the first linear array within    *
// the 2D array received as argument for param 1. 				  *
// If '0' appears in such dispensation, it shifts the index of	   *
// the linear array by one spot, stores the '0' in Param 2		   *
// array, and return 1. Else it simply returns 0.					*
// *******************************************************************
int	number_zero(char **pttr, int *stack)
{
	while ((**pttr >= 9 && **pttr <= 13) || (**pttr == 32))
		(*pttr)++;
	if ((**pttr == 43 || **pttr == 45) && (*(*pttr + 1) == 48))
		(*pttr)++;
	if (**pttr == 48)
	{
		*stack = 0;
		(*pttr)++;
		return (1);
	}
	else
		return (0);
}

// ********************************************************************
// Best bottom element best_btel() function checks if param 2 int is *
// less than all array elements in param 1 that are greater than the  *
// last array element of param 1; if yes, it will return 1,			 *
// else it will return 0.										  *
// Param 3 is the number of array elements in param 1			 *
// ****************************************************************
int	best_btel(int *stk, int n, int len)
{
	int	btma;
	int	flag;

	btma = stk[len - 1];
	flag = 1;
	len -= 2;
	if (n < btma)
		flag = 0;
	while (len >= 0)
	{
		if (stk[len] > btma && stk[len] < n)
			flag = 0;
		len--;
	}
	return (flag);
}

// *****************************************************************
// shift_down() shifts all array elements down by one spot in 	  *
// the array received as argument for param 1.					   *
// This means an additional array space will be encroached 		  *
// at the bottom of src, while array[0] will be duplicated into    *
// array[1] in the end.											  *
// *****************************************************************
void	shift_down(int *src, int len)
{
	while (len > 0)
	{
		src[len] = src[len - 1];
		len--;
	}
}

// ********************************************************************
// shift_up() shifts all array elements up by one spot in			 *
// the array received as argument for param 1.						*
// This means array[0] will be overwritten. And in the end,			*
// it overwrite the last element at the bottom of the array with 0	 *
// ********************************************************************
void	shift_up(int *src, int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		src[i] = src[i + 1];
		i++;
	}
	src[i] = 0;
}

// *********************************************************************
// least_ele() returns 1 if the integer received as param 2 arg	  *
// is equal to the least among all the int elements stored in 	 *
// the array of param 1. Else if param 2 is greater than				*
// any of the int elements in param 1, it returns 0.				 *
// Param 3 is the number/length of elements in 						  *
// *********************************************************************
int	les_el(int *stack, int n, int len)
{
	len--;
	while (len >= 0)
	{
		if (stack[len] < n)
			return (0);
		len--;
	}
	return (1);
}
