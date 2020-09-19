#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct {
    int type, x, y;
} Prosvet;

void read_n(int *const n) {
     do {
        printf("Enter n: ");
        scanf("%d", n);
        printf("\n");

        if (*n <= 0) {
            printf("n is invalid. Try again.\n");
        } else if (*n > 500) {
            printf("n is too big. Try again.\n");
        }
    } while (*n <= 0 || *n > 500);

    return;
}

int enter_cube(const int *const n, int ***const cube) {
    int i, j, k;

    for (i = 0; i < *n; i++) {
        printf("layer %d:\n", i + 1);

        for (j = 0; j < *n; j++) {
            for (k = 0; k < *n; k++) {
                scanf("%d", &cube[i][j][k]);

                if (cube[i][j][k] != 1  && cube[i][j][k] != 0) {
                    printf("\nYou have entered incorrect data.\n");
                    printf("You will have to enter all the layers of the cube again. :(\n\n");
                    return 1;
                }
            }
        }
        printf("\n");
    }

    return 0;
}

int try(int ***const cube, const int *const n, int i, int j, int k,
        const int di, const int dj, const int dk) {       
    int count = 0;

    while ((i >= 0 && i < *n) && (j >= 0 && j < *n) && (k >= 0 && k < *n)) {
        if (!cube[i][j][k]) {
            count++;
        }

        i += di; j += dj; k += dk;
    }

    return count;
}

int main() {
    int n, i, j, k;
    int ***cube;

    read_n(&n);
    

    cube = (int ***)malloc(n * sizeof(int **));
    if (cube == NULL) {
        printf("Failed to allocate memory. The program has been interrupted.\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        cube[i] = (int **)malloc(n * sizeof(int *));
        if (cube[i] == NULL) {
            printf("Failed to allocate memory. The program has been interrupted.\n");
            return 0;
        }

        for (j = 0; j < n; j++) {
            cube[i][j] = (int *)malloc(n * sizeof(int));
            if (cube[i][j] == NULL) {
                printf("Failed to allocate memory. The program has been interrupted.\n");
                return 0;
            }
        }
    }


    printf("Enter the types of cubes for each layer (0 or 1):\n\n");

    int f = 1;
    while (f) {
        f = enter_cube(&n, cube);
    }


    Prosvet prosvet[n * n * n * 3 + 1];
    int stn = 0;

    /* fixed i */
    for (j = 0; j < n; j++) {
        for (k = 0; k < n; k++) {
            if (try(cube, &n, 0, j, k, 1, 0, 0) == n) {
                stn++;
                prosvet[stn].type = 1;
                prosvet[stn].x = j;
                prosvet[stn].y = k;
            }
        }
    }

    /* fixed j */
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            if (try(cube, &n, i, 0, k, 0, 1, 0) == n) {
                stn++;
                prosvet[stn].type = 2;
                prosvet[stn].x = i;
                prosvet[stn].y = k;
            }
        }
    }

    /* fixed k */
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (try(cube, &n, i, j, 0, 0, 0, 1) == n) {
                stn++;
                prosvet[stn].type = 3;
                prosvet[stn].x = i;
                prosvet[stn].y = j;
            }
        }
    }


    if (stn) {
        printf("The number of prosvets: %d\n", stn);

        for (i = 1; i <= stn; i++) {
            if (prosvet[i].type == 1) {
                printf("Coordinates: %d %d %d\n", 0, prosvet[i].x, prosvet[i].y);
                printf("Direction of prosvet: down\n");
            } else if (prosvet[i].type == 2) {
                printf("Coordinates: %d %d %d\n", prosvet[i].x, 0, prosvet[i].y);
                printf("Direction of prosvet: straight\n");
            } else if (prosvet[i].type == 3) {
                printf("Coordinates: %d %d %d\n", prosvet[i].x, prosvet[i].y, 0);
                printf("Direction of prosvet: sideways\n");
            }

            printf("\n");
        }
    } else {
        printf("The cube hasn't any prosvets. :(\n");
    }


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            free(cube[i][j]);
        }
        free(cube[i]);
    }
    free(cube);


    return 0;
}