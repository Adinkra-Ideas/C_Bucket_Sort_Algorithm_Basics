/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:24:09 by euyi              #+#    #+#             */
/*   Updated: 2022/07/05 18:32:23 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/push_swap.h"

// **********************************************************************
// cmd_to_stk() function retrieves all ints from the 2D array		   *
// received as arg for param 2, and stores these ints in the array 	   *
// pointed to by param 1. 											  *
// The return value is the length count of all ints it successfully	  *
// retrieved from param 2 and stored in param 1. If for some reasons   *
// it encountered a value besides an int in param 2, it returns false. *
// **********************************************************************
int	cmd_to_stk(int stack[], char **argv)
{
	int	length;

	length = 0;
	if (argv && !argv[0])
		return (0);
	while (*argv)
	{
		while (**argv)
		{
			while (number_zero(&argv[0], &stack[length]))
				length++;
			if (ft_atoi(*argv))
				cmd_to_stk_2(stack, &length, &argv);
			else if (check_for_char(*argv) && !ft_atoi(*argv))
				return (0);
			else if (!ft_atoi(*argv))
				break ;
		}
		argv++;
	}
	return (length);
}

// ****************************************************************
// This function is simply a child of cmd_to_stk()				 *
// that had to be torn out in order to limit the parent's lines *
// to the permitted 25 lines according to 42's norm				 *
// ****************************************************************
void	cmd_to_stk_2(int *stack, int *length, char ***argv)
{
	stack[*length] = ft_atoi(**argv);
	(*length)++;
	while ((***argv >= 9 && ***argv <= 13) || (***argv == 32))
		(**argv)++;
	if (***argv == 45 || ***argv == 43)
		(**argv)++;
	while ((***argv >= 48 && ***argv <= 57))
		(**argv)++;
}

// ********************************************************************
// sorted_arg() checks the pointer to an int array received as arg	 *
// for param 1 to see if it's values are sorted already.			*
// if the array argument passed to param 1 is sorted already,		 *
// meaning it begins from lowest number to the highest,		   		*
// this function returns 1, else if unsorted, it returns 0			 *
// Param 2 is the array length count of param 1						*
// ******************************************************************
int	sorted_arg(int *stack, int len)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (i + 1 < len)
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

// ***************************************************
// chk_dup() does what it names says: It checks		*
// the array received as Param 1's arg to see if	 *
// it has duplicate elements.						*
// Param 2 is the array length count of Param 1.	*
// If duplicates exists, it returns 1, else if no	 *
// duplicates, it will return 0						*
// ***************************************************
int	chk_dup(int *stack, int len)
{
	int	i;
	int	x;

	while (len >= 0)
	{
		i = len - 1;
		x = stack[len];
		while (i >= 0)
		{
			if (x == stack[i])
				return (1);
			i--;
		}
		len--;
	}
	return (0);
}

// *****************************************************
// check_for_char() checks the array received as arg  *
// has characters besides spaces as elements.		 *
// If chars exists, it returns 1, else if no chars	 *
// it will return 0					  				  *
// *****************************************************
int	check_for_char(char *ptr)
{
	int	i;

	i = 0;
	while (*ptr)
	{
		if ((*ptr < 9 || *ptr > 13) && (*ptr != 32))
			i++;
		ptr++;
	}
	return (i);
}
