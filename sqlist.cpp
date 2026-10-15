#include <stdio.h>

#define MAXSIZE 10

struct SqList {
    int data[MAXSIZE];
    int length;
};

void InitList(struct SqList L) {
    L.length = 0
}
int main() {
    struct SqList L;
    L.length = 5;
    InitList(L);
    printf("length=%d\n", L.length);
    return 0;
}