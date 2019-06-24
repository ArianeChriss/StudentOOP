#ifndef LINKED_H
#define LINKED_H

#include <iostream>


/*
 * The struct `Node`, which is the building block of our linked list code.
 * */
struct Node {
    Node(int d, Node* n=nullptr) : data(d), next(n) {}
    int data;
    Node* next;
};


/*
 * The various functions that can operate on our linked lists:
 * */
std::ostream& operator<<(std::ostream& os, const Node* nd);
void print_list(std::ostream& os, const Node* curr);
Node* last(Node* head);
void add_at_end(Node*& head, int d);
void add_at_front(Node*& head, int d);

/*
 * These are coming:
bool del_head(Node*& head);
bool del_tail(Node** prev_next);
Node* duplicate(Node* head);
Node* reverse(Node* curr, Node* prev=nullptr);
*/

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head);

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& head);

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head);

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */
Node* reverse(Node* curr, Node* new_next);

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2);


#endif
