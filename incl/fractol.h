/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include "keycode_mac.h"

# define WIDTH 1000
# define HEIGHT 1000
# define MAXINTER 100

typedef struct s_cord
{
	double	x;
	double	y;
}	t_cord;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	void	*img;
	char	*addr;
	int		psize;
	int		sline;
	int		end;
	char	*cl;
	int		color;
	char	*fractal;
	char	*ty;
	t_cord	cd;
	t_cord	min;
	t_cord	max;
	t_cord	julia;
}	t_data;

void	fractol(t_data *d);
void	mandelbrot(t_data *d, t_cord pixel);
void	set_fractal(t_data *d);
void	julia(t_data *d, t_cord calc);
void	set_julia(t_data *d);
int		mouse_hook(int key, int x, int y, t_data *d);
int		key_hook(int k, t_data *d);
void	putpixel(t_data *d, int interat);
void	ft_error(t_data *d);
void	set_color(t_data *d);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putendl_fd(char *s);
int		end(char *str);

#endif