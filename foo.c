#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next ;
} Node;

//init list  and assign value
bool init_list(Node** head, int const *data, size_t len)
{
	Node* current;
	Node* tail;
	current = tail = NULL;
	for (size_t i = 0; i < len; i++) {
		current = (Node *) malloc(sizeof(Node));
		if (NULL == current)
			return false;
		current->next = NULL;
		current->data = data[i];
		if (NULL == *head) {
			*head = current;
			tail = current;
		} else {
			tail->next = current;
			tail = current;
		}
	}
	return true;
}

//print list
void print_list(Node const *head)
{
	printf("%s", "START");
	while (head != NULL) {
		printf(" -> [%d]", head->data);
		head = head->next;
	}
	printf("%s\n", "-> END");
}

//not find return 0
size_t find(Node const *head, int key)
{
	size_t index = 1;
	while ((head != NULL) && (head->data != key)) {
		index++;
		head = head->next;
	}
	return (head == NULL) ? 0 : index;
}
int main(void)
{
	Node* head;
	int key;
	int data[]= {10,7,12,66,99};

	head = NULL;
	if (! init_list(&head, data, sizeof(data)/sizeof(data[0])))
		return 1;

	print_list(head);
	printf("Enter search key: ");
	if (scanf("%d", &key) != 1)
		return 1;

	size_t index = find(head,key);
	if(0 == index)
		printf("Not Found\n");
	else
		printf("The index is: %u\n", index);

	return 0;
}