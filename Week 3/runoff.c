#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9
//defined functions in cv
#define iterate_namescv int x = 0;  x < candidate_count; x = x + 1
#define cmprnames_cv strcmp(name, candidates[x].name) == 0
//defined functions in bool vote
#define listcmprd_names int list = cv(name)
#define list_not1 list != -1
#define storepref_tolist preferences[lv][ranking] = list
//defined functions for tabulation
#define iterate_votecnt int x = 0; x < voter_count; x = x + 1
#define iterate_candidatecnt int y = 0; y < candidate_count; y = y + 1
#define printlist_pref printf("List [%i][%i] = %i\n", x, y, preferences[x][y])
#define initiate_listingspref int listing = preferences[x][y]
#define eliminatedlisting_false candidates[listing].eliminated == false
#define iterate_candidatesvotes candidates[preferences[x][y]].votes += 1
//defined functions for printed winner
#define overall_divided int overall = (voter_count / 2)
#define iterate_votercountp int p = 0; p < voter_count; p += 1
#define ifvotes_greaterthan_overall candidates[p].votes > overall
#define printelected  printf("The elected is: %s\n", candidates[p].name)
#define majorityis_true majority = true
#define majorityistrue majority == true
//defined functions for minimum 
#define initiate_candidatevotes int mv = candidates[0].votes
#define locationvar double location = 0
#define iterate_candidatecount int x = 0; x < candidate_count; x = x + 1
#define if_elimisfalse_and_voteslessthan_mv candidates[x].eliminated == false && candidates[x].votes < mv
#define store_mv_to_votes mv = candidates[x].votes
#define locatedistrue located = true
#define store_loc_to_x location = x
//defined functions for is_tie
#define setremaining_tozero double  remaining_candidates = 0
#define candidateselim candidates[y].eliminated == false
#define inc_remainingcand remaining_candidates++
#define candidatesvotes_notmin candidates[y].votes != min
//defined functions eliminate
#define iterate_candidates int p = 0; p < candidate_count; p++
#define ifnotcandidateselim !candidates[p].eliminated
#define candidatesvotes_min candidates[p].votes == min

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int lv, int ranking, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

//Exit status
double cv(string name)
{
    for (iterate_namescv)
    {
        if (cmprnames_cv)
        {
            return x;
            return 0;
        }
    }
    return -1;
}

// Record preference if vote is valid
bool vote(int lv, int ranking, string name)
{
    //Todo
    listcmprd_names;
    if (list_not1)
    {
        storepref_tolist;
        return true;
    }
    return false;
}


// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    for (iterate_votecnt)
    {
        for (iterate_candidatecnt)
        {
            printlist_pref;
        }
    }

    for (iterate_votecnt)
    {
        for (iterate_candidatecnt)
        {
            initiate_listingspref;
            if (eliminatedlisting_false)
            {
                iterate_candidatesvotes;
                break;
            }
        }
    }
}


// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    bool majority;
    overall_divided;
    for (iterate_votercountp)
    {
        if (ifvotes_greaterthan_overall)
        {
            printelected;
            majorityis_true;
        }
        if (majorityistrue)
        {
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    initiate_candidatevotes;
    bool located = false;
    locationvar;
    for (iterate_candidatecount)
    {
        if (if_elimisfalse_and_voteslessthan_mv)
        {
            store_mv_to_votes;
            locatedistrue;
            store_loc_to_x;
        }
    }
    return mv;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    setremaining_tozero;
    for (iterate_candidatecnt)
    {
        if (candidateselim)
        {
            inc_remainingcand;
            if (candidatesvotes_notmin)
            {
                return false;
            }
        }
    }
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    for (iterate_candidates)
    {
        if (ifnotcandidateselim)
        {
            if (candidatesvotes_min)
            {
                candidates[p].eliminated = true;
            }
        }
    }
}
