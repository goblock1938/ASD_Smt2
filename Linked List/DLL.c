#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next, *prev;
} Node;

Node simpul, *new = NULL, *search = NULL, *head = NULL, *tail = NULL;

void in();
void del();
void alokasi();
void inaw();
void inak();
// insert awal dan akhir overall algonya sama
void inaf();
void inbef();
// insert before dan after overall algonya sama
void delaw();
void delak();
// delete awal dan akhir overall algonya sama
void delq();
// delete by key dan insert after before overall algonya sama
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
    tampil();
  } while (choice != 3);
}

void alokasi() {

  // alokasi memory baru dengan pointer
  new = (Node *)malloc(sizeof(Node));

  if (!new) {
    printf("ALOCATION FAILED!!!\n");
    return;
  }

  printf("Alokasi berhasil\n\n"); // log alokasi
  int nilai;
  printf("masukkan data : ");
  scanf("%d", &nilai);
  new->data = nilai;
  new->next = new->prev = NULL;
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

  if (head == NULL)
    head = tail = new; // head & tail point ke memory pertama
  else {
    // memory awal menunjuk ke memory baru
    head->prev = new;

    // next memory baru menunjuk head
    new->next = head;
    head = new; // update point head
  }
}

void inak() {
  alokasi();

  if (!new)
    return;

  if (head == NULL)
    head = tail = new;
  else {
    // prev memory baru menunjuk memory terakhir
    new->prev = tail;

    // next yang ditunjuk oleh tail menunjuk memory baru
    tail->next = new;
    tail = new;
  }
}

void inaf() {
  int key;
  printf("Masukkan nilai key : ");
  scanf("%d", &key);
  search = head;

  /* searching key dan akan berhenti jika sudah ketemu
  atau mencapai memory terakhir */
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

  new->prev = search;
  new->next = search->next;
  new->prev->next = new;
  new->next->prev = new;
  search = NULL;
}

void inbef() {
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

  if (head->data == key) {
    inaw();
    return;
  }

  alokasi();
  if (!new)
    return;

  new->next = search;
  new->prev = search->prev;
  new->prev->next = new;
  new->next->prev = new;
  search = NULL;
}

void delaw() {
  if (head == NULL) {
    printf("SLL kosong!\n");
    return;
  }

  search = head;
  head = head->next;

  // set pointer prev ke NULL agar memory yang dihapus hilang sepenuhnya
  if (head != NULL)
    head->prev = NULL;
  else
    tail = NULL;
  free(search);
  search = NULL; // search pointer kembali ke deafult valuenya
}

void delak() {
  if (head == NULL) {
    printf("SLL kosong!\n");
    return;
  }

  if (head == tail) { // jika memory yang tersisa hanya 1
    free(head);
    head = tail = NULL;
    return;
  }

  search = tail;

  // pindahkan tail kesebelumnya dan buat next nya NULL
  tail = tail->prev;
  tail->next = NULL;

  // hapus isi pointer dan NULL
  free(search);
  search = NULL;
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

    while (search != NULL && search->data != key)
      search = search->next;

    if (search == NULL) {
      printf("KEY NOT FOUND !!!\n");
      return;
    }

    search->next->prev = search->prev;
    search->prev->next = search->next;
    free(search);
    search = NULL;
  }
}

void tampil() {
  search = head;
  printf("\nHEAD->");
  while (search != NULL) {
    printf("%d", search->data);
    if (head != tail && search != tail)
      printf("<->");
    search = search->next;
  }
  printf("<-TAIL\n");
}
