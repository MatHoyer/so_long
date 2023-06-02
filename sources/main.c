/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:15:38 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 14:55:47 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_file_name(char *file)
{
	int	mark;

	mark = ft_strlen(file);
	mark -= 4;
	if (file[mark] != '.' || file[mark + 1] != 'b'
		|| file[mark + 2] != 'e' || file[mark + 3] != 'r')
		exit(ft_printf("Error : L'extension de la map doit etre \".ber\".\n"));
}

void	parsing_arg(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		exit(ft_printf("Error : ./so_long necessite 1 argument.\n"));
	fd = open(av[1], O_RDONLY);
	if (!read(fd, 0, 0))
		exit(ft_printf("Error : Fichier introuvable.\n"));
	close(fd);
	check_file_name(av[1]);
}

int	main(int ac, char **av)
{
	t_game	game;

	parsing_arg(ac, av);
	new_matrix(av[1], game.map);
	if (!game.map->mat)
		error(1, "Mauvaise allocation de la matrice", &game);
	parsing(&game);
	game.player = malloc(sizeof(t_player));
	if (!game.player)
		error(1, "Mauvaise allocation du joueur", &game);
	init_player(&game);
	init_texture(&game);
	return (0);
}
