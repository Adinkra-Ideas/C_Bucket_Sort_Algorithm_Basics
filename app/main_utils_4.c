/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:18:38 by euyi              #+#    #+#             */
/*   Updated: 2022/07/08 16:07:00 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/push_swap.h"

// *******************************************************************
// sort_parts_rem(int *stk, int *stkb, int *stklen) is called by 	*
// big_algo() to sort the remainder elements that were not pushed	*
// to buckets.													   *
// It's job is to prepares these remainder as input for new_algo() *
// Param 1 is the stack A which holds these remainder elements,	   *
// Param 2 is the Stack B which holds the buckets,					*
// Param 3 is a pointer to the array that holds the length			*
// of both Param 1 and Param 2.										*
// *******************************************************************
void	sort_parts_rem(int *stk, int *stkb, int *stklen)
{
	int	stklentmp[2];

	stklentmp[0] = stklen[0];
	stklentmp[1] = 0;
	while (stklentmp[0] > 0)
	{
		shift_down(stkb, stklen[1]);
		stklen[1]++;
		stklentmp[0]--;
	}
	stklentmp[0] = stklen[0];
	new_algo(stk, stkb, stklentmp);
	stklentmp[0] = stklen[0];
	while (stklentmp[0] > 0)
	{
		shift_up(stkb, stklen[1]);
		stklen[1]--;
		stklentmp[0]--;
	}
}

// *********************************************************************
// greatest_ele() returns 1 if the integer received as param 2 arg	  *
// is equal to the greatest among all the int elements stored in 	 *
// the array of param 1. Else if param 2 is less than				*
// any of the int elements in param 1, it returns 0.				 *
// Param 3 is the array length of param 1						  *
// *********************************************************************
int	greatest_ele(int *stack, int n, int len)
{
	len--;
	while (len >= 0)
	{
		if (stack[len] > n)
			return (0);
		len--;
	}
	return (1);
}

// ********************************************************************
// int	highest_top(int *stack, int stacklen, int *count) 			 *
// sets 3 params.													 *
// Param 1 is the stack which we need to test,						*
// param 2 is the length of the array elements in param 1,			*
// Param 3 is the memory address where the result of the test		*
// will be stored.													*
// It return 0 if the element in arr[0] of Param 1 is the greatest 	*
// integer among all the array elements, 1 if element in arr[1] is,	 *
// 2 for arr[2] ...													 *
// ********************************************************************
int	highest_top(int *stack, int stacklen, int *count)
{
	*count = 0;
	while (*count < stacklen)
	{
		if (greatest_ele(stack, stack[*count], stacklen))
			break ;
		(*count)++;
	}	
	return (*count);
}

// **********************************************************************
// int	highest_btm(int *stack, int stacklen, int *count) 				*
// sets 3 params.													   *
// Param 1 is the stack which we need to test,						   *
// param 2 is the length of the array elements in param 1,			   *
// Param 3 is the memory address where the result of the test		   *
// will be stored.													   *
// It searches the greatest int in param 1 array from bottom to top    *
// and returns 1 if the element in the last array of Param 1 		   *
// passes the test, 2 if element before the last array passes...		*
// **********************************************************************
int	highest_btm(int *stack, int stacklen, int *count)
{
	*count = 1;
	while (stacklen > 0)
	{
		if (greatest_ele(stack, stack[stacklen - 1], stacklen))
			break ;
		stacklen--;
		(*count)++;
	}	
	return (*count);
}
