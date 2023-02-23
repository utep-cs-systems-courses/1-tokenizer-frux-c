#include "history.h"
#include <cstdlib>
#include <cstdio>

List *init_history(){
	List * lst = (List*)malloc(sizeof(List));
	return lst;
}
void add_history(List *list,char* str){
	if(list->root == 0){
		Item * item = (Item*)malloc(sizeof(Item));
		item->id = 0;
		item->str = str;
		list->root = item;
		return;
	}
	Item *tmp = list->root;
	while(tmp->next != 0)
		tmp = tmp->next;
	Item *item = (Item*)malloc(sizeof(Item));
	item->id = tmp->id + 1;
	item->str = str;
	tmp->next = item;
}

char *get_history(List *list, int id){
	if(list == 0) return 0;
	if(list->root->id == id) return list->root->str;
	Item * tmp = list->root;
	while(tmp != 0 && tmp->id != id){
		tmp = tmp->next;
	}
	return tmp->str;
}

void print_history(List * list){
	Item *tmp = list->root;
	while(tmp != 0){
		printf("%d. %s\n",tmp->id,tmp->str);
		tmp = tmp->next;
	}
}
int main(int argc,char *argv[]){
	List * mylist = init_history();
	add_history(mylist,(char *)"this is one");
	add_history(mylist,(char *)"this is list two");
	print_history(mylist);
	return 0;
}