#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAKS 100000

int sequent(int[], int, int);
int binary(int[], int, int);
void generate(int[], int);
void acak(int[], int);
void tukar(int *, int *);

int main() {
  time_t start, end;
  int arr[MAKS], n, arr1[MAKS], choice, comp;
  printf("Berapa data : ");
  scanf("%d", &n);

  generate(arr, n);
  for (int i = 0; i < n; i++)
    arr1[i] = arr[i];
  acak(arr1, n);

  while (1) {
    printf("Searching Metode\n0. Exit\n1. Sequent tanpa Sorting\n2. Sequent "
           "dengan Sorting\n3. Binary\n");
    scanf("%d", &choice);

    if (choice == 0) {
      printf("Selesai\n");
      break;
    }
    start = clock();
    switch (choice) {
    case 1:
      comp = sequent(arr1, n, rand() % n);
      break;
    case 2:
      comp = sequent(arr, n, rand() % n);
      break;
    case 3:
      comp = binary(arr1, n, rand() % n);
      break;
    }

    end = clock();
  };
}

int sequent(int arr[], int n, int key) {
  int comp;
  for (int i = 0; i < n; i++) {
    comp++;
    if (arr[i] == key)
      return comp;
  }
  return -1;
}

int binary(int arr[], int n, int key) {
  int low = 0;
  int high = n - 1;
  int comp;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    comp++;
    if (arr[mid] == key) {
      return comp;
    }

    if (arr[mid] < key) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void generate(int arr[], int n) {
  for (int i = 0; i < n; i++)
    arr[i] = i + 1;
}

void acak(int arr[], int n) {
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);

    tukar(&arr[i], &arr[j]);
  }
}
void tukar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
