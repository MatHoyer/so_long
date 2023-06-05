/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:54:41 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 15:30:07 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	modif_matrix(t_map *map)
{
	int	i;

	i = -1;
	while (map->mat[0][++i])
		if (map->mat[0][i] == '1')
			map->mat[0][i] = '2';
	map->x_max = i;
	i = -1;
	while (map->mat[++i])
		if (map->mat[i][0] == '1')
				map->mat[i][0] = '2';
	i = -1;
	while (map->mat[++i])
		if (map->mat[i][map->x_max - 1] == '1')
			map->mat[i][map->x_max - 1] = '2';
	i = -1;
	while (++i < map->x_max)
		if (map->mat[map->y_max - 1][i] == '1')
			map->mat[map->y_max - 1][i] = '2';
}
