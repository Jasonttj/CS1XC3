#include <stdlib.h>

#include <stdio.h>

#include <string.h>

#include "time.h" /**including file time.h and course.h*/

#include "course.h"


/**driver function*/
int main()

{

srand((unsigned) time(NULL));

Course *MATH101 = calloc(1, sizeof(Course)); /**dynamically allocating memory*/

strcpy(MATH101->name, "Basics of Mathematics"); /**strcpy() : copy string to variable*/

strcpy(MATH101->code, "MATH 101");

for (int i = 0; i < 20; i++) /**for loop to enroll students*/

enroll_student(MATH101, generate_random_student(8));

print_course(MATH101);

Student *student; /**creating object of structure Student*/

student = top_student(MATH101); /** getting top student*/

printf("\n\nTop student: \n\n");

print_student(student);

int total_passing;

Student *passing_students = passing(MATH101, &total_passing); /**calling function passing ()*/

printf("\nTotal passing: %d\n", total_passing);

printf("\nPassing students:\n\n");

for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]); /**for loop to print passing students*/

return 0;

}