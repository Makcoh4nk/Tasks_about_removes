#include "TaskAboutDelete.h"

void Add(List **L, int data)
{	
	if (*L == NULL)
	{
		*L = new List;
		(*L)->data = data;
		(*L)->next = NULL;
	}
	else
	{
		List *temp = new List;
		List *clone = *L;

		while ((*L)->next != NULL)
			*L = (*L)->next;
		(*L)->next = temp;
		temp->data = data;
		temp->next = NULL;
		*L = clone;
		
	}
}

void printList(List *L)
{
	while (L != NULL)
	{
		if (L->next == NULL)
			cout << L->data;
		else
			cout << L->data << "->";
		L = L->next;
	}
	cout << endl;
}

void deleteElemFromEnd(List *&L, int pos)
{
	if (pos <= 0)
		throw 1;

	if (L == NULL)
		throw 1;

	int count = 0;
	List *Clone = L;
	

	while (Clone != NULL)
	{
		count++;
		Clone = Clone->next;
	}

	if (pos > count)
		throw 1;

	List *list = L;

	for (int i = 1; i < count-pos; ++i)
		list = list->next;
	Clone = list->next->next;
	delete list->next;
	list->next = Clone;
}

void deleteRepeats(List *&L)
{
	if (L == NULL)
		throw 1;

	List *list = L;
	List *Clone = NULL;

	while ( list->next != NULL)
		if (list->data == list->next->data)
		{
			Clone = list->next->next;
			delete list->next;
			list->next = Clone;
		}
		else list = list->next;
}
