#include <stdio.h>

int fact(int);
int muta(int, int);
int comb(int, int);

int main() {
  int choice, r, n;
  do {
    printf("\nPERHITUNGAN PERMUTASI DAN KOMBINASI\n");
    printf("1. Permutasi\n");
    printf("2. Kombinasi\n");
    printf("3. Exit\n\n");

    printf("Pilihan : ");
    scanf("%d", &choice);

    if (choice != 3) {
      printf("Nilai n : ");
      scanf("%d", &n);

      printf("Nilai r : ");
      scanf("%d", &r);
    }
    if (n == 0 || r == 0 || n < r) {
      printf("value tidak valid, n harus lebih besar dari r dan tidak boleh "
             "'0' !!\n");
      continue;
    }
    switch (choice) {
    case 1:
      printf("nilai permutasi dari %d! / (%d - %d)! adalah => %d\n", n, n, r,
             muta(n, r));
      break;
    case 2:
      printf("nilai kombinasi dari %d! / %d! (%d - %d)! adalah => %d\n", n, r,
             n, r, comb(n, r));
      break;
    case 3:
      break;

    default:
      printf("INVALID CHOICE !!\n");
      break;
    }
  } while (choice != 3);
}

int fact(int x) {
  if (x <= 1)
    return 1;

  return x * fact(x - 1);
}

int muta(int n, int r) { return fact(n) / fact(n - r); } // n! / (n - r)!

int comb(int n, int r) {
  return fact(n) / (fact(r) * fact(n - r));
} // n! / r! (n - r)!
