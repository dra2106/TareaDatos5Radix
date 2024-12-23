#pragma once

#include <stdexcept>
#include <iostream>
#include "List.h"
#include "Node.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class LinkedList : public List<E> {
private:
	Node<E>* head;
	Node<E>* tail;
	Node<E>* current;
	int size;

public:
	LinkedList() {
		current = head = tail = new Node<E>();
		size = 0;
	}
	~LinkedList() {
		clear();
		delete head;
	}
	void insert(E element) {
		current->next = new Node<E>(element, current->next);
		if (current == tail)
			tail = tail->next;
		size++;
	}
	void append(E element) {
		tail = tail->next = new Node<E>(element);
		size++;
	}
	E remove() {
		if (size == 0)
			throw runtime_error("List is empty");
		if (current == tail)
			throw runtime_error("No current element.");
		E result = current->next->element;
		Node<E>* temp = current->next;
		if (current->next == tail)
			tail = current;
		current->next = temp->next;
		delete temp;
		size--;
		return result;
	}
	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty");
		if (current == tail)
			throw runtime_error("No current element.");
		return current->next->element;
	}
	void clear() {
		while (head->next != nullptr) {
			current = head->next;
			head->next = current->next;
			delete current;
		}
		current = tail = head;
		size = 0;
	}
	void goToStart() {
		current = head;
	}
	void goToEnd() {
		current = tail;
	}
	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds.");
		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
	}
	void next() {
		if (current != tail)
			current = current->next;
	}
	void previous() {
		if (current != head) {
			Node<E>* temp = head;
			while (temp->next != current) 
				temp = temp->next;
			current = temp;
		}
	}
	bool atStart() {
		return current == head;
	}
	bool atEnd() {
		return current == tail;
	}
	int getPos() {
		int pos = 0;
		Node<E>* temp = head;
		while (temp != current) {
			temp = temp->next;
			pos++;
		}
		return pos;
	}
	int getSize() {
		return size;
	}
	void print() {
		cout << "[ ";
		Node<E>* temp = head->next;
		while (temp != nullptr) {
			if (temp == current->next)
				cout << "*";
			cout << temp->element << " ";
			temp = temp->next;
		}
		if (current == tail)
			cout << "*";
		cout << "]" << endl;
	}
	E getMax() {
		if (size == 0)
			throw runtime_error("List is empty");

		goToStart();
		E maxVal = getElement();
		next();

		while (!atEnd()) {
			E currentElement = getElement();
			if (currentElement > maxVal) {
				maxVal = currentElement;
			}
			next();
		}
		return maxVal;
	}

};




