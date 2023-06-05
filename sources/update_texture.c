/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:00 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 15:29:01 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_player(t_game *game, int x, int y)
{
	game->player.nb_img += game->player.updown;
	if (game->player.nb_img == ANIM || game->player.nb_img == -1)
	{
		game->player.updown *= -1;
		game->player.nb_img += game->player.updown;
	}
}

void	update_case(t_game *game, int x, int y)
{
	if (game->map.mat[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.perso[game->player.nb_img].img, x * 50, y * 50);
		update_player(game, x, y);
	}
	else if (game->map.mat[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.vide.img, x * 50, y * 50);
	else if (game->map.mat[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.obs.img, x * 50, y * 50);
	else if (game->map.mat[y][x] == '2')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.bed.img, x * 50, y * 50);
	else if (game->map.mat[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.gap.img, x * 50, y * 50);
	else if (game->map.mat[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.sortie.img, x * 50, y * 50);
}

void	update_texture(t_game *game, int prec_x, int prec_y)
{
	update_case(game, prec_x, prec_y);
	update_case(game, game->player.x, game->player.y);
}
