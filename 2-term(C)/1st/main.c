#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void end() {
  printf("Incorect input");
  exit(0);
}

int main() {
  int n;

  printf("Enter a number less  than 100000:\n");
  scanf("%d",&n);

  if (n < 0) end();
  if (n > 100000) end();

  int i;
  for (i = 2; i <= n; i++) {
    int sum = 1;
    int m = sqrt(i);
    int j;
    
    for (j = 2; j <= m; j++) 
      if (i % j == 0) {
        sum = sum + j;
        if (i != i / j) sum = sum + (i / j);  
      }


    if (sum == i) printf("%d ", i);
  }
  
  return 0;
}
