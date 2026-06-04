#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAKS 20000

void bubble(int[], int, int);
void shell(int[], int, int);
void tampil(int[]);
void tukar(int *, int *);
void generate(int[]);
time_t t1, t2;
int comp, mv, sp;

int main() {
  int choice_1, choice_2;
  int data[MAKS];
  generate(data);
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
    time(&t1);
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
    time(&t2);
    printf("waktu komputasi : %f\n", difftime(t2, t1));
    printf("Total Compare : %d\n", comp);
    printf("Total Swap : %d\n", sp);
    printf("Total Movement : %d\n", mv);

  } while (choice_1 != 3);
}

void bubble(int arr[], int n, int choice) {
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

void shell(int arr[], int n, int choice) {
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
void generate(int arr[]) {
  int n;
  do {
    printf("Mau generate berapa? (Maksimal : 20000)\n");
    scanf("%d", &n);
    if (n < 20000) {
      for (int i = 0; i < n; i++)
        arr[i] = rand() / 1000;
    } else {
      printf("Terlalu banyak data, silahkan input kembali\n");
    }
  } while (n > 20000);
}
