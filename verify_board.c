/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:37:24 by glaurich          #+#    #+#             */
/*   Updated: 2023/08/27 14:37:26 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int		ft_str_len(char *tab);
void	calculate_views_rows(char *board, char *views, int size_board, int *j);
void	calculate_views_rows_rev(char *board, char *views, int size, int *j);
void	calculate_views_collums(char *board, char *views, int size, int *j);
void	calculate_views_collums_rev(char *board, char *views, int size, int *j);
void	show_board(char *board);

// return 1 if the board calculated views arent the same as tab_views
int	does_board_respect_views(char *tab_board, char *tab_views)
{
	int		i;
	int		j;
	int		size_tab;
	char	*tab_true_views;

	j = 0;
	size_tab = ft_str_len(tab_views) / 4;
	tab_true_views = (char *)malloc(size_tab * 4 * sizeof(char));
	calculate_views_collums(tab_board, tab_true_views, size_tab, &j);
	calculate_views_collums_rev(tab_board, tab_true_views, size_tab, &j);
	calculate_views_rows(tab_board, tab_true_views, size_tab, &j);
	calculate_views_rows_rev(tab_board, tab_true_views, size_tab, &j);
	i = 0;
	while (i < (size_tab * 4))
	{
		if (tab_true_views[i] != tab_views[i])
		{
			free(tab_true_views);
			return (1);
		}
		i++;
	}
	free(tab_true_views);
	return (0);
}

// return 1 if there is multiple instances of the same number in a column.
int	does_board_respect_base_rules(char *board)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 15)
	{
		j = 0;
		k = i % 4;
		while (j < 4)
		{
			if ((board[i] == board[k + 4 * j]) && i != k + 4 * j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// return 1 and show the board if board
// respect all rules and the views we were looking for
int	is_board_correct(char *board, char *tab_views)
{
	if (does_board_respect_base_rules(board) == 0)
	{
		if (does_board_respect_views(board, tab_views) == 0)
		{
			show_board(board);
			return (1);
		}
	}
	return (0);
}
