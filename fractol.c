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

void	fractol(t_data *data)
{
	t_cord	pixel;
	t_cord	psize;
	
	psize.x = ((data->max.x - data->min.x) / WIDTH);
	psize.y = ((data->max.y - data->min.y) / HEIGHT);
	data->cd.y = 0;
	while (data->cd.y < HEIGHT)
	{
		data->cd.x = 0;
		pixel.y = (data->min.y + data->cd.y * psize.y);
		while (data->cd.x < WIDTH)
		{
			pixel.x = (data->min.x + data->cd.x * psize.x);
			mandelbrot(data, pixel);
			data->cd.x++;
		}
		data->cd.y++;
	}
}

void	mandelbrot(t_data *data, t_cord pixel)
{
	t_cord	result;
	int		interat;
	t_cord	calc;

	calc.x = 0.0;
	calc.y = 0.0;
	result.x = calc.x * calc.x;
	result.y = calc.y * calc.y;
	interat = 0;
	while (interat < MAXINTER && (result.x * result.y) < 4)
	{
		calc.y = 2 * calc.x * calc.y + pixel.y;
		calc.x = result.x - result.y + pixel.x;
		result.x = calc.x * calc.x;
		result.y = calc.y * calc.y;
		interat++;
	}
	putpixel(data, interat);
}

void	julia(t_data *data, t_cord pixel)
{
	t_cord	result;
	int		interat;
	t_cord	calc;

	calc.x = 0.0;
	calc.y = 0.0;
	result.x = calc.x * calc.x;
	result.y = calc.y * calc.y;
	interat = 0;
	while (interat < MAXINTER && (result.x * result.y) < 4)
	{
		calc.y = 2 * calc.x * calc.y + pixel.y;
		calc.x = result.x - result.y + pixel.x;
		result.x = calc.x * calc.x;
		result.y = calc.y * calc.y;
		interat++;
	}
	putpixel(data, interat);
}

// /*
// ** d->rng is a random value that will produce different remarkable Julias
// ** each time the user chooses Julia it refreshes Julia initialization
// */

// void	remarkable_julias(t_data *data)
// {
// 	if (!data->rng)
// 		d->julia = (t_cnb) {.real = -0.506667, .imag = 0.520000 };
// 	else if (d->rng == 1)
// 		d->julia = (t_cnb) {.real = 0.403333, .imag = 0.273333 };
// 	else if (d->rng == 2)
// 		d->julia = (t_cnb) {.real = 0.386667, .imag = 0.103333 };
// 	else if (d->rng == 3)
// 		d->julia = (t_cnb) {.real = -0.203333, .imag = -0.696667 };
// 	else if (d->rng == 4)
// 		d->julia = (t_cnb) {.real = 0.18, .imag = -0.566667 };
// 	else if (d->rng == 5)
// 		d->julia = (t_cnb) {.real = 0.371504, .imag = -0.153893 };
// }