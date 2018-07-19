/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:34:03 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/22 12:48:31 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_binds(t_pic *pic)
{
	mlx_hook(pic->win_p, 17, 1L << 17, exit_press, pic);
	mlx_hook(pic->win_p, 2, 5, choice, (void *)pic);
}

int		choice(int k, void *par)
{
	if (k == 53)
		exit(1);
	if (k == 24 || k == 27)
		return (zoom_pic(k, par));
	if (k == 0 || k == 1 || k == 2 || k == 13)
		return (move_pic(k, par));
	if (k == 83 || k == 84 || k == 86 || k == 87 || k == 89 || k == 91)
		return (rotate_pic(k, par));
	if (k == 31 || k == 35 || k == 37 || k == 41 || k == 47 || k == 44)
		scale_pic(k, par);
	if (k == 49)
		return (back_to_normal(par));
	if (k == 3)
		return (tut(par));
	return (1);
}

int		exit_press(void)
{
	exit(1);
	return (1);
}

int		back_to_normal(void *par)
{
	t_pic	*pic;

	pic = (t_pic *)(par);
	mlx_clear_window(pic->mlx_p, pic->win_p);
	refresh_pic(pic);
	draw_pic(pic);
	return (1);
}

int		tut(void *par)
{
	t_pic	*pic;

	pic = (t_pic *)(par);
	mlx_clear_window(pic->mlx_p, pic->win_p);
	if (pic->show == 0)
		pic->show = 1;
	else if (pic->show == 1)
		pic->show = 0;
	draw_pic(pic);
	return (1);
}
