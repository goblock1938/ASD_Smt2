#include <stdio.h>
#define MAKS 5
void sequent();
void binary();
void quick(int arr[], int low, int high, int mode);
void tukar(int *, int *);
int partition(int Data[], int low, int high, int mode);

int main() {
  int arr[MAKS] = {5, 2, 3, 7, 4}, search;

  printf("Data yang mau dicari : ");
  scanf("%d", &search);
}

void sequent() {}

void binary() {}

void quick(int arr[], int low, int high, int mode) {
  if (low < high) {
    int pi = partition(arr, low, high, mode);

    quick(arr, low, pi - 1, mode);
    quick(arr, pi + 1, high, mode);
  }
}

int partition(int Data[], int low, int high, int mode) {
  int pivot = Data[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (mode == 1) {
      if (Data[j] <= pivot) {
        i++;
        tukar(&Data[i], &Data[j]);
      }
    } else {
      if (Data[j] >= pivot) {
        i++;
        tukar(&Data[i], &Data[j]);
      }
    }
  }
  tukar(&Data[i + 1], &Data[high]);
  return (i + 1);
}

void tukar(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
