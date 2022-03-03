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
//int argc, char **argv
int	main(void)
{
	t_data	data;

	data.ptr = mlx_init();
	if (data.ptr == NULL)
		return (0);
	data.win = mlx_new_window(data.ptr, WIDTH, HEIGHT, "Narnia Closet");
	if (data.win == NULL)
		return (0);

	data.min.x = -1.5;
	data.max.x = 1.5;
	data.min.y = -1.5; //Waiting to do a function
	data.max.y = 1.5;
	data.scale = 1;

	data.img = mlx_new_image(data.ptr, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.psize, &data.sline, &data.end);
	
	mlx_mouse_hook(data.win, mouse_hook, &data);
	
	mlx_hook(data.win, 2, 4, key_hook, &data);
	
	mlx_loop(data.ptr);
	mlx_destroy_image(data.ptr, data.win);
	free(data.ptr);
	return (0);
}
