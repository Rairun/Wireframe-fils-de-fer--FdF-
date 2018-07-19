/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brez.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 10:27:11 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/22 12:51:21 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	brez(t_pic *pic, t_pix p0, t_pix p1)
{
	int	d[2];
	int	s[2];
	int	e[2];

	d[0] = abs(p1.x - p0.x);
	d[1] = abs(p1.y - p0.y);
	s[0] = p0.x < p1.x ? 1 : -1;
	s[1] = p0.y < p1.y ? 1 : -1;
	e[0] = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		mlx_pixel_put(pic->mlx_p, pic->win_p, p0.x, p0.y,
				convert_to_dec(p0.color));
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		e[1] = e[0];
		if (e[1] > -d[0])
			do_x(&e[0], d[1], &p0.x, s[0]);
		if (e[1] < d[1])
		{
			e[0] += d[0];
			p0.y += s[1];
		}
	}
}

void	do_x(int *e, int d, int *x, int s)
{
	*e -= d;
	*x += s;
}

void	check(t_pic *pic)
{
	if (pic->show == 1)
		set_tutorial(pic);
	else if (pic->show == 0)
		set_hint(pic);
}
