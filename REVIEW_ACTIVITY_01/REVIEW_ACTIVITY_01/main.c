#include <stdio.h>
#include <stdlib.h>
#include "StaticArray.h"
// include the library you want to test

int main(int argc, char *argv[]) {
	List list;
	list = newList();
	displayList(list);
	return 0;
}
