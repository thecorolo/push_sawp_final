/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:05:54 by azinbi-           #+#    #+#             */
/*   Updated: 2022/10/17 03:12:02 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*fill_table(t_list *a, int *tab)
{
	int	i;

	i = 0;
	while (a)
	{
		tab[i] = a->val;
		a = a->next;
		i++;
	}
	return (tab);
}

int	*ft_bubblesort(int total, int *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < total - 1)
	{
		j = 0;
		while (j < total - i - 1)
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
	return (tab);
}

t_list	*ft_indexing(t_list *a, int total, int *tab)
{
	int		i;
	t_list	*head;

	head = a;
	while (a)
	{
		i = 0;
		while (i < total)
		{
			if (a->val == tab[i])
			{
				a->val = i;
				a = a->next;
				break ;
			}
			i++;
		}
	}
	return (head);
}

t_list	*ft_sort_and_index(t_list *a, int total)
{
	int	*tab;

	tab = malloc(sizeof(int) * total);
	tab = fill_table(a, tab);
	tab = ft_bubblesort(total, tab);
	a = ft_indexing(a, total, tab);
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	if (argc == 1)
		exit(0);
	check_int(argv);
	a = ft_fillourstack(a, argc, argv);
	b = NULL;
	ft_check_erreur(argv);
	a = ft_sort_and_index(a, argc - 1);
	it_is_sorted(a);
	if (argc == 3)
		a = rotate_a(a);
	else if (argc == 4)
		a = sort_3_numbers(a);
	else if (argc == 5)
		a = sort_4_numbers(a, b, 4);
	else if (argc == 6)
		a = sort_4_numbers(a, b, 5);
	else
		radix_sort(&a, &b, argc - 1);
}
