#include <stdio.h>
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
void tukar(sis *, sis *);
void search(int *, char[], int);

int main() {
  sis arr[MAKS];
  int n, choice, mode, hasil;
  inuser(arr);

  while (1) {
    printf("Searching Metode\n0. Exit\n1. Sequent tanpa Sorting\n2. Sequent "
           "dengan Sorting\n3. Binary\n");
    printf("Pilihan : ");
    scanf("%d", &choice);
    if (choice == 0) {
      printf("Selesai\n");
      break;
    }
    printf("Order by :\n1. No\n2. Nama\n3. Nilai\n");
    printf("Pilihan : ");
    scanf("%d", &mode);

    switch (choice) {
    case 1:
      hasil = sequent(arr, n, mode);
      break;
    case 2:
      hasil = sequent(arr, n, mode);
      break;
    case 3:
      hasil = binary(arr, n, mode);
      break;
    }
    if (hasil != -1) {
      printf("Data Ditemukan\n");
      printf("jumlah perbandingan : %d\n", hasil);
    } else
      printf("Data tidak ditemukan \n");
  };
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
      // No diff
      if (arr[mid].no == key) {
        printf("Berhasil di temukan \n");
        return mid;
      }

      if (arr[mid].no < key) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
      break;
    case 2:
      // Nama diff
      if (strcasecmp(arr[mid].nama, skey) == 0) {
        printf("Berhasil di temukan \n");
        return mid;
      }

      if (strcasecmp(arr[mid].nama, skey) < 0) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
      break;
    case 3:
      // Nilai diff
      if (arr[mid].nilai == key) {
        printf("Berhasil di temukan \n");
        return mid;
      }

      if (arr[mid].nilai < key) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
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
    printf("Masukkan nama siswa : ");
    fgets(arr[i].nama, MAKS, stdin);
    arr[i].nama[strcspn(arr[i].nama, "\n")] = '\0';
    printf("Masukkan nilai siswa : ");
    scanf("%d", &arr[i].nilai);
    getchar();

    arr[i].no = i + 1;
    i++;

    printf("input lagi ? ");
    scanf("%c", &ch);
    getchar();
  }
  return i;
}

void search(int *integer, char string[], int mod) {
  if (mod == 2) {
    printf("Masukkan Key (string) : ");
    fgets(string, MAKS, stdin);
    string[strcspn(string, "\n")] = '\0';
  } else {
    printf("Masukkan Key (int) : ");
    scanf("%d", integer);
  }
}
