/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:13:11 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/21 17:14:12 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		make_points(t_pic *pic, char **arr)
{
	int		i;
	t_pix	pix;

	i = 0;
	while (arr[i])
	{
		pix.x = i;
		pix.y = pic->pic[1];
		pix.z = ft_atoi(arr[i]);
		pix.color = get_color(arr[i]);
		ft_lstaddend_x(&(pic->dots), ft_newpix(pix));
		i++;
	}
	return (1);
}

t_lst	*ft_newpix(t_pix pix)
{
	t_lst	*dot;

	dot = (t_lst *)ft_memalloc(sizeof(*dot));
	dot->pix = pix;
	dot->next = NULL;
	return (dot);
}

void	ft_lstaddend_x(t_lst **lst, t_lst *dot)
{
	t_lst	*curr;

	if (*lst == NULL)
		*lst = dot;
	else
	{
		curr = *lst;
		while (curr->next)
			curr = curr->next;
		curr->next = dot;
	}
}

t_pix	**conv_to_matr(t_pic *pic)
{
	int		i;
	t_lst	*curr;
	t_pix	**dotp;

	if (!(dotp = (t_pix **)ft_memalloc(sizeof(t_pix *) * pic->pic[1])))
		return (0);
	i = 0;
	curr = pic->dots;
	while (i < pic->pic[1])
	{
		if (!(dotp[i] = (t_pix *)ft_memalloc(sizeof(t_pix) * pic->pic[0])))
			return (0);
		fill_line(dotp[i], &curr, pic->pic[0]);
		i++;
	}
	return (dotp);
}

void	fill_line(t_pix *arr, t_lst **curr, int width)
{
	int	i;

	i = 0;
	while (i < width && *curr)
	{
		arr[i] = (*curr)->pix;
		i++;
		*curr = (*curr)->next;
	}
}
