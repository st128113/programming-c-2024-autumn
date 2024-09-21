#include<iostream>
int main(int argc, char* argv[])
{
    int h = 0;
    int a = 0;
    int b = 0;
    int d = 0;
    scanf("%d", &h);
    scanf("%d", &a);
    scanf("%d", &b);
    
    h = h + (((a - b) - h % (a - b)) % (a - b));
    h = (h - a) * ((h / a) - ((h - a) / a));
    d++;
    h = h + (((a - b) - h % (a - b)) % (a - b));
    d += h / (a - b);
    
    printf("%d", d);
    
    return EXIT_SUCCESS;
}
