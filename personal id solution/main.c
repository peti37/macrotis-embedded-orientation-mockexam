#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Create a personal ID registers
 * You should store the following data in a structure, called "person":
 * - the name of the person (which is shorter than 256 characters)
 * - the year of the birth (1990)
 * - the type of the highest qualification (as a custom type, see below)
 *
 * You should store the qualification type in an enumeration ("qualification"),
 * the valid types are:
 *  - elementary-school
 *  - high-school
 *  - bsc-degree
 *  - master-degree
 *  - phd
 *
 * The "person" -s are stored in an array.
 *
 * Implement the following functions:
 * - get_oldest_alive()
 *    - it should return the age of the oldest person
 * - get_qualification_count()
 *    - it returns the count of persons which has "quali" qualification
 * For both functions you have to add the needed parameters!
 * You don't need to implement a function, which initializes the persons, just do it manually from main(). E.g. initialize your persons in main() with 4 elements in order to be able to test your 2 implemented functions if it works correctly.
 */

 enum qualification_type {ELEMENTARY_SCHOOL, HIGH_SCHOOL, BSC_DEGREE, MASTER_DEGREE, PHD};

 typedef struct {
	char name[256];
	int birth_year;
	enum qualification_type type;
} Person;

int get_oldest_alive(Person*, int);
int get_qualification_count(Person*, int, enum qualification_type);

int main()
{
    Person persons[3];
    strcpy(persons[0].name, "John");
    persons[0].birth_year = 1990;
    persons[0].type = PHD;

    strcpy(persons[1].name, "Esmeralda");
    persons[1].birth_year = 1980;
    persons[1].type = HIGH_SCHOOL;

    strcpy(persons[2].name, "Dr Doctor");
    persons[2].birth_year = 1986;
    persons[2].type = PHD;

    int size = sizeof(persons)/sizeof(persons[0]);

    printf("%d\n", get_oldest_alive(persons, size));
    printf("%d\n", get_qualification_count(persons, size, PHD));

    return 0;
}
int get_oldest_alive(Person* array, int size){
    int oldest = array[0].birth_year;
    for(int i = 0; i < size; i++){
            if (array[i].birth_year < oldest){
                oldest = array[i].birth_year;
            }
    }
    return oldest;
}

int get_qualification_count(Person* array, int size, enum qualification_type type){
    int i;
    int counter = 0;
    for (i = 0; i < size; i++){
        if (array[i].type == type)
            counter++;
    }
    return counter;
}
