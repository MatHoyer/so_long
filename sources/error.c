/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:53 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 13:47:41 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error(int state, char *error_str, t_game *game)
{
	int	i;

	i = -1;
	if (state >= 1)
	{
		while (game->map->mat[++i])
			free(game->map->mat[i]);
		free(game->map->mat);
	}
	ft_printf("Error : %s.\n", error_str);
	exit (0);
}
