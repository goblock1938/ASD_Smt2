#include <stdio.h>

/* Soal :
    a. Buatlah program menghitung faktorial dalam bentuk iterasi
    b. Buatlah program menghitung faktorial dalam bentuk rekursi
    c. Buatlah program menghitung faktorial dalam bentuk rekursi tail
    d. Buatlah menu untuk menampilkan pilihan faktorial menggunakan : iterasi,
    rekursi & rekursi tail. Setelah itu bandingkan waktu komputasi masing-masing
    untuk menghitung faktorial untuk n yang cukup besar */

int iteration(int);
int rekursi(int);
int tail(int, int);

int main() {
  int choice, fac;
  printf("PENGHITUNG FAKTORIAL ITERASI VS REKURSI\n");
  printf("1. iterasi\n");
  printf("2. rekursi\n");
  printf("3. rekursi tail\n");
  printf("masukkan pilihan kalian : ");
  scanf("%d", &choice);
  printf("nilai N dari faktorial : ");
  scanf("%d", &fac);
  switch (choice) {
  case 1:
    printf("nilai faktorial iterasi n = %d, bernilai : %d\n", fac,
           iteration(fac));
    break;
  case 2:
    printf("nilai faktorial rekursi n = %d, bernilai : %d\n", fac,
           rekursi(fac));
    break;
  case 3:
    printf("nilai faktorial rekursi tail n = %d, bernilai : %d\n", fac,
           tail(fac, 1));
    break;
  default:
    printf("invalid choice !!\n");
    break;
  }
}

int iteration(int n) {
  if (n == 1)
    return n;

  int temp = 1;

  while (n != 1) {
    temp *= n--;
  }

  return temp;
}

int rekursi(int n) {
  if (n == 1)
    return 1;

  return n * rekursi(n - 1);
}

int tail(int n, int hasil) {
  if (n == 0 || n == 1)
    return hasil;
  return tail(n - 1, hasil * n);
}
