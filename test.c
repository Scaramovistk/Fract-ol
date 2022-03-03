#include <mlx.h>
#include <stdio.h>
#define WIDTH 600
#define HEIGHT 600

typedef struct	s_vars {
	void	*ptr;
	void	*win;
}				t_vars;

void fractol(t_vars *data, float	scaling)
{
	int i = 0;
	int j;
	static int size;
	if (!size)
		size = 10;
	if (scaling == 1.25)
	{
		size = size * scaling;
		while (i < size)
		{
			j = 0;
			while (j < size)
			{
				mlx_pixel_put(data->ptr, data->win, i, j, 0x05A8F0);
				j++;
			}
			i++;
		}
	}
	else
	{
		while (i < size)
			{
				j = 0;
				while (j < size)
				{
					mlx_pixel_put(data->ptr, data->win, i, j, 0x91C3FF);
					j++;
				}
				i++;
			}
	}
}

int	mouse_hook(int key, int x, int y, t_vars *data)
{
	if ((key == 1 || key == 2 || key == 4 || key == 5) &&
	(x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT))
	{
		if (key == 4 || key == 1)
			scaling = 1.25;
		else if (key == 5 || key == 2)
			scaling = 0.8;
		fractol(data, scaling);
	}
	return (1);
}



int	main(void)
{
	t_vars	vars;

	vars.ptr = mlx_init();
	vars.win = mlx_new_window(vars.ptr, 600, 600, "Hello world!");
	//mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	mlx_loop(vars.ptr);
}