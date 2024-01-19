#include <stdio.h>

int main() {
    FILE *file1, *file2, *resultFile;

    file1 = fopen("file1.txt", "r");
    if (file1 == NULL) {
        perror("error opening the first file");
        return 1;
    }

    file2 = fopen("file2.txt", "r");
    if (file2 == NULL) {
        perror("error opening the second file");
        fclose(file1);
        return 1;
    }

    resultFile = fopen("result.txt", "w");
    if (resultFile == NULL) {
        perror("error opening the third file");
        fclose(file1);
        fclose(file2);
        return 1;
    }

    int ch;
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, resultFile);
    }

    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, resultFile);
    }

    fclose(file1);
    fclose(file2);
    fclose(resultFile);

    printf("concatenation completed successfully! \n");

    return 0;
}
