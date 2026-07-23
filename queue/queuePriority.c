#include <stdio.h>
#include <stdlib.h>

// queue priority perbedaan terletak pada
// enqueue yang lebih rumit dari yang biasanya

typedef int item;
typedef struct node {
  item data;
  int priority;
  struct node *next;
} queue;

queue *front, *rear, *p, *search, *ps;
int count = 0;

void enqueue();
void dequeue();
void tampil();
int isNull();

int main() {
  int choice;

  do {

    printf("\n=== MENU QUEUE PIORITY using LINKED LIST ===\n");
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
  int data, prio;
  p = (queue *)malloc(sizeof(queue));

  if (p == NULL) {
    printf("MALLOC FAILED !!!\n");
    return;
  }

  printf("masukkan nilai data (int) : ");
  scanf("%d", &data);
  printf("priority (int, paling kecil paling prioritas) : ");
  scanf("%d", &prio);
  p->data = data;
  p->priority = prio;
  p->next = NULL;

  if (isNull())
    front = rear = p;
  else if (front->priority > prio) {
    // jika priority terbaru lebih kecil (yang paling darurat)
    p->next = front;
    front = p;

  } else {

    // jika priority terbaru lebih besar (tidak darurat)
    search = front;
    // mencari sampai prioritas yang lebih besar atau antrian terakhir
    while (search->next != NULL && search->next->priority <= prio)
      search = search->next;

    p->next = search->next;
    search->next = p;

    if (p->next == NULL)
      rear = p;
  }
  count++; // update jumlah antrian
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
  printf("\n");
  while (p != NULL) {
    printf("%d prioritas : %d\n", p->data, p->priority);
    p = p->next;
  }
}

int isNull() { return count == 0; }
