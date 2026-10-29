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
    if (i < 1 || i > L.length + 1) {
        return 0;
    }
    for (int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return 1;
}

int GetElem(struct SqList L, int i, int *e) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    *e = L.data[i - 1];
    return 1;
}

int LocateElem(struct SqList L, int e) {
    for (int j = 0; j < L.length; j++) {
        if (L.data[j] == e) {
            return j + 1;
        }
    }
    return 0;
}

int ListDelete(struct SqList &L, int i, int *e) {
    if (i < 1 || i > L.length) {
        return 0;
    }
    *e = L.data[i - 1];
    for (int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return 1;
}

int main() {
    struct SqList L;
    InitList(L);

    int v = -1;
    int e1 = GetElem(L, 1, &v);
    printf("空表取第1个: %d, v=%d\n", e1, v);

    ListInsert(L, 1, 7);
    ListInsert(L, 2, 9);
    ListInsert(L, 3, 4);
    printf("三次插入: length=%d, data=%d %d %d\n", L.length, L.data[0], L.data[1], L.data[2]);

    v = -1;
    int ok = GetElem(L, 2, &v);
    printf("取第2个: %d, v=%d\n", ok, v);

    v = -1;
    ok = GetElem(L, 5, &v);
    printf("取第5个: %d, v=%d\n", ok, v);

    printf("找9: 位置=%d\n", LocateElem(L, 9));

    int del = 0;
    int od = ListDelete(L, 2, &del);
    printf("删第2个: %d, 被删=%d, length=%d, data=%d %d\n", od, del, L.length, L.data[0], L.data[1]);

    del = 0;
    od = ListDelete(L, 5, &del);
    printf("删第5个: %d, 被删=%d, length=%d\n", od, del, L.length);

    InitList(L);
    int cnt = 0;
    for (int k = 1; k <= 10; k++) {
        cnt = cnt + ListInsert(L, k, k * 10);
    }
    printf("装满10个: 成功%d次, length=%d\n", cnt, L.length);
    int full = ListInsert(L, 11, 99);
    printf("满表再插第11个: %d, length=%d\n", full, L.length);
    printf("满表找999: 位置=%d\n", LocateElem(L, 999));

    return 0;
}


