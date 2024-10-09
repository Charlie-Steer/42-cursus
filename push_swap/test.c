#include "stdio.h"

struct s_node {
	struct s_node	*next_node;
	int				*number;
	int				*position;
	int				*ordered_position;
	int				*target_position;
	int				*a_surface_cost;
	int				*b_surface_cost;
	int				*total_cost;
	int				test;
} t_node;

int main()
{
	printf("%lu\n", sizeof(t_node));
	printf("%lu\n", sizeof(struct s_node*));
}