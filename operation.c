/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:36:16 by azinbi-           #+#    #+#             */
/*   Updated: 2022/10/17 03:12:02 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*rotate_a(t_list *a)
{
	t_list	*head;
	t_list	*remind;

	ft_putstr("ra\n");
	head = a->next;
	remind = a;
	while (a->next)
		a = a->next;
	a->next = remind;
	remind->next = NULL;
	return (head);
}

t_list	*swap_a(t_list *a)
{
	int		value;

	ft_putstr("sa\n");
	value = a->val;
	a->val = a->next->val;
	a->next->val = value;
	return (a);
}

t_list	*rotate_b(t_list *b)
{
	t_list	*head;
	t_list	*remind;

	ft_putstr("rb\n");
	head = b->next;
	remind = b;
	while (b->next)
		b = b->next;
	b->next = remind;
	remind->next = NULL;
	return (head);
}

t_list	*rotate_reverse_a(t_list *a)
{
	t_list	*head;
	t_list	*before;
	t_list	*reminder;

	head = a;
	before = a;
	ft_putstr("rra\n");
	while (a->next)
		a = a->next;
	while (before->next->next)
		before = before->next;
	reminder = a;
	reminder->next = head;
	before->next = NULL;
	return (reminder);
}

void	push_a(t_list **a, t_list **b)
{
	t_list	*to_a;
	t_list	*to_b;

	ft_putstr("pa\n");
	to_b = (*b)->next;
	to_a = (*b);
	to_a->next = *(a);
	(*a) = to_a;
	(*b) = to_b;
}
