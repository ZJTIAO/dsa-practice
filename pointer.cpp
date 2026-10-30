#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    int a = 5;
    int *p = &a;

    printf("a 的值=%d\n", a);
    printf("p 里存的地址=%p\n", (void *)p);
    printf("顺着 p 取到=%d\n", *p);

    *p = 99;
    printf("改完 a=%d\n", a);
    printf("改完 p 还指着原来那间=%p\n", (void *)p);

    int s[3] = {10, 20, 30};
    int *q = s;
    printf("s[1]=%d  *(q+1)=%d\n", s[1], *(q + 1));
    printf("s[2]=%d  *(q+2)=%d\n", s[2], *(q + 2));

    struct Point pt;
    pt.x = 3;
    pt.y = 4;
    struct Point *pp = &pt;
    printf("pt.x=%d  pp->x=%d\n", pt.x, pp->x);
    (*pp).y = 40;
    printf("改完 pt.y=%d  pp->y=%d\n", pt.y, pp->y);

    return 0;
}