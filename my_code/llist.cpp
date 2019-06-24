#include <iostream>
#include "llist.h"

using namespace std;



/*
 * Output a Node pointer.
 * */
ostream& operator<<(ostream& os, const Node* nd) {
	if (nd) os << nd->data;
    return os;
}


/*
 * Add a node to the end of a list.
 * */
void add_at_end(Node*& head, int d) {
	if (!head) {
		head = new Node(d);
	}
	else {
		Node* temp = head;
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = new Node(d);
	}
}


/*
 * Given the head of a list, print the whole thing.
 * Let's do this recursively!
 * */
void print_list(ostream& os, const Node* curr) {
	if (curr) {
		os << curr << " ";
		if (curr->next) print_list(os, curr->next);
	}
}

/*
 * Add a node at the front of a linked list.
 * */
void add_at_front(Node*& head, int d) {
	Node* temp = new Node(head->data, head->next);
	head->next = temp;
	head->data = d;
}


/*
 * Get the last node of a list.
 * */
Node* last(Node* head) {
	Node* curr = head;
	while (curr->next->next) curr = curr->next;
	return curr->next;
}

/*
 * Delete the first node and attach head to the 2nd node:
 * */
bool del_head(Node*& head) {
	Node* temp = head;
	head = head->next;
	delete temp;
	return true;
}

/*
 * Delete the last node and set prev->next to nullptr:
 * */
bool del_tail(Node*& head) {
	Node* curr = head;
	Node* prev = head;
	if (curr->next) {
		curr = curr->next;
	}
	else head = nullptr;
	while (curr->next) {
		curr = curr->next;
		prev = prev->next;
	}
	prev->next = nullptr;
	delete curr;
	return true;
}

/*
 * Duplicate the entire list -- you must not share memory!
 * */
Node* duplicate(Node* head) {
	Node* newNode = new Node(head->data);
	if (head->next) {
		newNode->next = duplicate(head->next);
	}
	return newNode;
}

/*
 * Reverse the list: return a brand new list with everything reversed.
 * */

Node* reverse(Node* curr, Node* new_next = nullptr) {
	if (!curr->next) {
		if (new_next) {
			Node* newNode = new Node(curr->data, new_next);
			return newNode;
		}
		else return new Node(curr->data);
	}
	else {
		Node* newNode = new Node(curr->data);
		if (new_next) newNode->next = new_next;
		return reverse(curr->next, newNode);
	}
}

/*
 * Join two lists: tack list 2 onto the end of list 1:
 * Use existing memory.
 * */
Node* join(Node*& list1, Node* list2) {
	Node* iter = list1;
	while (iter->next) {
		iter = iter->next;
	}
	iter->next = list2;
	return list1;
}
