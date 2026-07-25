#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} stack;

stack *p = NULL, *head = NULL;

void Push();
void Pop();
void Tampil();
int isNull();

int main() {
  int choice;

  printf("\nMENU STACK USING SLL : \n\n");
  do {
    printf("1. Mengisi stack ( PUSH )\n");
    printf("2. Mengambil isi stack ( POP )\n");
    printf("3. Tampilkan isi stack => LIFO\n");
    printf("4. Exit\n");
    printf("Masukkan pilihanmu : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      Push();
      break;
    case 2:
      Pop();
      break;
    case 3:
      Tampil();
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

int isNull() { return (head == NULL); }

void Push() {
  int temp;
  p = (stack *)malloc(sizeof(stack));
  printf("masukkan data (int) : ");
  scanf(" %d", &temp);

  p->data = temp;
  p->next = head;
  head = p;
}

void Pop() {
  p = head;
  if (!isNull()) {
    printf("data sudah diambil : %d\n", p->data);
    head = head->next;
    free(p);
    p = NULL;
  }
  printf("Stack kosong\n");
}

void Tampil() {
  p = head;
  while (p != NULL) {
    printf("%d\n", p->data);
    p = p->next;
  }
}
