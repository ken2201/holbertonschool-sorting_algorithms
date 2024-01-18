#include "sort.h"
/**
 * swap_nodes - Swaps the positions of two nodes in a doubly linked list.
 * @list: Address of the head of the list.
 * @node1: First node to be swapped.
 * @node2: Second node to be swapped.
 *
 * This function swaps the positions of node1 and node2 in the doublylinkedlist
 * by adjusting the pointers of adjacent nodes. It updates the head of
 * the list if the swapped nodes include the head.
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node1->prev = node2;
	node2->next = node1;
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
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	listint_t *current;
	listint_t *insert_node;
	listint_t *prev;
	listint_t *temp;
	
	current = (*list)->next;

	while (current != NULL)
	{
		insert_node = current;
		prev = current->prev;

		while (prev != NULL && insert_node->n < prev->n)
		{
			swap_nodes(list, insert_node, prev);

			temp = *list;

			while (temp != NULL)
			{
				printf("%d", temp->n);
				if (temp->next != NULL)
					printf(" <-> ");
				temp = temp->next;
			}
			printf("\n");
			prev = insert_node->prev;
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

