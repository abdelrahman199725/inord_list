#include <iostream>
#include <algorithm>
#include <cstdlib>
#include<stdlib.h>
#include <string.h>
#include <fstream>
#include<sstream>
#include "inord_list.h"

using namespace std;
int main(int argc,char*argv[])
{
	 inord_list inlist; int x;
		string z;
		string word;
		 ifstream file;
		  file.open (argv[1]);
	    if (!file.is_open())
	        {
	          cout << "File not found";
	          return 0 ;
	        }
	    else if(argc != 3)
	     {
	         cout <<"Incorrect number of arguments"<<endl;
	                   return 0 ;
	     }
	    int l = 0;

		while (getline(file, z))
		{
			l++;
		       replace( z.begin(), z.end(), ',', ' ' );
		          replace( z.begin(), z.end(), ';', ' ' );
		          replace( z.begin(), z.end(), ':', ' ' );
		          //replace( satr.begin(), satr.end(), '\'', ' ' );
		          replace( z.begin(), z.end(), '`', ' ' );
		          replace( z.begin(), z.end(), '&', ' ' );
		          replace( z.begin(), z.end(), '"', ' ' );
		          replace( z.begin(), z.end(), '.', ' ' );
		          replace( z.begin(), z.end(), '[', ' ' );
		          replace( z.begin(), z.end(), ']', ' ' );
		          replace( z.begin(), z.end(), '{', ' ' );
		          replace( z.begin(), z.end(), '}', ' ' );
		          replace( z.begin(), z.end(), '(', ' ' );
		          replace( z.begin(), z.end(), ')', ' ' );

		        for (int p =0;p<z.length();p++)
		          {
		             // if (satr[p]=='’')
		             if (z[p]==39)
		                z[p]=' ';
		          }


          stringstream now(z);
  			while (now >> word){

  				for (int i = 0; i < word.length(); i++){
  					word[i] = tolower(word[i]);}
  					inlist.insert(word,l);
  			}

		}
	    file.close();

	    ifstream inst_file;
	     inst_file.open (argv[2]);
	     if (!inst_file.is_open())
	         {
	           cout << "File not found";
	           return 0 ;
	         }
	     string  w , y,temp;
	 while (getline(inst_file, y))
	     {
	         stringstream f(y);
	         f >> w;
	         if(w=="wordCount")
	         {
            f>>temp; if(!(f.fail()))   {cout <<"Incorrect number of arguments"<<endl;}
            else{
	        	cout<<inlist.wordcount()<<" "<<"words"<<endl;
            }
	         }
	         else  if (w=="search")
	         {
	         	 f>>temp;
	        	 inlist.search(temp);
	         }
	         else if(w=="frequentWord")
	         {
	        	 f>>temp;
	        	inlist.frequentword();
	         }
	         else if(w=="starting")
	         {
	        	  f>>temp;
	        	inlist.starting(temp);
	         }
	         else if(w=="containing")
	         {
	        	  f>>temp;
	        	inlist.containing(temp); cout<<endl;
	         }
	         else if(w=="countWord")
	         {
	        	 f>>temp;
	        	x=inlist.countword(temp);
	        	cout<<temp<<" is repeated "<<x<<" times"<<endl;
	         }
	         else if(w=="distWords")
	 	         {
	        	   f>>temp; if(!(f.fail()))   {cout <<"Incorrect number of arguments"<<endl;}
	        	            else{
                 inlist.distwords();
	 	         }}
	         else if (w=="charCount")
	          {   f>>temp; if(!(f.fail()))   {cout <<"Incorrect number of arguments"<<endl;}
	            else{
	             char temp_char;
	             int sum =0;
	             file.open (argv[1]);
	             while( !file.eof())
	             {
	               file.get(temp_char);
	                         sum++;
	             }
	                  cout << sum-1 <<" characters"<<endl;
	          }}
	         else {
	        	 cout<<"undefined command"<<endl;
	         }

	         }

	 inst_file.close();
return 0;

}
