/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_fractol(t_data data)
{
	t_cord	cord;
	t_cord	pixel;
	t_win	params;

	params.min.x = -1.7;
	params.max.x = 1.7;
	params.min.y = -1.7; //Waiting to do a function
	params.max.y = 1.7;
	params.scale = 0.7;
	
	pixel.x = ((params.max.x - params.min.x) / WIDTH);
	pixel.y = ((params.max.y - params.min.y) / HEIGHT);
	cord.y = 0;
	while (cord.y < HEIGHT)
	{
		cord.x = 0;
		pixel.y = (params.min.y + cord.y * pixel.y) * params.scale;
		while (cord.x < WIDTH)
		{
			pixel.x = (params.min.x + cord.x * pixel.x) * params.scale;
			ft_mandelbrot(data, cord, pixel);
			cord.x++;
		}
		cord.y++;
	}
}

void	ft_mandelbrot(t_data data, t_cord cd, t_cord pixel)
{
	double	result;
	int		interat;
	t_cord	calc;

	calc.x = 0.0;
	calc.y = 0.0;
	result = (calc.x * calc.x) + (calc.y * calc.y);
	interat = 0;
	while (interat < 200 && result < 4)
	{
		calc.y = 2 * calc.x * calc.y + pixel.y;
		calc.x = (calc.x * calc.x) - (calc.y * calc.y) + pixel.x;
		result = (calc.x * calc.x) + (calc.y * calc.y);
		interat++;
	}
	ft_putpixel(data, cd, interat);
}
