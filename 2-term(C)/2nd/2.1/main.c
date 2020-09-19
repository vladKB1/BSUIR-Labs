#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI acos(-1)
#define sqr(a) ((a) * (a))
#define cub(a) ((a) * (a) * (a))

void menu() {
    printf("            Menu\n");
    printf("1. Enter the radius of the ball.\n");
    printf("2. Print the ball surface area.\n");
    printf("3. Print the volume of the ball.\n");
    printf("4. Print the length of the edge of the inscribed regular tetrahedron.\n");
    printf("5. Print the cross-sectional area, drawn at a distance k from center of the ball.\n");
    printf("6. Print the information about the version and the author of the program.\n");
    printf("7. Exit the program.\n\n");

    printf("Enter the 1-7: ");

    return;
}

void read_rad(double *ptr_rad) {
    printf("Enter The radius: ");
    scanf("%lf", ptr_rad);

    while (*ptr_rad < 0) {
        printf("The value entered is invalid. Try again.\n\n");
        printf("Enter The radius: ");
        scanf("%lf", ptr_rad);    
    }

    return;
}

double surface_area(const double rad) {
    return 4 * PI * sqr(rad);
}

double volume_of_ball(const double rad) {
    return 4/3 * PI * cub(rad);
}

double length_of_edge(const double rad) {
    return 2 * sqrt(6) * rad / 3;
}

double cross_sectional_area(const double rad) {
    double k = -1, leng = -1;

    printf("Enter k: ");
    scanf("%lf", &k);
    leng = (sqr(rad) - sqr(k)) * PI;

    while (k < 0 || leng < 0) {
        if (k < 0) {
            printf("The value entered is invalid. Try again.\n\n");
        } else if (leng < 0) {
            printf("k is too big. Try again.\n\n");
        }

        printf("Enter k: ");
        scanf("%lf", &k);

        leng = (sqr(rad) - sqr(k)) * PI;
    }

    return leng;
}

void info() {
    printf("Ball v1.1.1\n");
    printf("Author: vladKB1\n\n");
    printf("This program may be freely redistributed under\n");
    printf("the terms of the MY LICENSE\n");
}

void end() {
    exit(0);
}

int main() {
    double rad = -1;

    while (1) {
        int type = -1;

        menu();
        
        scanf("%d", &type);
        printf("\n");
        while (type < 1 || type > 7) {
            printf("The value entered is invalid. Try again.\n\n");
            printf("Enter the 1-7: ");
            scanf("%d", &type);
            printf("\n");
        }

        if (rad == -1 && type != 1 && type != 7) {
            printf("The radius isn't entered.\n");
            read_rad(&rad);
            printf("\n");
        }

        switch (type) 
        {
            case 1:
                read_rad(&rad);
                break;
            case 2:
                printf("The ball surface area is %lf\n", surface_area(rad));
                break;
            case 3:
                printf("The volume of the ball is %lf\n", volume_of_ball(rad));
                break;
            case 4:
                printf("The length of the edge is %lf\n", length_of_edge(rad));
                break;
            case 5:
                printf("The cross-sectional area is %lf\n", cross_sectional_area(rad));
                break;
            case 6:
                info();
                break;
            case 7:
                end();
                break;
            default:
                break;
        }

        printf("\n");
    }

    return 0;
}