//1. Write a C program to read data from keyboard, write it to a file called INPUT, again read the same data from input file and display it on the screen.

#include <stdio.h>

int main() {
    FILE *fp;
    char s[50];
    int n;
    fp = fopen("INPUT.txt", "w+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Read a string and a number from the user
    printf("Enter the string to be entered into the file:\n");
    fgets(s, sizeof(s), stdin); 

    printf("Enter the number to be entered to the file:\n");
    scanf("%d", &n);  

    // Write the number and string to the file
    fprintf(fp, "%d %s", n, s);
    rewind(fp);

    // Read the data from the file
    fscanf(fp, "%d %s", &n, s);  

   
    printf("Data read from the file:\n");
    printf("Number: %d\n", n);
    printf("String: %s\n", s);

    fclose(fp);

    return 0;
}

