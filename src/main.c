#include <stdio.h>
#include <stdlib.h>
#include "../include/file_ops.h"
#include <string.h> 

void menu() {

    printf("\n==== File Manager ====\n");
    printf("[1] List Files\n");
    printf("[2] Open File\n");
    printf("[3] Delete File\n");
    printf("[4] Copy File\n");
    printf("[5] Change Directory\n");
    printf("[6] Exit\n");
    printf("Enter your choice: ");

}

int main() {

    int choice;
    char path[256];

    while (1) {

        menu();

        scanf("%d", &choice);

        getchar(); 

        switch (choice) {
            case 1:
                list_files(".");
                break;
            case 2:
                printf("Enter file name to open: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0; 
                open_file(path);
                break;
            case 3:
                printf("Enter file name to delete: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0;
                delete_file(path);
                break;
            case 4:
                {
                    char dest[256];
                    printf("Enter source file name: ");
                    fgets(path, sizeof(path), stdin);
                    path[strcspn(path, "\n")] = 0;

                    printf("Enter destination file name: ");
                    fgets(dest, sizeof(dest), stdin);
                    dest[strcspn(dest, "\n")] = 0;

                    copy_file(path, dest);
                }
                break;
            case 5:
                printf("Enter new directory: ");
                fgets(path, sizeof(path), stdin);
                path[strcspn(path, "\n")] = 0;
                change_directory(path);
                break;
            case 6:
                printf("Exiting.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice: Please try again.\n");
        }
    }
    return 0;
}

