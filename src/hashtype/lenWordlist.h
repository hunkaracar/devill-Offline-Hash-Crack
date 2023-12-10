#include <stdio.h>
#include <stdlib.h>

int calculate_len_wordlist(char *path_wordlist){
    FILE *file = fopen(path_wordlist, "r");

    if (file == NULL) {
        perror("File Open Error!");
        return -1;
    }

    int count = 0;
    char character;

    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            count++;
        }
    }

    // Dosyayı kapat
    fclose(file);

    return count;
}
