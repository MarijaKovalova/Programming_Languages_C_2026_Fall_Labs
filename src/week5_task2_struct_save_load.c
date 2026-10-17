
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
  char name[MAX_NAME_LEN];
  int age;
  float gpa;
} Student;

// Function prototypes
int save_student(const Student* s, const char* filename);
int load_student(const char* filename, Student* out);

int main(void) {
  Student s1 = {0};
  strcpy(s1.name, "Amir");
  s1.age = 20;
  s1.gpa = 4.25f;

  Student loaded = {0};
  const char* filename = "student.txt";

  printf("Saving student to file...\n");

  if (save_student(&s1, filename) != 0) {
    printf("Error saving student.\n");
    return EXIT_FAILURE;
  }

  printf("Loading student from file...\n");

  if (load_student(filename, &loaded) != 0) {
    printf("Error loading student.\n");
    return EXIT_FAILURE;
  }

  // Print the loaded student
  printf("Loaded student: %s, %d, GPA %.2f\n", loaded.name, loaded.age,
         loaded.gpa);

  return EXIT_SUCCESS;
}

// Save student data to a file
int save_student(const Student* s, const char* filename) {
  FILE* fp = fopen(filename, "w");

  if (fp == NULL) {
    return -1;
  }

  fprintf(fp, "%s %d %.2f\n", s->name, s->age, s->gpa);

  fclose(fp);

  return 0;
}

// Load student data from a file
int load_student(const char* filename, Student* out) {
  FILE* fp = fopen(filename, "r");

  if (fp == NULL) {
    return -1;
  }

  int result = fscanf(fp, "%49s %d %f", out->name, &out->age, &out->gpa);

  fclose(fp);

  if (result != 3) {
    return -1;
  }

  return 0;
}
