/*2. A file named DATA contains a series of integer numbers. 
Write a C program to read these numbers and then write all ‘odd’ numbers to a file to be called ODD and all ‘even’ numbers to a file to be called EVEN.
*/

#include <stdio.h>

int main() {
    FILE *fp, *oddFile, *evenFile;
    int n, i;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int a[n];
    fp = fopen("integers.txt", "w");
    if (fp == NULL) {
        printf("Error in opening the file integers.txt\n");
        return 1;
    }

    printf("Enter the %d integers:\n", n);
    for(i=0; i < n; i++) 
	{
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        fprintf(fp, "%d ", a[i]);
    }

    fclose(fp);

    fp = fopen("integers.txt", "r");
    if (fp == NULL) {
        printf("Error in opening the file integers.txt\n");
        return 1;
    }

    oddFile = fopen("ODD.txt", "w");
    evenFile = fopen("EVEN.txt", "w");

    if (oddFile == NULL || evenFile == NULL) {
        printf("Error in opening ODD.txt or EVEN.txt\n");
        return 1;
    }

    // Read & classify the numbers as odd or even
    while (fscanf(fp, "%d", &n) == 1) {
        if (n % 2 == 0) {
            fprintf(evenFile, "%d ", n);  
        } else {
            fprintf(oddFile, "%d ", n);  
        }
    }

    fclose(fp);
    fclose(oddFile);
    fclose(evenFile);

    printf("Odd and even numbers have been written to ODD.txt and EVEN.txt respectively.\n");

    return 0;
}

    
