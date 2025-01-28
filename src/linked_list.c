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
