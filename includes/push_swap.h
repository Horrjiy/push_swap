/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoplow <mpoplow@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 12:55:29 by mpoplow           #+#    #+#             */
/*   Updated: 2025/02/14 15:50:25 by mpoplow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_list
{
	long			num;
	int				pushcost;
	struct s_list	*next;
	struct s_list	*target;
}					t_list;

typedef struct s_data
{
	char			**source;
	int				numbers_counts;
	bool			split_used;
	int				smallest_num;
	int				smallest_pos;
	int				largest_num;
	int				largest_pos;
	int				cheap_a;
	int				cheap_b;
	bool			a_up;
	bool			b_up;
}					t_data;

/**/
////	initialization functions
/**/
void				ft_arg_convert(int argc, char *argv[], t_data *data,
						t_list **a);
t_list				*ft_init_node(int i, t_data *data, t_list *a);
int					ft_find_position(t_list *node, int i);
int					ft_listlen(t_list *a);
t_list				*ft_lastnode(t_list *a);
t_list				*ft_secondlastnode(t_list *a);
void				ft_node_addback(t_list **a, t_list *node);

/**/
////	algorythm functions
/**/
void				ft_sort_3(t_list **a, t_data *data);
void				ft_sort_4(t_list **a, t_list **b, t_data *data);
void				ft_sort_5(t_list **a, t_list **b, t_data *data);
void				ft_turksort(t_list **a, t_list **b, t_data *data);
bool				ft_checksorted(t_list *a, t_list *b);
bool				ft_check_reverse_sorted(t_list *a, t_list *b);
void				ft_spot_numbers(t_list **nd, t_data *data);
void				ft_target_smallest(t_list **a, t_list **b, t_data *data);
void				ft_target_largest(t_list **a, t_list **b, t_data *data);
void				ft_calccost_to_b(t_list **a, t_list **b);
void				ft_calccost_to_a(t_list **a, t_list **b);
int					ft_cheapest_position(t_list *node);

/**/
////	operation functions
/**/
void				ft_sa(t_list **a);
void				ft_sb(t_list **b);
void				ft_ss(t_list **a, t_list **b);
void				ft_pa(t_list **a, t_list **b);
void				ft_pb(t_list **a, t_list **b);
void				ft_ra(t_list **a);
void				ft_rb(t_list **b);
void				ft_rr(t_list **a, t_list **b);
void				ft_rra(t_list **a);
void				ft_rrb(t_list **b);
void				ft_rrr(t_list **a, t_list **b);

/**/
//// error & free functions
/**/
void				ft_error(t_data *data, t_list *a);
void				ft_free_data(t_data *data);
void				ft_free_a(t_list **a);

// /**/
// ////	DEBUG
// /**/
// void				print_linked_list(t_list *a, char c);

#endif
