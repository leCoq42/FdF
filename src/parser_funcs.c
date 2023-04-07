/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:12:38 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/07 16:57:33 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

static t_map	*init_map(void);

t_map	*fdf_parse_map(char *filename)
{
	t_map	*map;
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error();
	map = init_map();
	tmp = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	while (line)
	{
		tmp = gnl_strjoin(tmp, line);
		free(line);
		line = get_next_line(fd);
	}
	map->map = ft_split(tmp, ' ');
	return (free(tmp), map);
}


static t_map	*init_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->map = NULL;
	map->width = 0;
	map->height = 0;
	return (map);
}