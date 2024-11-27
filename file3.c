//3. Write a C program to copy the contents of one file into another

#include <stdio.h>

int main()
{
    FILE *fp, *copyfile;
    char s[50];
    int c;
    fp = fopen("originalfile.txt", "w+");
    if (fp == NULL) {
        printf("Error in opening the original file\n");
        return 1;
    }

    // give the string to write into file
    printf("Enter the string to be entered into the file:\n");
    // Read string
    fgets(s, sizeof(s), stdin); 

    // Write the string in the original file
    fprintf(fp, "%s", s);
    
    rewind(fp);

    fclose(fp);

    // Open in read mode
    fp = fopen("originalfile.txt", "r");
    if (fp == NULL) {
        printf("Error in opening the original file for reading\n");
        return 1;
    }

    copyfile = fopen("copyfile.txt", "w");
    if (copyfile == NULL) {
        printf("Error in opening the copy file\n");
        return 1;
    }

    while ((c = getc(fp)) != EOF) {
        putc(c, copyfile); 
    }

    fclose(fp);
    fclose(copyfile);

    printf("Contents of the first file have been successfully copied into the second file.\n");

    return 0;
}

   
    
