/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/10 18:54:02 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nb(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int	highest;

	if (!(*a) || (*a)->next == NULL)
		return ;
	tmp1 = *a;
	tmp2 = (*a)->next;
	highest = get_highest(a);
	if (check_sorting(a))
		return ;
	if (tmp1->index == highest)
		ra(a);
	else if (tmp2->index == highest)
		rra(a);
	tmp1 = *a;
	tmp2 = (*a)->next;
	if (tmp1->index > tmp2->index)
		sa(a);
}

void	sort_five_nb(t_list **a, t_list **b)
{
	int	i;
	int	j;

	i = get_sizelst(a);
	j = get_sizelst(b);
	if (i > 5 || i < 3)
		return ;
	if (check_sorting(a) == 1)
		return ;
	while (j < 2)
	{
		if ((*a)->index == 1 || (*a)->index == 2)
			push_b(a, b);
		else if ((*a)->index != 1 || (*a)->index != 2)
			ra(a);
		j = get_sizelst(b);
	}
	if (check_sorting(a) == 0)
		sort_three_nb(a);
	if (check_sorting(b) == 1 && (*b)->next != NULL)
		sb(b);
	while ((*b) != NULL)
		push_a(a, b);
}

/*void	radix_sorting(t_list **a, t_list **b)
{
}*/

void	sort_list(t_list **a, t_list **b, int size)
{
	if (size < 2)
		return ;
	if (size <= 3)
		sort_three_nb(a);
	else if (size > 3 && size <= 5)
		sort_five_nb(a, b);
	/*else
		radix_sorting(a, b);*/
}

int main(int ac, char **av)
{
	t_list	*test = NULL;
	t_list	*test1 = NULL;
	int i = 1;

	if (ac < 2)
		return (0);
	while (av[i] != NULL)
	{
		test = get_list(&test, ft_atoi(av[i]));
		if (check_parsing(&test, ft_atoi(av[i]), av[i]) == 1)
			return (0);
		i++;
	}
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	test = firstelement(&test);
	get_index(test);
	printf("\n\n-->GET INDEX : \n");
	while (test != NULL)
	{
		printf("index : %d   value : %d\n", test->index, test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	test = firstelement(&test);
	int size = get_sizelst(&test);
	printf("\n-->SORT NB : \n");
	sort_list(&test, &test1, size);
	printf("\n-->New list a\n");
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	if (test1 == NULL)
		printf("\n-->List b is empty\n");
	else
	{
	printf("\n\n-->New list b\n");
		while (test1 != NULL)
		{
			printf("%d ", test1->content);
			if (test->next == NULL)
				break ;
			test1 = test1->next;
		}
	}
	lstclear(&test);
	lstclear(&test1);
	return (0);
}
