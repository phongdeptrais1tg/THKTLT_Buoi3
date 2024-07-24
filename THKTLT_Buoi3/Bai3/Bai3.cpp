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
int timPhanTuLonNhatTrenBien(int a[MAX][MAX], int m, int n) {
    int max = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[0][i] > max) max = a[0][i];
        if (a[m - 1][i] > max) max = a[m - 1][i];
    }
    for (int i = 1; i < m - 1; i++) {
        if (a[i][0] > max) max = a[i][0];
        if (a[i][n - 1] > max) max = a[i][n - 1];
    }
    return max;
}
int demPhanTuCoChuSo2(int a[MAX][MAX], int m, int n) {
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num != 0) {
                if (num % 10 == 2) {
                    count++;
                    break;
                }
                num /= 10;
            }
        }
    }
    return count;
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
        printf("3. Tim phan tu lon nhat tren bien\n");
        printf("4. Dem phan tu co chu so 2\n");
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
        case 3:
            printf("Phan tu lon nhat tren bien: %d\n", timPhanTuLonNhatTrenBien(a, m, n));
            break;
        case 4:
            printf("So phan tu co chu so 2: %d\n", demPhanTuCoChuSo2(a, m, n));
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