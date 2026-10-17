
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_FILENAME "data.txt"
#define LINE_LEN 256

int main(int argc, char* argv[]) {
  FILE* fp = NULL;
  const char* filename = DEFAULT_FILENAME;
  char line[LINE_LEN];
  int line_count = 0;

  // Use the file name from the command line if provided
  if (argc > 1) {
    filename = argv[1];
  }

  // Open the file for writing
  printf("Writing lines to %s...\n", filename);
  fp = fopen(filename, "w");

  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  // Write lines to the file
  fprintf(fp, "Hello, file I/O in C!\n");
  fprintf(fp, "This is another line.\n");

  // Close the file
  fclose(fp);

  // Open the file for reading
  fp = fopen(filename, "r");

  if (fp == NULL) {
    perror(filename);
    return EXIT_FAILURE;
  }

  // Read and print the contents
  printf("Reading contents:\n");

  while (fgets(line, LINE_LEN, fp) != NULL) {
    printf("%s", line);
    line_count++;
  }

  // Close the file
  fclose(fp);

  // Print the number of lines read
  printf("Lines read: %d\n", line_count);

  return EXIT_SUCCESS;
}
