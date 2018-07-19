/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:46:57 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/22 12:54:52 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		readfile(int fd, t_pic *pic)
{
	char	*line;
	int		res;

	pic->pic[0] = -1;
	pic->pic[1] = 0;
	while ((res = get_next_line(fd, &line)) > 0)
	{
		if (readline(line, pic) == 0)
		{
			ft_strdel(&line);
			exit(1);
		}
		ft_strdel(&line);
		pic->pic[1]++;
	}
	pic->dotp = conv_to_matr(pic);
	if (res == -1)
	{
		ft_putendl("Error");
		exit(1);
	}
	return (1);
}

int		readline(char *line, t_pic *pic)
{
	if (pic->pic[0] == -1)
	{
		if ((pic->pic[0] = find_length(line)) == 0)
		{
			ft_putendl("Invalid map.");
			exit(1);
		}
	}
	if (pic->pic[0] != find_length(line))
	{
		ft_putendl("Found wrong line length. Exiting.");
		exit(1);
	}
	if (add_line(pic, line) == 0)
	{
		ft_putendl("Error");
		exit(1);
	}
	return (1);
}

int		add_line(t_pic *pic, char *line)
{
	char	**arr;

	if (!(arr = ft_strsplit(line, ' ')))
	{
		ft_arrfree(arr);
		return (0);
	}
	if (make_points(pic, arr) == 0)
	{
		ft_arrfree(arr);
		return (0);
	}
	ft_arrfree(arr);
	return (1);
}
