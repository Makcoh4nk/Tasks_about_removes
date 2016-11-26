#pragma once
#include <stdio.h>
#include <conio.h>
#include <iostream>
using namespace std;

struct List
{
	int data;
	List *next;
};

void Add(List**, int);
void printList(List*);
void deleteElemFromEnd(List*&, int);
void deleteRepeats(List*&);
