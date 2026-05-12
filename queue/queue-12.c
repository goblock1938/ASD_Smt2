#include <stdio.h>
#include <stdlib.h>

typedef int item;
typedef struct node {
  item data;
  struct node *next;
} queue;

queue *front, *rear, *p;
int count = 0;

void enqueue();
void dequeue();
void tampil();
int isNull();

int main() {
  int choice;

  do {

    printf("\n=== MENU QUEUE using LINKED LIST ===\n");
    printf("1. ENQUEUE (Insert)\n");
    printf("2. DEQUEUE (Delete)\n");
    printf("3. TAMPIL -> FIFO\n");
    printf("4. keluar\n\n");
    printf("pilihanmu : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      enqueue();
      break;

    case 2:
      dequeue();
      break;

    case 3:
      tampil();
      break;

    case 4:
      break;

    default:
      printf("PILIHAN INVALID !!!\n");
      break;
    }
    printf("\n");
  } while (choice != 4);
}

void enqueue() {
  int data;
  p = (queue *)malloc(sizeof(queue));

  if (p == NULL) {
    printf("MALLOC FAILED !!!\n");
    return;
  }

  printf("masukkan nilai data (int) : ");
  scanf("%d", &data);
  p->data = data;

  if (isNull())
    front = rear = p;
  else
    rear->next = p;
  rear = p;
  count++;
}

void dequeue() {
  p = front;
  front = front->next;
  free(p);
  p = NULL;
  count--;
}

void tampil() {
  p = front;
  while (p != NULL) {
    printf("%d ", p->data);
    p = p->next;
  }
}

int isNull() { return count == 0; }
