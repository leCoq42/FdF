/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_funcs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:12:38 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 14:27:57 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

int	fdf_open_map_file(char *input_file)
{
	int	valid;
	int	fd;

	valid = ft_strncmp(input_file + ft_strlen(input_file) - 4, ".fdf", 5);
	if (valid)
		ft_error("Error: Invalid file extension.\n");
	fd = open(input_file, O_RDONLY);
	if (fd < 0)
		ft_error("Error: invalid fd.\n");
	return (fd);
}

t_list	*fdf_parse_map_data(int fd)
{
	char	*line;
	t_list	*node;
	t_list	*last;
	t_list	*head;

	head = NULL;
	line = get_next_line(fd);
	if (!line)
		ft_error("No data to read!\n");
	while (line)
	{
		node = ft_lstnew((char *)line);
		if (!node)
			ft_error("Error with parsing data.\n");
		if (!head)
		{
			ft_lstadd_back(&head, node);
			last = head;
		}
		else
			ft_lstadd_back(&last, node);
		line = get_next_line(fd);
	}
	return (close(fd), head);
}
