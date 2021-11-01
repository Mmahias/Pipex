/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:25:44 by mmahias           #+#    #+#             */
/*   Updated: 2021/10/25 15:25:45 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1_process(int fd, t_data *data, int pipefd[2])
{
	int	i;

	i = 0;
	if (dup2(fd, 0) < 0)
		close_and_free(data, 0);
	close(pipefd[0]);
	if (dup2(pipefd[1], 1) < 0)
		exit(1);
	close(fd);
	if (data->abs1 == 1 || data->exc1 == 1)
	{
		execve(data->cmds1[0], data->cmds1, data->env);
		perror(data->cmds1[0]);
		close_and_free(data, 0);
	}
	while (i < data->len_path)
	{
		execve(data->pathname1[i], data->cmds1, data->env);
		i++;
	}
	close_and_free(data, 1);
}

void	child2_process(int fd, t_data *data, int pipefd[2])
{
	int	i;

	i = 0;
	if (dup2(pipefd[0], 0) < 0)
		exit(1);
	close(pipefd[1]);
	if (dup2(fd, 1) < 0)
		exit(1);
	close(fd);
	if (data->abs2 == 1 || data->exc2 == 1)
	{
		execve(data->cmds2[0], data->cmds2, data->env);
		perror(data->cmds2[0]);
		close_and_free(data, 0);
	}
	while (i < data->len_path)
	{
		execve(data->pathname2[i], data->cmds2, data->env);
		i++;
	}
	close_and_free(data, 1);
}
