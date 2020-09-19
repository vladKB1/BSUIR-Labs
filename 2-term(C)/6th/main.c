#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int n, m;

FILE *fp;
char *file_name = "test.txt";


void file_open() {
    if((fp = fopen(file_name, "r")) == NULL) {
        printf("Error occured while opening %s\n", file_name);
        exit(-1);
    }     
}

void checkPtr(void *ptr) {
    if (ptr == NULL) {
        printf("Failed to allocate memory. The program has stopped working.\n");
        exit(-1);
    }
}

void read(int *x, char *message) {
    do {
        printf("%s", message);
        fscanf(fp, "%d", x);

        if (*x < 0) {
            printf("The number can't be less than zero.\n");
            printf("The program has stopped working.\n"); 
            exit(-1);
        } else if (*x > 1000000) {
            printf("The number is too big.\n");
            printf("The program has stopped working.\n"); 
            exit(-1);
        }
    } while(*x < 0 || *x > 1000000);
}


typedef struct bor {
    struct bor *ptr[2];
    int count;
} Bor;

void bor_add(char *const str, Bor *ptr) {
    int j;

    for (j = 0; j < m; j++) {
        if (ptr->ptr[str[j] - '0'] == NULL) {
            ptr->ptr[str[j] - '0'] = (Bor*)malloc(sizeof(Bor));
            checkPtr(ptr->ptr[str[j] - '0']);
            
            ptr->ptr[str[j] - '0']->ptr[0] = NULL;
            ptr->ptr[str[j] - '0']->ptr[1] = NULL;
            ptr->ptr[str[j] - '0']->count = 0;
        }

        ptr = ptr->ptr[str[j] - '0'];
    }

    ptr->count++;
}

void dfs(Bor *ptr, char *way, int len) {
    if (len == m) {
        int i;

        for (i = 0; i < ptr->count; i++) {
            printf("%s\n", way);
        }

        free(ptr);
        return;
    }

    way[len] = '0';        
    if (ptr->ptr[0] != NULL) {
        dfs(ptr->ptr[0], way, len + 1);
    }

    way[len] = '1';         
    if (ptr->ptr[1] != NULL) {
        dfs(ptr->ptr[1], way, len + 1);
    }

    free(ptr);
    return;
}

int main() {    
    file_open();

    int i, j;

    read(&n, "Enter the number of numbers:\n");
    read(&m, "Enter the number of bits in the numbers:\n");

    char *list[n];

    printf("Enter n numbers. Each number on the new line:\n");
    getc(fp);

    for (i = 0; i < n; i++) {  
        list[i] = (char*)malloc((m + 1) * sizeof(char));
        checkPtr(list[i]);
        list[i][m] = '\0';

        for (j = 0; j < m; j++) {
            list[i][j] = getc(fp);

            if (list[i][j] == '\n') {
                printf("The binary number length is less than the number of bits.\n");
                printf("The program has stopped working.\n"); 
                goto freee;
            } 

            if (list[i][j] != '0' && list[i][j] != '1') {
                printf("A binary number can only contain zeros and ones.\n");
                printf("The program has stopped working.\n"); 
                goto freee;
            }
        }

        char end = getc(fp);
        if (end != '\n' && end != EOF) {
            printf("The binary number length is more than the number of bits.\n");
            printf("The program has stopped working.\n"); 
            goto freee;
        }
    }

    Bor *root = (Bor*)malloc(sizeof(Bor));
    checkPtr(root);

    root->ptr[0] = NULL;
    root->ptr[1] = NULL;
    root->count = 0;

    for (i = 0; i < n; i++) {
        bor_add(list[i], root);
    } 
    
    printf("The list of sorted binary numbers:\n");

    char *way = (char*)malloc((m + 1) * sizeof(char));
    checkPtr(way);
    way[m] = '\0';

    if (root->ptr[0] != NULL) {
        way[0] = '0';
        dfs(root->ptr[0], way, 1);
    }
    if (root->ptr[1] != NULL) {
        way[0] = '1';
        dfs(root->ptr[1], way, 1);
    }

    freee:

    free(way);
    free(root);
    for (i = 0; i < n; i++) {
        if (list[i] != NULL) {
            free(list[i]);
        }
    }
    free(list);


    fclose(fp);
    return 0;
}
