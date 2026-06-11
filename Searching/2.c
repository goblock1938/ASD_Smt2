#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define MAKS 20

typedef struct siswa {
  int no;
  char nama[MAKS];
  int nilai;
} sis;

int sequent(sis[], int, int);
int binary(sis[], int, int);
int inuser(sis[]);
void search(int *, char[], int);

void quickSort(sis[], int, int, int);
int partition(sis[], int, int, int);
int bandingkan(sis, sis, int);
void tukar(sis *, sis *);

int main() {
  sis arr[MAKS];
  int n, choice, mode, hasil;
  n = inuser(arr);

  while (1) {
    printf("\nSearching Metode\n0. Exit\n1. Sequent tanpa Sorting\n2. Sequent "
           "dengan Sorting\n3. Binary\n");
    printf("Pilihan : ");
    scanf("%d", &choice);

    if (choice == 0) {
      printf("Selesai\n");
      break;
    }

    printf("Search by :\n1. No\n2. Nama\n3. Nilai\n");
    printf("Pilihan : ");
    scanf("%d", &mode);
    getchar();

    switch (choice) {
    case 1:
      hasil = sequent(arr, n, mode);
      break;
    case 2:
      quickSort(arr, 0, n - 1, mode);
      hasil = sequent(arr, n, mode);
      break;
    case 3:
      quickSort(arr, 0, n - 1, mode);
      hasil = binary(arr, n, mode);
      break;
    default:
      hasil = -1;
      break;
    }

    if (hasil != -1) {
      printf("Data Ditemukan\n");
      printf("%-2d %-20s %-2d\n", arr[hasil].no, arr[hasil].nama,
             arr[hasil].nilai);
    } else {
      printf("Data tidak ditemukan \n");
    }
  };
  return 0;
}

int sequent(sis arr[], int n, int mod) {
  int key;
  char skey[MAKS];
  search(&key, skey, mod);

  switch (mod) {
  case 1:
    for (int i = 0; i < n; i++) {
      if (arr[i].no == key)
        return i;
    }
    break;
  case 2:
    for (int i = 0; i < n; i++) {
      if (strcasecmp(arr[i].nama, skey) == 0)
        return i;
    }
    break;
  case 3:
    for (int i = 0; i < n; i++) {
      if (arr[i].nilai == key)
        return i;
    }
    break;
  }
  return -1;
}

int binary(sis arr[], int n, int mod) {
  int low = 0;
  int high = n - 1;
  int key;
  char skey[MAKS];
  search(&key, skey, mod);

  while (low <= high) {
    int mid = low + (high - low) / 2;

    switch (mod) {
    case 1:
      if (arr[mid].no == key) {
        printf("Berhasil ditemukan \n");
        return mid;
      }
      if (arr[mid].no < key)
        low = mid + 1;
      else
        high = mid - 1;
      break;
    case 2:
      if (strcasecmp(arr[mid].nama, skey) == 0) {
        printf("Berhasil ditemukan \n");
        return mid;
      }
      if (strcasecmp(arr[mid].nama, skey) < 0)
        low = mid + 1;
      else
        high = mid - 1;
      break;
    case 3:
      if (arr[mid].nilai == key) {
        printf("Berhasil ditemukan \n");
        return mid;
      }
      if (arr[mid].nilai < key)
        low = mid + 1;
      else
        high = mid - 1;
      break;
    }
  }
  return -1;
}

void tukar(sis *a, sis *b) {
  sis temp = *a;
  *a = *b;
  *b = temp;
}

int inuser(sis arr[]) {
  int i = 0;
  char ch = 'y';
  while (ch == 'y' || ch == 'Y') {
    printf("\nMasukkan nama siswa : ");
    fgets(arr[i].nama, MAKS, stdin);
    arr[i].nama[strcspn(arr[i].nama, "\n")] = '\0';

    printf("Masukkan nilai siswa : ");
    scanf("%d", &arr[i].nilai);
    getchar();

    arr[i].no = i + 1;
    i++;

    printf("input lagi ? (y/n) ");
    scanf("%c", &ch);
    getchar();
  }
  return i;
}

void search(int *integer, char string[], int mod) {
  if (mod == 2) {
    printf("\nMasukkan Key (string) : ");
    fgets(string, MAKS, stdin);
    string[strcspn(string, "\n")] = '\0';
  } else {
    printf("\nMasukkan Key (int) : ");
    scanf("%d", integer);
    getchar();
  }
}

int bandingkan(sis a, sis b, int kolom) {
  if (kolom == 1)
    return (a.no <= b.no);
  else if (kolom == 2)
    return (strcasecmp(a.nama, b.nama) <= 0);
  else
    return (a.nilai <= b.nilai);
}

void quickSort(sis arr[], int low, int high, int kolom) {
  if (low < high) {
    int pi = partition(arr, low, high, kolom);
    quickSort(arr, low, pi - 1, kolom);
    quickSort(arr, pi + 1, high, kolom);
  }
}

int partition(sis arr[], int low, int high, int kolom) {
  sis pivot = arr[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (bandingkan(arr[j], pivot, kolom)) {
      i++;
      tukar(&arr[i], &arr[j]);
    }
  }
  tukar(&arr[i + 1], &arr[high]);
  return (i + 1);
}
