#include <stdio.h> 
 
int main(int argc, char* argv[]) { 
    int H, A, B; 
    scanf("%d", &H); 
    scanf("%d", &A); 
    scanf("%d", &B); 
 
    int N = A - B; 
    int D = (H - A + (N + (N / (N + 1) * (1 - N) + (N == 0))) - 1) / (N + (N / (N + 1) * (1 - N) + (N == 0))) + 1; 
    D = (D + 1) / 2 + (D) / 2; 
 
    printf("%d", D); 
    return 0; 
}
