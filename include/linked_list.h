#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

/**
 * \typedef void* NodeData
 * \brief A generic type to represent data that can be stored in a node.
 *
 * This typedef allows storing any type of data in a node, as it is a pointer to void. The data can be of any type, and specific operations on the data should be provided by function pointers.
 */
typedef void *NodeData;

/**
 * \typedef void (*PrintDataFunction)(NodeData)
 * \brief A function pointer type for a function that prints the data of a node.
 *
 * This typedef represents a function pointer for a function that takes `NodeData` as an argument and returns nothing (`void`).
 * This function is used for printing the contents of the data stored in a node.
 */
typedef void (*PrintDataFunction)(NodeData);

/**
 * \typedef void (*FreeDataFunction)(NodeData)
 * \brief A function pointer type for a function that frees the data of a node.
 *
 * This typedef represents a function pointer for a function that takes `NodeData` as an argument and returns nothing (`void`).
 * This function is used for freeing the memory allocated for the data stored in a node.
 */
typedef void (*FreeDataFunction)(NodeData);

/**
 * \typedef bool (*CompareDataFunction)(NodeData, NodeData)
 * \brief A function pointer type for a function that compares two pieces of node data.
 *
 * This typedef represents a function pointer for a function that takes two `NodeData` pointers as arguments and returns a boolean value (`true` or `false`) based on the comparison of the two data elements.
 */
typedef bool (*CompareDataFunction)(NodeData, NodeData);

/**
 * \struct Node
 * \brief A structure representing a node in a linked list.
 *
 * This structure contains the data of the node and a pointer to the next node in the list.
 * The `node_data` field can hold any type of data, and the `next_node` points to the next node in the list, or `NULL` if there is no next node.
 */
typedef struct Node
{
  NodeData node_data;     /**< Pointer to the data stored in the node. */
  struct Node *next_node; /**< Pointer to the next node in the list. */
} Node;

/**
 * \struct LinkedList
 * \brief A structure representing a linked list.
 *
 * This structure represents a singly linked list with a pointer to the head node, a pointer to the tail node, and function pointers for specific operations on the data.
 * The list can store data of any type, and operations like printing, freeing, and comparing data can be customized by providing the appropriate function pointers.
 */
typedef struct LinkedList
{
  Node *head_node;                           /**< Pointer to the first node in the list. */
  Node *tail_node;                           /**< Pointer to the last node in the list. */
  PrintDataFunction print_data_function;     /**< Function pointer for printing node data. */
  FreeDataFunction free_data_function;       /**< Function pointer for freeing node data. */
  CompareDataFunction compare_data_function; /**< Function pointer for comparing node data. */
} LinkedList;

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
LinkedList *create_linked_list(PrintDataFunction print_data_function, FreeDataFunction free_data_function, CompareDataFunction compare_data_function);

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
Node *create_node(NodeData node_data);

void insert_node_at_head(LinkedList *linked_list, NodeData node_data);
void insert_node_at_tail(LinkedList *linked_list, NodeData node_data);
void print_linked_list(LinkedList *linked_list);
void free_linked_list(LinkedList *linked_list);
int get_linked_list_length(LinkedList *linked_list);

#endif
