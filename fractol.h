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
# include <stdio.h>
# include <mlx.h>
# include <math.h>
#include "keycode_mac.h"

# define WIDTH 1000
# define HEIGHT 1000
# define MAXINTER 100

typedef struct s_color
{
	int	red;
	int	blue;
	int	green;
}	t_color;

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

	t_cord	cd;
	t_color	cl;
	t_cord	min;
	t_cord	max;
	t_cord	julia;
	long double	scale;
}	t_data;

void	fractol(t_data *data);
void	putpixel(t_data *data, int interat);
void	mandelbrot(t_data *data, t_cord pixel);
void	julia(t_data *data, t_cord pixel);
int		mouse_hook(int key, int x, int y, t_data *data);
int		key_hook(int k, t_data *data);

#endif