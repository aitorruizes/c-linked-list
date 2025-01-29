#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

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
 * \brief A structure representing a node in a singly linked list.
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
 * \struct SinglyLinkedList
 * \brief A structure representing a singly linked list.
 *
 * This structure represents a singly singly linked list with a pointer to the head node, a pointer to the tail node, and function pointers for specific operations on the data.
 * The list can store data of any type, and operations like printing, freeing, and comparing data can be customized by providing the appropriate function pointers.
 */
typedef struct SinglyLinkedList
{
  Node *head_node;                           /**< Pointer to the first node in the list. */
  Node *tail_node;                           /**< Pointer to the last node in the list. */
  PrintDataFunction print_data_function;     /**< Function pointer for printing node data. */
  FreeDataFunction free_data_function;       /**< Function pointer for freeing node data. */
  CompareDataFunction compare_data_function; /**< Function pointer for comparing node data. */
} SinglyLinkedList;

/**
 * \brief Creates a new singly linked list with the provided function pointers.
 *
 * This function allocates memory for a new `SinglyLinkedList` structure, initializes its fields,
 * and sets the function pointers for printing, freeing, and comparing node data. It performs
 * checks to ensure that none of the function pointers are NULL, and if any are, an error
 * message is printed and the function returns `NULL`. If memory allocation for the singly linked list
 * fails, an error message is also printed.
 *
 * \param print_data_function A function pointer used to print the data of a node.
 * \param free_data_function A function pointer used to free the data of a node.
 * \param compare_data_function A function pointer used to compare the data of two nodes.
 *
 * \return A pointer to the newly created `SinglyLinkedList` if successful, or `NULL` if an error occurs.
 */
SinglyLinkedList *create_singly_linked_list(PrintDataFunction print_data_function, FreeDataFunction free_data_function, CompareDataFunction compare_data_function);

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

/**
 * \brief Inserts a new node at the head of the singly linked list.
 *
 * This function creates a new node using the provided `node_data` and inserts it at the head
 * of the singly linked list. If the singly linked list is empty (i.e., `head_node` is `NULL`), the new node
 * becomes both the head and the tail of the list. If the list already has nodes, the new node
 * is inserted at the front, and the previous head becomes the second node. The function also
 * checks if the node creation fails and prints an error message if necessary.
 *
 * \param singly_linked_list A pointer to the `SinglyLinkedList` where the node will be inserted.
 * \param node_data The data to be stored in the new node. This cannot be `NULL`.
 */
void insert_node_at_head(SinglyLinkedList *singly_linked_list, NodeData node_data);

/**
 * \brief Inserts a new node at the tail of the singly linked list.
 *
 * This function creates a new node using the provided `node_data` and inserts it at the
 * tail of the singly linked list. If the list is empty (i.e., `head_node` is `NULL`), the new node
 * becomes both the head and the tail of the list. If the list already has nodes, the new node
 * is added after the current tail. The function also checks if the node creation fails and
 * prints an error message if necessary.
 *
 * \param singly_linked_list A pointer to the `SinglyLinkedList` where the node will be inserted.
 * \param node_data The data to be stored in the new node. This cannot be `NULL`.
 */
void insert_node_at_tail(SinglyLinkedList *singly_linked_list, NodeData node_data);

/**
 * \brief Prints all the nodes in the singly linked list.
 *
 * This function iterates through the entire singly linked list starting from the head node and
 * prints the data stored in each node using the `print_data_function` provided during
 * the creation of the singly linked list. The function continues until it reaches the end of the list,
 * where the `next_node` is `NULL`.
 *
 * \param singly_linked_list A pointer to the `SinglyLinkedList` to be printed.
 */
void print_singly_linked_list(SinglyLinkedList *singly_linked_list);

/**
 * \brief Frees all the nodes in the singly linked list and releases the memory.
 *
 * This function iterates through the singly linked list, starting from the head node, and frees
 * each node’s data using the `free_data_function` provided during the creation of the singly linked list.
 * After freeing the node’s data, it frees the memory allocated for the node itself. The function
 * continues until all nodes are freed. Afterward, it sets the `head_node` and `tail_node` of the
 * singly linked list to `NULL` to indicate that the list is empty.
 *
 * \param singly_linked_list A pointer to the `SinglyLinkedList` to be freed.
 */
void free_singly_linked_list(SinglyLinkedList *singly_linked_list);

/**
 * \brief Returns the length of the singly linked list.
 *
 * This function iterates through the singly linked list starting from the head node and counts
 * the number of nodes until it reaches the end of the list (i.e., when `current_node` becomes `NULL`).
 * It returns the total count of nodes in the list. If the list is empty (i.e., the `head_node` is `NULL`),
 * it returns 0.
 *
 * \param singly_linked_list A pointer to the `SinglyLinkedList` whose length is to be calculated.
 *
 * \return The number of nodes in the singly linked list.
 */
int get_linked_list_length(SinglyLinkedList *singly_linked_list);

/**
 * \brief Reverses the order of elements in a singly linked list.
 *
 * This function reverses the `next_node` pointers of each node in a singly linked list,
 * making the first node become the last, the second node become the second-to-last, and so on.
 * It also updates the `head_node` pointer of the singly linked list to point to the new first node after reversal.
 *
 * \param singly_linked_list Pointer to the singly linked list to be reversed.
 */
void reverse_singly_linked_list(SinglyLinkedList *singly_linked_list);

/**
 * \brief Searches for a node in the singly linked list by its data.
 *
 * This function iterates through the singly linked list and compares the data of each node
 * with the provided `node_data`. If a node with matching data is found, the function
 * returns a pointer to that node. If no match is found or the list is empty, it returns `NULL`.
 *
 * \param singly_linked_list A pointer to the singly linked list to search in.
 * \param node_data The data to search for in the singly linked list.
 *
 * \return A pointer to the node containing the matching data, or `NULL` if no node is found.
 */
Node *find_node_by_data(SinglyLinkedList *singly_linked_list, NodeData node_data);

/**
 * \brief Checks if a singly linked list is valid.
 *
 * This function checks whether the provided singly linked list pointer is not NULL.
 * It is a simple validation function to ensure the singly linked list is properly
 * allocated before performing any further operations on it.
 *
 * \param singly_linked_list A pointer to the singly linked list to be checked.
 *
 * \return true if the singly linked list is not NULL, false otherwise.
 */
bool is_valid_singly_linked_list(SinglyLinkedList *singly_linked_list);

#endif
