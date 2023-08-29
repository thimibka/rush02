/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_rush.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:30:35 by glaurich          #+#    #+#             */
/*   Updated: 2023/08/27 14:30:40 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_len(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_parsing(char *str, char *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_str_len(str) != 31)
		return (1);
	while (str[i])
	{
		if ((i % 2) == 0)
		{
			if ((str[i] >= '1') && (str[i] <= '4'))
			{
				tab[j] = str[i];
				j++;
			}
			else
				return (1);
		}
		else
			if (str[i] != ' ')
				return (1);
		i++;
	}
	return (0);
}
