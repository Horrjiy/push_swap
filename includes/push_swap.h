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
	int				*arglist;
}					t_data;

t_list				*ft_init_a(int argc, char *argv[], t_list *a);
int					*ft_argv_convert(int argc, char *argv[]);

#endif