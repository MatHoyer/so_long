/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_background.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:13:42 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 08:57:20 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	affiche_texture_annexe(t_game *game, int i, int j)
{
	if (game->map.mat[j][i] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.perso[0].img, i * 50, j * 50);
	else if (game->map.mat[j][i] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.gap.img, i * 50, j * 50);
	else if (game->map.mat[j][i] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->texture.sortie.img, i * 50, j * 50);
}

void	print_background(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.x_max)
	{
		j = -1;
		while (++j < game->map.y_max)
		{
			if (game->map.mat[j][i] == '0')
				mlx_put_image_to_window(game->mlx, game->win,
					game->texture.vide.img, i * 50, j * 50);
			else if (game->map.mat[j][i] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->texture.obs.img, i * 50, j * 50);
			else if (game->map.mat[j][i] == '2')
				mlx_put_image_to_window(game->mlx, game->win,
					game->texture.bed.img, i * 50, j * 50);
			else
				affiche_texture_annexe(game, i, j);
		}
	}
}
