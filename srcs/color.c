/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/08 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	my_mlx_pixel_put(t_data *d, int x, int y, int color)
{
	char	*dst;

	dst = d->addr + (y * d->sline + x * (d->psize / 8));
	*(unsigned int *)dst = color;
}

void	putpixel(t_data *d, int interat)
{
	set_color(d);
	if (interat == MAXINTER)
		my_mlx_pixel_put(d, d->cd.x, d->cd.y, 0x000000);
	else
	{
		while (interat < MAXINTER)
		{
			interat++;
			d->color += 2106;
		}
		my_mlx_pixel_put(d, d->cd.x, d->cd.y, d->color);
	}
}
