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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->sline + x * (data->psize / 8));
	*(unsigned int*)dst = color;
}

void	putpixel(t_data *data, int interat)
{
	double	color;
	//blue 1722496
	//purple 6711680
	// red 7822496
	color = 1722496;
	if (interat == MAXINTER)
	{
		//mlx_pixel_put(data->ptr, data->win, data->cd.x, data->cd.y, 0x000000);
		my_mlx_pixel_put(data, data->cd.x, data->cd.y, 0x000000);
	}
	else
	{
		while (interat < MAXINTER)
		{//320

			interat++;
			color += 3106;
		}//3106
		//mlx_pixel_put(data->ptr, data->win, data->cd.x, data->cd.y, color);
		my_mlx_pixel_put(data, data->cd.x, data->cd.y, color);
	}
	
}