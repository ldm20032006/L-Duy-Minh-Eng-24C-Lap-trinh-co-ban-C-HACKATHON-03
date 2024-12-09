#include <stdio.h>


int Ktsonguyento(int n) {
    if (n <= 1) return 0; // Không phai so nguyên to
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; // Khong phai so nguyên to
    }
    return 1; // La so nguyen to
}


int nhapmang(int arr[]) {
    int size;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        printf("Nhap phan tu arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    return size;
}


void inmang(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d", i, arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("\n");
}


int Demsonguyento(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (Ktsonguyento(arr[i])) {
            count++;
        }
    }
    return count;
}


int nhothu2(int arr[], int size) {
    int min = __INT_MAX__, secondMin = __INT_MAX__;
    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            secondMin = min;
            min = arr[i];
        } else if (arr[i] > min && arr[i] < secondMin) {
            secondMin = arr[i];
        }
    }
    return secondMin;
}


int themphantu(int arr[], int size, int element, int pos) {
    if (pos < 0 || pos > size) {
        printf("Vi tri khong hop le\n");
        return size;
    }
    for (int i = size; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    return size + 1;
}


int xoaphantutaivitri(int arr[], int size, int pos) {
    if (pos < 0 || pos >= size) {
        printf("Vi tri khong hop le!\n");
        return size;
    }
    for (int i = pos; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}


void giamdan(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


int timkiemnhiphan(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == target) return 1; // Tim thay
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return 0; // Khong tim thay
}


int xoaphantutrung(int arr[], int size) {
    int unique[size], newSize = 0;
    for (int i = 0; i < size; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == unique[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unique[newSize++] = arr[i];
        }
    }
    for (int i = 0; i < newSize; i++) {
        arr[i] = unique[i];
    }
    return newSize;
}


void Daonguocmang(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

void menu() {
    int arr[100], size = 0, choice;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap so phan tu và gia tri cho mang\n");
        printf("2. In ra gia tri cac phan tu trong mang\n");
        printf("3. Dem so luong cac so nguyen to\n");
        printf("4. Tim gia tri nho thu hai\n");
        printf("5. Them mot phan tu vao vi tri ngau nhien\n");
        printf("6. Xoa phan tu tai mot vi tri cu the\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Tim kiem phan tu (Binary Search)\n");
        printf("9. Xoa toan bo phan tu trung lap\n");
        printf("10. Dao nguoc mang\n");
        printf("11. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                size = nhapmang(arr);
                break;
            case 2:
                inmang(arr, size);
                break;
            case 3:
                printf("So luong so nguyen to: %d\n", Demsonguyento(arr, size));
                break;
            case 4:
                printf("Gia tri nho thu hai: %d\n", nhothu2(arr, size));
                break;
            case 5: {
                int element, pos;
                printf("Nhap phan tu can them: ");
                scanf("%d", &element);
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                size = themphantu(arr, size, element, pos);
                break;
            }
            case 6: {
                int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                size = xoaphantutaivitri(arr, size, pos);
                break;
            }
            case 7:
                giamdan(arr, size);
                printf("Mang sau khi sap xep giam dan:\n");
                inmang(arr, size);
                break;
            case 8: {
                int target;
                printf("Nhap phan tu can tim: ");
                scanf("%d", &target);
                if (timkiemnhiphan(arr, size, target)) {
                    printf("Phan tu %d co ton tai trong mang.\n", target);
                } else {
                    printf("Phan tu %d khong ton tai trong mang.\n", target);
                }
                break;
            }
            case 9:
                size = xoaphantutrung(arr, size);
                printf("Mang sau khi xoa phan tu trung lap:\n");
                inmang(arr, size);
                break;
            case 10:
                Daonguocmang(arr, size);
                printf("Mang sau khi dao nguoc:\n");
                inmang(arr, size);
                break;
            case 11:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while (choice != 11);
}

int main() {
    menu();
    return 0;
}








