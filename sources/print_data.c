/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 18:09:00 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	affiche_rect_top(t_game *game, int start, int x_max, int y_start)
{
	int	x;
	int	y;

	y = y_start;
	while (y < 15 + y_start)
	{
		x = start;
		while (x < x_max)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0x00000000);
			x++;
		}
		y++;
	}
}

void    print_data(t_game *game)
{
    affiche_rect_top(game, 0, 160, 0);
	affiche_rect_top(game, 0, 100, 20);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFFFF,
		"nbr de mouvements :");
	mlx_string_put(game->mlx, game->win, 130, 10, 0xFFFFFFFF,
		ft_itoa(game->move));
	mlx_string_put(game->mlx, game->win, 10, 32, 0xFFFFFFFF, "item :");
	mlx_string_put(game->mlx, game->win, 50, 32, 0xFFFFFFFF,
		ft_itoa(game->player.collec));
	mlx_string_put(game->mlx, game->win, 60, 32, 0xFFFFFFFF, "/");
	mlx_string_put(game->mlx, game->win, 70, 32, 0xFFFFFFFF,
		ft_itoa(game->map.collectible));
}