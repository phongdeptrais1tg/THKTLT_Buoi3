#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTranVuong(int a[MAX][MAX], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = min + rand() % (max - min + 1);
        }
    }
}

void xuatMaTran(int a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }
}
int main() {
    srand(time_t(NULL));
    int a[MAX][MAX];
    int n, min, max;
    int chon;

    do {
        printf("Nhap cap ma tran vuong n (>= 5): ");
        scanf_s("%d", &n);
    } while (n < 5);

    printf("Nhap gia tri nho nhat: ");
    scanf_s("%d", &min);
    printf("Nhap gia tri lon nhat: ");
    scanf_s("%d", &max);

    taoMaTranVuong(a, n, min, max);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tao va xuat ma tran\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf_s("%d", &chon);

        switch (chon) {
        case 1:
            xuatMaTran(a, n);
            break;
        case 0:
            printf("Thoat chuong trinh\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (chon != 0);

    return 0;
}
