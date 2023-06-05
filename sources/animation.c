/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:35 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 12:14:08 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	anime_top(t_game *game)
{
	int	i;
	int	count;
	int	time;

	i = game->player.y * 50;
	count = 0;
	while (i > (game->player.y - 1) * 50)
	{
		time = 200;
		while (time)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[3].img, game->player.x * 50, i);
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[4].img, game->player.x * 50, i);
			time--;
		}
		i--;
		count++;
	}
}

void	anime_bot(t_game *game)
{
	int	i;
	int	count;
	int	time;

	i = game->player.y * 50;
	count = 0;
	while (i < (game->player.y + 1) * 50)
	{
		time = 200;
		while (time)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[1].img, game->player.x * 50, i);
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[2].img, game->player.x * 50, i);
			time--;
		}
		i++;
		count++;
	}
}

void	anime_right(t_game *game)
{
	int	i;
	int	count;
	int	time;

	i = game->player.x * 50;
	count = 0;
	while (i < (game->player.x + 1) * 50)
	{
		time = 200;
		while (time)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[7].img, i, game->player.y * 50);
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[8].img, i, game->player.y * 50);
			time--;
		}
		i++;
		count++;
	}
}

void	anime_left(t_game *game)
{
	int	i;
	int	count;
	int	time;

	i = game->player.x * 50;
	count = 0;
	while (i > (game->player.x - 1) * 50)
	{
		time = 200;
		while (time)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[5].img, i, game->player.y * 50);
			mlx_put_image_to_window(game->mlx, game->win,
				game->texture.perso[6].img, i, game->player.y * 50);
			time--;
		}
		i--;
		count++;
	}
}

void	animation(int depl, t_game *game)
{
	if (depl == 1)
		anime_top(game);
	else if (depl == 2)
		anime_bot(game);
	else if (depl == 3)
		anime_right(game);
	else if (depl == 4)
		anime_left(game);
}
