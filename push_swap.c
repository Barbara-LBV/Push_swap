/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:37:07 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/14 16:04:02 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	if (ac < 2)
		return (0);
	while (av[i] != NULL)
	{
		a = get_list(&a, ft_atoi(av[i]));
		if (check_parsing(&a, ft_atoi(av[i]), av[i]) == 1)
		{
			lstclear(&a);
			return (0);
		}
		i++;
	}
	a = firstelement(&a);
	get_index(a);
	sort_list(&a, &b);
	lstclear(&a);
	lstclear(&b);
	return (0);
}
