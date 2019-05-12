#include <iostream>
#include "LinkedList.h"

LinkedList::LinkedList() {
   head = nullptr;

   // TODO
}
LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Clear()
{
	Node* cur = head;
	while (cur)
	{
		Node* temp = cur->next;
		delete cur->tile;
		delete cur;
		cur = temp;
	}
	head = nullptr;
}

void LinkedList::AddTail(Colour colour, Shape shape)
{
	Tile* tile = new Tile();
	tile->colour = colour;
	tile->shape = shape;
	Node* node = new Node(tile, nullptr);
	AddTail(node);
}

void LinkedList::AddTail(Node * node)
{
	if (node == nullptr) return;
	if (head == nullptr) head = node;
	else
	{
		Node* temp = head;
		while (temp->next) temp = temp->next;
		temp->next = node;
	}
}

void LinkedList::PrintContent()
{
	Node* temp = head;
	while (temp)
	{
		std::cout << temp->tile->colour << temp->tile->shape;
		if (temp->next) std::cout << ',';
		temp = temp->next;
	}
	std::cout << std::endl;
}

Node* LinkedList::Pop()
{
	Node* temp = head;
	if (head) head = head->next;
	temp->next = nullptr;
	return temp;
}



int LinkedList::size()
{
	int count = 0;
	Node* temp = head;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

LinkedList::~LinkedList() {
}
