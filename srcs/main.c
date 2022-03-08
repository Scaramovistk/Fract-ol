/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/03/08 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	main(int argc, char **argv)
{
	t_data	d;

	d.ptr = mlx_init();
	if (d.ptr == NULL || argc > 4)
		return (end("Failed to create pointer"));
	d.win = mlx_new_window(d.ptr, WIDTH, HEIGHT, "Fract-ol");
	if (d.win == NULL)
		return (end("Failed to create window"));
	d.fractal = argv[1];
	d.cl = argv[2];
	d.ty = argv[3];
	set_fractal(&d);
	d.img = mlx_new_image(d.ptr, WIDTH, HEIGHT);
	d.addr = mlx_get_data_addr(d.img, &d.psize, &d.sline, &d.end);
	mlx_mouse_hook(d.win, mouse_hook, &d);
	mlx_hook(d.win, 2, 4, key_hook, &d);
	mlx_loop(d.ptr);
	mlx_destroy_image(d.ptr, d.win);
	return (0);
}
