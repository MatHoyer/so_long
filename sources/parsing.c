/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:12:29 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 14:47:28 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	error_check_contenue(t_game *game)
{
	if (game->map->exit != 1)
		error(1, "nombre de sortie != 1", game);
	else if (game->map->perso != 1)
		error(1, "nombre de position de depart != 1", game);
	else if (game->map->collectible < 1)
		error(1, "trop peu d'item", game);
}

void	check_contenue(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map->mat[++i])
	{
		j = -1;
		while (game->map->mat[i][++j])
		{
			if (game->map->mat[i][j] == 'E')
				game->map->exit++;
			else if (game->map->mat[i][j] == 'P')
				game->map->perso++;
			else if (game->map->mat[i][j] == 'C')
				game->map->collectible++;
			else if (game->map->mat[i][j] != '1' && game->map->mat[i][j] != '0')
				error(1, "Caractere de map invalide", game);
		}
	}
	error_check_contenue(game);
}

void	check_fermeture(t_game *game)
{
	int	i;

	i = -1;
	while (game->map->mat[0][++i])
		if (game->map->mat[0][i] != '1')
			error(1, "La map n'est pas fermee en haut", game);
	i = -1;
	while (game->map->mat[++i])
		if (game->map->mat[i][0] != '1')
			error(1, "La map n'est pas fermee a gauche", game);
	i = -1;
	while (game->map->mat[++i])
		if (game->map->mat[i][game->map->x_max - 1] != '1')
			error(1, "La map n'est pas fermee a droite", game);
	i = -1;
	while (++i < game->map->x_max)
		if (game->map->mat[game->map->y_max - 1][i] != '1')
			error(1, "La map n'est pas fermee en bas", game);
}

int	check_rect(t_game *game)
{
	int	i;
	int	val;
	int	j;

	i = 0;
	val = 0;
	while (game->map->mat[0][val])
		val++;
	while (game->map->mat[i])
	{
		j = 0;
		while (game->map->mat[i][j])
			j++;
		if ((game->map->y_max == i && j != val -1) || j != val)
			error(1, "La map n'est pas un rectangle", game);
		i++;
	}
	game->map->x_max = val;
	game->map->y_max = i;
	return (0);
}

void	parsing(t_game *game)
{
	if (!game->map->mat[0])
		error(1, "Aucune de map trouvee", game);
	check_rect(game);
	check_fermeture(game);
	check_contenue(game);
	annexe_parsing(game);
}
