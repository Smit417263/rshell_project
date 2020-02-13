#include  <stdio.h>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sys/wait.h>

#include "CMD.h"
#include "Token.h"
#include "Connector.h"
#include "And.h"
#include "Or.h"
#include "Semicolon.h"

using namespace std;

char** parse(string);
bool prototype(char** toks);

int main(){
  char *cmd;
  string input;
  bool run;
  vector<CMD*> command;
  vector<char*> t;
  
  while(input != "exit"){
 	 cout << "$ ";
 	 getline(cin,input);

 	 if(input == "exit"){
 	     break;
 	 }
  	 char **arr;
  	 arr = parse(input);
 	if(prototype(arr)){}
  }


  return 0;
}	

char** parse(string input){
   char *token = new char [input.size()];
   for(int i = 0; i < input.size(); ++i){
    	token[i] = input.at(i);
   }
   token[input.size()] = '\0';    

   vector<char*> t;

    int SIZE = 0;	
    while(token[SIZE] != '\0'){
      ++SIZE;
    }

    for(int i = 0; i < SIZE; ++i){
      if (token[i] == ' '){
        token[i] = '+';
      }
    }

    token = strtok(token, "+");
    
    while(token != NULL){
      t.push_back(token);
      token = strtok(NULL, "+");
    }
    
    char **array = new char*[t.size()];
    for(unsigned i = 0; i < t.size(); ++i){
         array[i] = t.at(i);
    }
    array[t.size()] = '\0';
    return array;
}



bool prototype(char** toks){
  pid_t pid;
  pid_t wpid;
  int status;

  pid = fork();
  if (pid < 0){
          perror("FORK FAILURE");
          exit(false);
  }

  switch(pid){
          case 0:
        	if(execvp(toks[0], toks) != 0){
        		perror("EXECVP FAILURE");
        		exit(false);
		}
		exit(true);
          default:
                  if (waitpid(pid, &status, WUNTRACED) < 0){
                          perror("CHILD IN PROGRESS");
                  }
		  if(WIFEXITED(status)){
			return true;
		  }
  }
	return true;
}