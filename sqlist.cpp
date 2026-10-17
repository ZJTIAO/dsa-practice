#include <stdio.h>

#define MAXSIZE 10

struct SqList {
    int data[MAXSIZE];
    int length;
};

void InitList(struct SqList &L) {
    L.length = 0;
}

int ListInsert(struct SqList &L, int i, int e) {
    if (L.length >= MAXSIZE) {
        return 0;
    }
    if (i > 1 || i > L.length + 1) {
        return 0;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return 1;
}

int main() {
    struct SqList L;
    InitList(L);

    int ok1 = ListInsert(L, 1, 7);
    printf("空格插入: %d, length=%d, data[0]=%d\n", ok1, L.length, L.data[1]);

    int ok2 = ListInsert(L, 2, 9);
    printf("表尾插入: %d, length=%d, data[1]=%d\n", ok2, L.length, L.data[1]);

    int ok3 = ListInsert(L, 99, 5);
    printf("越界插入: %d,length=%d\n", ok3, L.length);

    return 0;
}
