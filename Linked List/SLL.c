#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} Node;

Node simpul, *new = NULL, *search = NULL, *ps = NULL, *head = NULL,
             *tail = NULL;

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
void tampil();

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
  printf("Alokasi berhasil\n\n");
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

void inaw() {
  alokasi();

  if (!new)
    return;

  if (head == NULL) {
    head = new;
    tail = new;
  } else {
    new->next = head;
    head = new;
  }
}

void inak() {
  alokasi();

  if (!new)
    return;

  if (head == NULL) {
    head = new;
    tail = new;
  } else
    tail->next = new;
}

void inaf() {
  int key;
  printf("Masukkan nilai key : ");
  scanf("%d", &key);
  search = head;

  while (search != NULL || search->data == key)
    search = search->next;

  if (search == NULL) {
    printf("KEY NOT FOUND !!!\n");
    return;
  }

  alokasi();
  if (!new)
    return;

  new->next = search->next;
  search->next = new;
}

void inbef() {
  int key;
  printf("Masukkan nilai key : ");
  scanf("%d", &key);
  search = head;

  while (search != NULL || search->data == key) {
    ps = search;
    search = search->next;
  }
  if (search == NULL) {
    printf("KEY NOT FOUND !!!\n");
    return;
  }

  alokasi();
  if (!new)
    return;

  new->next = search;
  ps->next = new;
}

void delaw() {
  if (head == NULL) {
    printf("SLL kosong!\n");
    return;
  }

  search = head;
  head = head->next;
  free(search);
  search = NULL;
}
void delak() {
  if (head == NULL) {
    printf("SLL kosong!\n");
    return;
  }

  search = tail;
  ps = head;

  while (ps->next != tail)
    ps = ps->next;

  tail = ps;
  free(search);
  search = NULL;
  ps = NULL;
}
void delq() {
  int key;
  printf("Masukkan key : ");
  scanf("%d", &key);
  search = head;

  while (search != NULL || search->data != key) {
    ps = search;
    search = search->next;
  }
}
