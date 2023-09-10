#include <stdio.h>
#include <stdlib.h>

void cat_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (NULL == fp) {
        printf("wcat: cannot open file\n");
        exit(1);
    }
    char buffer[1024];
    while(fgets(buffer, 1024, fp) != NULL) {
        printf("%s", buffer);
    }
    if (fclose(fp)) {
        printf("Failed to close file\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        return 0;
    }
    for (int i = 1; i<argc; i++) {
        cat_file(argv[i]);
    }
    return 0;
}
