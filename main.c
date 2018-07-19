/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:36:52 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/21 16:37:38 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_pic	*pic;

	pic = ft_memalloc(sizeof(t_pic));
	if (check_arg(argc, argv, &(pic->fd)))
	{
		pic->name = argv[1];
		if (readfile(pic->fd, pic) != 0)
		{
			init_ptrs(pic);
			draw_pic(pic);
			init_binds(pic);
			mlx_loop(pic->mlx_p);
		}
	}
	system("leaks fdf");
	return (0);
}
