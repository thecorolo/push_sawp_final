/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:04:54 by azinbi-           #+#    #+#             */
/*   Updated: 2022/10/17 03:12:02 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_int(char **argv)
{
	int		i;
	int		num;
	char	*str;

	i = 1;
	while (argv[i])
	{
		if (*argv[i] == '0')
		{
			while (*argv[i] == '0')
				(argv[i])++;
		}
		num = ft_atoi(argv[i]);
		str = ft_itoa(num);
		if (ft_strcmp(str, argv[i]) && num != 0)
			ft_breakdown("Error\n");
		free(str);
		i++;
	}
}

t_list	*ft_fillourstack(t_list *a, int argc, char **argv)
{
	t_list	*head;
	int		i;

	i = 1;
	a = malloc(sizeof(t_list) * 1);
	a->val = ft_atoi(argv[i]);
	a->next = NULL;
	head = a;
	while (i < argc - 1)
	{
		a->next = malloc(sizeof(t_list) * 1);
		i++;
		a->next->val = ft_atoi(argv[i]);
		a->next->next = NULL;
		a = a->next;
	}
	return (head);
}

void	ft_breakdown(char *str)
{
	ft_putstr(str);
	exit(0);
}

void	comparison_args(char **argv, int j)
{
	int	index;

	index = 1;
	while (index < j)
	{
		if (!(ft_strcmp(argv[j], argv[index])))
			ft_breakdown("Error\n");
		index++;
	}
}

void	duplication_erreur(char **argv)
{
	int	j;

	j = 2;
	while (argv[j])
	{
		comparison_args(argv, j);
		j++;
	}
}
