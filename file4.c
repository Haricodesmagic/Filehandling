// Write a C program that compares 2 files and returns 0 if they are equal, and 1 if not equal
#include <stdio.h>
#include <string.h>

int main()
{
    char s1[25], s2[25];
    int i;
    FILE *firstfile, *secondfile;
    
    // Open the first file for writing
    firstfile = fopen("firstfile.txt", "w+");
    if (firstfile == NULL) {
        printf("Error in opening the first file\n");
        return 1;
    }

    printf("Enter the string to be entered into the first file:\n");
    fgets(s1, sizeof(s1), stdin);  // Read input for the first file

    // Remove the newline character added by fgets()
    s1[strcspn(s1, "\n")] = '\0';  // strcspn finds the position of '\n' and replaces it with '\0'

    fprintf(firstfile, "%s", s1);  // Write the string into the first file
    rewind(firstfile);  // Rewind to the beginning to prepare for reading
    fclose(firstfile);  // Close the first file
    
    // Open the second file for writing
    secondfile = fopen("secondfile.txt", "w+");
    if (secondfile == NULL) {
        printf("Error in opening the second file\n");
        return 1;
    }

    printf("Enter the string to be entered into the second file:\n");
    fgets(s2, sizeof(s2), stdin);  // Read input for the second file

    // Remove the newline character added by fgets()
    s2[strcspn(s2, "\n")] = '\0';  // Removing the newline character

    fprintf(secondfile, "%s", s2);  // Write the string into the second file
    rewind(secondfile);  // Rewind to the beginning to prepare for reading
    fclose(secondfile);  // Close the second file

    // Open both files for reading
    firstfile = fopen("firstfile.txt", "r");
    secondfile = fopen("secondfile.txt", "r");

    if (firstfile == NULL || secondfile == NULL) {
        printf("Error in opening files for reading\n");
        return 1;
    }

    // Compare the contents of both files
    int areEqual = 1;  // Flag to indicate if files are equal

    while (1) {
        char c1 = fgetc(firstfile);
        char c2 = fgetc(secondfile);

        // Check if characters are the same
        if (c1 != c2) {
            areEqual = 0;
            break;
        }

        // If both files reached the end, they are equal
        if (c1 == EOF && c2 == EOF) {
            break;
        }
    }

    // Print the result based on the comparison
    if (areEqual) {
        printf("The files are equal\n");
    } else {
        printf("The files are unequal\n");
        fclose(firstfile);
        fclose(secondfile);
        return 1;
    }

    // Close both files
    fclose(firstfile);
    fclose(secondfile);

    return 0;
}

    
    
