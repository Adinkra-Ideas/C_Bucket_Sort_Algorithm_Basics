#ifndef TEST_H
# define   TEST_H

# include	<stdlib.h>
# include	<unistd.h>
# include	<string.h>

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

#endif
