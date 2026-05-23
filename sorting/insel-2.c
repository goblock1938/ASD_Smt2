#include <stdio.h>
#include <string.h>
#define MAKS 20

typedef struct data {
  int no;
  char nama[MAKS];
  char nilai;
} Data;

void insertion(Data[], int, int);
void selection(Data[], int, int);
void tampil(Data[], int);
void tukar(Data *, Data *);
int input(Data[]);
void copy(Data *, Data *);

int main() {
  int choice_1, choice_2;
  Data arr[MAKS], bak[MAKS];
  int n = input(arr);
  copy(arr, bak);
  do {

    tampil(arr, n);
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
      insertion(arr, n, choice_2);
      break;
    case 2:
      selection(arr, n, choice_2);
      break;
    default:
      printf("INVALID CHOICE METHODE !!\n");
      break;
    }
    printf("Kondisi Akhir \n");
    tampil(arr, n);
    copy(bak, arr);
  } while (choice_1 != 3);
}

void insertion(Data arr[], int n, int mode) {
  Data key;
  int j;
  for (int i = 1; i < n; i++) {
    key = arr[i]; // Simpan seluruh struct
    j = i - 1;

    if (mode == 2) { // Descending
      while (j >= 0 && arr[j].no < key.no) {
        arr[j + 1] = arr[j];
        j--;
      }
    } else { // Ascending
      while (j >= 0 && arr[j].no > key.no) {
        arr[j + 1] = arr[j];
        j--;
      }
    }
    arr[j + 1] = key;
  }
}

void selection(Data arr[], int n, int mode) {
  int min;
  for (int i = 0; i < n - 1; i++) {
    min = i;
    for (int j = i + 1; j < n; j++) { // Gunakan n, bukan MAKS[cite: 1]
      if (mode == 2) {
        if (arr[j].no > arr[min].no)
          min = j;
      } else {
        if (arr[j].no < arr[min].no)
          min = j;
      }
    }
    tukar(&arr[i], &arr[min]); // Tukar berdasarkan pointer[cite: 1]
  }
}

void tampil(Data arr[], int n) {
  printf("%-3s %-20s %5s \n", "No", "Nama", "Nilai");
  for (int i = 0; i < n; i++)
    printf("%-3d%-20s%c\n", arr[i].no, arr[i].nama, arr[i].nilai);
  printf("\n");
}

void tukar(Data *a, Data *b) {
  Data temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

int input(Data a[]) {
  int i = 0;
  char choice;
  printf("INPUT USER\n");
  do {

    printf("Masukkan nomor : ");
    scanf("%d", &a[i].no);
    getchar();
    printf("Masukkan nama : ");
    fgets(a[i].nama, MAKS, stdin);
    a[i].nama[strcspn(a[i].nama, "\n")] = '\0';
    printf("Masukkan nilai : ");
    scanf("%c", &a[i].nilai);
    getchar();
    printf("Lagi (Y/n) : ");
    scanf("%c", &choice);
    getchar();
    if (choice == 'n')
      break;
    i++;
  } while (choice == 'y');
  return i + 1;
}

void copy(Data *sc, Data *dest) {
  for (int i = 0; i < MAKS; i++)
    dest[i] = sc[i];
}
