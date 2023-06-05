/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:16 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 15:28:09 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	msg_portail(t_game *game)
{
	affiche_rect_top(game, 50, 300, (50 * (game->map.y_max - 1)));
	mlx_string_put(game->mlx, game->win, 60,
		(50 * (game->map.y_max - 1)) + 10, 0xFFFFFFFF,
		"Pas assez de gap pour passer le portail");
}

void	msg_rmv(t_game *game)
{
	update_case(game, 1, game->map.y_max - 1);
	update_case(game, 2, game->map.y_max - 1);
	update_case(game, 3, game->map.y_max - 1);
	update_case(game, 4, game->map.y_max - 1);
	update_case(game, 5, game->map.y_max - 1);
}

void	print_data(t_game *game)
{
	char	*move;
	char	*collec;
	char	*all_collec;

	move = ft_itoa(game->move);
	collec = ft_itoa(game->player.collec);
	all_collec = ft_itoa(game->map.collectible);
	if (!move || !collec || !all_collec)
		error(2, "Mauvaise allocation des donnees du joueur (aff)", game);
	affiche_rect_top(game, 0, 160, 0);
	affiche_rect_top(game, 0, 100, 20);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFFFF,
		"nbr de mouvements :");
	mlx_string_put(game->mlx, game->win, 130, 10, 0xFFFFFFFF, move);
	mlx_string_put(game->mlx, game->win, 10, 32, 0xFFFFFFFF, "item :");
	mlx_string_put(game->mlx, game->win, 50, 32, 0xFFFFFFFF, collec);
	mlx_string_put(game->mlx, game->win, 60, 32, 0xFFFFFFFF, "/");
	mlx_string_put(game->mlx, game->win, 70, 32, 0xFFFFFFFF, all_collec);
	if (game->mem == 'E')
		msg_portail(game);
	else
		msg_rmv(game);
	free(move);
	free(collec);
	free(all_collec);
}
