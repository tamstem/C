// eratosthenes sieve - to determine prime numbers up to n.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j, *prime;
    printf("Number of elements: ");
    scanf("%d", &n);
    prime = (int *)malloc((n + 1) * sizeof(int));
    if (prime == NULL) {
        printf("Error!");
        exit(0);
    }
    for (i = 0; i <= n; i++)
        prime[i] = 0;
    
    for (i = 2; i * i <= n; i++) {
        if (prime[i] == 0) {
            for (j = i * i; j <= n; j += i) {
                // if %i == 0 postavi na true (1)
                if (j % i == 0)
                    prime[j] = 1;
            }
        }
    }
    for (i = 2; i <= n; i++) {
        if (prime[i] == 0)
            printf("%d ", i);
    }
    free(prime);
    return 0;
}
