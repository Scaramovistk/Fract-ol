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

# define WIDTH 1000
# define HEIGHT 1000
# define MAXINTER 200

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

typedef struct s_win
{
	t_cord	min;
	t_cord	max;
	double	scale;
}	t_win;

typedef struct s_data
{
	void	*ptr;
	void	*win;
	t_color	cl;
}	t_data;

void	ft_fractol(t_data data);
void	ft_putpixel(t_data data, t_cord cd, int interat);
void	ft_mandelbrot(t_data data, t_cord cd, t_cord pixel);

#endif