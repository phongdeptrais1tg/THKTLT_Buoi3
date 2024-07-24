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
void xuatBien(int a[MAX][MAX], int m, int n) {
    printf("Phan tu duong bien:\n");
    for (int j = 0; j < n; j++) printf("%4d", a[0][j]);
    printf("\n");
    for (int i = 1; i < m - 1; i++) {
        printf("%4d", a[i][0]);
        for (int j = 1; j < n - 1; j++) printf("    ");
        printf("%4d\n", a[i][n - 1]);
    }
    for (int j = 0; j < n; j++) printf("%4d", a[m - 1][j]);
    printf("\n");
}
void xuatCucDai(int a[MAX][MAX], int m, int n) {
    printf("Phan tu cuc dai:\n");
    for (int i = 1; i < m - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] &&
                a[i][j] > a[i][j - 1] && a[i][j] > a[i][j + 1]) {
                printf("%4d", a[i][j]);
            }
            else {
                printf("    ");
            }
        }
        printf("\n");
    }
}

void xuatDongChan(int a[MAX][MAX], int m, int n) {
    printf("Dong chi chua so chan:\n");
    for (int i = 0; i < m; i++) {
        int soChan = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                soChan = 0;
                break;
            }
        }
        if (soChan) {
            for (int j = 0; j < n; j++) {
                printf("%4d", a[i][j]);
            }
            printf("\n");
        }
    }
}
void sapXepDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i][j] > a[i][k]) {
                    int temp = a[i][j];
                    a[i][j] = a[i][k];
                    a[i][k] = temp;
                }
            }
        }
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
        printf("4. Xuat cac phan tu thuoc cac duong bien\n");
        printf("5. Xuat cac phan tu cuc dai\n");
        printf("6. Xuat dong chi chua so chan\n");
        printf("7. Sap xep mang a tang theo tung dong\n");
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
        case 4:
            xuatBien(a, m, n);
            break;
        case 5:
            xuatCucDai(a, m, n);
            break;
        case 6:
            xuatDongChan(a, m, n);
            break;
        case 7:
            sapXepDong(a, m, n);
            xuatMaTran(a, m, n);
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
