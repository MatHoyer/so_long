/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:12:46 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 15:07:38 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_p3(char c)
{
	return (c == 'P' || c == '3' || c == '4' || c == '5');
}

void	reset(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '3')
			{
				map[i][j] = '0';
			}
			else if (map[i][j] == '4')
			{
				map[i][j] = 'C';
			}
			else if (map[i][j] == '5')
			{
				map[i][j] = 'E';
			}
		}
	}
}

int	check_3(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
			{
				if (!check_p3(map[i + 1][j]) && !check_p3(map[i - 1][j])
				&& !check_p3(map[i][j + 1]) && !check_p3(map[i][j - 1]))
					return (1);
			}
		}
	}
	return (0);
}

int	repandre(char **map)
{
	int	i;
	int	j;
	int	modif;

	modif = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ((map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E')
				&& (check_p3(map[i + 1][j])
				|| check_p3(map[i - 1][j]) || check_p3(map[i][j + 1])
				|| check_p3(map[i][j - 1])))
			{
				modif = modif_case(j, i, map);
			}
		}
	}
	return (modif);
}

void	annexe_parsing(t_game *game)
{
	int	modif;

	modif = 1;
	while (modif)
		modif = repandre(game->map.mat);
	if (check_3(game->map.mat))
		error(1, "Pas de solution possible", game);
	reset(game->map.mat);
}
