/*
 * inordlist.cpp
 *
 *  Created on: Apr 8, 2019
 *      Author: lenovo
 */

#include "inord_list.h"

#include <iostream>
#include <iomanip>
using namespace std;
inord_list::inord_list() {
	// TODO Auto-generated constructor stub
	   head=NULL;
	    tail=NULL;
	    current=NULL;
}


bool inord_list::insert(string e,int L)
{ link addednode; link pred;
addednode=new node;
if(addednode==NULL) {return false;}
else {
	addednode->item=e;
	addednode ->line=L;
	//addednode->next=NULL;

	if(head==NULL || e<=head->item )
	{ addednode->next=head;
	head=addednode;
	return true;}


	else{  pred=head;
	while(pred->next!=NULL && pred->next->item <=e)
	{
	pred=pred->next;
	}
	addednode->next =pred->next;
	pred->next=addednode;
     return true;
    }


}
}
bool inord_list::first(string &e)
{
	if(head==NULL)  {return false;}
	else{
		current=head;
		e=current->item;
		return true;
	}

}


int inord_list::wordcount()
{link pred=head;
int i=0;

while(pred !=NULL)
{i++; pred=pred->next; }
return i;


}

void inord_list::distwords()
{
int x=wordcount();
	        if(head == NULL)
	        {   cout << 0 <<" distinct words" <<endl; return;
	        }

	int  i=0;
	link pred = head;
	         while(pred ->next != NULL)
	           {
	            if(((pred->item)==(pred->next->item)) )
	                i++;
	            pred = pred ->next;
	           }
	         cout <<(x-i)<<" distinct words" <<endl;
}


int inord_list :: countword( string  e)
{   int i =0; link pred = head;
    if(head == NULL)
        {cout << 0;
        return 0;}
    else
        {

         while(pred != NULL)
           {

               if (pred->item==e) {i=i+1; }

            pred=pred->next;
           }


        }
return i;
}


bool inord_list::next(string &e)
{
if(head==NULL || current->next==NULL)
{ return false;}
else{
	current=current->next;
	e=current->item;
	return true;
}


}




void inord_list::frequentword()
{
	link pred=head; string s; int i=wordcount();  int k[i],u=0; int j=0;
	while(pred !=NULL)
	{ if((pred->item=="a")||(pred->item=="an")||(pred->item=="the")||(pred->item=="of")||(pred->item=="in")||(pred->item=="on")||(pred->item=="and")||(pred->item=="is")||(pred->item=="are"))
		{k[u]=0;}
	else{k[u]=countword(pred->item);}
	//	cout<<pred->item;
	//	cout<<k[u]<<endl;
		u++;
		pred=pred->next; }
	int max=k[0]; int f=0;; int m=0; int b=0; string w,z; bool typed=false;
	for(u=0; u<i; u++)
	{
	if(k[u]>max)	{max=k[u]; m=u; } //cout<<max<<" ";

	}
	cout<<"Most frequent word is: ";
	for(u=0; u<i; u++)
	{
	if(k[u]==max)	{ m=u; j++;

	f=m+1;
	 pred=head; link temp,temp2; //cout<<f<<" ";
	while(pred!=NULL && (f!=0))
	{  temp=pred;
		//cout<<pred->item<<" ";
		pred=pred->next;
		f--;
	}
	//cout<<endl;

if((j==countword(temp->item)))	{cout<<temp->item<<" "; j=0;}


	} //cout<<max<<" ";

	}
//	cout<<w<<" ";

 cout<<endl;

}

void inord_list::starting(string e)
{
link pred=head; int j=0; int t=0; bool found=false; int i=wordcount();
while(pred!=NULL)
{
string wanted=pred->item;
j++;
    for(int x=0;x<e.length();x++)
    {	 if(e[x]!=wanted[x]) {break;}
   else{
	   if(x==e.length()-1)
	   { t++;
	   if(t==countword(wanted)) { found=true; t=0;}
	   }
    }

     if(found)
    	{cout<<wanted<<": "<<countword(wanted)<<'\t';
     found=false; j=0;}

    }
if(j==i) {cout<<"Word not found";}
    pred=pred->next;

}

cout<<endl;

}

void inord_list::containing(string e)
{
	string secondString=e; int m=0; bool found=false;
	link pred=head;
	while(pred!=NULL)
	{
	string firstString=pred->item;

    for (int i = 0; i < firstString.length(); i++){
        int j = 0;
        // If the first characters match
        if(firstString[i] == secondString[j]){
            int k = i;
            while (firstString[i] == secondString[j] && j < secondString.length()){
                j++;
                i++;
            }
            if (j == secondString.length())
                {m++; if(m==countword(firstString)) {found=true; cout<<firstString<<":"<<'\t'; cout<<countword(firstString)<<'\t'; m=0;}}
            else
                i = k;
        }

}

pred=pred->next;
}
	if(found==false) {cout<<"Word not found";}
	cout<<endl;

}



void inord_list::search(string e)
{
	string secondString=e; int m=0; bool found=false; int u=0;
	link pred=head;
	while(pred!=NULL)
	{
	string firstString=pred->item;

    for (int i = 0; i < firstString.length(); i++){
        int j = 0;
        // If the first characters match
        if(firstString[i] == secondString[j]){
            int k = i;
            while (firstString[i] == secondString[j] && j < secondString.length()){
                j++;
                i++;
            }
            if (j == secondString.length())
                {m++; if(m==countword(firstString)) {found=true;  cout<<firstString<<':'<<'\t'<<"lines "; printlines(firstString);  m=0;}}
            else
                i = k;
        }
}

pred=pred->next;
}
	if(found==false) {cout<<"Word not found";}
	cout<<endl;
}


void inord_list::printlines(string e)
{
	link pred2=head; int o=wordcount();  int i;  int a[o]; int k=0; bool entered=false;
	for(int y=0;y<o;y++) {a[y]=0;}

      while(pred2!=NULL)
      { if((pred2->item==e))       {entered=true;  cout<<pred2->line<<" "; }
       pred2=pred2->next;
       }
cout<<endl;
}

