/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bind1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 17:32:26 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/22 10:26:02 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		zoom_pic(int key, void *par)
{
	t_pic	*pic;

	pic = (t_pic *)(par);
	mlx_clear_window(pic->mlx_p, pic->win_p);
	if (key == 27 && pic->zoom >= 0.3)
		pic->zoom -= 0.3;
	else if (key == 24)
		pic->zoom += 0.3;
	draw_pic(pic);
	return (1);
}

int		move_pic(int k, void *par)
{
	t_pic	*pic;

	pic = (t_pic *)(par);
	mlx_clear_window(pic->mlx_p, pic->win_p);
	if (k == 0)
		pic->xyz[0] -= 10;
	else if (k == 2)
		pic->xyz[0] += 10;
	else if (k == 13)
		pic->xyz[1] -= 10;
	else if (k == 1)
		pic->xyz[1] += 10;
	draw_pic(pic);
	return (1);
}

int		rotate_pic(int k, void *par)
{
	t_pic	*pic;

	pic = (t_pic *)(par);
	mlx_clear_window(pic->mlx_p, pic->win_p);
	if (k == 83)
		pic->an[0] -= 0.1;
	else if (k == 84)
		pic->an[0] += 0.1;
	else if (k == 86)
		pic->an[1] -= 0.1;
	else if (k == 87)
		pic->an[1] += 0.1;
	else if (k == 89)
		pic->an[2] -= 0.1;
	else if (k == 91)
		pic->an[2] += 0.1;
	draw_pic(pic);
	return (1);
}

int		scale_pic(int k, void *par)
{
	t_pic	*pic;

	pic = (t_pic *)(par);
	mlx_clear_window(pic->mlx_p, pic->win_p);
	if (k == 47)
		pic->scale[0] -= 0.1;
	else if (k == 44)
		pic->scale[0] += 0.1;
	else if (k == 37)
		pic->scale[1] -= 0.1;
	else if (k == 41)
		pic->scale[1] += 0.1;
	else if (k == 31)
		pic->scale[2] -= 1;
	else if (k == 35)
		pic->scale[2] += 1;
	draw_pic(pic);
	return (1);
}
