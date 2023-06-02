/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:26 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 18:38:30 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	move_top(t_game *game)
{
	if (game->player.y == 1)
		return (0);
	if (game->map.mat[game->player.y - 1][game->player.x] == '1')
		return (0);
	game->map.mat[game->player.y][game->player.x] = game->mem;
	game->mem = game->map.mat[game->player.y - 1][game->player.x];
	//anime(game, 1);
	game->player.y--;
	game->map.mat[game->player.y][game->player.x] = 'P';
	return (1);
}

int	move_bot(t_game *game)
{
	if (game->player.y == game->map.y_max - 2)
		return (0);
	if (game->map.mat[game->player.y + 1][game->player.x] == '1')
		return (0);
	game->map.mat[game->player.y][game->player.x] = game->mem;
	game->mem = game->map.mat[game->player.y + 1][game->player.x];
	//anime(game, 2);
	game->player.y++;
	game->map.mat[game->player.y][game->player.x] = 'P';
	return (2);
}

int	move_right(t_game *game)
{
	if (game->player.x == game->map.x_max - 2)
		return (0);
	if (game->map.mat[game->player.y][game->player.x + 1] == '1')
		return (0);
	game->map.mat[game->player.y][game->player.x] = game->mem;
	game->mem = game->map.mat[game->player.y][game->player.x + 1];
	//anime(game, 3);
	game->player.x++;
	game->map.mat[game->player.y][game->player.x] = 'P';
	return (3);
}

int	move_left(t_game *game)
{
	if (game->player.x == 1)
		return (0);
	if (game->map.mat[game->player.y][game->player.x - 1] == '1')
		return (0);
	game->map.mat[game->player.y][game->player.x] = game->mem;
	game->mem = game->map.mat[game->player.y][game->player.x - 1];
	//anime(game, 4);
	game->player.x--;
	game->map.mat[game->player.y][game->player.x] = 'P';
	return (4);
}

void	movement(int key, t_game *game)
{
	int	check_move;

	if (key == XK_w)
		check_move = move_top(game);
	else if (key == XK_s)
		check_move = move_bot(game);
	else if (key == XK_d)
		check_move = move_right(game);
	else if (key == XK_a)
		check_move = move_left(game);
	if (check_move)
		game->move++;
	//in_game(game);
}
