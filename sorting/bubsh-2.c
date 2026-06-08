#include <stdio.h>
#include <stdlib.h>
#define MAKS 20

typedef struct data {
  int no;
  char nama[MAKS];
  int nilai;
} Data;

void bubble(Data[], int, int);
void shell(Data[], int, int);
void tampil(Data[]);
void tukar(int *, int *);
int order();
int comp, mv, sp;

int main() {
  int choice_1, choice_2;
  Data data[MAKS];
  Data bak[MAKS];
  do {

    mv = comp = sp = 0;
    printf("MENU METODE SORTING : \n");
    printf("1. BUBBLE \n");
    printf("2. SHELL \n");
    printf("3. Exit \n");
    printf("Pilihan : ");
    scanf("%d", &choice_1);

    if (choice_1 == 3)
      break;

    printf("MENU NILAI SORTING : \n");
    printf("1. Ascending \n");
    printf("2. Descending \n");
    printf("Pilihan : ");
    scanf("%d", &choice_2);

    if (choice_2 != 1 && choice_2 != 2) {
      printf("INVALID CHOICE VALUE !!\n");
      continue;
    }
    switch (choice_1) {
    case 1:
      bubble(data, 20000, choice_2);
      break;
    case 2:
      shell(data, 20000, choice_2);
      break;
    default:
      printf("INVALID CHOICE METHODE !!\n");
      break;
    }
    tampil(bak);
    printf("Total Compare : %d\n", comp);
    printf("Total Swap : %d\n", sp);
    printf("Total Movement : %d\n", mv);

  } while (choice_1 != 3);
}

void bubble(Data arr[], int n, int choice) {
  int isSwap = 1, i = 0;
  while (i < MAKS && isSwap) {
    isSwap = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (choice == 1) {
        if (arr[j] > arr[j + 1]) {
          tukar(&arr[j], &arr[j + 1]);
          isSwap = 1;
        }
      } else {
        if (arr[j] < arr[j + 1]) {
          tukar(&arr[j], &arr[j + 1]);
          isSwap = 1;
        }
      }
      comp++;
    }
    if (!isSwap)
      break;
    i++;
  }
}

void shell(Data arr[], int n, int choice) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;

      if (choice == 1) {
        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
          arr[j] = arr[j - gap];
          mv++;
        }
      } else {
        for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
          arr[j] = arr[j - gap];
          mv++;
        }
      }
      comp++;
      arr[j] = temp;
    }
  }
}

void tukar(int *a, int *b) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
  sp++;
}

void tampil(Data arr[]) {
  int i;
  printf("%-2s|%-20s|%-5s\n", "No", "Nama", "Nilai");
  while (arr[i].nama[1] == '\0')
    printf("%-2d|%-20s|%-5d\n", arr[i].no, arr[i].nama, arr[i].nilai);
}

int order() {
  int choice;
  do {
    printf("Pengurutan berdasarkan :\n");
    printf("1. Nomor\n");
    printf("2. Nama\n");
    printf("3. Nilai\n");
    if (choice < 1 && choice > 3)
      printf("INVALID CHOICE!!!\n");
  } while (choice < 1 && choice > 3);
  return choice;
}
