
#include "tracer.h"

int	exit_simple(int keycode, t_img_data *data)
{
	(void)data;
	if (keycode == ESC)
	{
		exit(0);
	}
	return (0);
}

int	main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;
	t_seine		*seine;

	mlx = mlx_init();
	seine = init_seine();
	mlx_win = mlx_new_window(mlx, RESOLUTION, RESOLUTION, "Ray_Sphere");
	img.img = mlx_new_image(mlx, RESOLUTION, RESOLUTION);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	render(seine, &img, RESOLUTION);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, KEY_RELEASE, BUTTON_RELEASE, exit_simple, &img);
	mlx_hook(mlx_win, DESTROY_NOTIFY, NO_EVENT, exit_simple, &img);
	mlx_loop(mlx);
	return (0);
}
