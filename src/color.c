/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/08 16:06:03 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/11 17:06:10 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	create_color(uint32_t num, t_color *color)
{
	color->t_rgba.r = (num >> 16) & 0xFF;
	color->t_rgba.g = (num >> 8) & 0xFF;
	color->t_rgba.b = num & 0xFF;
	color->t_rgba.a = 255;
}

uint32_t	ft_hextodec(char *hex)
{
	int			i;
	uint32_t	res;
	uint8_t		byte;

	i = 0;
	if (hex[0] && hex[0] == '0' && hex[1] && (hex[1] == 'x' || hex[1] == 'X'))
		i += 2;
	while (hex[i] && hex[i] != '\n')
	{
		byte = hex[i];
		if (byte >= '0' && byte <= '9')
			byte = byte - '0';
		else if (byte >= 'a' && byte <= 'f')
			byte = byte - 'a' + 10;
		else if (byte >= 'A' && byte <= 'F')
			byte = byte - 'A' + 10;
		else
			ft_error("Error: invalid collor code.\n") ;
		res = (res << 4) | (byte & 0xF);
		i++;
	}
	return (res);
}
