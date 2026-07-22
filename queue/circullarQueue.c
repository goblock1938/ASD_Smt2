#include <stdio.h>
#define MAX 5

typedef int item;
typedef struct {
  item data[MAX];
  int front, rear, count;
} queue;

void enqueue(queue *); // memasukkan data queue
void dequeue(queue *); // mengeluarkan data queue
void init(queue *);    // init atau state awal circular queue
void tampil(queue *);
int isNull(queue *);
int isFull(queue *);

int main() {
  int choice, temp;
  queue antri;
  init(&antri);

  do {

    printf("\n=== MENU QUEUE using ARRAY (circular queue) ===\n");
    printf("1. ENQUEUE (Insert)\n");
    printf("2. DEQUEUE (delete)\n");
    printf("3. TAMPIL -> FIFO\n");
    printf("4. keluar\n\n");
    printf("pilihanmu : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      enqueue(&antri);
      break;

    case 2:
      dequeue(&antri);
      break;

    case 3:
      tampil(&antri);
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

void init(queue *x) { x->count = x->front = x->rear = 0; }

void enqueue(queue *x) {
  int data;
  printf("masukkan nilai data (int) : ");
  scanf("%d", &data);
  if (!isFull(x))
    x->data[x->rear++] = data;
  x->rear %= MAX; // update rear
}

void dequeue(queue *x) {
  if (isNull(x))
    x->data[x->front++] = 0;
  x->front %= MAX; // update front
}

void tampil(queue *x) {
  int i = x->front;
  while (x->data[i] != 0) {
    printf("%d ", x->data[i++]);
    if (i == 5)
      i = 0;
  }
}

int isFull(queue *q) { return q->count == MAX; }
int isNull(queue *q) { return q->count == 0; }
