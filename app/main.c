/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: euyi <euyi@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:19:46 by euyi              #+#    #+#             */
/*   Updated: 2022/07/07 16:46:53 by euyi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../assets/push_swap.h"

int	main(int argc, char *argv[])
{
	int	stk[1000001];
	int	stkb[1000001];
	int	*stklen;

	argc++;
	stklen = (int []){0, 0};
	stklen[0] = cmd_to_stk(stk, argv + 1);
	if ((!argv[1] && write(2, "No parameters specified\n", 24))
		|| ((!stklen[0] || chk_dup(stk, stklen[0] -1)) && write(2, "Error\n", 6))
		|| ((sorted_arg(stk, stklen[0]) || stklen[0] == 1)
			&& write(2, "Sorted\n", 7)))
		return (1);
	else if (stklen[0] > 1 && stklen[0] <= 10)
		new_algo(stk, stkb, stklen);
	else if (stklen[0] > 10)
		big_algo(stk, stkb, stklen);
	return (0);
}
