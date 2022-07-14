/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:38:40 by euyi              #+#    #+#             */
/*   Updated: 2022/07/08 16:12:57 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/push_swap.h"

// *********************************************************************
// reverse_buckets(int *stk, int *stkb, int *stklen) pushes elements  *
// back to stack A from the array holding all the buckets. It sorts	  *
// these elements from highest to lowest before pushing them back	  *
// to stack A.														  *
// Param 1 is the Stack A where the sorted elements will be pushed,	  *
// Param 2 is the Stack B currently holding the buckets,			 *
// Param 3 is a pointer to the array that holds the length			*
// of both Param 1 and Param 2.										*
// *******************************************************************
void	reverse_buckets(int *stk, int *stkb, int *stklen)
{
	int	top_btm[2];

	while (!sorted_arg(stk, stklen[0]) || stklen[1])
	{
		if (greatest_ele(stkb, stkb[0], stklen[1]))
			ft_pp(stkb, stk, stklen, 1);
		else if (greatest_ele(stkb, stkb[1], stklen[1]))
			ft_ss(stkb, 2);
		else if (highest_top(stkb, stklen[1], &top_btm[0])
			<= highest_btm(stkb, stklen[1], &top_btm[1]))
		{
			while (highest_top(stkb, stklen[1], &top_btm[0]))
				ft_rot(stkb, stklen[1], 2);
		}
		else if (highest_btm(stkb, stklen[1], &top_btm[1])
			< highest_top(stkb, stklen[1], &top_btm[0]))
		{
			while (top_btm[1])
			{
				ft_rr(stkb, stklen[1], 2);
				top_btm[1]--;
			}
		}	
	}
}
