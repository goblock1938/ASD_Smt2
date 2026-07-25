#include <stdio.h>
#include <stdlib.h>

int fpb(int, int);
void fibonacciIterasi(int);
void tampilFibonacciRekursi(int);
int cekPrimaRekursi(int, int);

int main() {
  int pilihan;
  int a, b, n;

  do {
    printf("\nMENU PROGRAM REKURSI & ITERASI\n");
    printf("1. Cari FPB (Rekursi)\n");
    printf("2. Fibonacci Iterasi\n");
    printf("3. Fibonacci Rekursi\n");
    printf("4. Cek Bilangan Prima (Rekursi)\n");
    printf("5. Keluar\n");
    printf("Pilihan : ");
    scanf("%d", &pilihan);

    switch (pilihan) {

    case 1:
      printf("Masukkan bilangan pertama : ");
      scanf("%d", &a);

      printf("Masukkan bilangan kedua : ");
      scanf("%d", &b);

      printf("FPB dari %d dan %d adalah %d\n", a, b, fpb(a, b));
      break;

    case 2:
      printf("Jumlah deret Fibonacci : ");
      scanf("%d", &n);

      fibonacciIterasi(n);
      break;

    case 3:
      printf("Jumlah deret Fibonacci : ");
      scanf("%d", &n);

      tampilFibonacciRekursi(n);
      break;

    case 4:
      printf("Masukkan bilangan : ");
      scanf("%d", &n);

      if (cekPrimaRekursi(n, 2))
        printf("%d adalah bilangan prima\n", n);
      else
        printf("%d bukan bilangan prima\n", n);

      break;

    case 5:
      printf("Program selesai.\n");
      break;

    default:
      printf("Pilihan tidak valid!\n");
    }

  } while (pilihan != 5);

  return 0;
}

int fpb(int a, int b) {
  a = abs(a);
  b = abs(b);

  if (b == 0)
    return a;
  return fpb(b, a % b);
}

void fibonacciIterasi(int n) {
  if (n <= 0) {
    printf("jumlah deret harus lebih dari 0\n");
    return;
  }
  int a = 0, b = 1, c;

  printf("Deret Fibonacci (Iterasi): ");

  for (int i = 1; i <= n; i++) {
    printf("%d ", a);

    c = a + b;
    a = b;
    b = c;
  }

  printf("\n");
}

int fibonacciRekursi(int n) {
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  return fibonacciRekursi(n - 1) + fibonacciRekursi(n - 2);
}

void tampilFibonacciRekursi(int n) {
  if (n <= 0) {
    printf("jumlah deret harus lebih dari 0\n");
    return;
  }

  printf("Deret Fibonacci (Rekursi): ");

  for (int i = 0; i < n; i++) {
    printf("%d ", fibonacciRekursi(i));
  }

  printf("\n");
}

int cekPrimaRekursi(int n, int i) {
  if (n <= 1)
    return 0; // 0, 1, dan bilangan negatif bukan prima
  if (n == 2)
    return 1; // 2 adalah prima
  if (n % i == 0)
    return 0; // Habis dibagi angka lain -> bukan prima
  if (i * i > n)
    return 1; // Sudah melewati batas akar kuadrat -> pasti prima

  return cekPrimaRekursi(n, i + 1);
}
