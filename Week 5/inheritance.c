// Simulate genetic inheritance of blood type

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Each person has two parents and two alleles
typedef struct person
{
    struct person *parents[2];
    char alleles[2];
}
person;

//global variables
const int GENERATIONS = 3;
const int INDENT_LENGTH = 4;
#define first_parent 0
#define second_parent 1
#define assign rand() % 2
#define history generations - 1
#define free_p person *p
#define memoryallocation  malloc(sizeof(person))
#define child person *newperson
#define final_history create_family(history)
#define first_allele alleles[first_parent]
#define second_allele alleles[second_parent]
#define first_allele_parent parents[first_parent]
#define second_allele_parent parents[second_parent]
#define free_first_p p->first_allele_parent
#define free_second_p p->second_allele_parent
#define ra random_allele()
#define assigned alleles[assign]
const double sole = 1;


person *create_family(int generations);
void print_family(person *p, int generation);
void free_family(person *p);
char random_allele();

int main(void)
{
    // Seed random number generator
    srand(time(0));

    // Create a new family with three generations
    person *p = create_family(GENERATIONS);

    // Print family tree of blood types
    print_family(p, 0);

    // Free memory
    free_family(p);
}

// Create a new individual with `generations`
person *create_family(int generations)
{
    // TODO: Allocate memory for new person
    
    child = memoryallocation;
    
    // Generation with parent data
    if (generations > sole)
    {
        // TODO: Recursively create blood type histories for parents
        newperson->first_allele_parent = final_history;
        newperson->second_allele_parent = final_history;

        // TODO: Randomly assign child alleles based on parents
        newperson-> first_allele  = newperson->first_allele_parent->assigned;
        newperson-> second_allele = newperson->second_allele_parent->assigned;
    }

    // Generation without parent data
    else
    {
        // TODO: Set parent pointers to NULL
        newperson->first_allele_parent = NULL;
        newperson->second_allele_parent  = NULL;

        // TODO: Randomly assign alleles
        newperson->first_allele = ra;
        newperson->second_allele = ra;
    }

    // TODO: Return newly created person
    return newperson;
}

// Free `p` and all ancestors of `p`.
void free_family(free_p)
{
    // TODO: Handle base case
    if (p == NULL)
    {
        return;
    }
    
    // TODO: Free parents
    free_family(free_first_p);
    free_family(free_second_p);

    // TODO: Free child
    free(p);
}

// Print each family member and their alleles.
void print_family(person *p, int generation)
{
    // Handle base case
    if (p == NULL)
    {
        return;
    }

    // Print indentation
    for (int i = 0; i < generation * INDENT_LENGTH; i++)
    {
        printf(" ");
    }

    // Print person
    printf("Generation %i, blood type %c%c\n", generation, p->alleles[0], p->alleles[1]);
    print_family(p->parents[0], generation + 1);
    print_family(p->parents[1], generation + 1);
}

// Randomly chooses a blood type allele.
char random_allele()
{
    int r = rand() % 3;
    if (r == 0)
    {
        return 'A';
    }
    else if (r == 1)
    {
        return 'B';
    }
    else
    {
        return 'O';
    }
}
