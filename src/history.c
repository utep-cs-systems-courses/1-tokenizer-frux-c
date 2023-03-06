#include "history.h"
#include "tokenizer.h"
#include "tokenizer.c"

List *init_history(){
	List * lst = (List*)malloc(sizeof(List));
	return lst;
}
void add_history(List *list,char* str){
	if(list->root == 0){
		Item * item = (Item*)malloc(sizeof(Item));
		item->id = 0;
		char * start = word_start(str);
		item->str = copy_str(start,word_terminator(str) - start);
		list->root = item;
		return;
	}
	Item *tmp = list->root;
	while(tmp->next != 0) tmp = tmp->next;
	Item *item = (Item*)malloc(sizeof(Item));
	item->id = tmp->id + 1;
	char * start = word_start(str);
	item->str = copy_str(start,word_terminator(str) - start);
	tmp->next = item;
}

char *get_history(List *list, int id){
	if(list == 0) return 0;
	if(list->root->id == id) return list->root->str;
	Item * tmp = list->root;
	while(tmp != 0 && tmp->id != id){
		tmp = tmp->next;
	}
	if(tmp == 0) return (char*)"No History";
	return tmp->str;
}

void print_history(List * list){
	Item *tmp = list->root;
	while(tmp != 0){
		printf("%d. %s\n",tmp->id,tmp->str);
		tmp = tmp->next;
	}
}