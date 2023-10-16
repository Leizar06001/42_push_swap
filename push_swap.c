/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rloussig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 10:06:00 by rloussig          #+#    #+#             */
/*   Updated: 2023/04/24 10:06:01 by rloussig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	select_method(t_info *info)
{
	if (info->sa == 2)
		sort_2(info, 0, 0);
	else if (info->sa == 3)
		sort_3(info);
	else if (info->sa <= 5)
		sort_5(info);
	else
		sort_big(info);
	opti_rrr(info->instr, info->pos);
	return (0);
}

int	check_arg_len(char *str, int len)
{
	if (str[0] != '-')
	{
		if (len > 11)
			return (1);
	}
	else
	{
		if (len > 10)
			return (1);
	}
	return (0);
}

int	check_numbers(char *str)
{
	int	k;
	int	len;

	len = (int)ft_strlen(str);
	if (check_arg_len(str, len))
		return (7);
	k = -1;
	while (++k < len)
	{
		if (str[k] == '-')
			k++;
		if (str[k] < '0' || str[k] > '9')
			return (3);
	}
	return (0);
}

int	check_input(int len, char **li)
{
	int	i;
	int	j;

	i = 0;
	while (++i < len - 1)
	{
		if (check_numbers(li[i]))
			return (3);
		j = i;
		while (++j < len)
		{
			if (ft_strcmp(li[i], li[j]) == 0)
				return (4);
		}
	}
	if (check_numbers(li[len - 1]))
		return (3);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		err;

	info.argc = argc;
	info.argv = argv;
	info.split = 0;
	if (argc == 1)
		err = 99;
	else if (argc == 2)
	{
		info.argv = ft_split(argv[1], ' ', &info);
		info.argc = 0;
		while (info.argv[info.argc] != 0)
			info.argc++;
	}
	err = check_input(info.argc, info.argv);
	init_struct(&info, info.argc - 1);
	if (!err)
		err = malloc_struct(&info, info.argc - 1, info.argv);
	if (!err && !is_all_sorted(info.c, info.sa))
		select_method(&info);
	clean_exit(&info);
	if (err)
		errors(err);
	return (0);
}

/* 
5 : 12max

With 100 numbers, we can get

5 points if the size of the list of instructions is less than 700

4 points if the size of the list of instructions is less than 900

3 points if the size of the list of instructions is less than 1100

2 points if the size of the list of instructions is less than 1300

1 points if the size of the list of instructions is less than 1500

With 500 numbers, we can get

5 points if the size of the list of instructions is less than 5500

4 points if the size of the list of instructions is less than 7000

3 points if the size of the list of instructions is less than 8500

2 points if the size of the list of instructions is less than 10000

1 points if the size of the list of instructions is less than 11500
*/
