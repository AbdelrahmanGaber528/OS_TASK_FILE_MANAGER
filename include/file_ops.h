#ifndef FILE_OPS_H
#define FILE_OPS_H

void list_files(const char *path);
void open_file(const char *filename);
void delete_file(const char *filename);
void copy_file(const char *src, const char *dest);
void change_directory(const char *path);

#endif

