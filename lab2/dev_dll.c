#include "dev_dll.h"

int main(){
	struct device_list *d = create();
	return 0;
}

struct device_list* create(){
	struct device_list *dl = malloc(sizeof(struct device_list*));
	dl->head = malloc(sizeof(struct device*));
	dl->tail = malloc(sizeof(struct device*));
	return dl;
}

void insert(struct device_list *dl, unsigned int maj, unsigned int min, char* name){
	struct device *temp = malloc(sizeof(struct device*));
	temp->name = name;
	temp->major = maj;
	temp->minor = min;
	if(!dl->head){
		dl->head = temp;
		temp->prev = dl->head;
		dl->head->prev = NULL;
		dl->tail = dl->head;
		return;
	}	
	
	temp->prev = dl->tail;
	temp->next = NULL;
	dl->tail->next = temp;
	dl->tail = temp;

}

int at_index(unsigned int maj, unsigned int min){
	return 0;
}

struct device* del(struct device_list *dl){
	if(!dl->head)
	return NULL;
}

int size(struct device_list *dl){
	return 0;
}

int is_empty(struct device_list *dl){
	return 0;
}

void print(struct device_list *dl){
	
}

int destroy(struct device_list *dl){
	return 0;
}
