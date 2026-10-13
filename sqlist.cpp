#include <stdio.h>

struct SqList {
    int data[10];
    int length;
};

int main() {
    struct SqList L;
    L.length = 0;
    printf("length=%d\n", L.length);
    return 0;
}