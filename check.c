/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 16:10:22 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/21 16:11:54 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	check_arg(int argc, char **argv, int *fd)
{
	if (argc == 1)
	{
		ft_putendl("Usage : ./fdf <filename>");
		exit(1);
	}
	else if (argc == 2)
	{
		*fd = open(argv[1], O_RDONLY);
		if (*fd < 0)
		{
			ft_putstr("No file ");
			ft_putendl(argv[1]);
			exit(1);
		}
	}
	return (1);
}

int	find_length(char *line)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (line[i])
	{
		if (line[i] >= '0' && line[i] <= '9')
		{
			len++;
			while (line[i] && line[i] != ' ')
				i++;
		}
		if (line[i])
			i++;
	}
	return (len);
}
