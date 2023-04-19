/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:07:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/19 17:29:24 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	f(void)
// {
// 	system("leaks fdf");
// }


int	main(int argc, char **argv)
{
	int			fd;
	char		**map_data;
	t_fdf		*fdf;

	// atexit(f);
	fdf = NULL;
	// 1. Basic error check, open map file and check the .fdf extension.
	if (argc != 2)
		ft_error("Usage: ./fdf <path_to_map>\n");
	fd = fdf_open_map_file(argv[1]);
	// 2. Parse map data from fd.
	map_data = fdf_parse_map_data(fd);
	// 3. Create map
	fdf = fdf_init(fdf, map_data);
	fdf_create_map(fdf->map, map_data);
	// To do: free map_data
	// free_map_data(map_data);
	// if(!map_data)
	// 	ft_error("succes!\n");
	// print_map_data(map_data);
	// 4. Create the image and a window to display the iamge.
	fdf_draw_image(fdf, 0x00000000);
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		exit(EXIT_FAILURE);
	mlx_loop(fdf->mlx);
	// 5. Handle user input.
	// 6. Exit program.
	mlx_terminate(fdf->mlx);
	// free_map()
	// free_map_data()
	// Test funcs:
	// print_map(map_data);
	exit(EXIT_SUCCESS);
	// return (0);
}
