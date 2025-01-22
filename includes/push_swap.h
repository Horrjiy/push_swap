#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	int				*dup_check;
	int				*arglist;
	char			**source;
}					t_data;

void				ft_error(t_data *data, t_list *a);
void				free_data(t_data *data);
void				ft_arg_convert(int argc, char *argv[], t_data *data);
t_list				*ft_init_node(int i, t_data *data, t_list *a);
int					ft_listlen(t_list *a);
t_list				*ft_lastnode(t_list *a);
t_list				*ft_secondlastnode(t_list *a);
void				ft_node_addback(t_list **a, t_list *node);
void				ft_sa(t_list **a);
void				ft_sb(t_list **b);
void				ft_ss(t_list **a, t_list **b);
void				ft_pa(t_list **a, t_list **b);
void				ft_pb(t_list **a, t_list **b);
void				ft_ra(t_list **a);
void				ft_rb(t_list **b);
void				ft_ss(t_list **a, t_list **b);
void				ft_ra(t_list **a);
void				ft_rra(t_list **a);
void				ft_rrb(t_list **b);
void				ft_rrr(t_list **a, t_list **b);

#endif
