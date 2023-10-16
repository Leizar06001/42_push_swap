/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_list2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:06:32 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:06:33 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_shorter_way_ab(t_info *dt, size_t pos)
{
	size_t	i;
	size_t	pnext;
	int		res;

	i = 0;
	pnext = 1;
	while (!valid_pos(dt->c[pos], dt->b[i], dt->b[pnext]))
	{
		i++;
		pnext = i + 1;
		if (pnext > dt->sb - 1)
			pnext = 0;
		if (i > dt->sb - 1)
			break ;
	}
	if (i * 2 <= dt->sb)
		res = -i;
	else
		res = dt->sb - i;
	return (res);
}

int	check_in_a_top(t_info *dt, int *min, int pbest)
{
	size_t	i;
	int		act;

	i = 0;
	while (i < dt->range && i < dt->sa)
	{
		act = find_shorter_way_ab(dt, i);
		if (act < 0)
			act = act * (-1);
		if (act + (int)i < *min)
		{
			*min = act;
			pbest = (int)i;
		}
		i++;
	}
	return (pbest);
}

int	check_in_a_bottom(t_info *dt, int *min, int pbest)
{
	size_t	i;
	int		act;

	i = 0;
	while (i < dt->range && dt->sa - i > 0)
	{
		act = find_shorter_way_ab(dt, dt->sa - i);
		if (act < 0)
			act = act * (-1);
		if (act +(int)i < *min)
		{
			*min = act;
			pbest = (int)-i;
		}
		i++;
	}
	return (pbest);
}

void	find_faster_move(t_info *dt)
{
	int		min;
	int		pbest;
	int		act;

	(void)act;
	min = (unsigned int)(-1) / 2;
	pbest = 0;
	pbest = check_in_a_top(dt, &min, pbest);
	pbest = check_in_a_bottom(dt, &min, pbest);
	if (pbest > 0)
	{
		while (pbest-- > 0)
			rot(dt, 0);
	}
	else if (pbest < 0)
	{
		while (pbest++ < 0)
			revrot(dt, 0);
	}
}

void	sort_big(t_info *dt)
{
	int	move_found;

	pushab(dt);
	pushab(dt);
	sort_2(dt, 1, 1);
	move_found = 0;
	while (dt->sa > 0)
	{
		if (!move_found)
		{
			find_faster_move(dt);
			move_found = 1;
		}
		if (check_push_ab(dt))
			move_found = 0;
		else
		{
			if (find_shorter_way_ab(dt, 0) <= 0)
				rot(dt, 1);
			else
				revrot(dt, 1);
		}
	}
	rewind_and_return(dt);
}
