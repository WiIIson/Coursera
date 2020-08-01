#include <stdio.h>		//Loads neccesary libraries
#include <stdlib.h> 
#include <time.h> 

typedef struct list		//List data type
{
	int data;
	struct list *next;
} list;

list* create_list(int d)			//Function that creates a new list
{
	list* head = malloc(sizeof(list));
	head->data = d;
	head->next = NULL;
	return head;
}

list* add_to_front(int d, list* h)		//Function that ties a new value to the front of the list
{
	list* head = create_list(d);
	head->next = h;
	return head;
}

list* array_to_list(int d[], int size)		//Function that converts an array into a list
{
	list* head = create_list(d[0]);
	int i;
	for (i = 1; i < size; i++)
	{
		head = add_to_front(d[i], head);
	}
	return head;
}


void sort_list(list* h)		//Function that rearranges the data in the list based on integer size (smallest to largest)
{
	int i;
	int temp;
	while (h->next != NULL)
	{
		if (h->data > (h->next)->data)
		{
			temp = (h->next)->data;
			(h->next)->data = h->data;
			h->data = temp;
		}
		h = h->next;
	}
}

void print_list(list *h)		//Function that prints out the list
{
	int count = 0;

	while (h != NULL)
	{
		printf("%d ", h->data);
		h = h->next;
		count++;

		if (count == 4)
		{
			count = 0;
			printf("\n");
		}
	}
}

int main(void)
{
	int randomint[100];		//Declares required variables
	int i;
	int temp;
	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		randomint[i] = (rand() % 1000) + 1;	//Creates an array of random numbers
	}


	list list_of_int;
	list* head = NULL;

	head = array_to_list(randomint, 100);		//Sets up the list

	for (i = 0; i < 100; i++)
	{
		sort_list(head);			//Sorts the list
	}


	print_list(head);		//Prints the list
}