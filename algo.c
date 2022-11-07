/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/07 17:51:32 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nb(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int	highest;

	if (!(*a) || (*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	tmp1 = *a;
	tmp2 = (*a)->next;
	highest = get_highest(a);
	if (check_sorting(a))
		return ;
	if (tmp1->index == highest)
		rotate_a(a);
	else if (tmp2->index == highest)
		rev_rot_a(a);
	tmp1 = *a;
	tmp2 = (*a)->next;
	if (tmp1->index > tmp2->index)
		swap_a(a);
}

void	sort_five_nb(t_list **a, t_list **b)
{
	int	i;

	i = get_sizelst(b);
	if (check_sorting(a) == 1)
		return ;
	while (i < 2)
	{
		if ((*a)->index == 1 || (*a)->index == 2)
			push_b(a, b);
		else if ((*a)->index != 1 || (*a)->index != 2)
			rotate_a(a);
		i = get_sizelst(b);
		*b = firstelement(b);
	}
	if (check_sorting(a) == 0)
		sort_three_nb(a);
	if (check_sorting(b) == 1 && (*b)->next != NULL)
		swap_b(b);
	while ((*b) != NULL)
		push_a(a, b);
}

void	radix()
{
}

/*int main(int argc, char **argv)
{
	t_list	*test = NULL;
	t_list	*test1 = NULL;
	int i = 1;

	if (!test)
		test = lstnew(ft_atoi(argv[i++]));
	while (i < argc)
		lstadd_end(&test, lstnew(ft_atoi(argv[i++])));
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	test = firstelement(&test);
	get_index(test);
	printf("\n GET INDEX : \n");
	while (test != NULL)
	{
		printf("%d ", test->index);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	test = firstelement(&test);
	printf("\n SORT 5 NB : \n");
	sort_five_nb(&test, &test1);
	test = firstelement(&test);
	printf("\n new list a\n");
	while (test != NULL)
	{
		printf("%d ", test->content);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	printf("\n new list b\n");
	while (test1 != NULL)
	{
		printf("%d ", test1->content);
		if (test->next == NULL)
			break ;
		test1 = test1->next;
	}
	lstclear(&test);
	lstclear(&test1);
	return (0);
}*/
