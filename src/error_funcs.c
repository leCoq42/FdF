/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:13:57 by mhaan         #+#    #+#                 */
/*   Updated: 2023/05/18 14:17:58 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_after_error(t_fdf **fdf, char *s)
{
	free_before_exit(fdf);
	ft_error(s);
}
