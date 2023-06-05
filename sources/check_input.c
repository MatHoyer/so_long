/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:35:40 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 15:27:03 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_input(int key, t_game *game)
{
	if (key == XK_w || key == XK_s
		|| key == XK_d || key == XK_a)
	{
		movement(key, game);
	}
	else if (key == XK_Escape)
		close_game(game);
	return (0);
}
