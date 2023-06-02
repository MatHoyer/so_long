/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:13:02 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 18:30:20 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_texture_annexe(t_game *game)
{
	game->texture.perso[8].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_right2.xpm",
			&game->texture.perso[8].largeur, &game->texture.perso[8].hauteur);
}

void	init_texture_perso(t_game *game)
{
	game->texture.perso[0].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_base.xpm",
			&game->texture.perso[0].largeur, &game->texture.perso[0].hauteur);
	game->texture.perso[1].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_down1.xpm",
			&game->texture.perso[1].largeur, &game->texture.perso[1].hauteur);
	game->texture.perso[2].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_down2.xpm",
			&game->texture.perso[2].largeur, &game->texture.perso[2].hauteur);
	game->texture.perso[3].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_up1.xpm",
			&game->texture.perso[3].largeur, &game->texture.perso[3].hauteur);
	game->texture.perso[4].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_up2.xpm",
			&game->texture.perso[4].largeur, &game->texture.perso[4].hauteur);
	game->texture.perso[5].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_left1.xpm",
			&game->texture.perso[5].largeur, &game->texture.perso[5].hauteur);
	game->texture.perso[6].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_left2.xpm",
			&game->texture.perso[6].largeur, &game->texture.perso[6].hauteur);
	game->texture.perso[7].img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/perso/perso_right1.xpm",
			&game->texture.perso[7].largeur, &game->texture.perso[7].hauteur);
	init_texture_annexe(game);
}

void	init_texture(t_game *game)
{
	game->texture.vide.img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/terre.xpm",
			&game->texture.vide.largeur, &game->texture.vide.hauteur);
	game->texture.obs.img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/obsi.xpm",
			&game->texture.obs.largeur, &game->texture.obs.hauteur);
	game->texture.bed.img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/bedrock.xpm",
			&game->texture.bed.largeur, &game->texture.bed.hauteur);
	game->texture.gap.img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/gap.xpm",
			&game->texture.gap.largeur, &game->texture.gap.hauteur);
	game->texture.sortie.img = mlx_xpm_file_to_image(game->mlx,
			"../texture_xpm/nether.xpm",
			&game->texture.sortie.largeur, &game->texture.sortie.hauteur);
	game->mem = '0';
	init_texture_perso(game);
}
