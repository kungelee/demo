#include <stdio.h>

typedef struct demo demo;

struct demo {
  int no;
  demo* next;
} item[3] = { {1, &item[1]}, {2, &item[2]}, {3, NULL} };

demo* reverse(demo* head);

int main(void)
{
  demo* head = item;
  while (head != NULL) {
    printf("%d\n", head->no);
    head = head->next;
  }

  printf("\n------------reverse the list------------\n");
  head = reverse(item);
  while (head != NULL) {
    printf("%d\n", head->no);
    head = head->next;
  }
  return 0;
}

demo* reverse(demo* head)
{
  if (head == NULL)
    return NULL;

  demo* begin, * end;

  begin = head->next;
  head->next = NULL;
  while (begin != NULL) {
    end = begin->next;
    begin->next = head;
    head = begin;
    begin = end;
  }

  return head;
}
