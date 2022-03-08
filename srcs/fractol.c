/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/08 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	fractol(t_data *d)
{
	t_cord	pixel;
	t_cord	psize;

	psize.x = (d->max.x - d->min.x) / WIDTH;
	psize.y = ((d->max.y - d->min.y) / HEIGHT);
	d->cd.y = 0;
	while (d->cd.y < HEIGHT)
	{
		d->cd.x = 0;
		pixel.y = (d->min.y + d->cd.y * psize.y);
		while (d->cd.x < WIDTH)
		{
			pixel.x = (d->min.x + d->cd.x * psize.x);
			if (!ft_strcmp(d->fractal, "Julia"))
				julia(d, pixel);
			else if (!ft_strcmp(d->fractal, "Mandelbrot"))
				mandelbrot(d, pixel);
			d->cd.x++;
		}
		d->cd.y++;
	}
}

void	julia(t_data *d, t_cord pixel)
{
	t_cord	calc;
	t_cord	result;
	int		interat;

	calc.x = pixel.x;
	calc.y = pixel.y;
	interat = 0;
	while (interat < MAXINTER)
	{
		result.x = calc.x * calc.x;
		result.y = calc.y * calc.y;
		calc.y = 2 * calc.x * calc.y + d->julia.y;
		calc.x = result.x - result.y + d->julia.x;
		if ((result.x + result.y) > 4)
			break ;
		interat++;
	}
	putpixel(d, interat);
}

void	mandelbrot(t_data *d, t_cord pixel)
{
	t_cord	calc;
	t_cord	result;
	int		interat;

	calc.x = 0;
	calc.y = 0;
	interat = 0;
	while (interat < MAXINTER)
	{
		result.x = calc.x * calc.x;
		result.y = calc.y * calc.y;
		calc.y = 2 * calc.x * calc.y + pixel.y;
		calc.x = result.x - result.y + pixel.x;
		if ((result.x + result.y) > 4)
			break ;
		interat++;
	}
	putpixel(d, interat);
}
