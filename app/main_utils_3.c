/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:24:09 by euyi              #+#    #+#             */
/*   Updated: 2022/07/08 15:59:28 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/push_swap.h"

// *************************************************
// return_b() simply returns all integers stored   *
// in Stack B (Param 1) back to Stack A(Param 2)  * 
// by calling the PA command function			   *
// Param 3 is a pointer to the array that holds   *
// the length of both Param 1 and Param 2. 		   *	
// *************************************************
void	return_b(int *stkb, int *stk, int *len)
{
	while (len[1])
		ft_pp(stkb, stk, len, 1);
}

// ******************************************************************
// int_rank() sets 4 params											*
// param 1 takes the array arg. Param 2 is the length of the array	*
// param 3 is the array element whose rank we need to check			*
// param 4 is a pointer to the memory location where the rank	   *
// result will be stored (since it runs fully on stack memory)		*
// The return value is either 0 if the param 3 arg is the lowest 	*
// among all the array element, or the number of how many elements	*
// that param 3 is greater than among the param 1 array elements	*
// *******************************************************************
int	int_rank(int *arr, int len, int ele, int *rank)
{
	len--;
	*rank = 0;
	while (len >= 0)
	{
		if (arr[len] < ele)
			*rank += 1;
		len--;
	}
	return (*rank);
}

// *******************************************************************
// int	begin_top(int *stack, int *stklen, int parts, int *count)	*
// sets 4 params.													*
// Param 1 is the stack which we need to test,						*
// param 2 is the length of the array elements in param 1,			*
// Param 3 is the number of lowest parts of the 				   *
// array that we are testing for.								  *
// Param 4 is the memory address where the result of the test	   *
// will be stored.													*
// It return 0 if the element in arr[0] of Param 1 is among the     *
// lowest "parts" elements in Param 1, 1 if element in arr[1] is, 	*
// 2 for arr[2] ...													*
// *******************************************************************
int	begin_top(int *stack, int stacklen, int parts, int *count)
{
	int	rank;

	rank = 0;
	*count = 0;
	while (*count < stacklen)
	{
		if (int_rank(stack, stacklen, stack[*count], &rank) < parts)
			break ;
		(*count)++;
	}	
	return (*count);
}

// ********************************************************************
// int	begin_btm(int *stack, int *stklen, int parts, int *count) 		*
// sets 4 params.														 *
// Param 1 is the stack which we need to test,							 *
// param 2 is the length of the array elements in param 1,				*
// Param 3 is the number of lowest parts of the 				  		*
// array that we are testing for.								  		*
// Param 4 is the memory address where the result of the test	   		 *
// will be stored.														  *
// It checks param 1 array from bottom to top.							   *	
// It return 1 if the element in arr[last] of Param 1 is among the     		*
// lowest "parts" elements in Param 1, 1 if element in arr[second-to-last]	*
// is, 2 for arr[third-to-last] ...											*
// **************************************************************************
int	begin_btm(int *stack, int stacklen, int parts, int *count)
{
	int	rank;

	rank = 0;
	*count = 1;
	while (stacklen > 0)
	{
		if (int_rank(stack, stacklen, stack[stacklen - 1], &rank) < parts)
			break ;
		stacklen--;
		(*count)++;
	}
	return (*count);
}

// ***********************************************************************
// push_to_buckets(int *stk, int *stkb, int *stklen, int *parts_rem)	*
// pushes elements from the array received as arg for Param 1, to 		*
// the array received as arg for Param 2, using batches also known		*
// as buckets. The specific size of each bucket or batch is set in 		*
// array[0] of the arg pointed to by Param 4. 						   *
// Param 3 is a pointer to the array that holds the length			   *
// of both Param 1 and Param 2.										   *
// The commented out is a more advanced variant that searches the	   *
// param 1 from both top and bottom to see which sides requires the		*
// least moves to access the next needed element, before using the		*
// result to decide the next push move.									*
// It is useful for unevenly spread random numbers.						*
// ***********************************************************************
void	push_to_buckets(int *stk, int *stkb, int *stklen, int *parts_rem)
{
	int	parts;
	int	rank;

	parts = parts_rem[0];
	while (stklen[0] > parts_rem[1])
	{
		if (int_rank(stk, stklen[0], stk[0], &rank) < parts)
		{
			ft_pp(stk, stkb, stklen, 0);
			parts -= 1;
			if (parts == 0)
				parts = parts_rem[0];
		}
		else if (les_el(stk, stk[1], stklen[0])
			&& greatest_ele(stkb, stkb[1], stklen[1]))
			ft_s2(stk, stkb);
		else
			ft_rot(stk, stklen[0], 1);
	}
}
// void	push_to_buckets(int *stk, int *stkb, int *stklen, int *parts_rem)
// {
// 	int parts;
// 	int	rank;
// 	int top_btm[2];

// 	parts = parts_rem[0];
// 	while (stklen[0] > parts_rem[1])
// 	{
// 		if (int_rank(stk, stklen[0], stk[0], &rank) < parts)
// 		{
// 			ft_pp(stk, stkb, stklen, 0);
// 			parts -= 1;
// 			if (parts == 0)
// 				parts = parts_rem[0];
// 		}
// 		else if (begin_top(stk, stklen[0], parts, &top_btm[0])
//			<= begin_btm(stk, stklen[0], parts, &top_btm[1]) )
// 		{
// 			while (begin_top(stk, stklen[0], parts, &top_btm[0]))
// 				ft_rot(stk, stklen[0], 1);			
// 		}
// 		else if ( begin_btm(stk, stklen[0], parts, &top_btm[1])
//			< begin_top(stk, stklen[0], parts, &top_btm[0]) )
// 		{
// 			while (top_btm[1])
// 			{
// 				ft_rr(stk, stklen[0], 1);
// 				top_btm[1]--;
// 			}	
// 		}
// 	}
// }
