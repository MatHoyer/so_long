/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:45 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 12:05:28 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	do_case(t_game *game)
{
	update_case(game, game->player.x, game->player.y);
	if (game->mem == 'C')
	{
		game->mem = '0';
		game->player.collec++;
	}
	else if (game->mem == 'E')
	{
		if (game->map.collectible == game->player.collec)
		{
			ft_printf("Bravo, vous avez reussit en %d mouvements !\n",
				game->move);
			close_game(game);
		}
		else
		{
			print_data(game);
		}
	}
}
