#include "sort.h"
/**
 * swap_nodes - Swaps the positions of two nodes in a doubly linked list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped.
 *
 * This function swaps the positions of node1 and node2 in the doublylinkedlist
 * by adjusting the pointers of adjacent nodes. It updates the head of
 * the list if the swapped nodes include the head.
 */

void swap_nodes(listint_t *node1, listint_t *node2)
{
	int tmp;

	tmp = node1->n;

	node1->n = node2->n;
	node2->n = tmp;
}
/**
 * insertion_sort_list - Sorts a doubly linked list in ascending
 * order using Insertion Sort.
 * @list: Address of the head of the list.
 *
 * This function implements the Insertion Sort algorithm to arrange elements
 * of the doubly linked list in ascending order.
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL)
		return;
	
	listint_t *current;
	listint_t *insert_node;
	
	while ((*list)->prev != NULL)
	{
		*list = (*list)->prev;
	}

	current = (*list);

	while (current != NULL)
	{
		insert_node = current;
		while (insert_node->prev != NULL && insert_node->prev->n > insert_node->n)
		{
			swap_nodes(insert_node, insert_node->prev);
			print_list(*list);
			insert_node = insert_node->prev;
		}
		current = current->next;
	}
}

/**
 * add_node - Adds a node with specified value to the end of doubly linked list
 * @list: Address of the head of the list.
 * @value: Value to be added to the new node.
 *
 * This function creates a node with the given value and appends it to the end
 * the doubly linked list. It updates the head of the list if it is
 * initially empty.
 */
void add_node(listint_t **list, int value)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*list == NULL)
	{
		*list = new_node;
	}
	else
	{
		listint_t *temp = *list;

		while (temp->next != NULL)
		{
			temp = temp->next;
		}

		temp->next = new_node;
		new_node->prev = temp;
	}
}

