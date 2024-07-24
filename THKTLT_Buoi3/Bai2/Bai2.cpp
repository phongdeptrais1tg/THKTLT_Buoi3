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
void xuatCheoChinh(int a[MAX][MAX], int n) {
    printf("Phan tu tren duong cheo chinh: ");
    for (int i = 0; i < n; i++) {
        printf("%4d", a[i][i]);
    }
    printf("\n");
}
void xuatCheoSongSong(int a[MAX][MAX], int n) {
    printf("Phan tu tren duong cheo song song duong cheo chinh:\n");
    for (int k = 1; k < n; k++) {
        for (int i = 0; i < n - k; i++) {
            printf("%4d", a[i][i + k]);
        }
        printf("\n");
        for (int i = 0; i < n - k; i++) {
            printf("%4d", a[i + k][i]);
        }
        printf("\n");
    }
}
void maxTamGiacTren(int a[MAX][MAX], int n) {
    int max = a[0][1];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }
    printf("Phan tu lon nhat trong tam giac tren duong cheo chinh: %d\n", max);
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
        printf("2. Xuat cac phan tu tren duong cheo chinh\n");
        printf("3. Xuat cac phan tu thuoc duong cheo song song voi duong cheo chinh\n");
        printf("4. Tim phan tu lon nhat thuoc tam giac tren cua duong cheo chinh\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf_s("%d", &chon);

        switch (chon) {
        case 1:
            xuatMaTran(a, n);
            break;
        case 2:
            xuatCheoChinh(a, n);
            break;
        case 3:
            xuatCheoSongSong(a, n);
            break;
        case 4:
            maxTamGiacTren(a, n);
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
