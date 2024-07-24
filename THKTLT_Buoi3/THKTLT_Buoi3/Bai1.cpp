#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void taoMaTran(int a[MAX][MAX], int m, int n, int min, int max) {
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
void tongTungDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int tong = 0;
        for (int j = 0; j < n; j++) {
            tong += a[i][j];
        }
        printf("Tong dong %d: %d\n", i, tong);
    }
}

void lonNhatTungCot(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        int max = a[0][j];
        for (int i = 1; i < m; i++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
        printf("Phan tu lon nhat cot %d: %d\n", j, max);
    }
}
int main() {
    srand(time_t(NULL));
    int a[MAX][MAX];
    int m, n, min, max;
    int chon;

    printf("Nhap so dong m: ");
    scanf_s("%d", &m);
    printf("Nhap so cot n: ");
    scanf_s("%d", &n);
    printf("Nhap gia tri nho nhat: ");
    scanf_s("%d", &min);
    printf("Nhap gia tri lon nhat: ");
    scanf_s("%d", &max);

    taoMaTran(a, m, n, min, max);

    do {
        printf("\n===== MENU =====\n");
        printf("1. Tao va xuat ma tran\n");
        printf("2. Tinh va xuat tong gia tri tung dong\n");
        printf("3. Xuat phan tu lon nhat tren tung cot\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf_s("%d", &chon);
        switch (chon) {
        case 1:
            xuatMaTran(a, m, n);
            break;
        case 2:
            tongTungDong(a, m, n);
            break;
        case 3:
            lonNhatTungCot(a, m, n);
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
