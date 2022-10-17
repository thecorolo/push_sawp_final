/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:06:41 by azinbi-           #+#    #+#             */
/*   Updated: 2022/10/17 03:50:05 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_list_b(t_list **a, t_list **b, int check)
{
	if (check == 5)
	{
		if ((*b)->val < (*b)->next->val)
			*b = rotate_b(*b);
		push_a(a, b);
		push_a(a, b);
	}
	else
		push_a(a, b);
}

t_list	*sort_4_numbers(t_list *a, t_list *b, int num)
{
	int	index;
	int	check;

	index = num;
	check = num;
	while (num)
	{
		if ((a->val == 0) || (a->val == 1 && check == 5))
		{
			push_b(&a, &b);
			index--;
		}
		a = rotate_reverse_a(a);
		num--;
	}
	a = sort_3_numbers(a);
	check_list_b(&a, &b, check);
	return (a);
}

t_list	*sort_3_numbers(t_list *a)
{
	int		num[3];
	t_list	*temp;

	temp = a;
	num[0] = temp->val;
	num[1] = temp->next->val;
	num[2] = temp->next->next->val;
	if (num[0] > num[1] && num[0] < num[2] && num[1] < num[2])
		a = swap_a(a);
	else if (num[0] > num[1] && num[0] > num[2] && num[1] > num[2])
	{
		a = swap_a(a);
		a = rotate_reverse_a(a);
	}
	else if (num[0] > num[1] && num[0] > num[2] && num[1] < num[2])
		a = rotate_a(a);
	else if (num[0] < num[1] && num[0] < num[2] && num[1] > num[2])
	{
		a = swap_a(a);
		a = rotate_a(a);
	}
	else if (num[0] < num[1] && num[0] > num[2] && num[1] > num[2])
		a = rotate_reverse_a(a);
	return (a);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*to_a;
	t_list	*to_b;

	ft_putstr("pb\n");
	to_a = (*a)->next;
	to_b = (*a);
	to_b->next = *(b);
	(*b) = to_b;
	(*a) = to_a;
}

void	ft_check_erreur(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && j == 0)
				j++;
			if (!(ft_isdigit(argv[i][j])))
				ft_breakdown("Error\n");
			j++;
		}
		i++;
	}
	duplication_erreur(argv);
}
