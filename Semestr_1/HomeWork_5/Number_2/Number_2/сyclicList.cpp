#include "cyclicList.h"

struct CyclicList
{
	Node *first = nullptr;
	Node *head = nullptr;
};

struct Node
{
	int data;
	Node *next;
};

bool isEmpty(CyclicList *list)
{
	return list->head == nullptr;
}

void push(CyclicList *list, const int data)
{
	auto newNode = new Node{ data, list->head };
	if (isEmpty(list))
	{
		list->first = newNode;
	}
	list->head = newNode;
	list->first->next = newNode;
}

CyclicList *createCyclicList()
{
	return new CyclicList;
}

int deleteWithStep(CyclicList *list, const int step)
{
	auto temp = list->head;

	while (list->head != list->first)
	{
		for (int i = 2; i < step; ++i)
		{
			temp = temp->next;
		}

		if (temp->next == list->head)
		{
			list->head = temp->next->next;
		}

		if (temp->next == list->first)
		{
			list->first = temp;
		}

		auto deleter = temp->next;
		temp->next = temp->next->next;
		temp = temp->next;
		delete deleter;
	}

	return temp->data;
}

void deleteList(CyclicList *list)
{
	while (list->head != nullptr)
	{
		if (list->first == list->head)
		{
			delete list->head;
			break;
		}

		auto temp = list->head;
		list->head = list->head->next;
		delete temp;
	}
	delete list;
}

