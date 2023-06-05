/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:13:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 13:47:23 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map.mat[++y])
	{
		x = -1;
		while (game->map.mat[y][++x])
		{
			if (game->map.mat[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
				game->player.collec = 0;
			}
		}
	}
	game->player.nb_img = 0;
	game->player.updown = 1;
	game->move = 0;
}
