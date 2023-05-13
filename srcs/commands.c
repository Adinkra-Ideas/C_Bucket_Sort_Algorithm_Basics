#include "../includes/sorter.h"

// ****************************************************************
// The ft_rot() function rotates all elements in an int array.	 *
// pushing the element in position 1 to bottom position, 		*
// then position 2 becomes position 1.						    *
// Param 1 is a pointer to the int array that will be rotated. *
// Param 2 is the length of this array.						   *
// Param 3 is a flag. If 1, it prints "ra\n" else if 2, it 		*
// prints "rb\n" else if 3, it prints "rr\n".					*
// It returns a pointer to the rotated array.					 *
// ****************************************************************
int	*ft_rot(int *stk, int len, int flag)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stk[0];
	while (i + 1 < len)
	{
		stk[i] = stk[i + 1];
		i++;
	}
	stk[i] = tmp;
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 2)
		write(1, "rb\n", 3);
	else if (flag == 3)
		write(1, "rr\n", 3);
	return (stk);
}

// ****************************************************************
// ft_rr() reverse-rotates all elements in an int array.		 *
// Pushing the last element to position 1, and shifting all		*
// other elements' positions down by 1.							*
// Param 1 is a pointer to the int array that will be 		+ * * *
// reverse-rotated.										   +    ****
// Param 2 is the length of Param 1's array.				  * * *
// Param 3 is a flag. If 1, it prints "rra\n" else if 2, it		*
// prints "rrb\n" else if 3, it prints "rrr\n".					*
// It returns a pointer to the reverse-rotated array.			 *
// ****************************************************************
int	*ft_rr(int *stk, int len, int flag)
{
	int	tmp;

	tmp = stk[len - 1];
	while (len > 0)
	{
		stk[len - 1] = stk[len - 2];
		len--;
	}
	stk[0] = tmp;
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
	else if (flag == 3)
		write(1, "rrr\n", 4);
	return (stk);
}

// **********************************************************
// The ft_ss() function swaps array element 1 and array	   *
// element 2 in the array passed to it as argument for	  *
// Param 1.												 *
// Param 1 is a pointer to an array.					 *
// Param 2 is a flag. If 1, it prints "sa\n" else if 2,	 *
// it prints "sb\n" else if 3, it prints "ss\n"			  *
// It returns a pointer to the swapped array.			   *
// **********************************************************
int	*ft_ss(int *stk, int flag)
{
	int	tmp;

	tmp = stk[0];
	stk[0] = stk[1];
	stk[1] = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
	return (stk);
}

// Only used once for printing SS
void	ft_s2(int *stk, int *stk2)
{
	int	tmp;

	tmp = stk[0];
	stk[0] = stk[1];
	stk[1] = tmp;
	tmp = stk2[0];
	stk2[0] = stk2[1];
	stk2[1] = tmp;
	write(1, "ss\n", 3);
}

// **********************************************************************
// ft_pp() function pushes the element from src[0] (param 1)		   *
// to dest[0] (param 2). 											  *
// Param 3 is an int array that holds the length count of 			  *
// both param 1 and param 2. On each call, the function modifies	   *
// both of these array length counts using flag (param 4) as a 			*
// guide.  																*
// Param 4 is a flag that tells us whether the array recieved as arg  **
// by src was stack a or stack b. So the function knows whether to		*
// print "pa" or "pb"													*
// if flag==0, means src param received stack a (len[0]) as argument   *
// while param dest received stack b (len[1])						  *
// if flag==1, means src received stack b (len[1]) as argument while  *
// dest received stack a (len[0])									   *
// **********************************************************************
void	ft_pp(int *src, int *dest, int *len, int flag)
{
	int	*srclen;
	int	*destlen;

	if (flag == 0)
	{
		srclen = &len[0];
		destlen = &len[1];
		write(1, "pb\n", 3);
	}
	else if (flag == 1)
	{
		srclen = &len[1];
		destlen = &len[0];
		write(1, "pa\n", 3);
	}
	shift_down (dest, *destlen);
	dest[0] = src[0];
	*destlen += 1;
	shift_up(src, *srclen);
	*srclen -= 1;
}
