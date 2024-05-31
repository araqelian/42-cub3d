/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:50:55 by darakely          #+#    #+#             */
/*   Updated: 2023/01/18 20:54:50 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>

# include "keys.h"

# define WIDTH			2040
# define HEIGHT			1000

# define ROTATE_SPEED	0.15
# define MOVE_SPEED		0.2

# define BUFFER_SIZE 10

typedef struct s_index
{
	int	index_no;
	int	index_so;
	int	index_ea;
	int	index_we;
	int	index_c;
	int	index_f;
}				t_index;

typedef struct s_parsing
{
	char	**split_arg_c;
	char	**split_arg_f;
	char	*hex_arg_c;
	char	*hex_arg_f;
	int		dec_arg_c;
	int		dec_arg_f;
	char	**full_map;
	char	**norm_map;
	int		index_map;
	char	*arg_no;
	char	*arg_so;
	char	*arg_ea;
	char	*arg_we;
	char	*arg_c;
	char	*arg_f;
	int		count;
	char	**map;
	int		y;
}				t_parsing;

typedef struct s_img
{
	void	*ptr;
	char	*img;
	int		bpp;
	int		width;
	int		height;
	int		size_line;
	int		endian;
}				t_img;

typedef struct s_game
{
	int		index;
	void	*mlx;
	void	*win;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	int		x;
	int		y;
}				t_game;

typedef struct s_raycasting
{
	double	perpwalldist;
	double	deltadistx;
	double	deltadisty;
	int		lineheight;
	double	sidedistx;
	double	sidedisty;
	int		drawstart;
	double	camerax;
	double	raydiry;
	double	raydirx;
	int		drawend;
	double	planex;
	double	planey;
	int		stepx;
	int		stepy;
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	int		side;
	int		mapx;
	int		mapy;
	int		hit;
}				t_raycasting;

typedef struct s_data
{
	t_raycasting	*rcasting;
	t_parsing		*parsing;
	t_index			*index;
	t_game			*game;
	t_img			*img;
}				t_data;

//moves
void				rotate_right(t_data *data, double rotate);
void				move_left(t_data *data);
void				move_right(t_data *data);
void				move_up(t_data *data);
void				move_down(t_data *data);

//key_manager
int					key_manager(int key, t_data *data);

//init_win_4
void				ft_get_data_addr(t_data *data);
int					check_nwse(t_data *data);

//init_win_3
char				*get_correct_arg(char *ptr);
float				ft_abs(float num);
void				init_player_pos(t_data *data, int i, int j);
void				init_dir(t_data *data, double i, double j);
void				init_plane(t_data *data, double i, double j);

//init_win_2
void				draw_floor_and_celling(t_data *data, char *dest);
int					draw_walls(t_data *data, char *dest, \
					char *dest_2, int texx);
void				norm_init_win_3(t_data *data);
int					ft_texx(t_data *data, int n);

//init_win
void				init_win(t_data *data);
void				continue_init_win(t_data *data);
void				norm_init_win(t_data *data);
void				norm_init_win_2(t_data *data);
void				find_pos_player(t_data *data);

//ft_mlx_xpm
void				ft_mlx_xpm(t_data *data);

//init_structs
void				init_struct_parsing(t_data *data);
void				init_struct_index(t_data *data);
void				init_struct_game(t_data *data);
void				init_structs(t_data *data);

//check_map_6
void				last_check_colors(t_data *data);
void				add_new_map(t_data *data);

//check_map_5
void				check_arg_in_map(t_data *data);
void				continue_norm_get_add_arg(char *str, int i, \
					char *ptr, int *j);
void				check_arg_colors(t_data *data, int i, char *str, \
					char **check);
void				continue_check_arg_colors(t_data *data, int i, \
					char *str, char **check);
void				norm_continue_get_add_arg(t_data *data, char *ptr, \
					char *delim);

//check_map_4
void				continue_check(t_data *data, int index_str, int len_str);
void				norm_get_add_arg(t_data *data, char *delim, int i, \
					char *str);
void				continue_get_add_arg(t_data *data, char *ptr, char *delim);
void				check_down_and_up_spaces(t_data *data, char *str, int len, \
					int index_str);
void				check_down_and_up_walls(t_data *data, char *str, int len, \
					int index_str);

//check_map_3
int					continue_check_arg(char **check, char *str);
void				add_map_arg_in_struct(t_data *data, int j);
void				get_add_arg(t_data *data, char *str, int i, int j);
void				check_left_and_right_walls(t_data *data, char *str, int i, \
					int index_str);
void				check_all_spaces(t_data *data, int i);

//check_map_2
void				check_arg(t_data *data, int i, int j);
void				check_count_player(t_data *data, int i);
void				check_characters(t_data *data, int i);
void				continue_check_walls(t_data *data, int i);
void				check_arg_map(t_data *data, int i);

//check_map
void				get_correct_data(t_data *data, int i);
void				check_walls(t_data *data, int i);
void				check_map_3(t_data *data, int i, int j, int k);
void				check_map_2(t_data *data, int i, int j, int k);
void				check_map(t_data *data, int i, int j, int count);

//print_error
void				print_close(t_data *data, char *str);
int					close_game(t_data *data);
void				print_error(t_data *data, char *err, int flag);

//ft_split
char				**ft_split(char *s, char c);

//get_map
void				check_name_map(t_data *data, char *name_map);
void				read_map(t_data *data, char *line, char *map);
void				continue_read_map(t_data *data, char *map);
void				get_map(char **argv, t_data *data);

//utils_3
char				*ft_hex(int n);

//utils_2
int					check_size_str(char *s1, char *s2);
char				*my_strjoin(char *s1, char *s2);
int					ft_atoi(const char *str);
char				*my_strdup(char *str);

//utils
int					ft_strlen(char *str);
void				my_free(char **str);
char				*ft_strdup(char *str);
void				*ft_strcpy(char *dst, char *src, size_t n);
int					ft_strncmp(char *s1, char *s2, size_t n);

//get_next_line
int					get_next_line(int fd, char **line);

//free_all
void				free_array(char ***str);
void				free_all(t_data *data);

#endif
