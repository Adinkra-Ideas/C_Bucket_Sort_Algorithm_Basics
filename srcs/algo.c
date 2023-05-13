#include "../includes/sorter.h"

// ***********************************************************
// The new_algo(int *stk, int *stkb, int *stklen) function	*
// sorts the stack for sorter when the length of the 	*
// stack received is less than or equal to 10 elements.	   *
// Param 1 is the stack A, Param 2 is the stack B,			*
// Param 3 is a pointer to the array that holds the length 	*
// of both Param 1 and Param 2.								 *
// ************************************************************
void	new_algo(int *stk, int *stkb, int *stklen)
{
	while (!sorted_arg(stk, stklen[0]) || stklen[1])
	{
		if (best_btel(stk, stk[0], stklen[0]))
			ft_rot(stk, stklen[0], 1);
		else if (best_btel(stk, stk[1], stklen[0]))
		{
			ft_ss(stk, 1);
			ft_rot(stk, stklen[0], 1);
		}
		else if (les_el(stk, stk[0], stklen[0]) && !sorted_arg(stk, stklen[0]))
			ft_pp(stk, stkb, stklen, 0);
		else if (stk[1] < stk[0])
			ft_ss(stk, 1);
		else if (sorted_arg(stk, stklen[0]) && stklen[1])
			return_b(stkb, stk, stklen);
		else
			ft_rot(stk, stklen[0], 1);
	}
}

// ***********************************************************
// The big_algo(int *stk, int *stkb, int *stklen) function	*
// sorts the stack for sorter when the length of the 	*
// stack received is greater than 10 elements.	   		   *
// Param 1 is the stack A, Param 2 is the stack B,			*
// Param 3 is a pointer to the array that holds the length 	*
// of both Param 1 and Param 2.								 *
// ************************************************************
void	big_algo(int *stk, int *stkb, int *stklen)
{
	int	buckets;
	int	parts_rem[2];

	buckets = 7;
	if (stklen[0] > 100)
		buckets = 11;
	parts_rem[0] = stklen[0] / buckets;
	parts_rem[1] = stklen[0] % buckets;
	push_to_buckets(stk, stkb, stklen, parts_rem);
	if (parts_rem[1])
		sort_parts_rem(stk, stkb, stklen);
	if (stklen[1])
		reverse_buckets(stk, stkb, stklen);
}
