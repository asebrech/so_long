/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:32:06 by asebrech          #+#    #+#             */
/*   Updated: 2021/07/26 15:13:42 by asebrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_char(t_map *map, char c)
{
	if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
		ft_exit("Forbidden character in the map\n");
	if (c == 'E')
		map->E += 1;
	if (c == 'C')
		map->C += 1;
	if (c == 'P')
		map->P += 1;
}

static void	parsing_map(t_map *map)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	map->len = ft_strlen(map->map[0]);
	while (i < map->line)
	{
		j = 0;
		len = ft_strlen(map->map[i]);
		if (map->len != len)
			ft_exit("The map must be rectangular\n");
		if (map->map[i][0] != '1' || map->map[i][len - 1] != '1')
			ft_exit("The map must be closed/surrounded by walls\n");
		while (map->map[i][j])
		{
			if (i == 0 || i == map->line - 1)
				if (map->map[i][j] != '1')
					ft_exit("The map must be closed/surrounded by walls\n");
			check_char(map, map->map[i][j]);
			j++;
		}
		i++;
	}
}

static void	init_map(t_map *map)
{
	map->line = 0;
	map->len = 0;
	map->map = NULL;
	map->E = 0;
	map->C = 0;
	map->P = 0;
}

static void	get_map(t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	fd = open("./srcs/map.ber", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		map->line++;
		free(line);
		line = NULL;
	}
	map->map = malloc(sizeof(char *) * map->line);
	if (!map->map)
		ft_exit("Memory Allocation Error\n");
	fd = open("./srcs/map.ber", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		map->map[i] = ft_strdup(line);
		free (line);
		line = NULL;
		i++;
	}
}

t_map	ft_parsing(void)
{
	t_map	map;
	int		i;

	i = 0;
	init_map(&map);
	get_map(&map);
	parsing_map(&map);
	if (map.E <= 0 || map.C <= 0 || map.P != 1)
		ft_exit("The map must have at least one 'E' one 'C' and ONE 'P'\n");
	return (map);
}
