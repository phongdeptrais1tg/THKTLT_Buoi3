#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTranNgauNhien(int a[MAX][MAX], int m, int n, int min, int max) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}

void xuatCotChiChuaSoLe(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        int chiChuaSoLe = 1;
        for (int i = 0; i < m; i++) {
            if (a[i][j] % 2 == 0) {
                chiChuaSoLe = 0;
                break;
            }
        }
        if (chiChuaSoLe) {
            printf("Cot %d: ", j);
            for (int i = 0; i < m; i++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
    }
}
int main() {
    int a[MAX][MAX];
    int m, n;
    printf("Nhap so dong m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Tao va xuat ma tran ngau nhien\n");
        printf("2. Xuat cac cot chi chua so le\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            taoMaTranNgauNhien(a, m, n, 0, 100);
            xuatMaTran(a, m, n);
            break;
        case 2:
            xuatCotChiChuaSoLe(a, m, n);
            break;
        case 0:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
            break;
        }
    } while (choice != 0);

    return 0;
}