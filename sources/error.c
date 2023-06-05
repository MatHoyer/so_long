/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:53 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 14:25:47 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	error(2, "fermeture propre", game);
}

void	error(int state, char *error_str, t_game *game)
{
	int	i;

	i = -1;
	while (game->map.mat[++i])
		free(game->map.mat[i]);
	free(game->map.mat);
	if (error_str[0] != 'f')
	{
		ft_printf("Error : %s.\n", error_str);
	}
	if (state > 1)
	{
		i = -1;
		mlx_destroy_image(game->mlx, game->texture.bed.img);
		mlx_destroy_image(game->mlx, game->texture.gap.img);
		mlx_destroy_image(game->mlx, game->texture.obs.img);
		mlx_destroy_image(game->mlx, game->texture.vide.img);
		mlx_destroy_image(game->mlx, game->texture.sortie.img);
		while (++i < ANIM)
			mlx_destroy_image(game->mlx, game->texture.perso[i].img);
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit (0);
}
