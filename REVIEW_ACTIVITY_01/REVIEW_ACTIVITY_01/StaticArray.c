#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StaticArray.h"

void initList(List *list){
	int x;
	list->count = 0;
	for(x=0;x<MAX;x++){
		list->elems[x] = 0;
	}
}

List newList(){
	List list;
	initList(&list);
	return list;
}

void displayList(List list){
	int x;
	for(x=0;x<=MAX;x++){
		printf("%d, ", list.elems[x]);
	}
}

bool insertFront(List *list, DATA item){
	int x;
	for(x=list->count;x>=0;x--){
		list->elems[x] = list->elems[x-1];
	}
	list->count++;
	return true;
}

bool insertRear(List *list, DATA item){
	list->elems[list->count-1] = item;
	return true;
}

bool insertSorted(List *list, DATA item){
	int x,y,temp;
	list->elems[list->count-1] = item;

	for(x=1;x<list->count-1;x++){
		temp=list->elems[x];
		y=x-1;
		
		while(temp<list->elems[y] && y>=0){
			list->elems[y+1] = list->elems[y];
			--y;
		}
		list->elems[y+1] = temp;
	}
	return true;
}

bool insertAt(List *list, DATA item, int loc){
	if(list->elems[loc-1] == NULL){
		list->elems[loc-1] = item;
	}
	else{
		int x;
		for(x=list->count;x>loc;x--){
			list->elems[list->count] = list->elems[list->count-1];
		}
		list->elems[loc] = item;
	}
	return true;
}

bool searchItem(List list, DATA key){
	int x;
	for(x=0;x<=list.count;x++){
		if(list.elems[x]==key){
			return true;
		}
	}
	return false;
}

int getItem(List list, DATA key){
	int item, x;
	for(x=0;x<=list.count;x++){
		if(list.elems[x]==key){
			item = list.elems[x];
			break;
		}
	}
	return item;
}

bool deleteFront(List *list){
	int x;
	for(x=1;x<=list->count;x++){
		list->elems[x-1]=list->elems[x];
	}
	return true;
}

bool deleteRear(List *list){
	
	list->elems[list->count-1] = 0;
	return true;
}

int deleteAt(List *list, int loc){
	int x;
	for(x=loc+1;x<=list->count;x++){
		list->elems[x-1]=list->elems[x];
	}
	return 0;
}

bool deleteItem(List *list, DATA key){
	int x,y;
	for(x=0;x<list->count;x++){
		if(list->elems[x]==key){
			for(y=x+1;y<=list->count;y++){
				list->elems[y-1]=list->elems[y];
			}
			return true;
		}
	}
	return false;
}

int deleteAllItem(List *list, DATA key){
	int x,y;
	for(x=0;x<list->count;x++){
		if(list->elems[x]==key){
			for(y=x+1;y<=list->count;y++){
				list->elems[y-1]=list->elems[y];
			}
		}
	}
	return 0;
}
