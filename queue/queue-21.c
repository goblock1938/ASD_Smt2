#include <stdio.h>
#define MAX 5

typedef int item;
typedef struct {
  item data[MAX];
  int front, rear, count;
} queue;

void enqueue(queue *);
void dequeue(queue *);
void init(queue *);
void tampil(queue *);
void mm(queue *);
void search(queue *);
int isNull(queue *);
int isFull(queue *);

int main() {
  int choice, temp;
  queue antri;
  init(&antri);

  do {

    printf("\n=== MENU QUEUE using ARRAY ===\n");
    printf("1. ENQUEUE (Insert)\n");
    printf("2. DEQUEUE (delete)\n");
    printf("3. TAMPIL DATA MIN DAN MAX\n");
    printf("4. CARI DATA\n");
    printf("5. CETAK ISI QUEUE\n");
    printf("6. keluar\n\n");
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
      mm(&antri);
      break;

    case 4:
      search(&antri);
      break;

    case 5:
      tampil(&antri);
      break;

    case 6:
      break;

    default:
      printf("PILIHAN INVALID !!!\n");
      break;
    }
    printf("\n");
  } while (choice != 6);
}

void init(queue *q) { q->count = q->front = q->rear = 0; }

void enqueue(queue *q) {
  int data;
  if (!isFull(q)) {
    printf("masukkan nilai data (int) : ");
    scanf("%d", &data);
    q->data[q->rear++] = data;
    q->count++;
  } else {
    printf("QUEUE IS FULL\n");
  }
  if (q->rear == 5)
    q->rear = 0;
}

void dequeue(queue *q) {
  if (!isNull(q)) {
    q->data[q->front++] = 0;
    q->count--;
  } else {
    printf("QUEUE IS EMPTY\n");
  }
  if (q->front == 5)
    q->front = 0;
}

void tampil(queue *q) {
  int i = q->front;
  for (int i = 0; i < q->count; i++) {
    printf("%d ", q->data[i]);
    i %= MAX;
  }
}

void mm(queue *q) {
  int min = 0, max = 0;
  for (int i = 0; i <= q->count - 1; i++) {
    int index = (q->front + i) % MAX;
    if (!i)
      min = max = q->data[q->front];
    else {
      max = max < q->data[index] ? q->data[index] : max;
      min = min > q->data[index] ? q->data[index] : min;
    }
  }
  printf("\nMAX : %d\nMIN : %d\n", max, min);
}

void search(queue *q) {
  item s;
  int isFound = 0;
  printf("masukkan data yang mau dicari : ");
  scanf("%d", &s);
  for (int i = 0; i < q->count; i++) {
    int index = (q->front + i) % MAX;
    if (s == q->data[i]) {
      printf("data telah ditemukan !\n data terletak di urutan nomor %d\n",
             index);
      isFound = 1;
    }
  }
  if (!isFound)
    printf("data tidak ditemukan\n");
}

int isFull(queue *q) { return q->count == MAX; }
int isNull(queue *q) { return q->count == 0; }
