/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 18:05:24 by euyi              #+#    #+#             */
/*   Updated: 2022/07/11 18:28:52 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../assets/push_swap.h"
#include "../assets/checker.h"

// ******************************************************************
// chk_algo(int *stk, int *stkb, int *stklen, char *gelesen) reads *
// the push_swap commands stored as arguments in Param 4,		   *
// and executes these commands on the stack A (Param 1) &&		  *
// stack B (Param 2). 											  *
// Param 3 points to the array memory where the array length	   *
// of both stack A and stack B are stored.						   *
// ******************************************************************
int	chk_algo(int *stk, int *stkb, int *stklen, char *gelesen)
{
	while (*gelesen)
	{
		if (!ft_strncmp(gelesen, "ra", 2))
		{
			gelesen += 2;
			ch_rot(stk, stklen[0]);
		}
		else if (!ft_strncmp(gelesen, "sa", 2))
		{
			gelesen += 2;
			ch_ss(stk);
		}
		else if (!ft_strncmp(gelesen, "rra", 3))
		{
			gelesen += 3;
			ch_rr(stk, stklen[0]);
		}
		else
			chk_algo_2(stk, stkb, stklen, &gelesen);
	}
	if (sorted_arg(stk, stklen[0]))
		return (1);
	return (0);
}

// ************************************************************
// This is a child of 										 *
// chk_algo(int *stk, int *stkb, int *stklen, char *gelesen) *
// for reducing number of lines								 *
// ************************************************************
void	chk_algo_2(int *stk, int *stkb, int *stklen, char **gelesen)
{
	if (!ft_strncmp(*gelesen, "ss", 2))
	{
		*gelesen += 2;
		ch_s2(stk, stkb);
	}
	else if (!ft_strncmp(*gelesen, "pb", 2))
	{
		*gelesen += 2;
		ch_pp(stk, stkb, stklen, 0);
	}
	else if (!ft_strncmp(*gelesen, "pa", 2))
	{
		*gelesen += 2;
		ch_pp(stkb, stk, stklen, 1);
	}
	else if (!ft_strncmp(*gelesen, "rb", 2))
	{
		*gelesen += 2;
		ch_rot(stkb, stklen[1]);
	}
	else
		chk_algo_3(stkb, stklen, gelesen);
}

// ************************************************************
// This is a child of 										 *
// chk_algo(int *stk, int *stkb, int *stklen, char *gelesen) *
// for reducing number of lines								 *
// ************************************************************
void	chk_algo_3(int *stkb, int *stklen, char **gelesen)
{	
	if (!ft_strncmp(*gelesen, "sb", 2))
	{
		*gelesen += 2;
		ch_ss(stkb);
	}	
	else if (!ft_strncmp(*gelesen, "rrb", 3))
	{
		*gelesen += 3;
		ch_rr(stkb, stklen[1]);
	}
	else if (**gelesen == '\n')
		(*gelesen)++;
	else
	{
		write(2, "Error\n", 6);
		exit (0);
	}
}
