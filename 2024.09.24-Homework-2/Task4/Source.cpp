#include<iostream>

int main(int argc, char* argv[])
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int f = 0;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &d);
    scanf("%d", &e);
    scanf("%d", &f);

    if ((a == d && b == e && c == f) || (a == d && b == f && c == e) ||
        (a == e && b == d && c == f) || (a == e && b == f && c == d) ||
        (a == f && b == d && c == e) || (a == f && b == e && c == d)) {
        printf("Boxes are equal");
    }
    else {
        if ((a <= d && b <= e && c <= f) || (a <= d && b <= f && c <= e) ||
            (a <= e && b <= d && c <= f) || (a <= e && b <= f && c <= d) ||
            (a <= f && b <= d && c <= e) || (a <= f && b <= e && c <= d)) {
            printf("The first box is smaller than the second one");
        }
        else if ((d <= a && e <= b && f <= c) || (d <= a && e <= c && f <= b) ||
            (e <= a && d <= b && f <= c) || (e <= a && d <= c && f <= b) ||
            (f <= a && d <= b && e <= c) || (f <= a && d <= c && e <= b)) {
            printf("The first box is larger than the second one");
        }
        else {
            printf("Boxes are incomparable");
        }
    }


    return EXIT_SUCCESS;
}