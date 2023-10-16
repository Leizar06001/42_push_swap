/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:05:34 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:05:35 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reset_opti(t_opti *op)
{
	op->ra = 0;
	op->rb = 0;
	op->rra = 0;
	op->rrb = 0;
}

void	select_output(int cmd)
{
	if (cmd == 0)
		write(1, "sb\n", 3);
	if (cmd == 1)
		write(1, "sa\n", 3);
	if (cmd == 2)
		write(1, "pb\n", 3);
	if (cmd == 3)
		write(1, "pa\n", 3);
	if (cmd == 4)
		write(1, "rb\n", 3);
	if (cmd == 5)
		write(1, "ra\n", 3);
	if (cmd == 6)
		write(1, "rrb\n", 4);
	if (cmd == 7)
		write(1, "rra\n", 4);
}

void	opti_rrr(int *li, int len)
{
	t_opti	op;
	int		i;

	op.p_lock = 0;
	while (op.p_lock < len)
	{
		i = 0;
		reset_opti(&op);
		if (li[op.p_lock] == 5)
			i = count_rr(&op, li, len);
		if (li[op.p_lock] == 7)
			i = count_rrr(&op, li, len);
		prt_rot(&op);
		prt_revrot(&op);
		if (op.p_lock + i < len)
			select_output(li[op.p_lock + i]);
		op.p_lock = op.p_lock + i + 1;
	}
}

/*
0 - sb
1 - sa
2 - pb
3 - pa
4 - rb
5 - ra
6 - rrb
7 - rra
*/
