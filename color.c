/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putpixel(t_data data, t_cord cd, int interat)
{
	int		mxnterat;
	double	color;

	color = data.cl.red;
	color = data.cl.blue * 10^3;
	color = data.cl.green * 10^6;
	mxnterat = 200;
	if (interat == mxnterat)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x000000);
	else if (interat > mxnterat / 10)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x1A4880);
	else if (interat > mxnterat / 16)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x0A3770);
	else if (interat > mxnterat / 24)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x205A9F);
	else if (interat > mxnterat / 32)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x266CBF);
	else if (interat > mxnterat / 40)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x2D7EDF);
	else if (interat > mxnterat / 48)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x3390FF);
	else if (interat > mxnterat / 56)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x6D92BF);
	else if (interat > mxnterat / 64)
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x7FABDF);
	else
		mlx_pixel_put(data.ptr, data.win, cd.x, cd.y, 0x91C3FF);
}
