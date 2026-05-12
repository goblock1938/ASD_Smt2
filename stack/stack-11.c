#include <stdio.h>
#define MAX 10

typedef char data;
typedef struct {
  data arr[MAX];
  int isi;
} stack;

void Push(stack *);
void Pop(stack *);
void Tampil(stack *);
int isFull(int);
int isNull(int);

int main() {
  int choice;
  stack tumpuk;
  tumpuk.isi = 0;

  printf("\nMenu stack using array : \n\n");
  do {
    printf("1. Mengisi stack ( PUSH )\n");
    printf("2. Mengambil isi stack ( POP )\n");
    printf("3. Tampilkan isi stack => LIFO\n");
    printf("4. Exit\n");
    printf("Masukkan pilihanmu : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      Push(&tumpuk);
      break;
    case 2:
      Pop(&tumpuk);
      break;
    case 3:
      Tampil(&tumpuk);
      break;
    case 4:
      break;
    default:
      printf("Choice invalid\n");
      break;
    }
    printf("\n\n");
  } while (choice != 4);
}

int isFull(int t) { return (t == MAX ? 1 : 0); }

int isNull(int t) { return (t == 0 ? 1 : 0); }

void Push(stack *t) {
  data temp;
  if (!isFull(t->isi)) {
    printf("masukkan data (char) : \n");
    scanf(" %c", &temp);
    t->arr[t->isi] = temp;
    printf("data dimasukkan : %c\n", t->arr[t->isi]);
    t->isi++;
    return;
  }
  printf("Stack penuh\n");
}

void Pop(stack *t) {
  if (!isNull(t->isi)) {
    printf("data sudah diambil : %c\n", t->arr[t->isi]);
    t->isi--;
    t->arr[t->isi] = '\0';
    return;
  }
  printf("Stack kosong\n");
}

void Tampil(stack *t) {
  for (int i = t->isi - 1; i >= 0; i--) {
    printf("%c\n", t->arr[i]);
  }
}
