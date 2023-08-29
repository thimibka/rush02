/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_views.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:34:12 by glaurich          #+#    #+#             */
/*   Updated: 2023/08/27 14:34:14 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// calculated row left views of a board
void	calculate_views_rows(char *board, char *views, int size_board, int *j)
{
	int		i;
	int		k;
	int		nb;
	char	max;

	k = 0;
	while (k < size_board)
	{
		i = (size_board * k);
		nb = 0;
		max = '0';
		while (i < (size_board *(1 + k)))
		{
			if (board[i] > max)
			{
				max = board[i];
				nb++;
			}
			i++;
		}
		views[*j] = '0' + nb;
		k++;
		*j = *j + 1;
	}
}

// calculated row right views of a board
void	calculate_views_rows_rev(char *board, char *views, int size, int *j)
{
	int		i;
	int		k;
	int		nb;
	char	max;

	k = 0;
	while (k < size)
	{
		i = size *(1 + k) - 1;
		nb = 0;
		max = '0';
		while (i >= (size * k))
		{
			if (board[i] > max)
			{
				max = board[i];
				nb++;
			}
			i--;
		}
		views[*j] = '0' + nb;
		k++;
		*j = *j + 1;
	}
}

// calculated col up views of a board
void	calculate_views_collums(char *board, char *views, int size, int *j)
{
	int		i;
	int		k;
	int		nb;
	char	max;

	k = 0;
	while (k < size)
	{
		i = k;
		nb = 0;
		max = '0';
		while (i < (size * size))
		{
			if (board[i] > max)
			{
				max = board[i];
				nb++;
			}
			i = i + size;
		}
		views[*j] = '0' + nb;
		k++;
		*j = *j + 1;
	}
}

// calculated col down views of a board
void	calculate_views_collums_rev(char *board, char *views, int size, int *j)
{
	int		i;
	int		k;
	int		nb;
	char	max;

	k = 0;
	while (k < size)
	{
		i = (size * (size - 1)) + k ;
		nb = 0;
		max = '0';
		while (i >= 0)
		{
			if (board[i] > max)
			{
				max = board[i];
				nb++;
			}
			i = i - size;
		}
		views[*j] = '0' + nb;
		k++;
		*j = *j + 1;
	}
}
