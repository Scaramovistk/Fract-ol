/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setfractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/08 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	set_fractal(t_data *d)
{
	if (d->fractal == NULL)
		ft_error(d);
	if (!ft_strcmp(d->fractal, "Julia"))
	{
		d->min.x = -2;
		d->max.x = 2;
		d->min.y = -2;
		d->max.y = 2;
		set_julia(d);
	}
	else if (!ft_strcmp(d->fractal, "Mandelbrot"))
	{
		d->min.x = -1.5;
		d->max.x = 1.5;
		d->min.y = -1.5;
		d->max.y = 1.5;
	}
	else
		ft_error(d);
}

void	set_julia(t_data *d)
{
	if (d->ty == NULL)
		ft_error(d);
	if (!ft_strcmp(d->ty, "0"))
	{
		d->julia.x = 0.403333;
		d->julia.y = 0.273333;
	}
	else if (!ft_strcmp(d->ty, "1"))
	{
		d->julia.x = -0.506667;
		d->julia.y = 0.520000;
	}
	else if (!ft_strcmp(d->ty, "2"))
	{
		d->julia.x = -0.203333;
		d->julia.y = -0.696667;
	}
	else if (!ft_strcmp(d->ty, "3"))
	{
		d->julia.x = 0.18;
		d->julia.y = -0.566667;
	}
	else
		ft_error(d);
}

void	set_color(t_data *d)
{
	if (!ft_strcmp(d->cl, "0"))
		d->color = 1722496;
	else if (!ft_strcmp(d->cl, "1"))
		d->color = 4711680;
	else if (!ft_strcmp(d->cl, "2"))
		d->color = 7822496;
	else if (!ft_strcmp(d->cl, "3"))
		d->color = 915752;
	else
		ft_error(d);
}
