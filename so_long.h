/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:00:21 by moudrib           #+#    #+#             */
/*   Updated: 2023/03/17 05:47:22 by moudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
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
	int		x;
	int		y;
	int		e;
	int		p;
	int		c;
	void	*pu;
	void	*pd;
	void	*pl;
	void	*pr;
	void	*cl;
	void	*bg;
	void	*ex1;
	void	*ex2;
	void	*wl1;
	void	*wl2;
	void	*mlx;
	void	*img;
	char	**map;
	char	**tmp;
	int		lines;
	int		walls;
	int		count;
	int		moves;
	int		keycode;
	int		newline;
	void	*mlx_win;
	int		length_of_line;
}	t_vars;

/************************* Libft utils *************************/

void	ft_putnbr(int nbr);
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

void	ft_error(int cases);
int		ft_check_borders(t_vars *v);
int		ft_check_valid_map(t_vars *v);
int		ft_check_characters(t_vars *v);
int		ft_check_extension(char *file_name);
int		ft_check_rectangular_shape(t_vars *v);
int		ft_check_special_character(char **map);
char	**ft_copy_map_to_two_dim_array(char *file_path, t_vars *v);

/*********************** Get next line ************************/

char	*ft_save_rest(char *buf);
char	*ft_get_next_line(int fd);
int		ft_search_newline(char *s);

/********************** Window management **********************/

int		ft_valid_path(t_vars *v);
int		ft_open_window(t_vars *v);
void	ft_fill_window(t_vars *v);
int		ft_close_window(t_vars *v);
void	ft_fill_util(char c, t_vars *v);
int		ft_count_characters(char **map);
int		key_press(int keycode, t_vars *v);
void	ft_initialize_pointers(t_vars *v);
void	ft_swap_characters(t_vars *v, int i, int j);
char	**ft_fill(char **map, t_vars *v, int i, int j);
int		ft_move_player(t_vars *v, int keycode, int i, int j);

#endif