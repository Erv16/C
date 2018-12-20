#include"tournament.h"
#include"tournament.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define DEBUG 1

#define NUM_TEAMS 32
#define NUM_PLAYERS 10

int inLeague(Team *, Team **);

int main(){
    /*****  Change the team names to names of your choosing ******/
    char * team_names[] = {
        "team1",
        "team2",
        "team3",
        "team4",
        "team5",
        "team6",
        "team7",
        "team8",
        "team9",
        "team10",
        "team11",
        "team12",
        "team13",
        "team14",
        "team15",
        "team16",
        "team17",
        "team18",
        "team19",
        "team20",
        "team21",
        "team22",
        "team23",
        "team24",
        "team25",
        "team26",
        "team27",
        "team28",
        "team29",
        "team30",
        "team31",
        "team32",
    };

    /********************************************************************/
    /*    DO NOT ALTER ANY OF THE THE DRIVER CODE BELOW                 */
    /********************************************************************/
#if !DEBUG
    fclose(stderr);
#endif
    printf("\t-----------------------------------\n");
    printf("\t-   Part1 : Creating Your League  -\n");
    printf("\t-----------------------------------\n");
    srand(time(NULL));

    printf("\n\t=========Test #1: Creating your Teams and Players===========\n\n");
    Team ** league = malloc(sizeof(Team*) * NUM_TEAMS);
    //create teams i.e. league of N teams.
    for(int counter = 0; counter < NUM_TEAMS; counter++){
        Player * draft = draftPlayers("players.dat", counter, NUM_PLAYERS);
        for(int i = 0; i < NUM_PLAYERS; i++)
	    assert(draft[0].team == counter%NUM_TEAMS);
            league[counter] = newTeam(team_names[counter], draft);
            assert(sizeof((league[counter]->players[rand() % NUM_PLAYERS])) == sizeof(Player));
            assert((league[counter]->players[rand() % NUM_PLAYERS]).offensive > 0);
            assert((league[counter]->players[rand() % NUM_PLAYERS]).defensive > 0);
            assert(sizeof(*(league[counter])) == sizeof(Team));
    }
    printf("\n\t\t....Test Passed\n");

    printf("\t-----------------------------------\n");
    printf("\t-   Part2 : Exhibition Games      -\n");
    printf("\t-----------------------------------\n");

    printf("\n\t=========Test #2: Sanity check for the game===========\n\n");

    Team * winner = game(NULL, NULL);
    assert(winner == NULL);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Test #3: Playing a Game between two random teams===========\n\n");
    Team * team1 = league[rand() % NUM_TEAMS];
    Team * team2 = league[rand() % NUM_TEAMS];
    printf("Up next, an exhibition game between %s and %s\n", team1->name, team2->name);
    winner = game(team1, team2);
    assert(winner == team1 || winner == team2);
    printf("The winning team is %s\n\n", winner->name);
    printf("\n\t\t....Test Passed\n");
    printf("\n\t=========Test #4: Playing a Game between the same team===========\n\n");
    int team_num = rand() % NUM_TEAMS;
    printf("Up next, a a scrimmage for %s\n", league[team_num]->name);
    winner = game(league[team_num], league[team_num]);
    assert(winner == league[team_num]);
    printf("The winning team is %s\n\n", winner->name);
    printf("\n\t\t....Test Passed\n");

    printf("\t-----------------------------------\n");
    printf("\t-   Part3 : Running a Tournament  -\n");
    printf("\t-----------------------------------\n");
    printf("\n\t=========Test #5: Ensure number of teams is a power of 2===========\n\n");
    winner = tournament(league, 20);
    assert(winner == NULL);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Test #6: Should result in a single winner===========\n\n");
    winner = tournament(league, NUM_TEAMS/4);
    assert(inLeague(winner, league));
    winner = tournament(league, NUM_TEAMS/2);
    assert(inLeague(winner, league));
    winner = tournament(league, NUM_TEAMS);
    assert(inLeague(winner, league));
    printf("\n************************ Result *******************************\n\n");
    printf("The winning team is %s\n\n", winner->name);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Test #7: Should result in a random winner===========\n\n");
    const int NUM_SEASONS = 25;
    Team * winners[NUM_SEASONS];
    for(int counter = 0; counter < NUM_SEASONS; counter++){
        winners[counter] = tournament(league, NUM_TEAMS);
        printf("Winner is %s\n", winners[counter]->name);
        assert(inLeague(winners[counter], league));
    }
    Team * randomness_test = winners[0];
    int is_random = 0;
    for(int counter = 1; counter < NUM_SEASONS; counter++){
        if(randomness_test != winners[counter]){
            is_random = 1;
        }
    }
    assert(is_random);
    printf("\n\t\t....Test Passed\n");

    printf("\n\t=========Test #8: Delete team method should clean up memory for each team ===========\n\n");
    //free team array.
    for(int counter = 0; counter < NUM_TEAMS; counter++){
        league[counter]->delete(league[counter]);
    }
    free(league);
    printf("\n\t=========All Tests Passed. Don't forget to check Valgrind!===========\n\n");
}

int inLeague(Team * t, Team ** league){
    int i = 0;
    for(; i < NUM_TEAMS; i++){
        if(league[i] == t){
            return 1;
        }
    }
    return 0;
}
