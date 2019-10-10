#ifndef DEV_DLL
#define DEV_DLL
#include <stdlib.h>  

struct device{
	char* name;
	unsigned int major;
	unsigned int minor;
	struct device* next;
	struct device* prev;
} device;

struct device_list{
	struct device* head;
	struct device* tail;
} device_list;

// Create list. Return newly created doubly linked list 
struct device_list* create();

// Insert to he end of the list. 
// Ideally, insertion should happen by major number and then minor number
// devices should be sorted by major numbers
// all devices with the same major number should be together and within each major number devices should be sorted by minor number
void insert(struct device_list *dl, unsigned int maj, unsigned int min, char* name);

// return -1 if the device is not found, otherwise the index
// Two devices are considered ot be the same if they have the same major and minor numbers  
int at_index(unsigned int maj, unsigned int min);

// Delete a device from the tail of the list
// Alternatively, build in support to delete specific devices  
// Return device if successfully deleted, NULL otherwise  
struct device* del(struct device_list *dl);

// Return size of list  
int size(struct device_list *dl);

// Check if the list id empty  
// Return 0 if not empty, 1 if empty  
int is_empty(struct device_list *dl);

// Print device attributes  
void print(struct device_list *dl);

// Destroy the list.
// Allow deletion if empty or regardless, o on success, 1 on failure
int destroy(struct device_list *dl);
#endif
