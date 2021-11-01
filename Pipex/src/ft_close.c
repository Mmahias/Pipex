/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:25:16 by mmahias           #+#    #+#             */
/*   Updated: 2021/10/27 15:04:29 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_strs(char **strs, int index)
{
	int	i;

	i = 0;
	if (strs != NULL)
	{
		while (i < index)
			free(strs[i++]);
		free(strs);
		strs = NULL;
	}
}

void	close_and_free(t_data *data, int exit_code)
{
	if (data->fd1 > -1)
		close(data->fd1);
	close(data->fd2);
	free(data->line_zero);
	ft_free_strs(data->cmds1, data->s_cmds1);
	ft_free_strs(data->cmds2, data->s_cmds2);
	ft_free_strs(data->path, data->len_path);
	ft_free_strs(data->pathname1, data->len_path);
	ft_free_strs(data->pathname2, data->len_path);
	exit(exit_code);
}
