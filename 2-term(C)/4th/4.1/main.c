#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 255

void copy_from_buffer(char **buffer, char ***str, 
                      int *const length, int *const n) {

    **str = (char *)realloc(**str, (*n + *length + 1) * sizeof(char));
    if (str == NULL) {
        printf("Failed to allocate memory. The program has been interrupted.\n");
        exit(0);
    }

    int i;
    for (i = 0; i < *length; i++) {
        (**str)[(*n)++] = (*buffer)[i];
    }

    *length = 0;

    return;
}

int read_str(char **str) {
    char h;
    int length = 0, n = 0;

    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        printf("Failed to allocate memory. The program has been interrupted.\n");
        exit(0);
    }


    while ((h = getchar()) != '\n') {
        buffer[length++] = h;

        if (length == BUFFER_SIZE) {
            copy_from_buffer(&buffer, &str, &length, &n);
        }
    }    
    if (length != 0) {
        copy_from_buffer(&buffer, &str, &length, &n);
    }
    (*str)[n] = '\0';

    free(buffer);

    return n;
}

short string_equal(const char *const str, int l1, int l2, int len) {
    while (len) {
        if (str[l1] != str[l2]) {
            return 0;
        }

        l1++;
        l2++;
        len--;
    }

    return 1;
}

char* substr(const char *const str, const int len) {
    char *s = (char*)malloc(len * sizeof(char) + 1);
    if (s == NULL) {
        printf("Failed to allocate memory. The program has been interrupted.\n");
        exit(0);
    }


    int i;
    for (i = 0; i < len; i++) {
        s[i] = str[i];
    }
    s[len] = '\0';

    return s;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    char *str = NULL;
    int i;

    int n = read_str(&str);

    /* trivial algorithm */

    int len = 0;
    short flag = 1;

    for (len = 1; len < n / 2 + 1; len++) {
        flag = 0;

        for (i = len; i < n; i += len) {
            if (!string_equal(str, 0, i, len)) {
                flag = 1;
                break;
            }
        }

        if (!flag) {
            break;
        } 
    }
    
    if (!flag) {
        printf("The string is periodic. Period is \"%s\".\n", substr(str, len));
    } else {
        printf("the string isn't periodic.\n");
    }

    free(str);

    return 0;   
}


    /* complexity O(n) */
/*
    It doesn't work. :( 
    Example: aaabaaaaaabaaa 
    Answer: YES
    Output: NO
*/
/*
    if (n == 2) {
        if (str[0] == str[1]) {
        printf("The string is periodic. Period is \"%c\".\n", str[0]);
        }
        else {
            printf("the string isn't periodic.\n");
        }

        return 0;
    }

    int pref_func[n];
    pref_func[0] = 0;

    for (i = 1; i < n; i++) {
        int j = pref_func[i - 1];

        while (j > 0 && str[i] != str[j]) {
            j = pref_func[j - 1];
        }

        if (str[i] == str[j]) {
            j++;
        }

        pref_func[i] = j;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", pref_func[i]);
    }
    printf("\n");

    int len = 0, count = 0;
    short flag = 0;

    for (i = n - 1; i > 0; i--) {
        if (pref_func[i] - 1 != pref_func[i - 1]) {
            flag = 1;
            break;
        }

        if (pref_func[i] == 2) {
            len = i - 1;
            break;
        }
    }

    if (!len || pref_func[n - 1] % max(len, 1)) {
        flag = 1;
    }


    if (!flag) {
        printf("The string is periodic. Period is \"%s\".\n", substr(str, len));
    }
    else {
        printf("the string isn't periodic.\n");
    }
    
    free(str);

*/