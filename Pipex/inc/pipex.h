/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmahias <mmahias@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:27:37 by mmahias           #+#    #+#             */
/*   Updated: 2021/10/27 14:35:22 by mmahias          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_data
{
	int		fd1;
	int		acr_fd1;
	int		fd2;
	char	**cmds1;
	int		acces_cmd1;
	int		s_cmds1;
	char	**cmds2;
	int		acces_cmd2;
	int		s_cmds2;
	char	**path;
	char	**pathname1;
	char	**pathname2;
	char	**env;
	char	*line_zero;
	int		len_path;
	int		exc1;
	int		abs1;
	int		exc2;
	int		abs2;
}	t_data;

size_t	ft_strlen(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
char	**ft_split(char const *s, char c);
void	ft_putstr_fd(char *s, int fd);
int		ft_access_read(char *fd);
void	ft_found_path(t_data *data);
void	ft_dup_path(t_data *data);
int		ft_found_access(char **pathname, char *cmd, t_data *data);
void	ft_pathname_cmd(t_data *data);
void	ft_split_cmds(t_data *data, char **av);
void	child1_process(int fd, t_data *data, int pipefd[2]);
void	child2_process(int fd, t_data *data, int pipefd[2]);
void	ft_free_strs(char **strs, int index);
void	close_and_free(t_data *data, int exit_code);
#endif
