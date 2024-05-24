#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
const unsigned int NAME_SIZE = 30;
using namespace std;

struct FLIGHTS
{
	int number_fligts;
	char place[NAME_SIZE];
	string time;
	string date;
	int price_ticket;
	int number_sits;
	FLIGHTS* next;
	FLIGHTS* prev;
};

void insert(FLIGHTS* e, FLIGHTS** phead, FLIGHTS** plast);
FLIGHTS* setElement();
void outputList(FLIGHTS** phead, FLIGHTS** plast);
void find(FLIGHTS** phead, char place[NAME_SIZE]);
void countList(FLIGHTS** phead, FLIGHTS** plast);
void deleteList(FLIGHTS** phead, FLIGHTS** plast);
