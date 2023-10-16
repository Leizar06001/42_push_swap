/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger_list_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:12:55 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:12:56 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rewind_and_return(t_info *dt)
{
	size_t	i;
	int		max;

	max = find_max(dt->b, dt->sb);
	while (dt->b[0] != max)
	{
		i = 0;
		while (dt->b[i] != max)
			i++;
		if (i == 0)
			return ;
		if (i * 2 < dt->sb)
			rot(dt, 1);
		else
			revrot(dt, 1);
	}
	while (dt->sb)
		pushba(dt);
}

int	valid_pos(int to_push, int pos0, int pos1)
{
	if (to_push < pos0 && to_push > pos1)
		return (1);
	if (to_push < pos0 && pos1 > pos0)
		return (1);
	if (to_push > pos1 && pos1 > pos0)
		return (1);
	return (0);
}

int	check_push_ab(t_info *dt)
{
	int		minb;
	int		push;

	if (dt->sa == 0)
		return (0);
	push = 0;
	minb = find_min(dt->b, dt->sb);
	if (dt->c[0] > dt->b[0] && dt->c[0] < dt->b[dt->sb - 1])
		push = 1;
	else if (dt->c[0] < minb && dt->b[0] == find_max(dt->b, dt->sb))
		push = 2;
	else if (dt->c[0] > dt->b[0] && !find_pos_bigger(dt->b, dt->sb))
		push = 3;
	if (push)
		pushab(dt);
	return (push);
}
