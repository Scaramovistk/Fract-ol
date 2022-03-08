/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/08 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	mouse_hook(int key, int x, int y, t_data *d)
{
	float	tmp;

	x = y * 2;
	tmp = ((d->max.x - d->min.x) + (d->max.y - d->min.y)) / 10;
	if (key == 4)
	{
		d->max.x -= tmp;
		d->min.x += tmp;
		d->max.y -= tmp;
		d->min.y += tmp;
	}
	else if (key == 5)
	{
		d->max.x += tmp;
		d->min.x -= tmp;
		d->max.y += tmp;
		d->min.y -= tmp;
	}
	fractol(d);
	mlx_put_image_to_window(d->ptr, d->win, d->img, 0, 0);
	return (1);
}

static void	key_hook_ext(float tmp, int key, t_data *d)
{
	if (key == KEY_DOWN)
	{
		d->max.y -= tmp;
		d->min.y -= tmp;
	}
	else if (key == KEY_UP)
	{
		d->max.y += tmp;
		d->min.y += tmp;
	}
	else if (key == KEY_ESCAPE)
	{
		end(".......Exiting.......\nFractals are everywhere");
		mlx_destroy_image(d->ptr, d->win);
		exit(0);
	}
}

int	key_hook(int key, t_data *d)
{
	float	tmp;

	tmp = ((d->max.x - d->min.x) + (d->max.y - d->min.y)) / 10;
	if (key == KEY_LEFT)
	{
		d->max.x -= tmp;
		d->min.x -= tmp;
	}
	else if (key == KEY_RIGHT)
	{
		d->max.x += tmp;
		d->min.x += tmp;
	}
	key_hook_ext(tmp, key, d);
	fractol(d);
	mlx_put_image_to_window(d->ptr, d->win, d->img, 0, 0);
	return (1);
}
