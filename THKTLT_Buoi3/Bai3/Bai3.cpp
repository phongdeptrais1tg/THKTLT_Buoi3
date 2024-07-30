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
void xuatPhanTuCucTieu(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isMin = 1;
            if (i > 0 && a[i][j] >= a[i - 1][j]) isMin = 0;
            if (i < m - 1 && a[i][j] >= a[i + 1][j]) isMin = 0;
            if (j > 0 && a[i][j] >= a[i][j - 1]) isMin = 0;
            if (j < n - 1 && a[i][j] >= a[i][j + 1]) isMin = 0;
            if (isMin) {
                printf("a[%d][%d] = %d\n", i, j, a[i][j]);
            }
        }
    }
}
void sapXepDong(int dong[MAX], int n, int isOddRow) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((isOddRow && dong[i] > dong[j]) || (!isOddRow && dong[i] < dong[j])) {
                int temp = dong[i];
                dong[i] = dong[j];
                dong[j] = temp;
            }
        }
    }
}

void sapXepMaTranTheoDong(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        sapXepDong(a[i], n, i % 2 != 0);
    }
}
void sapXepCot(int a[MAX][MAX], int m, int n, int col, int isOddCol) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = i + 1; j < m; j++) {
            if ((isOddCol && a[i][col] < a[j][col]) || (!isOddCol && a[i][col] > a[j][col])) {
                int temp = a[i][col];
                a[i][col] = a[j][col];
                a[j][col] = temp;
            }
        }
    }
}

void sapXepMaTranTheoCot(int a[MAX][MAX], int m, int n) {
    for (int j = 0; j < n; j++) {
        sapXepCot(a, m, n, j, j % 2 != 0);
    }
}
int kiemTraZiczac(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i + 1][j] || a[i][j] < a[i][j + 1]) {
                return 0;
            }
        }
    }
    return 1;
}
void lietKeDongChuaToanGiaTriChan(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int isEvenRow = 1;
        for (int j = 0; j < n; j++) {
            if (a[i][j] % 2 != 0) {
                isEvenRow = 0;
                break;
            }
        }
        if (isEvenRow) {
            printf("Dong %d\n", i);
        }
    }
}
void lietKeDongChuaGiaTriGiamDan(int a[MAX][MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        int isDecreasing = 1;
        for (int j = 0; j < n - 1; j++) {
            if (a[i][j] < a[i][j + 1]) {
                isDecreasing = 0;
                break;
            }
        }
        if (isDecreasing) {
            printf("Dong %d\n", i);
        }
    }
}
int timGiaTriXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int freq[MAX * MAX] = { 0 };
    int maxFreq = 0;
    int maxValue = a[0][0];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            freq[a[i][j]]++;
            if (freq[a[i][j]] > maxFreq) {
                maxFreq = freq[a[i][j]];
                maxValue = a[i][j];
            }
        }
    }
    return maxValue;
}
void timCacChuSoXuatHienNhieuNhat(int a[MAX][MAX], int m, int n) {
    int digitCount[10] = { 0 };
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int num = a[i][j];
            while (num != 0) {
                digitCount[num % 10]++;
                num /= 10;
            }
        }
    }
    int maxCount = 0;
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] > maxCount) {
            maxCount = digitCount[i];
        }
    }
    printf("Cac chu so xuat hien nhieu nhat: ");
    for (int i = 0; i < 10; i++) {
        if (digitCount[i] == maxCount) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
void lietKeCacCotCoTongNhoNhat(int a[MAX][MAX], int m, int n) {
    int minSum = 0;
    for (int i = 0; i < m; i++) {
        minSum += a[i][0];
    }
    for (int j = 1; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum < minSum) {
            minSum = sum;
        }
    }
    printf("Cac cot co tong nho nhat: ");
    for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += a[i][j];
        }
        if (sum == minSum) {
            printf("%d ", j);
        }
    }
    printf("\n");
}
void hoanViHaiCot(int a[MAX][MAX], int m, int col1, int col2) {
    for (int i = 0; i < m; i++) {
        int temp = a[i][col1];
        a[i][col1] = a[i][col2];
        a[i][col2] = temp;
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
        printf("3. Tim phan tu lon nhat tren bien\n");
        printf("4. Dem phan tu co chu so 2\n");
        printf("5. Xuat cac phan tu cuc tieu\n");
        printf("6. Sap xep ma tran theo dong (le tang, chan giam)\n");
        printf("7. Sap xep ma tran theo cot (le giam, chan tang)\n");
        printf("8. Kiem tra ziczac\n");
        printf("9. Liet ke dong chua toan gia tri chan\n");
        printf("10. Liet ke dong chua gia tri giam dan\n");
        printf("11. Tim gia tri xuat hien nhieu nhat\n");
        printf("12. Tim cac chu so xuat hien nhieu nhat\n");
        printf("13. Liet ke cot co tong nho nhat\n");
        printf("14. Hoan vi hai cot\n");
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
        case 5:
            xuatPhanTuCucTieu(a, m, n);
            break;
        case 6:
            sapXepMaTranTheoDong(a, m, n);
            xuatMaTran(a, m, n);
            break;
        case 7:
            sapXepMaTranTheoCot(a, m, n);
            xuatMaTran(a, m, n);
            break;
        case 8:
            printf("Ma tran giam dan ziczac: %s\n", kiemTraZiczac(a, m, n) ? "Co" : "Khong");
            break;
        case 9:
            lietKeDongChuaToanGiaTriChan(a, m, n);
            break;
        case 10:
            lietKeDongChuaGiaTriGiamDan(a, m, n);
            break;
        case 11:
            printf("Gia tri xuat hien nhieu nhat: %d\n", timGiaTriXuatHienNhieuNhat(a, m, n));
            break;
        case 12:
            timCacChuSoXuatHienNhieuNhat(a, m, n);
            break;
        case 13:
            lietKeCacCotCoTongNhoNhat(a, m, n);
            break;
        case 14:
            int col1, col2;
            printf("Nhap hai cot can hoan vi (0 <= col < %d): ", n);
            scanf_s("%d %d", &col1, &col2);
            hoanViHaiCot(a, m, col1, col2);
            xuatMaTran(a, m, n);
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