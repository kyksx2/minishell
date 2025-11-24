/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzara <tzara@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:52:19 by kjolly            #+#    #+#             */
/*   Updated: 2025/05/23 15:33:45 by tzara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_bonus_ex(t_data *data, int ex, char *path)
{
	data->exit_code = ex;
	free(path);
	free_all(data);
	free_env(&data->env);
	rl_clear_history();
	exit(ex);
}

void	free_exec(t_data *data, t_exec *mini)
{
	free(mini->pidarray);
	free_all(data);
	free_env(&data->env);
	free(data);
	rl_clear_history();
}

int	is_delimiteur(int type)
{
	if (type == WORD || type == PIPE)
		return (0);
	else
		return (1);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
