#pragma once

template<class T>
class Node {
public:
	T data;
	Node* next;
	Node* prev;
	Node() :data(), next(), prev() {}
	Node(const T _data) :data(_data), next(), prev() {}
};

template<class T>
class DoubleLinkedList {
private:
	Node<T>* _head;
	Node<T>* _end;

public:
	DoubleLinkedList() : _head(), _end() {}

	void AddBegin(const T data);

	void AddEnd(const T data);

	void AddBegin(Node<T>* item);

	void AddEnd(Node<T>* item);

	void AddBefore(const T beforeItem, const T newItem);

	//void AddAfter(const string afterItem, const string newItem);
	void AddAfter(const T afterItem, const T newItem);

	void DeleteBegin();

	void DeleteEnd();

	//void DeleteVByValue(const string item);
	void DeleteVByValue(const T item);

	void DisplayFront();

	void DisplayEnd();
};

template<class T>
void DoubleLinkedList<T>::AddBegin(const T data) {
	AddBegin(new Node<T>(data));
}

template<class T>
void DoubleLinkedList<T>::AddEnd(const T data) {
	AddEnd(new Node<T>(data));
}

template<class T>
void DoubleLinkedList<T>::AddBegin(Node<T>* item) {
	if (_head == NULL) {
		_head = item;
		_end = item;
		return;
	}

	Node<T>* temp = _head;
	_head = item;
	_head->next = temp;
	temp->prev = _head;
}

template<class T>
void DoubleLinkedList<T>::AddEnd(Node<T>* item) {
	if (_head == NULL) {
		_head = item;
		_end = item;
		return;
	}

	_end->next = item;
	item->prev = _end;
	_end = item;
}

template<class T>
void DoubleLinkedList<T>::AddBefore(const T beforeItem, const T newItem) {
	Node<T>* newNode = new Node<T>(newItem);
	if (_head == NULL) {
		_head = newNode;
		_end = newNode;
		return;
	}

	Node<T>* temp = _head;
	while (temp != NULL) {
		if (temp->data == beforeItem) {
			if (temp == _head) {
				AddBegin(newNode);
			}
			else {
				Node<T>* save = temp->prev;
				temp->prev = newNode;
				newNode->prev = save;
				save->next = newNode;
				newNode->next = temp;
			}
			return;
		}
		temp = temp->next;
	}
}

//void AddAfter(const string afterItem, const string newItem);
template<class T>
void DoubleLinkedList<T>::AddAfter(const T afterItem, const T newItem) {
	Node<T>* newNode = new Node<T>(newItem);
	if (_head == NULL) {
		_head = newNode;
		_end = newNode;
		return;
	}

	Node<T>* temp = _head;
	while (temp != NULL) {
		if (temp->data == afterItem) {
			if (temp == _end) {
				AddEnd(newNode);
			}
			else {
				newNode->next = temp->next;
				newNode->prev = temp;
				temp->next->prev = newNode;
				temp->next = newNode;
			}
			return;
		}
		temp = temp->next;
	}
}

template<class T>
void DoubleLinkedList<T>::DeleteBegin() {
	if (_head == NULL)
		return;

	Node<T>* temp = _head;
	_head = _head->next;

	delete temp;
	_head->prev = NULL;
}

template<class T>
void DoubleLinkedList<T>::DeleteEnd() {
	if (_head == NULL)
		return;
	_end = _end->prev;
	delete _end->next;
	_end->next = NULL;
}

//void DeleteVByValue(const string item);
template<class T>
void DoubleLinkedList<T>::DeleteVByValue(const T item) {
	if (_head == NULL)
		return;

	Node<T>* temp = _head;
	while (temp != NULL) {
		if (temp->data == item) {
			if (temp == _head) {
				DeleteBegin();
			}
			else if (temp == _end) {
				DeleteEnd();
			}
			else {
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
				delete temp;
			}
			return;
		}
		temp = temp->next;
	}
}

template<class T>
void DoubleLinkedList<T>::DisplayFront() {
	Node<T>* temp = _head;
	cout << "[ ";
	while (temp->next != NULL) {
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout << temp->data << " ]" << endl;
}

template<class T>
void DoubleLinkedList<T>::DisplayEnd() {
	Node<T>* temp = _end;
	cout << "[ ";
	while (temp->prev != NULL) {
		cout << temp->data << ", ";
		temp = temp->prev;
	}
	cout << temp->data << " ]" << endl;
}
