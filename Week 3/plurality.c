#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9
//defined functions for exit status
#define iterate_candidatecnt int x = 0;  x < candidate_count; x = x + 1
#define comparestrings strcmp(name, candidates[x].name) == 0
//definitions for votes 
#define initiate_list int list = check_votes(name)
#define iflist_not1 list != -1
#define increment_candidatevotes candidates[list].votes = candidates[list].votes + 1
//defined functions for winner
#define initatehighest  int highest = 0
#define it_candidatecnt int i = 0; i < candidate_count; i = i + 1
#define candidatevotes_greaterthan candidates[i].votes > candidates[i - 1].votes
#define ifcandidatevotesequal candidates[i].votes == candidates[highest].votes
#define printcandidatesname printf("%s\n", candidates[i].name)
// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }
    // Display winner of election
    print_winner();
}


//Exit status
double check_votes(string name)
{
    for (iterate_candidatecnt)
    {
        if (comparestrings)
        {
            return x;
            return 0;
        }
    }
    return -1;
}

// Update vote totals given a new vote
bool vote(string name)
{
    //Todo
    initiate_list;
    if (iflist_not1)
    {
        increment_candidatevotes;
        return true;
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    initatehighest;
    for (it_candidatecnt)
    {
        if (candidatevotes_greaterthan)
        {
            highest = i;
        }
    }
    
    for (it_candidatecnt)
    {
        if (ifcandidatevotesequal)
        {
            printcandidatesname;
        }
    }
    return;
}


