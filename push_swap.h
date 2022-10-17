/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 22:06:41 by azinbi-           #+#    #+#             */
/*   Updated: 2022/10/17 03:52:07 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct list
{
	int			val;
	struct list	*next;
}	t_list;

int		ft_strcmp(char *s1, char *s2);
t_list	*ft_fillourstack(t_list *a, int argc, char **argv);
int		ft_strlen(const char *str);
int		ft_atoi(char *str);
void	ft_putstr(char *str);
int		ft_isdigit(int c);
void	ft_swap(int *a, int *b);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
t_list	*rotate_a(t_list *a);
t_list	*rotate_b(t_list *b);
t_list	*rotate_reverse_a(t_list *a);
void	push_a(t_list **a, t_list **b);
t_list	*swap_a(t_list *a);
void	push_b(t_list **a, t_list **b);
t_list	*sort_3_numbers(t_list *a);
t_list	*sort_4_numbers(t_list *a, t_list *b, int num);
void	check_list_b(t_list **a, t_list **b, int check);
void	radix_sort(t_list **a, t_list **b, int len);
void	check_int(char **argv);
void	ft_breakdown(char *str);
void	ft_check_erreur(char **argv);
void	it_is_sorted(t_list *a);
void	duplication_erreur(char **argv);

#endif
