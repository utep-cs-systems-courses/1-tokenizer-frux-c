#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "history.c"

int main(int argc, char* argv[]){
	List * hist = init_history();
	while(1){
		char str[25];
		printf("$");
		fgets(str,25,stdin);
		if(*str == '!') {
			if(*(str+1) == 'q') return 0; 
			add_history(hist,str);
			printf("%s",get_history(hist,atoi(str+1)));
		}
		else add_history(hist,str);
	}
}