/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_board.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:39:09 by glaurich          #+#    #+#             */
/*   Updated: 2023/08/27 14:39:10 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	is_board_correct(char *board, char *tab_views);

// return a char of one of the 24 possible rows
char	get_a_row(int i)
{
	char	*str1;
	char	*str2;

	str1 = "123412431324134214231432213421432314234124132431";
	str2 = "312431423214324134123421412341324213423143124321";
	if (i < 48)
		return (str1[i]);
	else
		return (str2[i - 48]);
}

// fill list with all 24 possible rows with the help of get_a_row
char	**list_all_row(char **list)
{
	int	j;
	int	k;
	int	l;

	j = 0;
	l = 0;
	while (j < 24)
	{
		list[j] = (char *)malloc(4 * sizeof(char));
		k = 0;
		while (k < 4)
		{
			list[j][k] = get_a_row(l);
			l++;
			k++;
		}
		j++;
		free(list[j]);
	}
	return (list);
}

//fusion 2 lines into board at i position
char	*append_board(char *brd, int i, char *l1, char *l2)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		if (j < 4)
			brd[i + j] = l1[j];
		else
			brd[i + j] = l2[j - 4];
		j++;
	}
	brd[i + j] = '\0';
	return (brd);
}

// generate all boards possible (even some not possible)
// return 1 when it find a board that respect rules / views
// return 0 if it find none respecting views
int	generate_all_boards(int *ind, char **l, char *brd, char *tab_views)
{
	ind[0] = 0;
	while (ind[0] < 24)
	{
		ind[1] = 0;
		while (ind[1] < 24)
		{
			ind[2] = 0;
			while (ind[2] < 24)
			{
				ind[3] = 0;
				while (ind[3] < 24)
				{
					brd = append_board(brd, 0, l[ind[0]], l[ind[1]]);
					brd = append_board(brd, 8, l[ind[2]], l[ind[3]]);
					if (is_board_correct(brd, tab_views) == 1)
						return (1);
					ind[3] = ind[3] + 1;
				}
				ind[2] = ind[2] + 1;
			}
			ind[1] = ind[1] + 1;
		}
		ind[0] = ind[0] + 1;
	}
	return (0);
}

// write the board in terminal
void	show_board(char *board)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i != 0)
			write(1, "\n", 1);
		write(1, &board[i], 1);
		if (i % 4 != 3)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
