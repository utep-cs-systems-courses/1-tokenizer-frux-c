#include "tokenizer.h"
#include <cstdlib>
#include <cstdio>


int space_char(char c){
	return c == ' ' || c == '\t';
}

int non_space_char(char c){
	if(c == '\0') return 0;
	return !space_char(c);
}

char *word_start(char * str){
	if(str == 0) return NULL;
	while(space_char(*str)) str++;
	return *str=='\0'?NULL:str;
}

char *word_terminator(char *word){
	while(non_space_char(*word)) word++;
	return word;
}

int count_words(char *str){
	int count = 0;
	str = word_start(str);
	while(str != NULL){
		count++;
		str = word_start(word_terminator(str));
	}
	return count;
}

char *copy_str(char *inStr, short len){
	char *str = (char*)malloc(sizeof(char) * len);
	char *tmp = str;
	while((--len) >= 0){
		*tmp = *inStr;
		tmp++;
		inStr++;
	}
	return str;
}
char **tokenize(char* str){
	int count = count_words(str);
	char **tokens = (char**)malloc(sizeof(char*) * count);
	int i = 0;
	str = word_start(str);
	while(i < count){
		char *start = str;
		char *end = word_terminator(str);
		int length = end - start;
		// while((void*)&*start != (void*)&*end){
		// 	start++;
		// 	length++;
		// }
		tokens[i++] = copy_str(str,length);
		str = word_start(end);
	}
	return tokens;
}
void print_tokens(char ** tokens){
	while(*tokens != 0){
		printf("%s\n",*tokens);
		tokens++;
	}
}
int main(int argc,char *argv[]){
	const char* str = "hello     world";
	char **token = tokenize((char*)str);
	int count = count_words((char*)str);
	print_tokens(token);
}