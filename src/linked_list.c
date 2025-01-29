#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

/**
 * \brief Creates a new linked list with the provided function pointers.
 *
 * This function allocates memory for a new `LinkedList` structure, initializes its fields,
 * and sets the function pointers for printing, freeing, and comparing node data. It performs
 * checks to ensure that none of the function pointers are NULL, and if any are, an error
 * message is printed and the function returns `NULL`. If memory allocation for the linked list
 * fails, an error message is also printed.
 *
 * \param print_data_function A function pointer used to print the data of a node.
 * \param free_data_function A function pointer used to free the data of a node.
 * \param compare_data_function A function pointer used to compare the data of two nodes.
 *
 * \return A pointer to the newly created `LinkedList` if successful, or `NULL` if an error occurs.
 */
LinkedList *create_linked_list(PrintDataFunction print_data_function, FreeDataFunction free_data_function, CompareDataFunction compare_data_function)
{
  if (print_data_function == NULL)
  {
    printf("[ERROR] 'print_data_function' cannot be NULL.\n");

    return NULL;
  }

  if (free_data_function == NULL)
  {
    printf("[ERROR] 'free_data_function' cannot be NULL.\n");

    return NULL;
  }

  if (compare_data_function == NULL)
  {
    printf("[ERROR] 'compare_data_function' cannot be NULL.\n");

    return NULL;
  }

  LinkedList *linked_list = (LinkedList *)malloc(sizeof(LinkedList));

  if (linked_list == NULL)
  {
    printf("[ERROR] Memory allocation failed for 'linked_list'.\n");

    return NULL;
  }

  linked_list->head_node = NULL;
  linked_list->tail_node = NULL;
  linked_list->print_data_function = print_data_function;
  linked_list->free_data_function = free_data_function;
  linked_list->compare_data_function = compare_data_function;

  return linked_list;
}

/**
 * \brief Creates a new node with the provided data.
 *
 * This function allocates memory for a new `Node` structure, sets its data to the provided
 * `node_data`, and initializes its `next_node` pointer to `NULL`. It checks if the `node_data`
 * is `NULL` before proceeding, and if so, prints an error message and returns `NULL`. It also
 * checks for memory allocation failure and prints an error message if allocation fails.
 *
 * \param node_data The data to be stored in the new node. This cannot be `NULL`.
 *
 * \return A pointer to the newly created `Node` if successful, or `NULL` if an error occurs.
 */
Node *create_node(NodeData node_data)
{
  if (node_data == NULL)
  {
    printf("[ERROR] You cannot create a new node with a NULL value.\n");

    return NULL;
  }

  Node *node = (Node *)malloc(sizeof(Node));

  if (node == NULL)
  {
    printf("[ERROR] Memory allocation failed for 'node'.\n");

    return NULL;
  }

  node->node_data = node_data;
  node->next_node = NULL;

  return node;
}

/**
 * \brief Inserts a new node at the head of the linked list.
 *
 * This function creates a new node using the provided `node_data` and inserts it at the head
 * of the linked list. If the linked list is empty (i.e., `head_node` is `NULL`), the new node
 * becomes both the head and the tail of the list. If the list already has nodes, the new node
 * is inserted at the front, and the previous head becomes the second node. The function also
 * checks if the node creation fails and prints an error message if necessary.
 *
 * \param linked_list A pointer to the `LinkedList` where the node will be inserted.
 * \param node_data The data to be stored in the new node. This cannot be `NULL`.
 */
void insert_node_at_head(LinkedList *linked_list, NodeData node_data)
{
  if (!is_valid_linked_list(linked_list))
  {
    printf("[ERROR] You cannot insert a node on a NULL linked list.\n");

    return;
  }

  Node *new_node = create_node(node_data);

  if (new_node == NULL)
  {
    printf("[ERROR] An error occurred while creating a new node.\n");
    return;
  }

  if (linked_list->head_node == NULL)
  {
    linked_list->head_node = new_node;
    linked_list->tail_node = new_node;
  }
  else
  {
    new_node->next_node = linked_list->head_node;
    linked_list->head_node = new_node;
  }
}

/**
 * \brief Inserts a new node at the tail of the linked list.
 *
 * This function creates a new node using the provided `node_data` and inserts it at the
 * tail of the linked list. If the list is empty (i.e., `head_node` is `NULL`), the new node
 * becomes both the head and the tail of the list. If the list already has nodes, the new node
 * is added after the current tail. The function also checks if the node creation fails and
 * prints an error message if necessary.
 *
 * \param linked_list A pointer to the `LinkedList` where the node will be inserted.
 * \param node_data The data to be stored in the new node. This cannot be `NULL`.
 */
void insert_node_at_tail(LinkedList *linked_list, NodeData node_data)
{
  if (!is_valid_linked_list(linked_list))
  {
    printf("[ERROR] You cannot insert a node on a NULL linked list.\n");

    return;
  }

  Node *new_node = create_node(node_data);

  if (new_node == NULL)
  {
    printf("[ERROR] An error occurred while creating a new node.\n");
    return;
  }

  if (linked_list->head_node == NULL)
  {
    linked_list->head_node = new_node;
    linked_list->tail_node = new_node;
  }
  else
  {
    linked_list->tail_node->next_node = new_node;
  }
}

/**
 * \brief Prints all the nodes in the linked list.
 *
 * This function iterates through the entire linked list starting from the head node and
 * prints the data stored in each node using the `print_data_function` provided during
 * the creation of the linked list. The function continues until it reaches the end of the list,
 * where the `next_node` is `NULL`.
 *
 * \param linked_list A pointer to the `LinkedList` to be printed.
 */
void print_linked_list(LinkedList *linked_list)
{
  if (!is_valid_linked_list(linked_list))
  {
    printf("[ERROR] You cannot print a NULL linked list.\n");

    return;
  }

  Node *current_node = linked_list->head_node;

  while (current_node != NULL)
  {
    linked_list->print_data_function(current_node->node_data);

    current_node = current_node->next_node;
  }
}

/**
 * \brief Frees all the nodes in the linked list and releases the memory.
 *
 * This function iterates through the linked list, starting from the head node, and frees
 * each node’s data using the `free_data_function` provided during the creation of the linked list.
 * After freeing the node’s data, it frees the memory allocated for the node itself. The function
 * continues until all nodes are freed. Afterward, it sets the `head_node` and `tail_node` of the
 * linked list to `NULL` to indicate that the list is empty.
 *
 * \param linked_list A pointer to the `LinkedList` to be freed.
 */
void free_linked_list(LinkedList *linked_list)
{
  if (!is_valid_linked_list(linked_list))
  {
    printf("[ERROR] You cannot free a NULL linked list.\n");

    return;
  }

  Node *current_node = linked_list->head_node;
  Node *next_node = NULL;

  while (current_node != NULL)
  {
    next_node = current_node->next_node;

    linked_list->free_data_function(current_node->node_data);

    free(current_node);

    current_node = next_node;
  }

  linked_list->head_node = NULL;
  linked_list->tail_node = NULL;
}

/**
 * \brief Returns the length of the linked list.
 *
 * This function iterates through the linked list starting from the head node and counts
 * the number of nodes until it reaches the end of the list (i.e., when `current_node` becomes `NULL`).
 * It returns the total count of nodes in the list. If the list is empty (i.e., the `head_node` is `NULL`),
 * it returns 0.
 *
 * \param linked_list A pointer to the `LinkedList` whose length is to be calculated.
 *
 * \return The number of nodes in the linked list.
 */
int get_linked_list_length(LinkedList *linked_list)
{
  int number_of_nodes = 0;

  if (!is_valid_linked_list(linked_list) || linked_list->head_node == NULL)
  {
    return number_of_nodes;
  }

  Node *current_node = linked_list->head_node;

  while (current_node != NULL)
  {
    current_node = current_node->next_node;

    number_of_nodes++;
  }

  return number_of_nodes;
}

/**
 * \brief Reverses the order of elements in a linked list.
 *
 * This function reverses the `next_node` pointers of each node in a linked list,
 * making the first node become the last, the second node become the second-to-last, and so on.
 * It also updates the `head_node` pointer of the linked list to point to the new first node after reversal.
 *
 * \param linked_list Pointer to the linked list to be reversed.
 */
void reverse_linked_list(LinkedList *linked_list)
{
  if (!is_valid_linked_list(linked_list))
  {
    printf("[ERROR] You cannot reverse a NULL linked list.\n");

    return;
  }

  if (linked_list->head_node == NULL)
  {
    printf("[ERROR] You cannot reverse an empty linked list.\n");

    return;
  }

  Node *previous_node = NULL;
  Node *current_node = linked_list->head_node;
  Node *next_node = NULL;

  while (current_node != NULL)
  {
    next_node = current_node->next_node;
    current_node->next_node = previous_node;
    previous_node = current_node;
    current_node = next_node;
  }

  linked_list->head_node = previous_node;
}

/**
 * \brief Searches for a node in the linked list by its data.
 *
 * This function iterates through the linked list and compares the data of each node
 * with the provided `node_data`. If a node with matching data is found, the function
 * returns a pointer to that node. If no match is found or the list is empty, it returns `NULL`.
 *
 * \param linked_list A pointer to the linked list to search in.
 * \param node_data The data to search for in the linked list.
 *
 * \return A pointer to the node containing the matching data, or `NULL` if no node is found.
 */
Node *find_node_by_data(LinkedList *linked_list, NodeData node_data)
{
  if (!is_valid_linked_list(linked_list))
  {
    printf("[ERROR] You cannot insert a node on a NULL linked list.\n");

    return NULL;
  }

  Node *current_node = linked_list->head_node;

  while (current_node != NULL)
  {
    if (linked_list->compare_data_function(current_node->node_data, node_data))
    {
      return current_node;
    }

    current_node = current_node->next_node;
  }

  return NULL;
}

bool is_valid_linked_list(LinkedList *linked_list)
{
  return linked_list != NULL;
}
