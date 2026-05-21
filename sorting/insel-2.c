#include <stdio.h>
#define MAKS 10

void insertion(int[], int);
void selection(int[], int);
void tampil(int[]);
void tukar(int *, int *);

int main() {
  int choice_1, choice_2;
  int data[MAKS] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
  int bak[MAKS] = {3, 10, 4, 6, 8, 9, 7, 2, 1, 5};
  do {

    printf("Kondisi awal array : \n");
    tampil(data);
    printf("MENU METODE SORTING : \n");
    printf("1. INSERTION \n");
    printf("2. SELECTION \n");
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
      insertion(data, choice_2);
      break;
    case 2:
      selection(data, choice_2);
      break;
    default:
      printf("INVALID CHOICE METHODE !!\n");
      break;
    }
    printf("Kondisi Akhir \n");
    tampil(data);
  } while (choice_1 != 3);
}

void insertion(int arr[], int mode) {
  int key, kondisi;
  for (int i = 1; i < 10; i++) {

    key = arr[i];
    int j = i - 1;

    if (mode == 2) {
      while (j >= 0 && arr[j] < key) {
        arr[j + 1] = arr[j];
        j--;
      }
    } else {
      while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      }
    }

    arr[j + 1] = key;
  }
}

void selection(int arr[], int mode) {
  int min, temp;
  for (int i = 0; i < MAKS; i++) {
    min = i;
    int j = i + 1;

    if (mode == 2) {
      while (j < MAKS) {
        if (arr[j] > arr[min])
          min = j;
        j++;
      }
    } else {
      while (j < MAKS) {
        if (arr[j] < arr[min])
          min = j;
        j++;
      }
    }

    tukar(&arr[i], &arr[min]);
    // temp = arr[i];
    // arr[i] = arr[min];
    // arr[min] = temp;
  }
}

void tampil(int arr[]) {
  int i;
  printf("[");
  for (i = 0; i < MAKS - 1; i++)
    printf("%d,", arr[i]);
  printf("%d]\n\n", arr[i]);
}

void tukar(int a[], int b[]) {
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}
