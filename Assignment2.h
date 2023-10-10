#pragma once

#include <iostream>

template<class T> 
struct Node // holds data and stores pointer to next node
{
	T data;
	Node<T>* next;

	Node(T data, Node<T>* next);

};

template<class T> 
class Single_Linked_List {
public:
	Single_Linked_List(); 
	~Single_Linked_List() {    // deconstructor that clears the variables and deletes every entry in the list
		if (empty()) {
			return;
		}
		while (!empty()) {     
			Node<T>* temp = head;
			head = head->next;
			temp->next = nullptr;
			delete temp;
			temp = nullptr;
			num_items--;
		}
	}
	void push_front(T data);
	void push_back(T data);
	void pop_front();
	void pop_back();
	T front();
	T back();
	bool empty();
	void insert(size_t index, const T& item);
	bool remove(size_t index);
	size_t find(const T& item);

	int size();
	
	void print();
private:
	Node<T>* head; // decalres head pointer
	Node<T>* tail; // declares tail pointer
	int num_items; // declares num_items variable
};



template<class T>
inline Node<T>::Node(T data, Node<T>* next) // constructor for node
{
	this->data = data;
	this->next = next;
}

template<class T>
inline bool Single_Linked_List<T>::empty() // checks if list is empty
{
	return num_items == 0;   // returns boolean value if the num_items is equal to 0
}

template<class T>
inline void Single_Linked_List<T>::insert(size_t index, const T& item) // inserts a value at given index
{
	
	if (index > num_items || index < 0) { // checks if index is in bounds
		return;
	}

	if (index == 0) { // adds value at start of list
		push_front(item);
		return;
	}
	if (index == num_items) { // adds value at end of list
		push_back(item);
		return;
	}

	else {
		Node<T>* curr = head; // sets head equal to curr pointer
		for (int i = 0; i < index - 1; i++) { // loops through to find the node right before the target node
			curr = curr->next;         
		}
		Node<T>* temp = new Node<T>(item, curr->next);  // creates new temp pointer and equals it to ??
		curr->next = temp; // sets temp equal to the value after curr
		num_items++; // increases num_items by one
	}
	

}

template<class T>
inline bool Single_Linked_List<T>::remove(size_t index) // removes value at given index
{
	if (index >= num_items || index < 0) { // checks if index is in bounds
		return false;
	}

	if (index == 0) { // deletes first value if index is 0
		pop_front();
		return true;
	}
	if (index == num_items - 1) { // deletes last value 
		pop_back();
		return true;
	}

	Node<T>* curr = head; 
	for (int i = 0; i < index - 1; i++) { // loops through to find the node right before the target node
		curr = curr->next;
	}
	Node<T>* temp = curr->next; //  make current nodes next pointer the node that comes after the node to be deleted
	curr->next = temp->next;
	temp->next = nullptr;
	delete temp;
	temp = nullptr;
	num_items--;
	return true;
}

template<class T>
inline size_t Single_Linked_List<T>::find(const T& item)
{
	if (empty()) {
		return 0;
	}

	Node<T>* curr = head;
	int i = 0;
	while (curr != nullptr) {      // loops through list
		if (curr->data == item) {   // returns index where the data value is equal to passed item
			return i;
		}
		i++;
		curr = curr->next;
	}
	return i;
}

template<class T>
inline int Single_Linked_List<T>::size()
{
	return num_items; 
}

template<class T>
inline void Single_Linked_List<T>::print() // prints values to display output
{
	Node<T>* temp = head;
	if (temp == nullptr) {
		std::cout << "List is empty";
		return;
	}
	while (temp != nullptr) {
		std::cout << temp->data << " -> ";
		temp = temp->next;
	}
}

template<class T>
inline Single_Linked_List<T>::Single_Linked_List() // constructor that initializes the values
{
	num_items = 0;
	head = nullptr;
	tail = nullptr;
}

template<class T>
inline void Single_Linked_List<T>::push_front(T data)
{
	if (empty()) {
		head = new Node<T>(data, nullptr); // inserts new node if list is empty
		tail = head;
	}
	else {
		Node<T>* temp = new Node<T>(data, head); // sets temp equal to new value and head equal to temp
		head = temp;
		temp = nullptr; // deletes temp
	}
	num_items++;
}

template<class T>
inline void Single_Linked_List<T>::push_back(T data)
{
	if (empty()) {
		push_front(data); // adds value if list is empty
	}
	else { 
		(tail->next) = new Node<T>(data, nullptr); // creates new node and adds at end
		tail = tail->next; // sets tail equal to new value
		num_items++;
	}
}
template<class T>
inline void Single_Linked_List<T>::pop_front() // deletes the first item
{
	if (empty()) { // checks if list is empty and returns
		return;
	}
	else if (num_items == 1) { // if list only has one value, delete it and set head and tail to nullptr
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<T>* temp = head; // creates temp variable and sets it equal to head
		head = head->next; // sets head equal to the next variable
		temp->next = nullptr; // temp points to nothing
		delete temp; 
		temp = nullptr; // temp equals nullptr
	}
	num_items--;
}

template<class T>
inline void Single_Linked_List<T>::pop_back() // deletes the last item
{
	if (empty()) {
		return;
	}
	else if (num_items == 1) { // if list only have one value, calls pop_front function to delete it
		pop_front();
	}
	else {
		Node<T>* temp = head; 
		while (temp->next != tail) { // finds value one before the last
			temp = temp->next;
		}
		tail = temp; // deletes last value and points tail to nullptr
		delete tail->next;
		tail->next = nullptr;
		num_items--;
	}
}

template<class T>
inline T Single_Linked_List<T>::front() // returns first data value
{
	if (empty()) {
		return NULL;
	}
	return head->data;
}

template<class T>
inline T Single_Linked_List<T>::back() // returns last data value
{
	if (empty()) {
		return NULL;
	}
	return tail->data;
}

