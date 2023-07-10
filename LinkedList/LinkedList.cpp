#include <iostream>
#include <cassert>

using namespace std;

//#include"SingleLinkedList.h"
#include"DoubleLinkedList.h"

int main() {
	/*SingleLinkedList<string> list;
	list.AddBegin(new Node<string>("Item_1"));
	list.AddBegin(new Node<string>("Item_2"));
	list.AddBegin(new Node<string>("Item_3"));
	list.AddEnd("4");
	list.AddEnd("5");
	list.AddEnd("Xeyal");
	list.display();

	cout << list.SearchValue("Item_2") << endl;
	list.DeleteByValue("Item_1");
	list.DeleteBegin();
	list.DeleteEnd();
	list.display();

	Node<string>* node1 = new Node<string>("5");
	list.AddBefore(node1, "World");
	list.display();*/


	DoubleLinkedList<string> list;
	list.AddBegin(new Node<string>("Item_1"));
	list.AddBegin(new Node<string>("Item_2"));
	list.AddBegin(new Node<string>("Item_3"));
	list.AddEnd("4");
	list.AddEnd("5");
	list.AddEnd("Xeyal");
	list.DisplayFront();
	list.DisplayEnd();

	cout << endl;
	list.DeleteBegin();
	list.DeleteEnd();
	list.DisplayFront();
	list.DisplayEnd();

	cout << endl;
	list.AddBefore("4", "Azer");
	list.AddBefore("Item_2", "12");
	list.DisplayFront();
	list.DisplayEnd();

	cout << endl;
	list.AddAfter("5", "~World~");
	list.AddAfter("Item_1", "Hello");
	list.DisplayFront();
	list.DisplayEnd();

	cout << endl;
	list.DeleteVByValue("12");
	list.DeleteVByValue("~World~");
	list.DeleteVByValue("4");
	list.DisplayFront();

	return 0;
}