#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define MAKS 100000

void insertion(int[], int, int);
void selection(int[], int, int);
void bubble(int[], int, int);
void shell(int[], int, int);
void merging(int[], int[], int, int, int, int);
void quick(int[], int, int, int);
void merge(int[], int[], int, int, int);
int partition(int[], int, int);
int generate(int[]);
void tukar(int *, int *);

int main() {
  time_t start, end;
  int choice, choice_2, data[MAKS], bak[MAKS], hasil[MAKS];
  int n = generate(data);
  for (int i = 0; i < n; i++)
    bak[i] = data[i];

  do {
    printf("\nSorting : \n");
    printf("0. Exit\n");
    printf("1. Selection Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble Sort\n");
    printf("4. Shell Sort\n");
    printf("5. Merge Sort\n");
    printf("6. Quick Sort\n");
    printf("Pilih : ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= 6) {
      printf("\nPengurutan : \n");
      printf("1. Ascending\n");
      printf("2. Descending\n");
      printf("Pilih : ");
      scanf("%d", &choice_2);
    }
    start = clock();
    switch (choice) {
    case 0:
      break;
    case 1:
      selection(data, n, choice_2);
      break;
    case 2:
      insertion(data, n, choice_2);
      break;
    case 3:
      bubble(data, n, choice_2);
      break;
    case 4:
      shell(data, n, choice_2);
      break;
    case 5:
      merge(data, hasil, 0, n - 1, choice_2);
      break;
    case 6:
      quick(data, 0, n - 1, choice_2);
      break;
    default:
      printf("INVALID CHOICE !!");
      break;
    }
    end = clock();
    if (choice != 0)
      printf("\nWaktu yang dibutuhkan: %f seconds\n",
             ((double)(end - start)) / CLOCKS_PER_SEC);

    for (int i = 0; i < n; i++)
      data[i] = bak[i];
  } while (choice != 0);
}

int generate(int arr[]) {
  int n;
  printf("Berapa data (min = 25000, max = 100000): ");
  scanf("%d", &n);
  srand(time(0) + clock() + getpid());
  for (int i = 0; i < n; i++)
    arr[i] = (rand() << 15) ^ rand();
  return n;
}

void tukar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void insertion(int arr[], int n, int mode) {
  int key, kondisi;
  for (int i = 1; i < n; i++) {

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

void selection(int arr[], int n, int mode) {
  int min, temp;
  for (int i = 0; i < n; i++) {
    min = i;
    int j = i + 1;

    if (mode == 2) {
      while (j < n) {
        if (arr[j] > arr[min])
          min = j;
        j++;
      }
    } else {
      while (j < n) {
        if (arr[j] < arr[min])
          min = j;
        j++;
      }
    }

    tukar(&arr[i], &arr[min]);
  }
}

void bubble(int arr[], int n, int mode) {
  int isSwap = 1, i = 0;
  while (i < n && isSwap) {
    isSwap = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (mode == 1) {
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
    }
    if (!isSwap)
      break;
    i++;
  }
}

void shell(int arr[], int n, int mode) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      int temp = arr[i];
      int j;

      if (mode == 1) {
        for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
          arr[j] = arr[j - gap];
        }
      } else {
        for (j = i; j >= gap && arr[j - gap] < temp; j -= gap) {
          arr[j] = arr[j - gap];
        }
      }
      arr[j] = temp;
    }
  }
}

void merge(int arr[], int res[], int low, int high, int mode) {
  if (low < high) {
    int medium = (low + high) / 2;
    merge(arr, res, low, medium, mode);
    merge(arr, res, medium + 1, high, mode);
    merging(arr, res, low, medium, high, mode);
  }
}
void merging(int arr[], int res[], int low, int medium, int high, int mode) {
  int L1 = low;
  int R1 = medium;
  int L2 = medium + 1;
  int R2 = high;
  int i = low;

  while (L1 <= R1 && L2 <= R2) {
    if (arr[L1] <= arr[L2]) {
      res[i] = arr[L1];
      L1++;
    } else {
      res[i] = arr[L2];
      L2++;
    }
    i++;
  }
  while (L1 <= R1) {
    res[i] = arr[L1];
    L1++;
    i++;
  }

  while (L2 <= R2) {
    res[i] = arr[L2];
    i++;
    L2++;
  }

  int j = low;

  while (j <= high) {
    arr[j] = res[j];
    j++;
  }
}
void quick(int arr[], int low, int high, int mode) {
  if (low < high) {
    int pi = partition(arr, low, high);

    quick(arr, low, pi - 1, mode);
    quick(arr, pi + 1, high, mode);
  }
}
int partition(int Data[], int low, int high) {
  int pivot = Data[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (Data[j] <= pivot) {
      i++;
      tukar(&Data[i], &Data[j]);
    }
  }
  tukar(&Data[i + 1], &Data[high]);
  return (i + 1);
}
