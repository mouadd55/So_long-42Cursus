/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:54:07 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/12 20:46:00 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_error(int cases)
{
	if (cases == 1)
		ft_putstr("\e[1m\x1B[31mError: \e[37mtoo few arguments\n");
	else if (cases == 2)
		ft_putstr("\e[1m\x1B[31mError: \e[37minvalid extension\n");
	else if (cases == 3)
		ft_putstr("\e[1m\x1B[31mError: \e[37mfile does not exist\n");
	else if (cases == 4)
		ft_putstr("\e[1m\x1B[31mError: \e[37minvalid map\n");
	else if (cases == 5)
		ft_putstr("\e[1m\x1B[31mError: \e[37mtoo many arguments\n");
	exit(1);
}

char	*ft_read_map(int fd)
{
	char	*str;
	char	*line;	

	str = NULL;
	line = ft_get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) < 4)
			ft_error(4);
		str = ft_strjoin(str, line);
		free(line);
		line = ft_get_next_line(fd);
	}
	return (str);
}

char	**ft_copy_map_to_two_dim_array(char *file_path, t_vars *v)
{
	int		i;
	int		fd;
	char	*str;
	char	**map;

	i = -1;
	v->lines = 0;
	v->newline = 0;
	fd = open(file_path, O_RDWR);
	if (fd < 0)
		ft_error(3);
	str = ft_read_map(fd);
	if (!str)
		return (NULL);
	while (str[++i])
		if (str[i] == '\n')
			v->newline++;
	map = ft_split(str, '\n');
	while (map[v->lines])
		v->lines++;
	if (v->lines <= v->newline)
		ft_error(4);
	free(str);
	return (map);
}

int	ft_check_special_character(char **map)
{
	int		i;
	int		j;
	char	**tmp;

	i = -1;
	tmp = map;
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			if (tmp[i][j] != '1' && tmp[i][j] != '0' && tmp[i][j] != 'E'
				&& tmp[i][j] != 'P' && tmp[i][j] != 'C')
				return (1);
		}
	}
	return (0);
}
