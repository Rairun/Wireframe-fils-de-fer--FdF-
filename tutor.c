/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaprono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 11:12:02 by psaprono          #+#    #+#             */
/*   Updated: 2018/04/22 11:37:28 by psaprono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_tutorial(t_pic *pic)
{
	char	*str[16];
	int		i;

	str[0] = "|MOVE         W, A, S, D |";
	str[1] = "|------------------------|";
	str[2] = "|ZOOM            -, +    |";
	str[3] = "|------------------------|";
	str[4] = "|SCALE           X (>, ?)|";
	str[5] = "|                Y (L, ;)|";
	str[6] = "|                Z (O, P)|";
	str[7] = "|------------------------|";
	str[8] = "|ROTATE(NUM)     X (1, 2)|";
	str[9] = "|                Y (4, 5)|";
	str[10] = "|                Z (7, 8)|";
	str[11] = "|------------------------|";
	str[12] = "|DEFAULT         SPACE   |";
	str[13] = "|------------------------|";
	str[14] = "|CLOSE           ESC     |";
	str[15] = "|------------------------|";
	i = 0;
	while (i < 256)
	{
		mlx_string_put(pic->mlx_p, pic->win_p, 0, i, 10025880, str[i / 16]);
		i += 16;
	}
}

void	set_hint(t_pic *pic)
{
	char	*str;

	str = "Press F to watch or close guide";
	mlx_string_put(pic->mlx_p, pic->win_p, 0, 0, 10025880, str);
}
