/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:23:38 by euyi              #+#    #+#             */
/*   Updated: 2022/07/08 16:16:07 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define   PUSH_SWAP_H

# include	<stdlib.h>
# include	<unistd.h>

//*************************************************************
// Function for filtering CMD line args and fixing them into *
// an array if the arguments pass all the Push_Swap standard *
//************************************************************* 
int		cmd_to_stk(int stk[], char **argv);
void	cmd_to_stk_2(int *stack, int *length, char ***argv);
int		number_zero(char **pttr, int *stack);
int		check_for_char(char *ptr);
int		chk_dup(int stack[], int len);
int		sorted_arg(int *stack, int len);

// *****************************************************
// Helper functions for logics used by the algorithm. *
// These functions are stored in main_utilsX files 	  *
// *****************************************************
int		best_btel(int *stk, int n, int len);
void	shift_down(int *src, int len);
void	shift_up(int *src, int len);
int		les_el(int *stack, int n, int len);
void	return_b(int *stkb, int *stk, int *len);
int		int_rank(int *arr, int len, int ele, int *rank);
int		begin_top(int *stack, int stacklen, int parts, int *count);
int		begin_btm(int *stack, int stacklen, int parts, int *count);
void	push_to_buckets(int *stk, int *stkb, int *stklen, int *parts_rem);
void	sort_parts_rem(int *stk, int *stkb, int *parts_rem);
void	reverse_buckets(int *stk, int *stkb, int *stklen);
int		greatest_ele(int *stack, int n, int len);
int		highest_top(int *stack, int stacklen, int *count);
int		highest_btm(int *stack, int stacklen, int *count);

//********************************
// Push_Swap command functions. *
// For pushing and swapping.	*
//********************************
int		*ft_rot(int *stk, int len, int flag);
int		*ft_rr(int *stk, int len, int flag);
int		*ft_ss(int *stk, int flag);
void	ft_pp(int *src, int *dest, int *len, int flag);
void	ft_s2(int *stk, int *stk2);

// Function from libft
int		ft_atoi(const char *nptr);

// Algorithm functions
void	new_algo(int *stk, int *stkb, int *stklen);
void	big_algo(int *stk, int *stkb, int *stklen);

#endif
