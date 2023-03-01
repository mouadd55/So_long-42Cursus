/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:02:16 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/01 23:11:46 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_check_extension(char *file_name)
{
	int	i;

	if (ft_strcmp(file_name, ".ber") == 0)
		return (1);
	else
	{
		i = ft_strlen(file_name) - 4;
		if (file_name[0] != '.' && ft_strcmp(file_name + i, ".ber") == 0)
			return (0);
	}
	return (1);
}

int	ft_check_borders(char **map)
{
	int	i;
	int	j;
	t_vars	variables;

	i = 0;
	j = -1;
	variables.lines = 0;
	variables.length_of_line = ft_strlen(map[0]);
	while (map[variables.lines])
		variables.lines++;
	if (variables.length_of_line == variables.lines)
		return (1);
	while (++j < variables.length_of_line)
		if (map[0][j] != '1' || map[variables.lines-1][j] != '1')
			return (1);
	while (++i <= variables.lines - 2)
		if (map[i][0] != '1' || map[i][variables.length_of_line-1] != '1')
			return (1);
	return (0);
}

int	ft_check_characters(char **map)
{
	int		i;
	int		j;
	t_vars	variables;

	variables.c = 0;
	variables.e = 0;
	variables.p = 0;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'E')
				variables.e++;
			else if (map[i][j] == 'P')
				variables.p++;
			else if (map[i][j] == 'C')
				variables.c++;
		}
	}
	if (variables.e == 1 && variables.p == 1 && variables.c >= 1)
		return (0);
	return (1);
}

int	ft_check_components(char **map)
{
	t_vars	variables;

	variables.lines = 0;
	variables.length_of_line = 0;
	while (map[variables.lines])
		variables.lines++;
	while (map[0][variables.length_of_line])
		variables.length_of_line++;
	if (ft_check_borders(map))
		return (1);
	else if (variables.lines == variables.length_of_line)
		return (1);
	else if (ft_check_characters(map))
		return (1);
	return (0);
}

char	**ft_copy_map_to_two_dim_array(char *file_path)
{
	int		fd;
	char	*str;
	char	*line;
	char	**map;

	str = NULL;
	fd = open(file_path, O_RDWR);
	if (fd < 0)
		ft_error();
	line = ft_get_next_line(fd);
	while (line)
	{
		str = ft_strjoin(str, line);
		line = ft_get_next_line(fd);
	}
	map = ft_split(str, '\n');
	return (map);
}
