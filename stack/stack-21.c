#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  char ch;
  struct Node *next;
} stack;

stack tumpuk, *p = NULL, *head = NULL;

void conv(int);
void push(char);
void pop(stack *);
int isNull();

int main() {
  int choice;
  printf("MENU KOVERSI ANGKA\n");
  do {
    printf("\n1. biner \n");
    printf("2. oktal \n");
    printf("3. hexadecimal \n");
    printf("4. exit \n");

    printf("pilihamu : ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
      conv(2);
      break;
    case 2:
      conv(8);
      break;
    case 3:
      conv(16);
      break;
    case 4:
      break;
    default:
      printf("invalid choice !!!\n");
    }
    if (choice != 4) {
      while (head != NULL) {
        p = head;
        printf("%c", p->ch);
        pop(p);
      }
    }
    printf("\n\n");
  } while (choice != 4);
}

void conv(int nilai) {
  int conv;
  printf("masukkan angka yang mau dikonversi : ");
  scanf("%d", &conv);
  while (conv) {
    int temp = conv % nilai;
    if (nilai == 16 && temp >= 10)
      push(temp - 10 + 'A');
    else
      push(temp + '0');
    conv /= nilai;
  }
}
void push(char hasil) {
  p = (stack *)malloc(sizeof(stack));

  if (p == NULL) {
    printf("malloc is failed\n");
    exit(0);
  }
  p->ch = hasil;
  if (!isNull())
    p->next = head;
  else
    p->next = NULL;

  head = p;
}

void pop(stack *ptr) {
  if (head->next != NULL)
    head = head->next;

  else
    head = NULL;

  free(ptr);

  ptr = NULL;
}

int isNull() { return head == NULL; }
