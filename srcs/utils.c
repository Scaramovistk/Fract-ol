/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/08 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			row;
	unsigned char	*ps1;
	unsigned char	*ps2;

	ps1 = (unsigned char *)s1;
	ps2 = (unsigned char *)s2;
	row = 0;
	while ((ps1[row] != '\0' || ps2[row] != '\0'))
	{
		if (ps1[row] != ps2[row])
			return (ps1[row] - ps2[row]);
		row++;
	}
	return (0);
}

void	ft_putendl(char *s)
{
	int	row;

	if (!s)
		return ;
	row = 0;
	while (s[row] != '\0')
	{
		write(1, &s[row], 1);
		row++;
	}
	write(1, "\n", 1);
}

void	ft_error(t_data *d)
{
	ft_putendl("Usage: ./fractol [Fractal] [Color] [Type]");
	ft_putendl("i.e: ./fractol Julia 3 2");
	ft_putendl("Fractal : [Mandelbrot] [Julia]");
	ft_putendl("Color : 0 - 3");
	ft_putendl("Type : Julia (0 - 3), Mandelbrot (0)");
	ft_putendl("[<-][^][->] Use the Arrows to move");
	mlx_destroy_image(d->ptr, d->win);
	exit(0);
}

int	end(char *str)
{
	ft_putendl(str);
	return (1);
}
