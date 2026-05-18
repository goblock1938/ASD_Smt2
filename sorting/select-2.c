#include <stdio.h>

void insort();
void selsort();
int asc();

int main() {
  int choice, asc;
  do {
    printf("MENU METODE SORTING\n");
    printf("1. INSERTION SORT\n");
    printf("2. SELECTION SORT\n");
    printf("3. Exit\n");
    printf("Pilihan : ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      insort();
      break;
    case 2:
      selsort();
      break;
    case 3:
      break;
    default:
      printf("INVALID CHOICE !!\n");
      break;
    }
  } while (choice != 3);
}

int asc() {
  int choice;
  printf("MENU PENGURUTAN : \n");
  printf("1. ASCENDING\n");
  printf("2. DESCENDING\n");
  printf("Pilihan : ");
  scanf("%d", &choice);
  return choice;
}
