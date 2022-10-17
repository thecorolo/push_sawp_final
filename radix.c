/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:06:41 by azinbi-           #+#    #+#             */
/*   Updated: 2022/10/17 03:12:02 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bits_calculator(int len)
{
	int	max_num;
	int	bits;

	bits = 0;
	max_num = len - 1;
	while (max_num)
	{
		max_num >>= 1;
		bits++;
	}
	return (bits);
}

void	ft_sort_radix(t_list **a, t_list **b, int index, int max_num)
{
	while (max_num--)
	{
		if (!((*a)->val >> index & 1))
			push_b(a, b);
		else
			(*a) = rotate_a(*a);
	}
}

void	radix_sort(t_list **a, t_list **b, int len)
{
	int	max_bits;
	int	i;

	max_bits = max_bits_calculator(len);
	i = 0;
	while (i < max_bits)
	{
		ft_sort_radix(a, b, i, len);
		while ((*b))
			push_a(a, b);
		i++;
	}
}

void	it_is_sorted(t_list *a)
{
	while (a->next && (a->val < a->next->val))
	{
		a = a->next;
		if (a->next == NULL)
			exit(0);
	}
}
