/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoyer <mhoyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:12:12 by mhoyer            #+#    #+#             */
/*   Updated: 2023/06/02 17:55:28 by mhoyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	**alloc_matrice(t_list *lst)
{
	int		i;
	t_list	*tmp;
	char	**mat;

	i = 0;
	mat = malloc((ft_lstsize(lst) + 1) * sizeof(char *));
	if (!mat)
		return (NULL);
	while (lst)
	{
		if (lst->next)
			mat[i] = ft_strdup_gnl(lst->content, 0,
					ft_strlen(lst->content) - 1);
		else
			mat[i] = ft_strdup(lst->content);
		i++;
		tmp = lst;
		lst = lst->next;
		ft_lstdelone(tmp);
	}
	mat[i] = NULL;
	return (mat);
}

void	new_matrix(char *file, t_map *map)
{
	int		fd;
	t_list	*lst;
	char	*str_tmp;

	lst = NULL;
	str_tmp = NULL;
	map->y_max = 0;
	map->x_max = 0;
	fd = open(file, O_RDONLY);
	str_tmp = get_next_line(fd);
	while (str_tmp)
	{
		ft_lstadd_back(&lst, ft_lstnew(str_tmp));
		free(str_tmp);
		str_tmp = get_next_line(fd);
		map->y_max++;
	}
	close(fd);
	map->mat = alloc_matrice(lst);
}
