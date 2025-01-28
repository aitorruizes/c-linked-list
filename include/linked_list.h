#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef void *NodeData;

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

#endif
