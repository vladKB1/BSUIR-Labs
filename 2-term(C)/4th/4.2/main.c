#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define BUFFER_SIZE 255

FILE *fp;
char *file_name = "test.txt";

void file_open(char **file_name, FILE **fp) {
    if((*fp = fopen(*file_name, "r")) == NULL) {
        perror("Error occured while opening text.txt");
        exit(0);
    }     
}

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
    
    while ((h = getc(fp)) != EOF) {
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

char* substr(const char *const str, const int pos, const int len) {
    char *s = (char*)malloc(len * sizeof(char) + 1);
    if (s == NULL) {
        printf("Failed to allocate memory. The program has been interrupted.\n");
        exit(0);
    }

    int i;
    for (i = 0; i < len; i++) {
        s[i] = str[pos + i];
    }
    s[len] = '\0';

    return s;
}

short check_symbols(const char h) {
    return (h == '.' || h == '!' || h == '?' || h == ',' || h == ':' ||
            h == ';' || h == '\"' || h == '\'' || h == '/' ||  h == '\n' || 
            h == '(' || h == ')' || h == '*' || h == '-' || h == ' ');
}

short check_letters(const char h) {
    return ((h >= 'a' && h <= 'z') || (h >= 'A' && h <= 'Z') ||
            (h == '+' || h == '-'));
}

int main() {
    file_open(&file_name, &fp);

    char *text = NULL;
    int n = read_str(&text);

    int l = 0, r = -1, l2 = 0, r2 = -1;
    double words = 0, sent = 0;
    int max_len_word = INT_MIN, max_len_sent = INT_MIN;
    double average_leters = 0, average_words = 0;

    char *longest_word = (char *)malloc((n + 1) * sizeof(char));
    if (longest_word == NULL) {
        printf("Failed to allocate memory. The program has been interrupted.\n");
        exit(0);
    }
    
    char *longest_sent = (char *)malloc((n + 1) * sizeof(char));
    if (longest_sent == NULL) {
        printf("Failed to allocate memory. The program has been interrupted.\n");
        exit(0);
    }


    int i;
    for (i = 1; i < n - 1; i++) {            
        if (l == -1 && check_symbols(text[i - 1]) && check_letters(text[i])) {
            l = i;

            if (l2 == -1) {
                l2 = i;
            }
        }

        if (l != -1 && r == -1 && check_letters(text[i]) && check_symbols(text[i + 1])) {
            r = i;

            if (r - l + 1 > max_len_word) {
                max_len_word = r - l + 1;
                longest_word = substr(text, l, max_len_word);
            }

            words++;
            average_leters += r - l + 1;
            l = r = -1;

            if (text[i + 1] == '.' || text[i + 1] == '?' || text[i + 1] == '!') {
                r2 = i;
                sent++;

                if (r2 - l2 + 2 > max_len_sent) {
                    max_len_sent = r2 - l2 + 2;
                    longest_sent = substr(text, l2, max_len_sent);  
                }

                l2 = r2 = -1;
            }

        }
    }

    if (words != 0) {
        average_leters /= words;
    }
    if (sent != 0) {
        average_words = words / sent;
    }

    printf("Analysis:\n");
    printf("The average number of letters in a word: %lf\n", average_leters);
    printf("The average number of words in a sentence: %lf\n", average_words);
    printf("The longest word: %s\n", longest_word);
    printf("The longest sentence: %s\n", longest_sent);

    free(text);
    free(longest_sent);
    free(longest_word);
    free(file_name);

    fclose(fp);
    return 0;   
}
