/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:13:02 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/05 13:53:52 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_texture_annexe(t_game *game)
{
	
}

void	init_texture_perso(t_game *game)
{
	int		i;
	char	*tmp;
	char	*ext;
	char	*path;

	i = -1;
	while (++i < ANIM)
	{
		tmp = ft_itoa(i);
		ext = ft_strjoin(tmp, ".xpm");
		free(tmp);
		path = ft_strjoin("texture_xpm/perso/perso", ext);
		game->texture.perso[i].img = mlx_xpm_file_to_image(game->mlx,
			path,
			&game->texture.perso[i].largeur, &game->texture.perso[i].hauteur);
		free(ext);
		free(path);
	}
	init_texture_annexe(game);
}

void	init_texture(t_game *game)
{
	game->texture.vide.img = mlx_xpm_file_to_image(game->mlx,
			"texture_xpm/terre.xpm",
			&game->texture.vide.largeur, &game->texture.vide.hauteur);
	game->texture.obs.img = mlx_xpm_file_to_image(game->mlx,
			"texture_xpm/obsi.xpm",
			&game->texture.obs.largeur, &game->texture.obs.hauteur);
	game->texture.bed.img = mlx_xpm_file_to_image(game->mlx,
			"texture_xpm/bedrock.xpm",
			&game->texture.bed.largeur, &game->texture.bed.hauteur);
	game->texture.gap.img = mlx_xpm_file_to_image(game->mlx,
			"texture_xpm/gap.xpm",
			&game->texture.gap.largeur, &game->texture.gap.hauteur);
	game->texture.sortie.img = mlx_xpm_file_to_image(game->mlx,
			"texture_xpm/nether.xpm",
			&game->texture.sortie.largeur, &game->texture.sortie.hauteur);
	game->mem = '0';
	init_texture_perso(game);
}
