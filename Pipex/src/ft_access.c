/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:24:46 by mmahias           #+#    #+#             */
/*   Updated: 2021/10/27 14:45:22 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_access_read(char *fd)
{
	int	access_fd;

	access_fd = 0;
	if (access(fd, R_OK) < 0)
	{
		access_fd = -1;
		perror(fd);
	}
	return (access_fd);
}

static int	ft_size_path(char **path)
{
	int	i;

	i = 0;
	while (path[i] && path[i][0] != '\0')
		i++;
	return (i);
}

void	ft_dup_path(t_data *data)
{
	int	i;

	i = 0;
	data->pathname2 = malloc(sizeof(char *) * (data->len_path + 1));
	while (i < data->len_path)
	{
		data->pathname2[i] = ft_strdup(data->pathname1[i]);
		i++;
	}
}

void	ft_found_path(t_data *data)
{
	int	i;

	i = 0;
	while (!(ft_strncmp(data->env[i], "PATH=", 5) == 0))
		i++;
	data->path = ft_split(data->env[i], ':');
	data->line_zero = ft_substr(data->path[0], 5, ft_strlen(data->path[0]));
	data->len_path = ft_size_path(data->path);
	data->pathname1 = malloc(sizeof(char *) * (data->len_path + 1));
	i = 0;
	while (data->path[i])
	{
		if (i == 0)
		{
			data->pathname1[i] = ft_strdup(data->line_zero);
			data->pathname1[i] = ft_strjoin(data->pathname1[i], "/");
			i++;
		}
		data->pathname1[i] = ft_strdup(data->path[i]);
		data->pathname1[i] = ft_strjoin(data->pathname1[i], "/");
		i++;
	}
}

int	ft_found_access(char **pathname, char *cmd, t_data *data)
{
	int	acces;
	int	i;

	acces = 0;
	i = 0;
	if (access(cmd, X_OK) == 0)
		acces = 0;
	else
	{
		while (i < data->len_path)
		{
			if (access(pathname[i], X_OK) == 0)
			{
				acces = 0;
				return (acces);
			}
			i++;
		}
		acces = -1;
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
	return (acces);
}
