/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:37:07 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/10 15:48:54 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*a = NULL;
	t_list	*b = NULL;

	int	i = 1;
	if (ac < 2)
		return (0);
	while (av[i] != NULL)
	{
		if (check_parsing(a, av[i]) == 1)
			return (0);
		a = get_list(&a, ft_atoi(av[i++]));
	}
	while (a != NULL)
	{
		printf("%d ", a->content);
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	printf("\n GET INDEX : \n");
	a = firstelement(&a);
	get_index(a);
	while (a != NULL)
	{
		printf("value : %d, index : %d\n", a->content, a->index);
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	a = firstelement(a);
	sort_five_nb(&a, b);
	while (a != NULL)
	{
		printf("index : %d, value : %d\n", a->index, a->content);
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	lstclear(&a);
	lstclear(&b);
	return (0);
}
