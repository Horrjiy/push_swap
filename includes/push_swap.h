#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*back;
}					t_list;

typedef struct s_data
{
	int				*dup_check;
	int				*arglist;
}					t_data;

void				ft_error(t_data *data, t_list *a);
void				free_data(t_data *data);
void				ft_arg_convert(int argc, char *argv[], t_data *data);
t_list				*ft_init_node(int i, t_data *data, t_list *a);
int					ft_listlen(t_list *a);
t_list				*ft_lastnode(t_list *a);
void				ft_node_addback(t_list **a, t_list *node);
void				ft_sa_sb(t_list *list, int operation);

#endif