#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Soal 1 : Buatlah sebuah program yang menulis angka dari n ke 0 dengan
            menggunakan proses rekursi.
   Soal 2 : Tulis sebuah program untuk menulis angka
            dari 0 ke n dengan menggunakan proses rekursi.
   Soal 3 : Tuliskan program dengan rekursi untuk membalik suatu kalimat.
            Sebagai contoh, kalimat 'ALGORITMA' dibalik menjadi 'AMTIROGLA'.
            Jadikan panjang kalimat sebagai parameter fungsi rekursi */
void soal1(int);
void soal2(int);
void soal3(char[], int);

int main() {
  int n, choice;
  char ch[64];
  printf("1. dari n ke 0\n");
  printf("2. dari 0 ke n\n");
  printf("3. pembalik kalimat\n");
  printf("\npilihanmu : ");
  scanf("%d", &choice);
  getchar();
  if (choice == 1 || choice == 2) {
    printf("masukkan nilai N : ");
    scanf("%d", &n);
  }
  switch (choice) {
  case 1:
    soal1(n);
    break;
  case 2:
    soal2(n);
    break;
  case 3:
    printf("masukkan kata : ");
    fgets(ch, 64, stdin);
    ch[strcspn(ch, "\n")] = '\0'; // menghapus endline ('\n')
    printf("hasil : ");
    soal3(ch, strlen(ch));
    break;
  }
}

void soal1(int x) {
  if (x <= 0)
    exit(0);
  printf("nilai ke - %d\n", x);
  soal1(x - 1);
}

void soal2(int x) {
  static int i = 0;

  if (x <= 0)
    exit(0);
  printf("nilai ke - %d\n", ++i);
  soal2(x - 1);
}

void soal3(char temp[], int len) {
  if (len < 0) {
    printf("\n");
    exit(0);
  }
  printf("%c", temp[len--]);
  soal3(temp, len);
}
