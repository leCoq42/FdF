/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:07:27 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/08 17:43:06 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	free_content(void *nodep);
// static void	f(void)
// {
// 	system("leaks fdf");
// }

int	main(int argc, char **argv)
{
	int			fd;
	t_list		*map_data;
	t_fdf		*fdf;

	// Test leaks:
	// atexit(f);
	fdf = NULL;
	if (argc != 2)
		ft_error("Usage: ./fdf <path_to_map>\n");
	fd = fdf_open_map_file(argv[1]);
	map_data = fdf_parse_map_data(fd);
	fdf = fdf_init(fdf, map_data);
	fdf_create_map(fdf->map, map_data);
	fdf->camera = init_camera(fdf->camera, fdf->map);
	if (!fdf->camera)
		ft_error("Error with initializing camera.\n");
	fdf_draw_image(fdf, 0x00000000);
	if (mlx_image_to_window(fdf->mlx, fdf->img, 0, 0) < 0)
		ft_error("Error: unsuccesful drawing of image.");
	ft_lstclear(&map_data, free_content);
	if (map_data)
		ft_error("Error with freeing!\n");
	user_controls(fdf);
	put_menu(fdf);
	mlx_key_hook(fdf->mlx, &my_keyhooks, fdf);
	// mlx_close_hook(mlx, close_func, mlx);
	mlx_loop(fdf->mlx);
	mlx_terminate(fdf->mlx);
	exit(EXIT_SUCCESS);
}

static void	free_content(void *nodeptr)
{
	char	*content;

	content = (char *)nodeptr;
	free(content);
}
