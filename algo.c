/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:09:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/04 17:24:05 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorting(t_list **lst)
{
	t_list	*tmp;

	tmp = NULL;
	if (!(*lst))
		return (1);
	while ((*lst)->next != NULL)
	{
		tmp = (*lst)->next;
		while (tmp->next != NULL)
		{
			if ((*lst)->index > tmp->index)
				return (0);
			tmp = tmp->next;
		}
		if ((*lst)->index > tmp->index)
			return (0);
		*lst = (*lst)->next;
	}
	return (1);
}

void	get_index(t_list *a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	tmp1 = a;
	while (tmp1 != NULL)
	{
		tmp1->index = 1;
		tmp1 = tmp1->next;
	}
	tmp1 = a;
	tmp2 = a->next;
	while (tmp1 != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp1->content < tmp2->content)
				tmp2->index += 1;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = a;
	}
}

void	sort_three_nb(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!(*a) || (*a)->next == NULL || (*a)->next->next == NULL)
		return ;
	tmp1 = *a;
	tmp2 = (*a)->next;
	if (check_sorting(a))
		return ;
	*a = firstelement(a);
	if (tmp1->index == 3)
		rotate_a(a);
	else if (tmp2->index == 3)
		rev_rot_a(a);
	tmp1 = *a;
	tmp2 = (*a)->next;
	if (tmp1->index > tmp2->index)
		swap_a(a);
	*a = firstelement(a);
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
		else if ((*a)->index != 1 || (*a)->next->index)
			rotate_a(a);
		*a = firstelement(a);
		*b = firstelement(a);
		i = get_sizelst(b);
	}
	/*if ((*a)->index == 1 || (*a)->index == 2)
		push_b(a, b);*/
	if (!check_sorting(a))
		sort_three_nb(a);
	if (check_sorting(b) && (*b)->next != NULL)
		swap_b(b);
	while ((*b)->next != NULL)
	{
		push_a(a, b);
		(*b) = (*b)->next;
	}
}

void	print_list(t_list **a, t_list **b)
{
	*a = firstelement(a);
	*b = firstelement(b);
	while ((*a) != NULL)
	{
		printf("%d ", (*a)->content);
		if ((*a)->next == NULL)
			break ;
		*a = (*a)->next;
	}
	printf("\n");
	while ((*b) != NULL)
	{
		printf("%d ", (*b)->content);
		if ((*b)->next == NULL)
			break ;
		*b = (*b)->next;
	}
	printf("\n");
	*a = firstelement(a);
	*b = firstelement(b);

}

int main(int argc, char **argv)
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
	while (test1->next != NULL)
	{
		printf("%d ", test1->content);
		test1 = test1->next;
	}
	lstclear(&test);
	lstclear(&test1);
	return (0);
}
