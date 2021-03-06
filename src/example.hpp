#ifndef EXAMPLE_HPP_
#define EXAMPLE_HPP_

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <fstream>
#include <sstream>
#include <cstring>

#include "CMD.h"
#include "Token.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"
#include "Exit.h"

using namespace std;

/*
CMD* buildTree(char** arr){
  stack<CMD*> s;
  int SIZE = 0;

  while(arr[SIZE] != NULL){
    ++SIZE;
  }
  ++SIZE;

  char *aSym = (char*) "&&";
  char *oSym = (char*) "||";
  char *sSym = (char*) ";";
  char *eSym = (char*) "exit";

  for(unsigned i = 0; i < SIZE-1; ++i){
    char *temp = arr[i];
    if (strcmp(temp, eSym) == 0){
      CMD *t = new Exit();
      s.push(t);
    }
    else if(strcmp(temp, aSym) == 0){
      CMD *t = new And();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }

    else if(strcmp(temp, oSym) == 0){
      CMD *t = new Or();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }

    else if(strcmp(temp, sSym) == 0){
      CMD *t = new Semicolon();
      t->SetR(s.top());
      s.pop();
      t->SetL(s.top());
      s.pop();
      s.push(t);
    }
    else{
      CMD* t = new Token(temp);
      s.push(t);
    }
  }
  CMD* t = s.top();
  s.pop();

  return t;
}

bool runTree(CMD* root){
	root->run();
}
*/

/*
 *   CMD* t = root;
 *     CMD* tL = root->GetL();
 *       CMD* tR = root->GetR();
 *         bool ran = true;
 *           if(tL != NULL && tL->isCon() == true){
 *               ran = runTree(tL);
 *                 }
 *                   if(t->isAnd()){
 *                       if(tL->isCon()){
 *                             if(ran){return tR->run();}
 *                                 }
 *                                     else{
 *                                           bool tf = tL->run();
 *                                                 if(tf){return tR->run();}
 *                                                       return false;
 *                                                           }
 *                                                             }
 *                                                               else if(t->isOr()){
 *                                                                   if(tL->isCon()){
 *                                                                         if(ran){return true;}
 *                                                                               else{return tR->run();}
 *                                                                                   }
 *                                                                                       else{
 *                                                                                             bool tf = tL->run();
 *                                                                                                   if(tf){return true;}
 *                                                                                                         return tR->run();
 *                                                                                                             }
 *                                                                                                               }
 *                                                                                                                 else if(t->isSemicolon()){
 *                                                                                                                     if(tL->isCon()){
 *                                                                                                                           return tR->run();
 *                                                                                                                               }
 *                                                                                                                                   else{
 *                                                                                                                                         tL->run();
 *                                                                                                                                               return tR->run();
 *                                                                                                                                                   }
 *                                                                                                                                                     }
 *                                                                                                                                                       return t->run();
 *                                                                                                                                                       */



char** infix_to_postfix(char** input){
int SIZE = 0;


while(input[SIZE] != NULL){
++SIZE;
}
++SIZE;

int index = 0;
int i1 = 0;
char **arr = new char* [SIZE];
char *aSym = (char*) "&&";
char *oSym = (char*) "||";
char *sSym = (char*) ";";
char *opSym = (char*) "(";
char *cpSym = (char*) ")";


for(int i = 0; i < SIZE-1; ++i){

     if(strcmp(input[i], aSym) == 0){
        char *sum  = new  char[64];
	int sz = 0;
	strcpy(sum, input[i1]);
	++sz;
	if(i1 +1 != i) {strcat(sum, " "); ++sz;}
 	++i1;
 

        for(int l = i1; l < i; ++l){
        strcat(sum, input[l]);
	++sz;
        if(l+1 !=  i){strcat(sum, " "); ++sz;}
        }
            i1 = i + 1;
	if(sz != 0){
        arr[index] = sum;
        ++index;
	}
        char* add = new char[3];

        add[0] = '&';
        add[1] = '&';
        add[2] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(input[i], oSym) == 0){
        char *sum  = new  char[64];
	int sz = 0;
	strcpy(sum, input[i1]);
	++sz;
	if(i1 +1 != i) {strcat(sum, " "); ++sz;}
 	++i1;
 

        for(int l = i1; l < i; ++l){
            strcat(sum, input[l]);
	    ++sz;
            if(l+1 !=  i){strcat(sum, " ");++sz; }
        }
        i1 = i + 1;
	if(sz != 0){
        arr[index] = sum;
        ++index;
	}
        char* add = new char[3];

        add[0] = '|';
        add[1] = '|';
        add[2] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(input[i], sSym) == 0){
        char *sum  = new  char[64];
	int sz = 0;
	strcpy(sum, input[i1]);
	++sz;
	if(i1 +1 != i) {strcat(sum, " "); ++sz;}
 	++i1;
  

        for(int l = i1; l < i; ++l){
            strcat(sum, input[l]);
	    ++sz;
            if(l+1 !=  i){strcat(sum, " "); sz++;}
        }
        i1 = i + 1;
	if(sz != 0){
        arr[index] = sum;
        ++index;
	}
        char* add = new char[2];

        add[0] = ';';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(input[i], cpSym) == 0){
        char *sum  = new  char[64];
	int sz = 0;
	strcpy(sum, input[i1]);
	++sz;
	if(i1 +1 != i) {strcat(sum, " "); ++sz;}
 	++i1;
    
        for(int l = i1; l < i; ++l){
            strcat(sum, input[l]);
		sz++;
            if(l+1 !=  i){strcat(sum, " "); sz++;}
        }
        i1 = i + 1;
	if(sz != 0){
        arr[index] = sum;
        ++index;
	}
        char* add = new char[2];

        add[0] = ')';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
    else if(strcmp(input[i], opSym) == 0){
    char *sum  = new  char[64];
	int sz = 0;
	strcpy(sum, input[i1]);
	++sz;
	if(i1 +1 != i) {strcat(sum, " "); ++sz;}
 	++i1;
  
       for(int l = i1; l < i; ++l){
            strcat(sum, input[l]);
		++sz;
            if(l+1 !=  i){strcat(sum, " "); ++sz;}
	 }
        i1 = i + 1;

	if(sz != 0){

        arr[index] = sum;
        ++index;
	}
        char* add = new char[2];

        add[0] = '(';
        add[1] = '\0';
        arr[index] = add;
        ++index;
    }
}

if(i1 < SIZE-1){
    char *sum  = new  char[64];
	strcpy(sum, input[i1]);
	if(i1 +1 != SIZE -1 ) {strcat(sum, " ")}
 	++i1;
 
    while (i1 < SIZE-1){
        strcat(sum, input[i1]);
        if(i1+1 != SIZE-1){strcat(sum, " ");}
        ++i1;
	}

arr[index] = sum;
++index;
}

arr[index] = NULL;
SIZE = index;


char** arr2 = new char* [SIZE + 5];
char* spSym = (char*) " ";
int j = 0;
for(int i = 0; i < SIZE; ++i){
	if(strcmp(arr[i], spSym) != 0){
		arr2[j] = arr[i];
		++j;
	}
}
arr2[j] = NULL;
SIZE = j;

delete [] arr;


stack<char*> c;
char** arr3 = new char* [SIZE];


int s = 0;
int i = 0;
while(arr2[i] != NULL){
	if((strcmp(arr2[i], aSym) == 0) || (strcmp(arr2[i], oSym) == 0) || (strcmp(arr2[i], sSym) == 0) || (strcmp(arr2[i], opSym) == 0) ){
		c.push(arr2[i]);
	}
	else if(strcmp(arr2[i], cpSym) == 0){
		while(strcmp(c.top(), opSym) != 0 ){	
			arr3[s] = c.top();
			c.pop();
			++s;

		}	
		if(strcmp(c.top(), opSym) == 0){
			c.pop();
		}
		
	}
	else{
		arr3[s] = arr2[i];
		++s;
	}
++i;	
}

while(!c.empty()){
	arr3[s] = c.top();
	c.pop();
	++s;
}
arr3[s] = NULL;


return arr3;

}

#endif
