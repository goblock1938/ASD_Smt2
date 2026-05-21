#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next, *prev;
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
    printf("\nMENU DLL : \n");
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
    tampil();
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
  } while (choice < 1 || choice > 5);
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
      delaw();
      break;
    case 2:
      delak();
      break;
    case 3:
      delq();
      break;
    case 4:
      break;
    default:
      printf("INVALID CHOICE!!!\n");
      break;
    }
  } while (choice > 4 || choice < 1);
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
  } else {
    tail->next = new;
    tail = new;
  }
}

void inaf() {
  int key;
  printf("Masukkan nilai key : ");
  scanf("%d", &key);
  search = head;

  while (search != NULL && search->data != key)
    search = search->next;

  if (search == NULL) {
    printf("KEY NOT FOUND !!!\n");
    return;
  }

  if (tail->data == key) {
    inak();
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

  while (search != NULL && search->data != key) {
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

  if (head == tail) {
    free(head);
    head = tail = NULL;
    return;
  }

  while (ps->next != tail)
    ps = ps->next;

  tail = ps;
  tail->next = NULL;
  free(search);
  search = NULL;
  ps = NULL;
}
void delq() {
  int key;
  printf("Masukkan key : ");
  scanf("%d", &key);

  if (head->data == key)
    delaw();

  else if (tail->data == key)
    delak();

  else {
    search = head;

    while (search != NULL && search->data != key) {
      ps = search;
      search = search->next;
    }

    if (search == NULL) {
      printf("KEY NOT FOUND !!!\n");
      return;
    }

    ps->next = search->next;
    free(search);
    search = NULL;
  }
}

void tampil() {
  search = head;
  printf("\nHEAD");
  while (search != NULL) {
    printf("->%d", search->data);
    search = search->next;
  }
  printf("<-TAIL\n");
}
