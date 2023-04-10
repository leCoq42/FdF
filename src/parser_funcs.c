/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:12:38 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/10 16:35:18 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int		fdf_open_map_file(char *input_file)
{
	int	valid;
	int	fd;

	valid = ft_strncmp(input_file + ft_strlen(input_file) - 4, ".fdf", 5);
	if (valid)
		ft_error("Error: Invalid file extension.");
	fd = open(input_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error: invalid fd.");
	return (fd);
}

char	**fdf_parse_map_data(fd)
{
	char			*tmp;
	char			*line;
	char			**map_data;
	unsigned int	rows;

	rows = 0;
	tmp = ft_calloc(1, sizeof(char));
	line = get_next_line(fd);
	if (!line)
		ft_error("No data to read!");
	while (line)
	{
		rows++;
		tmp = gnl_strjoin(tmp, line);
		free(line);
		line = get_next_line(fd);
	}
	map_data = ft_split(tmp, '\n');
	return (free(tmp), map_data);
}
