/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:32:51 by euyi              #+#    #+#             */
/*   Updated: 2022/07/11 18:29:11 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define   CHECKER_H

# include	<stdlib.h>
# include	<unistd.h>

//********************************
// checker helper functions. 	*
//********************************
int		chk_algo(int *stk, int *stkb, int *stklen, char *gelesen);
void	chk_algo_2(int *stk, int *stkb, int *stklen, char **gelesen);
void	chk_algo_3(int *stkb, int *stklen, char **gelesen);

//********************************
// checker command functions. 	*
// For pushing and swapping.	*
//********************************
int		*ch_rot(int *stk, int len);
int		*ch_rr(int *stk, int len);
int		*ch_ss(int *stk);
void	ch_pp(int *src, int *dest, int *len, int flag);
void	ch_s2(int *stk, int *stk2);

// Functions from libft
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t num, size_t size);
void	*ft_memset(void *s, int c, size_t n);

#endif
