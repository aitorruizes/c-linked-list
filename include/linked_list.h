#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef void *NodeData;
typedef void (*PrintDataFunction)(NodeData *);
typedef void (*FreeDataFunction)(NodeData *);
typedef void (*CompareDataFunction)(NodeData *, NodeData *);

typedef struct Node
{
  NodeData node_data;
  struct Node *next_node;
} Node;

typedef struct LinkedList
{
  Node *head_node;
  Node *tail_node;
  void (*print_data_function)(NodeData *);
  void (*free_data_function)(NodeData *);
  void (*compare_data_function)(NodeData *, NodeData *);
} LinkedList;

LinkedList *create_linked_list(PrintDataFunction print_data_function, FreeDataFunction free_data_function, CompareDataFunction compare_data_function);
Node *create_node(NodeData node_data);

#endif
