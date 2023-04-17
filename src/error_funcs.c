/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_funcs.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mhaan <mhaan@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/07 12:13:57 by mhaan         #+#    #+#                 */
/*   Updated: 2023/04/17 11:36:32 by mhaan         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"fdf.h"


void	ft_error(char *s)
{
	ft_putstr_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}