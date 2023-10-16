/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_output_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:05:41 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:05:43 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prt_rot(t_opti *op)
{
	while (op->rb || op->ra)
	{
		if (op->rb && op->ra)
		{
			write(1, "rr\n", 3);
			op->rb --;
			op->ra --;
		}
		else if (op->rb)
		{
			write(1, "rb\n", 3);
			op->rb --;
		}
		else if (op->ra)
		{
			write(1, "ra\n", 3);
			op->ra --;
		}
	}
}

void	prt_revrot(t_opti *op)
{
	while (op->rrb || op->rra)
	{
		if (op->rrb && op->rra)
		{
			write(1, "rrr\n", 4);
			op->rrb --;
			op->rra --;
		}
		else if (op->rrb)
		{
			write(1, "rrb\n", 4);
			op->rrb --;
		}
		else if (op->rra)
		{
			write(1, "rra\n", 4);
			op->rra --;
		}
	}
}

int	count_rr(t_opti *op, int *li, int len)
{
	int	i;

	i = 0;
	while (op->p_lock + i < len)
	{
		if (li[op->p_lock + i] == 5)
		{
			op->ra ++;
			i++;
		}
		else
			break ;
	}
	while (op->p_lock + i < len)
	{
		if (li[op->p_lock + i] == 4)
		{
			op->rb ++;
			i++;
		}
		else
			break ;
	}
	return (i);
}

int	count_rrr(t_opti *op, int *li, int len)
{
	int	i;

	i = 0;
	while (op->p_lock + i < len)
	{
		if (li[op->p_lock + i] == 7)
		{
			op->rra ++;
			i++;
		}
		else
			break ;
	}
	while (op->p_lock + i < len)
	{
		if (li[op->p_lock + i] == 6)
		{
			op->rrb ++;
			i++;
		}
		else
			break ;
	}
	return (i);
}
