/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:15:38 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 18:59:33 by mhoyer           ###   ########.fr       */
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

void	parsing_arg(int ac, char *av)
{
	int	fd;

	if (ac != 2)
		exit(ft_printf("Error : ./so_long necessite 1 argument.\n"));
	fd = open(av, O_RDONLY);
	if (!fd)
		exit(ft_printf("Error : Fichier introuvable.\n"));
	close(fd);
	check_file_name(av);
}

int	main(int ac, char **av)
{
	t_game	game;

	parsing_arg(ac, av[1]);
	new_matrix(av[1], &game.map);
	parsing(&game);
	modif_matrix(&game.map);
	init_player(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 50 * game.map.x_max,
			50 * game.map.y_max, "so_long");
	init_texture(&game);
	print_background(&game);
	print_data(&game);
	mlx_hook(game.win, KeyRelease, KeyReleaseMask, &check_input, &game);
	mlx_hook(game.win, 17, 0, &close_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
