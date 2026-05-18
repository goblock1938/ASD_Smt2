#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node simpul, *new, *search, *head, *tail;

void in();
void del();
void alokasi();
void inaw();
void inak();
void inaf();
void inbef();
void delaw();
void delak();
void delq();

int main() {
  int choice;
  do {
    printf("\nMENU SLL : \n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Exit\n");
    printf("pilihanmu : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      in();
      break;
    case 2:
      del();
      break;
    case 3:
      break;
    default:
      printf("INVALID CHOICE!!!\n");
      break;
    }
  } while (choice != 3);
}

void alokasi() {
  new = (Node *)malloc(sizeof(Node));
  if (!new) {
    printf("ALOCATION FAILED!!!\n");
    return;
  }
  printf("Alokasi berhasil\n");
  int nilai;
  printf("masukkan data : ");
  scanf("%d", &nilai);
  new->data = nilai;
  new->next = NULL;
}

void in() {
  int choice;
  do {
    printf("\nMENU INSERT : \n");
    printf("1. INSERT AWAL\n");
    printf("2. INSERT AKHIR\n");
    printf("3. INSERT AFTER\n");
    printf("4. INSERT BEFORE\n");
    printf("5. KEMBALI\n");
    printf("Pilihanmu : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      inaw();
      break;
    case 2:
      inak();
      break;
    case 3:
      inaf();
      break;
    case 4:
      inbef();
      break;
    case 5:
      break;
    default:
      printf("INVALID CHOICE!!!\n");
      break;
    }
  } while (choice != 5);
}

void del() {
  int choice;
  do {
    printf("\nMENU DELETE : \n");
    printf("1. DELETE AWAL\n");
    printf("2. DELETE AKHIR\n");
    printf("3. DELETE TERTENTU\n");
    printf("4. KEMBALI\n");
    printf("Pilihanmu : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      inaw();
      break;
    case 2:
      inak();
      break;
    case 3:
      inaf();
      break;
    case 4:
      break;
    default:
      printf("INVALID CHOICE!!!\n");
      break;
    }
  } while (choice != 4);
}
