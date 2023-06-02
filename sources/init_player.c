/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:13:15 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 13:54:47 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_player(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map->mat[++y])
	{
		x = -1;
		while (game->map->mat[y][++x])
		{
			if (game->map->mat[y][x] == 'P')
			{
				game->player->x = x;
				game->player->y = y;
				game->player->collec = 0;
			}
		}
	}
}
