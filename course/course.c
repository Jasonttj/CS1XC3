#include "course.h" /**including course.h*/

#include <stdlib.h>

#include <stdio.h>

/** function to enroll students to course*/

void enroll_student(Course *course, Student *student)

{

course->total_students++; /**incrementing the total number of students*/

if (course->total_students == 1)

{

course->students = calloc(1, sizeof(Student)); /**dynamically allocate the specified number of blocks of memory for the course ->students*/

}

else

{

course->students =

realloc(course->students, course->total_students * sizeof(Student)); /**dynamically changing the memory allocation of a previously allocated memory*/

}

course->students[course->total_students - 1] = *student;

}


/**functionto print the name ,code ,total students (course)*/

void print_course(Course* course)

{

printf("Name: %s\n", course->name);

printf("Code: %s\n", course->code);

printf("Total students: %d\n\n", course->total_students);

printf("****************************************\n\n");

for (int i = 0; i < course->total_students; i++)

print_student(&course->students[i]);

}

/** function to find the top sudent in a course*/

Student* top_student(Course* course)

{

if (course->total_students == 0) return NULL;

double student_average = 0;

double max_average = average(&course->students[0]); /**assinging first student as max avg for comparison*/

Student *student = &course->students[0];

for (int i = 1; i < course->total_students; i++) /**loop to iterate over all students*/

{

student_average = average(&course->students[i]);

if (student_average > max_average)   

{

max_average = student_average;

student = &course->students[i];

}

}

return student;

}

/**function to calculate the number of students passed if the student score more than or equal to 50 and return list of passed students*/

Student *passing(Course* course, int *total_passing)

{

int count = 0;

Student *passing = NULL;

for (int i = 0; i < course->total_students; i++)

if (average(&course->students[i]) >= 50) count++;

passing = calloc(count, sizeof(Student)); /**dynamically allocating memory to passing*/

int j = 0;

for (int i = 0; i < course->total_students; i++)

{

if (average(&course->students[i]) >= 50)

{

passing[j] = course->students[i];

j++;

}

}

*total_passing = count;

return passing;

}