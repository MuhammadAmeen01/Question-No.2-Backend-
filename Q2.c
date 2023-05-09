#include <stdio.h>
int FRecursive(int n) { //this is a recursive function 
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return FRecursive(n - 3) + FRecursive(n - 2);
}
int FIterative(int n) {
    if (n == 0) return 0; //this function follows the iterative method in a loop to solve the problem
    if (n == 1) return 1;
    if (n == 2) return 2;

    int a = 0, b = 1, c = 2, i;
    for (i = 3; i <= n; i++) {
        int d = c + b;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int FMemo(int n) { //this method follows memoization technique, store the result in a array so that we don't have to compute it again.
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;

    int memo[n+1];
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    int i;
    for (i = 3; i <= n; i++) {
        memo[i] = memo[i-3] + memo[i-2];
    }

    return memo[n];
}

int main() {
   int var=FRecursive(10);
   int var1=FIterative(10);
   int var2=FMemo(10);
   printf("Recursive Result: %d \n",var);
   printf("Iterative Result: %d \n",var);
   printf("Memoization Result: %d \n",var);
   return 0;
}
