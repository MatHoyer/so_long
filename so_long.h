/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:53:47 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 14:48:50 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

# include "libft/libft.h"

typedef struct image {
	void	*img;
	int		largeur;
	int		hauteur;
}	t_img;

typedef struct texture
{
	t_img	vide;
	t_img	obs;
	t_img	bed;
	t_img	gap;
	t_img	perso[9];
	t_img	sortie;
}	t_texture;

typedef struct player {
	int	x;
	int	y;
	int	collec;
}	t_player;

typedef struct map {
	char		**mat;
	char		prec;
	int			x_max;
	int			y_max;
	int			perso;
	int			exit;
	int			collectible;
}	t_map;

typedef struct game {
	void		*mlx;
	void		*win;
	int			move;
	char		mem;
	t_map		*map;
	t_texture	*texture;
	t_player	*player;
}	t_game;

void	new_matrix(char *file, t_map *map);

void	parsing(t_game *game);
void	annexe_parsing(t_game *game);

void	init_texture(t_game *game);
void	init_player(t_game *game);

void	print_background(t_game *game);
void	update_texture(t_game *game);
void	print_data(t_game *game);

void	movement(int key, t_game *game);
void	animation(int key, t_game *game);

void	do_case(t_game *game);

void	error(int state, char *error_str, t_game *game);

#endif
