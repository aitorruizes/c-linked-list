#include <stdio.h>
#include <stdlib.h>

#include "../include/linked_list.h"

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

void insert_node_at_head(LinkedList *linked_list, NodeData node_data)
{
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

void print_linked_list(LinkedList *linked_list)
{
  Node *current_node = linked_list->head_node;

  while (current_node != NULL)
  {
    linked_list->print_data_function(current_node->node_data);

    current_node = current_node->next_node;
  }
}

void free_linked_list(LinkedList *linked_list)
{
  if (linked_list == NULL)
  {
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
