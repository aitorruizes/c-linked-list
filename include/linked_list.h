#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef void *NodeData;
typedef void (*PrintDataFunction)(NodeData);
typedef void (*FreeDataFunction)(NodeData);
typedef bool (*CompareDataFunction)(NodeData, NodeData);

typedef struct Node
{
  NodeData node_data;
  struct Node *next_node;
} Node;

typedef struct LinkedList
{
  Node *head_node;
  Node *tail_node;
  PrintDataFunction print_data_function;
  FreeDataFunction free_data_function;
  CompareDataFunction compare_data_function;
} LinkedList;

LinkedList *create_linked_list(PrintDataFunction print_data_function, FreeDataFunction free_data_function, CompareDataFunction compare_data_function);
Node *create_node(NodeData node_data);
void insert_node_at_head(LinkedList *linked_list, NodeData node_data);
void print_linked_list(LinkedList *linked_list);

#endif
