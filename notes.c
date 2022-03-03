/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gscarama <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:13:42 by gscarama          #+#    #+#             */
/*   Updated: 2022/02/18 08:29:45 by gscarama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 1000

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

typedef struct s_color
{
	int	red;
	int	blue;
	int	green;
}	t_color;

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (0);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Narnia Closet");
	double	i,j;
	int heg, wig;
	double	center;

	center = WIDTH / 2;

	//if (data->win_ptr != NULL) protect window

// ******* BACKGROUND ***********
	i = 0;
	heg = 0;
	while (i < WIDTH)
	{
		j = 0;
		wig = 0;
		while (j < HEIGHT)
		{
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, heg, wig, 0xFFFFFF);
			wig++;
			j++;
		}
		heg++;
		i++;
	}

	// ******* Cartesian Plan ***********
	i = 0;
	heg = WIDTH / 2;
	while (i < 4)
	{
		j = 0;
		wig = HEIGHT / 2;
		while (j < HEIGHT)
		{
			if (i == 1) //RIGHT
			{
				wig = HEIGHT / 2;
				heg--;
			}
			if (i == 2) //LEFT
			{
				heg = WIDTH / 2;
				wig = wig - 2;
			}
			if (i == 3) //DOWN
			{
				wig = HEIGHT / 2;
				heg++;
			}
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, wig, heg, 0x000000);
			wig++;
			j++;
		}
		heg++;
		i++;
	}

	double	scale;

	double	y;
	double	x;

	double	xpixel;
	double	ypixel;

	scale = WIDTH / 4;


//******** Cordanates value **********

	xpixel = 0.5;
	ypixel = 1.5;

	x = center + (xpixel * scale);
	y = center + (ypixel * scale * -1); //Y work the inverse

	// mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, 0x00004C);
	// mlx_pixel_put(data.mlx_ptr, data.win_ptr, x - 1, y, 0x00004C);
	// mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y - 1, 0x00004C);
	// mlx_pixel_put(data.mlx_ptr, data.win_ptr, x - 1, y - 1, 0x00004C);

//******** Pixel value **********

	x = 600;
	y = 200;

	xpixel = (x - center) / scale;
	ypixel = ((y - center) / scale ) * -1;

//******** Calculating Mandebrot ****************

	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;

	double	pwidth;
	double	pheight;

	double	x2;
	double	y2;

	int		interat;

	int		mxnterat;

	int		h;
	int		w;

	mxnterat = 200;

	// The zoom and movment need to be a porcentage
	xmin= -1.7; //If one change the other change the inverse porprotion
	xmax = 1.7; //Bigger move right
	ymin = -1.7; //If one change the other change the inverse porprotion
	ymax = 1.7;	//Bigger move up

	scale = 0.7; // Smaler = plus zoom

//******* second option to calculate ************
	pwidth = ((xmax - xmin) / WIDTH); // WIDTH = 1000, result = 0.004
	pheight = ((ymax - ymin) / HEIGHT); // HEIGHT = 1000, result = 0.004

	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		ypixel = (ymin + h * pheight) * scale;
		while (w < WIDTH)
		{
			x = 0.0;
			y = 0.0;
			x2 = x * x;
			y2 = y * y;
			xpixel = (xmin + w * pwidth) * scale;
			interat = 0;
			while (interat < mxnterat && (x2 + y2) < 4)
			{
				y = 2 * x * y + ypixel;
				x = x2 - y2 + xpixel;
				x2 = x * x;
				y2 = y * y;

				interat++;
			}

// *********** Color for the Fractal ************
			if (interat == mxnterat)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x000000);
			else if (interat > mxnterat / 10)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x1A4880);
			else if (interat > mxnterat / 16)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x0A3770);
			else if (interat > mxnterat / 24)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x205A9F);
			else if (interat > mxnterat / 32)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x266CBF);
			else if (interat > mxnterat / 40)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x2D7EDF);
			else if (interat > mxnterat / 48)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x3390FF);
			else if (interat > mxnterat / 56)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x6D92BF);
			else if (interat > mxnterat / 64)
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x7FABDF);
			else
				mlx_pixel_put(data.mlx_ptr, data.win_ptr, w, h, 0x91C3FF);
			w++;
		}
		h++;
	}

	mlx_loop(data.mlx_ptr);
	//mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}
