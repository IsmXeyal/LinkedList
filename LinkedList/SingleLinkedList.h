#pragma once

template<class T>
class Node {
public:
	T data;
	Node* next;
	Node() :data(), next() {}
	Node(const T _data) :data(_data), next() {}
};

template<class T>
class SingleLinkedList {
private:
	Node<T>* _head;

public:
	SingleLinkedList() :_head() {}

	// AddBegin(Node* item)
	void AddBegin(Node<T>* item);

	// AddBegin(string item)
	void AddBegin(T item);

	// AddEnd(Node* item)
	void AddEnd(Node<T>* item);

	// AddEnd(string item)
	void AddEnd(T item);

	// AddBefore(const Node* _item, string item)
	void AddBefore(Node<T>* _item, T item);

	// AddBefore(const Node* _item, Node* item)
	void AddBefore(Node<T>* _item, Node<T>* item);

	// AddAfter(const Node* _item, string item)
	void AddAfter(Node<T>* _item, T item);

	// AddAfter(const Node* _item, Node* item)
	void AddAfter(Node<T>* _item, Node<T>* item);

	// DeleteBegin()
	void DeleteBegin();

	// DeleteEnd()
	void DeleteEnd();

	// DeleteByValue(const string item)
	void DeleteByValue(const T item);

	// SearchValue(const string item)
	bool SearchValue(const T item);

	// display()  => cout overloading
	void display();
};

template<class T>
void SingleLinkedList<T>::AddBegin(Node<T>* item) {
	if (_head == NULL) {
		_head = item;
		return;
	}

	Node<T>* temp = _head;
	_head = item;
	_head->next = temp;
	temp = NULL;
}

template<class T>
void SingleLinkedList<T>::AddBegin(T item) {
	Node<T>* newNode = new Node<T>(item);

	if (_head == NULL) {
		_head = newNode;
		return;
	}

	newNode->next = _head;
	_head = newNode;
}

template<class T>
void SingleLinkedList<T>::AddEnd(Node<T>* item) {
	if (_head == NULL) {
		_head = item;
		return;
	}

	Node<T>* temp = _head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = item;
}

template<class T>
void SingleLinkedList<T>::AddEnd(T item) {
	Node<T>* newNode = new Node<T>(item);

	if (_head == NULL) {
		_head = newNode;
		return;
	}

	Node<T>* temp = _head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;
}

template<class T>
void SingleLinkedList<T>::AddBefore(Node<T>* _item, T item) {
	Node<T>* newNode = new Node<T>(item);

	if (_head == NULL)
		return;

	if (_item == _head) {
		AddBegin(item);
		return;
	}

	Node<T>* temp = _head;
	while (temp->next != NULL) {
		if (temp->next == _item) {
			temp->next = newNode;
			newNode->next = _item;
		}
		temp = temp->next;
	}
}

template<class T>
void SingleLinkedList<T>::AddBefore(Node<T>* _item, Node<T>* item) {
	if (_head == NULL)
		return;

	if (_item == _head) {
		AddBegin(item);
		return;
	}

	Node<T>* temp = _head;

	while (temp->next != NULL) {

		if (temp->next == _item) {
			temp->next = item;
			item->next = _item;
		}
		temp = temp->next;
	}
}

template<class T>
void SingleLinkedList<T>::AddAfter(Node<T>* _item, T item) {
	Node<T>* newNode = new Node<T>(item);

	if (_head == NULL)
		return;

	if (_item->next == NULL) {
		AddEnd(item);
		return;
	}

	Node<T>* temp = _head;
	while (temp->next != NULL) {
		if (temp == _item) {
			Node<T>* save = temp->next;
			temp->next = newNode;
			newNode->next = save;
		}
		temp = temp->next;
	}
}

template<class T>
void SingleLinkedList<T>::AddAfter(Node<T>* _item, Node<T>* item) {
	if (_head == NULL)
		return;

	Node<T>* temp = _head;

	while (temp != NULL) {
		if (temp == _item) {
			item->next = temp->next;
			temp->next = item;
			return;
		}
		temp = temp->next;
	}
}

template<class T>
void SingleLinkedList<T>::DeleteBegin() {
	if (_head != NULL) {
		Node<T>* temp = _head;
		_head = _head->next;
		delete temp;
	}
}

template<class T>
void SingleLinkedList<T>::DeleteEnd() {
	if (_head == NULL) {
		assert(!"Linked list is empty!!");
		return;
	}

	if (_head->next == NULL) {
		delete _head;
		_head = NULL;
		return;
	}

	Node<T>* temp = _head;
	while (temp->next->next != NULL) {
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
}

template<class T>
void SingleLinkedList<T>::DeleteByValue(const T item) {
	if (_head == NULL) {
		assert(!"Linked list is empty!!");
		return;
	}

	if (_head->data == item) {
		Node<T>* temp = _head;
		_head = _head->next;
		delete temp;
		return;
	}

	Node<T>* current = _head->next;
	Node<T>* prev = _head;

	while (current != NULL) {
		if (current->data == item) {
			prev->next = current->next;
			delete current;
			return;
		}
		prev = current;
		current = current->next;
	}

	assert(!"Item not found in the linked list!");
}

template<class T>
bool SingleLinkedList<T>::SearchValue(const T item) {
	Node<T>* current = _head;
	while (current != NULL) {
		if (current->data == item) {
			return true;
		}
		current = current->next;
	}
	return false;
}

template<class T>
void SingleLinkedList<T>::display() {
	Node<T>* temp = _head;
	cout << "[ ";
	while (temp->next != NULL)
	{
		cout << temp->data << ", ";
		temp = temp->next;
	}
	cout << temp->data << " ]" << endl;
}