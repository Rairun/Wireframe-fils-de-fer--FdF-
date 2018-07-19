/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:18:27 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/22 12:50:31 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_pic(t_pic *pic)
{
	t_pix	p0;
	int		i;
	int		j;

	i = 0;
	while (i < pic->pic[1])
	{
		j = 0;
		while (j < pic->pic[0])
		{
			if (j != 0)
				brez(pic, conv_p(pic, i, j - 1), conv_p(pic, i, j));
			if (i != 0)
				brez(pic, conv_p(pic, i - 1, j), conv_p(pic, i, j));
			else if (i == 0 && j == 0)
			{
				p0 = conv_p(pic, 0, 0);
				mlx_pixel_put(pic->mlx_p, pic->win_p, p0.x, p0.y,
					convert_to_dec(p0.color));
			}
			j++;
		}
		i++;
	}
	check(pic);
}

t_pix	conv_p(t_pic *pic, int i, int j)
{
	t_pix	new_p;

	new_p.x = pic->zoom * pic->dotp[i][j].x * pic->bst * pic->scale[0];
	new_p.y = pic->zoom * pic->dotp[i][j].y * pic->bst * pic->scale[1];
	new_p.z = pic->zoom * pic->dotp[i][j].z * pic->scale[2];
	new_p.color = pic->dotp[i][j].color;
	new_p = conv_3d(new_p, pic->an);
	new_p.x = new_p.x + pic->xyz[0];
	new_p.y = new_p.y + pic->xyz[1];
	return (new_p);
}

t_pix	conv_3d(t_pix pix, float axyz[3])
{
	int xyz[3];

	xyz[0] = pix.x;
	xyz[1] = pix.y;
	xyz[2] = pix.z;
	pix.x = pix.x;
	pix.y = xyz[1] * cos(axyz[0]) + xyz[2] * sin(axyz[0]);
	pix.z = xyz[2] * cos(axyz[0]) - xyz[1] * sin(axyz[0]);
	xyz[0] = pix.x;
	xyz[1] = pix.y;
	xyz[2] = pix.z;
	pix.x = xyz[0] * cos(axyz[1]) - xyz[2] * sin(axyz[1]);
	pix.y = pix.y;
	pix.z = xyz[2] * cos(axyz[1]) + xyz[0] * sin(axyz[1]);
	xyz[0] = pix.x;
	xyz[1] = pix.y;
	xyz[2] = pix.z;
	pix.x = xyz[0] * cos(axyz[2]) + xyz[1] * sin(axyz[2]);
	pix.y = xyz[1] * cos(axyz[2]) - xyz[0] * sin(axyz[2]);
	return (pix);
}

void	init_ptrs(t_pic *pic)
{
	pic->wind[0] = 1000;
	pic->wind[1] = 1000;
	pic->zoom = 1;
	pic->mlx_p = mlx_init();
	pic->win_p = mlx_new_window(pic->mlx_p,
			pic->wind[0], pic->wind[1], pic->name);
	pic->bst = pic->wind[0] / 2 / pic->pic[0];
	pic->xyz[0] = pic->wind[0] / 4;
	pic->xyz[1] = (pic->wind[1] - pic->pic[1] * pic->bst) / 2;
	pic->an[0] = -1;
	pic->an[1] = -0.5;
	pic->an[2] = 0;
	pic->scale[0] = 1;
	pic->scale[1] = 1;
	pic->scale[2] = 1;
	pic->show = 0;
}

void	refresh_pic(t_pic *pic)
{
	pic->zoom = 1;
	pic->an[0] = -1;
	pic->an[1] = -0.5;
	pic->an[2] = 0;
	pic->scale[0] = 1;
	pic->scale[1] = 1;
	pic->scale[2] = 1;
	pic->xyz[0] = pic->wind[0] / 4;
	pic->xyz[1] = (pic->wind[1] - pic->pic[1] * pic->bst) / 2;
}
