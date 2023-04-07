/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:07:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/07 17:39:10 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	f(void)
// {
// 	system("leaks fdf");
// }

static void	print_map(char **map)
{
	int i = 0;
	while (map[i])
	{
		ft_printf("%s ", map[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map		*map;
	// mlx_image_t	img;
	// mlx_t		*mlx;

	// atexit(f);
	if (argc != 2)
		ft_error("Usage: ./fdf <path_to_map>\n");

	// 1. Parse mapdata from file.
	map = fdf_parse_map(argv[1]);

	// // 2. Check if mapdata is valid.

	// // 3. Create a MLX instance.
	// mlx = mlx_init(WIDTH, HEIGHT, "FdF: ’Fil de Fer’", false);
	// if (!mlx)
	// 	exit(EXIT_FAILURE);

	// // 4. Create the image and a window to display the iamge.
	// img = ft_draw_rect(mlx, WIDTH, HEIGHT, 0xFFFFFFFF);
	// if (mlx_image_to_window(mlx, img, 0, 0) < 0)
	// 	exit(EXIT_FAILURE);

	// // 5. Handle user input.


	// mlx_loop(mlx);
	// // 6. Exit program.
	// mlx_terminate(mlx);

	// Test funcs:
	print_map(map->map);
	// exit(EXIT_SUCCESS);
	return (0);
}
