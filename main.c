#include "so_long.h"

// void	my_pxl_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = data->addr + (y * data->line_lenght + x * (data->bit_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;
// 	void	*mlx;
// 	t_data	img;
// 	void	*win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 1920, 1080, "Zmart");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bit_per_pixel, &img.line_lenght, &img.endian);
// 	my_pxl_put(&img, 10, 100, 0x00FF0000);
// 	mlx_put_image_to_window(mlx, win, img.img, 0 , 0);
// 	mlx_loop(mlx);
// 	return (0);
// }

int main()
{
	char	*str = "s.ber";
	printf("----- %s ------\n", str + (ft_strlen(str) - 4));
	printf("|%d|\n", ft_strncmp(".ber", str + (ft_strlen(str) - 4)));
}
