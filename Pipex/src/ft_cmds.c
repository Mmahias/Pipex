/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:25:29 by mmahias           #+#    #+#             */
/*   Updated: 2021/10/27 14:47:15 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	size_cmd(char **cmds)
{
	int	i;

	i = 0;
	while (cmds[i])
		i++;
	return (i);
}

void	ft_pathname_cmd(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->len_path)
	{
		data->pathname1[i] = ft_strjoin(data->pathname1[i], data->cmds1[0]);
		data->pathname2[i] = ft_strjoin(data->pathname2[i], data->cmds2[0]);
		i++;
	}	
}

void	ft_split_cmds(t_data *data, char **av)
{
	data->cmds1 = ft_split(av[2], ' ');
	data->s_cmds1 = size_cmd(data->cmds1);
	if (data->s_cmds1 == 0)
		close_and_free(data, 1);
	data->cmds2 = ft_split(av[3], ' ');
	data->s_cmds2 = size_cmd(data->cmds2);
	if (data->s_cmds2 == 0)
		close_and_free(data, 1);
}
