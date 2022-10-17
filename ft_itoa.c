/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinbi- <azinbi-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 22:16:29 by azinbi-           #+#    #+#             */
/*   Updated: 2022/10/16 22:35:32 by azinbi-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*copy;

	i = 0;
	len = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static long	ft_count(int n)
{
	long	i;
	long	nb;

	nb = (long)n;
	i = 0;
	if (nb < 0)
	{
		i++;
		nb = nb * -1;
	}
	while (nb > 0)
	{
		nb = nb / 10 ;
		i++;
	}
	return (i);
}

static void	ft_converttochar(char *str, long *returni, long *keep, long *nb)
{
	while (*keep != 0)
	{
		if ((*keep) > 0)
		{
			str[(*returni) - 1] = (*nb) % 10 + '0';
			(*returni)--;
			(*keep) = (*keep) / 10;
			(*nb) = (*nb) / 10;
		}
		if (*keep < 0)
		{
			str[*returni] = (*nb) % 10 + '0';
			(*returni)--;
			(*keep) = (*keep) / 10;
			(*nb) = (*nb) / 10;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	long	keep;
	long	returni;

	if (n == 0)
		return (ft_strdup("0"));
	nb = (long)n;
	keep = (long)n;
	returni = ft_count(n);
	str = malloc(sizeof (char) * returni + 1);
	if (str == NULL)
		return (NULL);
	if (keep < 0)
		returni--;
	if (nb < 0)
	{
		nb *= -1;
		str[0] = '-';
		str[returni + 1] = '\0';
	}
	else
		str[returni] = 0;
	ft_converttochar(str, &returni, &keep, &nb);
	return (str);
}
// int main()
// {
// 	printf("%s\n", ft_itoa(-21212121));
// }
