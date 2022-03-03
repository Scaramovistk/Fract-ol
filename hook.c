/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_hook(int key, int x, int y, t_data *data)
{
	float	tmp;
	double	xpixel, ypixel, center, scale;

	center = (WIDTH + HEIGHT) / 4;
	scale = (WIDTH + HEIGHT) / 8;
	xpixel = (x - center) / scale;
	ypixel = ((y - center) / scale ) * -1;
	//tmp = ((ypixel) + (xpixel)) / 10;
	tmp = ((data->max.x - data->min.x) + (data->max.y - data->min.y)) / 10;

	if (key == 4)
	{
		data->max.x -= tmp;
		data->min.x += tmp;
		data->max.y -= tmp;
		data->min.y += tmp;
	}
	else if (key == 5)
	{
		data->max.x += tmp;
		data->min.x -= tmp;
		data->max.y += tmp;
		data->min.y -= tmp;
	}
	fractol(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0 , 0);
	return (1);
}

int	key_hook(int key, t_data *data)
{
	float	tmp;

	tmp = ((data->max.x - data->min.x) + (data->max.y - data->min.y)) / 10;
	if (key == KEY_LEFT)
	{
		data->max.x -= tmp;
		data->min.x -= tmp;
	}
	else if (key == KEY_RIGHT)
	{
		data->max.x += tmp;
		data->min.x += tmp;
	}
	else if (key == KEY_DOWN)
	{
		data->max.y -= tmp;
		data->min.y -= tmp;
	}
	else if (key == KEY_UP)
	{
		data->max.y += tmp;
		data->min.y += tmp;
	}
	else if (key == KEY_ESCAPE)
	{
		mlx_destroy_image(data->ptr, data->win);
		exit(0);
	}
	fractol(data);
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0 , 0);
	return (1);
}