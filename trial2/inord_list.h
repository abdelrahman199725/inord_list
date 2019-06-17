/*
 * inordlist.h
 *
 *  Created on: Apr 8, 2019
 *      Author: lenovo
 */

#ifndef INORD_LIST_H_
#define INORD_LIST_H_
#include<string>
using namespace std;



class inord_list {
public:
	inord_list();
	bool insert( string e,int L);
	bool first(string &e);
	bool next(string &e);
	int wordcount();
	void distwords();
	int  countword(string  e);
	void frequentword();
	void starting(string e);
	void containing(string e);
	void search(string e);
	void printlines(string e);



private:

	struct node;
	typedef node* link;
	struct node{
	string item;
	link next;
	int line;
	};

link pred2;
	link head;
	link current;
	link tail;

};

#endif /* INORD_LIST_H_ */
