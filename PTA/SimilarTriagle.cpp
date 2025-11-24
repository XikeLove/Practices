#include <stdio.h>
#include <stdbool.h>

long long A_a, A_b, A_c, B_a, B_b, B_c;

bool canMakeTriangle(long long a, long long b, long long c) {
    return (a + b > c && a + c > b && b + c > a);
}

bool similarTriangle(long long a1, long long b1, long long c1,
                     long long a2, long long b2, long long c2) {
    return (a1 * b2 == a2 * b1) &&
           (b1 * c2 == c1 * b2) &&
           (c1 * a2 == a1 * c2);
}

void swap_ll(long long *a, long long *b) {
    long long t = *a;
    *a = *b;
    *b = t;
}

void solve(void) {
    bool A_can = canMakeTriangle(A_a, A_b, A_c);
    bool B_can = canMakeTriangle(B_a, B_b, B_c);
    if (!A_can || !B_can) {
        if (!A_can && !B_can) {
            puts("Oh My God!");
        } else if (!A_can) {
            puts("Sorry Bob");
        } else {
            puts("Sorry Alice");
        }
    } else {
        if (similarTriangle(A_a, A_b, A_c, B_a, B_b, B_c)) {
            puts("Unbelievable");
        } else {
            puts("Amazing");
        }
    }
}

int main(void) {
    while (scanf("%lld %lld %lld %lld %lld %lld",
                 &A_a, &A_b, &A_c, &B_a, &B_b, &B_c) == 6) {
        if (A_a > A_b) swap_ll(&A_a, &A_b);
        if (A_a > A_c) swap_ll(&A_a, &A_c);
        if (A_b > A_c) swap_ll(&A_b, &A_c);
        if (B_a > B_b) swap_ll(&B_a, &B_b);
        if (B_a > B_c) swap_ll(&B_a, &B_c);
        if (B_b > B_c) swap_ll(&B_b, &B_c);
        solve();
    }
    return 0;
}
