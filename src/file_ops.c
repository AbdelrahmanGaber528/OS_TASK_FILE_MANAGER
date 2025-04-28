#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../include/file_ops.h"

void list_files(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    printf("\nFiles in %s:\n", path);
    while ((entry = readdir(dp))) {
        printf("%s\n", entry->d_name);
    }
    closedir(dp);
}

void open_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    printf("\nContents of %s:\n", filename);
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    fclose(fp);
}

void delete_file(const char *filename) {
    if (remove(filename) == 0) {
        printf("Deleted successfully.\n");
    } else {
        perror("remove");
    }
}

void copy_file(const char *src, const char *dest) {
    FILE *f1 = fopen(src, "rb");
    if (f1 == NULL) {
        perror("fopen source");
        return;
    }
    FILE *f2 = fopen(dest, "wb");
    if (f2 == NULL) {
        perror("fopen destination");
        fclose(f1);
        return;
    }

    char buf[1024];
    size_t size;
    while ((size = fread(buf, 1, sizeof(buf), f1)) > 0) {
        fwrite(buf, 1, size, f2);
    }

    fclose(f1);
    fclose(f2);
    printf("Copied successfully.\n");
}

void change_directory(const char *path) {
    if (chdir(path) == 0) {
        printf("Changed directory to %s\n", path);
    } else {
        perror("chdir");
    }
}

