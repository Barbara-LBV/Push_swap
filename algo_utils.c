/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:04:15 by blefebvr          #+#    #+#             */
/*   Updated: 2022/11/13 15:15:58 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sizelst(t_list **b)
{
	t_list	*tmp;
	int		i;

	i = 1;
	tmp = *b;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	get_highest(t_list **a)
{
	t_list	*tmp;
	int		cur_index;
	int		highest;

	if ((*a) == NULL)
		return (0);
	tmp = *a;
	highest = 0;
	while (tmp != NULL)
	{
		cur_index = tmp->index;
		tmp = tmp->next;
		if (cur_index < tmp->index && highest < tmp->index)
			highest = tmp->index;
		else
		{
			if (highest < cur_index)
				highest = cur_index;
		}
		if (tmp->next == NULL)
			break ;
	}
	return (highest);
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

void	lstclear(t_list **lst)
{
	t_list	*tmp;

	if ((*lst) == NULL)
		return ;
	while ((*lst)->before != NULL)
		(*lst) = (*lst)->before;
	while (*lst)
	{
		tmp = *lst;
		(*lst) = (*lst)->next;
		free(tmp);
	}
	free(*lst);
}

t_list	*get_list(t_list **a, long int content)
{
	if (!(*a))
		*a = lstnew(content);
	else
		lstadd_end(a, lstnew(content));
	return (*a);
}

/*int main(int ac, char **av)
{
	t_list	*a = NULL;
	int i = 1;
	int n;

	if(!a)
		a = lstnew(ft_atoi(av[i++]));
	while (i < ac)
		lstadd_end(&a, lstnew(ft_atoi(av[i++])));
	a = firstelement(&a);
	get_index(a);
	if (check_sorting(&a) == 0)
		printf("la liste n'est pas triee\n");
	else
		printf("la liste est triee\n");
	a = firstelement(&a);
	//get_index(a);
	printf(" GET INDEX\n");
	a = firstelement(&a);
	while (a != NULL)
	{
		printf("index : %d , value : %d\n", a->index, a->content);
		if (a->next == NULL)
			break ;
		a = a->next;
	}
	a = firstelement(&a);
	n = get_highest(&a);
	printf("\n valeur de highest : %d\n", n);
	lstclear(&a);
	return 0;
}*/
