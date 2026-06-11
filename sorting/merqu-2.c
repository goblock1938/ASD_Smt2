#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS 20

typedef struct mahasiswa {
  int no, nilai;
  char nama[MAKS];
} mhs;

// Prototipe Fungsi Utama (Lebih bersih dan parameter konsisten)
void insertion(mhs[], int, int, int);
void selection(mhs[], int, int, int);
void bubble(mhs[], int, int, int);
void shell(mhs[], int, int, int);
void mergeSort(mhs[], mhs[], int, int, int, int);
void merging(mhs[], mhs[], int, int, int, int, int);
void quickSort(mhs[], int, int, int, int);
int partition(mhs[], int, int, int, int);

int bandingkan(mhs, mhs, int, int);
void tukar(mhs *, mhs *);
int inuser(mhs[]);
void tampil(mhs[], int);
int pilihKolom();

int main() {
  int choice, choice_2, kolom, n;
  mhs data[MAKS], hasil[MAKS], bak[MAKS];

  n = inuser(data);
  for (int i = 0; i < n; i++)
    bak[i] = data[i];

  do {
    printf("\nSorting Menu : \n");
    printf("0. Exit\n1. Selection Sort\n2. Insertion Sort\n3. Bubble Sort\n4. "
           "Shell Sort\n5. Merge Sort\n6. Quick Sort\nPilihan : ");
    scanf("%d", &choice);

    if (choice == 0)
      break;
    if (choice < 1 || choice > 6) {
      printf("INVALID CHOICE !!\n");
      continue;
    }

    printf("Pengurutan : \n1. Ascending\n2. Descending\nPilihan : ");
    scanf("%d", &choice_2);

    kolom = pilihKolom();

    switch (choice) {
    case 1:
      selection(data, n, choice_2, kolom);
      break;
    case 2:
      insertion(data, n, choice_2, kolom);
      break;
    case 3:
      bubble(data, n, choice_2, kolom);
      break;
    case 4:
      shell(data, n, choice_2, kolom);
      break;
    case 5:
      mergeSort(data, hasil, 0, n - 1, choice_2, kolom);
      break;
    case 6:
      quickSort(data, 0, n - 1, choice_2, kolom);
      break;
    }

    printf("\nHasil Setelah Sorting:\n");
    tampil(data, n);

    for (int i = 0; i < n; i++)
      data[i] = bak[i];
  } while (choice != 0);

  return 0;
}

int bandingkan(mhs a, mhs b, int mode, int kolom) {
  int hasil = 0;
  if (kolom == 1)
    hasil = (a.no > b.no) ? 1 : (a.no < b.no) ? -1 : 0;
  else if (kolom == 2)
    hasil = strcasecmp(a.nama, b.nama);
  else
    hasil = (a.nilai > b.nilai) ? 1 : (a.nilai < b.nilai) ? -1 : 0;

  return (mode == 1) ? (hasil > 0) : (hasil < 0);
}

void tukar(mhs *a, mhs *b) {
  mhs temp = *a;
  *a = *b;
  *b = temp;
}

void insertion(mhs arr[], int n, int mode, int kolom) {
  for (int i = 1; i < n; i++) {
    mhs key = arr[i];
    int j = i - 1;
    while (j >= 0 && bandingkan(arr[j], key, mode, kolom)) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

void selection(mhs arr[], int n, int mode, int kolom) {
  for (int i = 0; i < n - 1; i++) {
    int targetIdx = i;
    for (int j = i + 1; j < n; j++) {
      if (bandingkan(arr[targetIdx], arr[j], mode, kolom)) {
        targetIdx = j;
      }
    }
    tukar(&arr[i], &arr[targetIdx]);
  }
}

void bubble(mhs arr[], int n, int mode, int kolom) {
  int isSwap = 1, i = 0;
  while (i < n - 1 && isSwap) {
    isSwap = 0;
    for (int j = 0; j < n - i - 1; j++) {
      if (bandingkan(arr[j], arr[j + 1], mode, kolom)) {
        tukar(&arr[j], &arr[j + 1]);
        isSwap = 1;
      }
    }
    i++;
  }
}

void shell(mhs arr[], int n, int mode, int kolom) {
  for (int gap = n / 2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      mhs temp = arr[i];
      int j = i;
      while (j >= gap && bandingkan(arr[j - gap], temp, mode, kolom)) {
        arr[j] = arr[j - gap];
        j -= gap;
      }
      arr[j] = temp;
    }
  }
}

void mergeSort(mhs arr[], mhs res[], int low, int high, int mode, int kolom) {
  if (low < high) {
    int medium = low + (high - low) / 2;
    mergeSort(arr, res, low, medium, mode, kolom);
    mergeSort(arr, res, medium + 1, high, mode, kolom);
    merging(arr, res, low, medium, high, mode, kolom);
  }
}

void merging(mhs arr[], mhs res[], int low, int medium, int high, int mode,
             int kolom) {
  int L1 = low, R1 = medium, L2 = medium + 1, R2 = high, i = low;

  while (L1 <= R1 && L2 <= R2) {
    if (bandingkan(arr[L2], arr[L1], mode, kolom)) {
      res[i++] = arr[L1++];
    } else {
      res[i++] = arr[L2++];
    }
  }
  while (L1 <= R1)
    res[i++] = arr[L1++];
  while (L2 <= R2)
    res[i++] = arr[L2++];
  for (int j = low; j <= high; j++)
    arr[j] = res[j];
}

void quickSort(mhs arr[], int low, int high, int mode, int kolom) {
  if (low < high) {
    int pi = partition(arr, low, high, mode, kolom);
    quickSort(arr, low, pi - 1, mode, kolom);
    quickSort(arr, pi + 1, high, mode, kolom);
  }
}

int partition(mhs arr[], int low, int high, int mode, int kolom) {
  mhs pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (bandingkan(pivot, arr[j], mode, kolom)) {
      i++;
      tukar(&arr[i], &arr[j]);
    }
  }
  tukar(&arr[i + 1], &arr[high]);
  return (i + 1);
}

int inuser(mhs arr[]) {
  int i = 0;
  char ch = 'y';
  while ((ch == 'y' || ch == 'Y') && i < MAKS) {
    printf("\nMasukkan nama siswa : ");
    fgets(arr[i].nama, MAKS, stdin);
    arr[i].nama[strcspn(arr[i].nama, "\n")] = '\0';

    printf("Masukkan nilai siswa: ");
    scanf("%d", &arr[i].nilai);
    arr[i].no = i + 1;
    i++;

    printf("Input lagi? (y/n)   : ");
    scanf(" %c", &ch);
    getchar();
  }
  return i;
}

void tampil(mhs arr[], int n) {
  printf("-----------------------------------------\n");
  printf("%-4s %-20s %-5s\n", "No", "Nama", "Nilai");
  printf("-----------------------------------------\n");
  for (int i = 0; i < n; i++) {
    printf("%-4d %-20s %-5d\n", arr[i].no, arr[i].nama, arr[i].nilai);
  }
  printf("-----------------------------------------\n");
}

int pilihKolom() {
  int n;
  do {
    printf("\nUrutkan Berdasarkan Kolom:\n1. No\n2. Nama\n3. Nilai\nPilihan "
           "Kolom : ");
    scanf("%d", &n);
  } while (n < 1 || n > 3);
  return n;
}
