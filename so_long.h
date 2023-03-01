/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:00:21 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/01 21:14:23 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct t_vars
{
	int		i;
	int		j;
	int		e;
	int		p;
	int		c;
	int		lines;
	int		walls;
	int		length_of_line;
	char	**map;

}	t_vars;

/************************* Libft utils *************************/

void	ft_putchar(char ch);
void	ft_putstr(char *str);
char	**ft_free_arr(char **arr);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_count_words(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/************************** Parsing ***************************/

void	ft_error(void);
int		ft_check_borders(char **map);
int		ft_check_characters(char **map);
int		ft_check_components(char **map);
int		ft_check_extension(char *file_name);
char	**ft_copy_map_to_two_dim_array(char *file_path);

/*********************** Get next line ************************/

char	*ft_save_rest(char *buf);
char	*ft_get_next_line(int fd);
int		ft_search_newline(char *s);

#endif