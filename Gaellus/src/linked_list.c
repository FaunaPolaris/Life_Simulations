#include "life.h"

s_list	new_node(organism content)
{
	s_list	node;

	node = (s_list)malloc(sizeof(s_list));
	node->inhabitant = content;
	node->next = NULL;
	node->prev = NULL;
	node.index = 0;
	return (node);
}

void	add_node(s_list node, s_list back)
{
	back->next = node;
	node->prev = back;
	node.index = back.index + 1;
}

