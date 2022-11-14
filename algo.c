/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/13 15:55:36 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_list **lst)
{
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *lst;
	if (!(*lst))
		return (1);
	while (tmp->next != NULL)
	{
		tmp1 = tmp->next;
		while (tmp1->next != NULL)
		{
			if (tmp->index > tmp1->index)
				return (0);
			tmp1 = tmp1->next;
		}
		if (tmp->index > tmp1->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_three_nb(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		highest;

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

void	radix_sorting(t_list **a, t_list **b, int size_a)
{
	int	i;
	int	j;

	i = 0;
	if (!(*a) || size_a == 1)
		return ;
	while (check_sorting(a) == 0)
	{
		j = 0;
		while (j < size_a)
		{
			if (((*a)->index >> i & 1) == 0)
				push_b(a, b);
			else
				ra(a);
			j++;
		}
		while ((*b) != NULL)
			push_a(a, b);
		i++;
	}
}

void	sort_list(t_list **a, t_list **b)
{
	int	size_a;

	size_a = get_sizelst(a);
	if (!(*a) || size_a < 2)
		return ;
	if (size_a > 1 && size_a <= 3)
		sort_three_nb(a);
	else if (size_a > 3 && size_a <= 5)
		sort_five_nb(a, b);
	else
		radix_sorting(a, b, size_a);
}

/*int main(int ac, char **av)
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
	int size_a = get_sizelst(&test);
	printf("\n-->SORT NB : \n");
	sort_list(&test, &test1, size_a);
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
}*/
