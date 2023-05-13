#include "../../includes/sorter.h"
#include "../includes/test.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int		*stk;
	int		*stkb;
	int		*stklen;
	char	gelesen[100005];

	argc++;
	stk = (int *)calloc(1000001, sizeof(int));
	stkb = (int *)calloc(1000001, sizeof(int));
	stklen = (int []){0, 0, 0};
	stklen[0] = cmd_to_stk(stk, argv + 1);
	if ((!argv[1]) || ((!stklen[0]
				|| chk_dup(stk, stklen[0] -1)) && write(2, "Error\n", 6)))
		return (1);
	stklen[2] = read(0, gelesen, 100000);
	if (stklen[2] > 0)
		gelesen[(stklen[2])] = 0;
	if (sorted_arg(stk, stklen[0]) || chk_algo(stk, stkb, stklen, gelesen))
		write (1, "OK\n", 3);
	else
		write (2, "KO\n", 3);
	free(stk);
	free(stkb);
	return (0);
}
