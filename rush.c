/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:13:46 by glaurich          #+#    #+#             */
/*   Updated: 2023/08/26 11:13:48 by glaurich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int		ft_str_len(char *tab);
int		ft_parsing(char *str, char *tab);
void	calculate_views_rows(char *board, char *views, int size_board, int *j);
void	calculate_views_rows_rev(char *board, char *views, int size, int *j);
void	calculate_views_collums(char *board, char *views, int size, int *j);
void	calculate_views_collums_rev(char *board, char *views, int size, int *j);
int		does_board_respect_views(char *tab_board, char *tab_views);
int		does_board_respect_base_rules(char *board);
int		is_board_correct(char *board, char *tab_views);
char	get_a_row(int i);
char	**list_all_row(char **list);
char	*mk_board(char *l1, char *l2, char *l3, char *l4);
int		generate_all_boards(int *ind, char **l, char *brd, char *tab_views);
void	show_board(char *board);
void	free_list(char **list);

int	main(int argc, char **argv)
{
	char	*tab_views;
	char	**list;
	char	*board;
	int		*indices;

	tab_views = (char *)malloc(16 * sizeof(char));
	if (argc == 2 && ft_parsing(argv[1], tab_views) == 0)
	{
		list = (char **)malloc(24 * sizeof(char *));
		list_all_row(list);
		indices = (int *)malloc(4 * sizeof(int));
		board = (char *)malloc(16 * sizeof(char));
		if (generate_all_boards(indices, list, board, tab_views) == 0)
			write(2, "Error\n", 6);
		free_list(list);
		free(indices);
		free(board);
	}
	else
		write(2, "Error\n", 6);
	free(tab_views);
}
