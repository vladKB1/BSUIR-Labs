#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define sqr(a) ((a) * (a))


void end() {
    printf("Impossible to count.\n");
    exit(0);
}

int main() {
    double x, e;
    int i;

    do {
        printf("Enter x, e: ");
        scanf("%lf%lf", &x, &e);

        if (x > 1000) {
            printf("x is too big. Please, try again.\n\n");
        }
    } while (x > 1000);
 
    double res1 = sin(x), res2 = x, k = x * x * x;
    int n = 1, fact = 6;

    for (i = 4; i <= 10; i += 2) {
        if ((fabs(res1 - res2)) >= e) {
            n++;
            if (n % 2) {
                res2 += k / fact;
            } else {
                res2 -= k / fact;
            }
        } else {
            break;
        }
        
        if (__INT_MAX__ / k <= x * x) {
            end();
        }

        k *= sqr(x);
        fact *= i * (i + 1);
    }

    if (fabs(res1 - res2) >= e) {
        end();
    } else {
        printf("n = %d\n", n);
        printf("sin(x) = %.9lf expression = %.9lf\n", res1, res2);
    }

    return 0;
}