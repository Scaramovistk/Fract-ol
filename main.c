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

int	main(void)
{
	t_data	data;

	data.ptr = mlx_init();
	if (data.ptr == NULL)
		return (0);
	data.win = mlx_new_window(data.ptr, WIDTH, HEIGHT, "Narnia Closet");
	if (data.win == NULL)
		return (0);
	ft_fractol(data);
	mlx_loop(data.ptr);
	//mlx_destroy_display(data.ptr);
	free(data.ptr);
	return (0);
}
