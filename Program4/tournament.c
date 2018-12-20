#ifndef TOURNI_C_FILE
#define TOURNI_C_FILE
#include "tournament.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_TEAMS 32
#define NUM_PLAYERS 10

//Function to create a player
Player * draftPlayers(char * filename, int team, int num_players){
	int i=0;
	Player *plyr = malloc(num_players * sizeof(Player));
	char line[50]; 
	FILE *file;
	file = fopen("players.dat","r");
	//Read in player details from the data file and assign it to the struct elements
	while(fgets(line,sizeof(line),file)!= NULL){
		char * team_num =strtok(line,",");
		if(team == atoi(team_num)){		
			plyr[i].team  = atoi(team_num);
			plyr[i].first = strdup(strtok(NULL,","));
			plyr[i].last = strdup(strtok(NULL,","));
			plyr[i].number = atoi(strtok(NULL,","));
			plyr[i].offensive = atoi(strtok(NULL,","));
			plyr[i].defensive = atoi(strtok(NULL,","));
			i++;
		}	
	}
	fclose(file);
	return plyr;	
}

//Function to free up memory allocated
void deleteTeam(Team * ptr){
	for(int i=0; i<NUM_PLAYERS;i++){
	free(ptr->players[i].first);
	free(ptr->players[i].last);}
	free(ptr->players);
	free(ptr->name);
	free(ptr);
}

//Function to create a team
Team * newTeam(char * name, Player * players){
	Team * team = malloc(sizeof(Team));
	team->players = players; //Referencing the players of the respective team
	team->name = malloc(strlen(name)+1); //Assigning the team name
	strcpy(team->name,name);
	team->delete = deleteTeam;
	return team;
}

//Game function
Team * game(Team * t1, Team * t2){
	//Condition to check sanity of null pointer
	if(t1 == NULL || t2 == NULL){
		return NULL;
	}
	//Algorithm to determine winner of the game
	int t1totaldef = 0, t2totaldef = 0, t1totaloff = 0, t2totaloff = 0, cntrt1 = 0, cntrt2 = 0, randoffval = 0;
	//Computing the total defense and offense stats of both the playing teams
	for(int i = 0; i < NUM_PLAYERS; i++){
		t2totaldef += t2->players[i].defensive;
		t1totaldef += t1->players[i].defensive;
		t1totaloff += t1->players[i].offensive;
		t2totaloff += t2->players[i].offensive;
	}
	//Algoritm to determine the winner. Each team gets atleast two shots to score. 
	//First team's chance to score
	for(int j = 0;j < 2; j++){
		randoffval = (rand()%(t1totaloff - 0 + 1)) + 0;
		if(randoffval > t2totaldef)
			cntrt1++; //Keep score for team 1
		else
			cntrt2++; //Keep score for team 2
	}
	//Second team's chance to score
	for(int j = 0;j < 2; j++){
		randoffval = (rand()%(t2totaloff - 0 + 1)) + 0;
		if(randoffval > t1totaldef)
			cntrt2++;
		else
			cntrt1++;
	}
	//If it ends in a tie breaker, simply compare the offense value of the first team with the second team. The team with the greater offense stats wins.	
	if(cntrt1 == cntrt2){
		if(t1totaloff > t2totaloff)
			return t1;
		else
			return t2;
	}
	else if(cntrt1 > cntrt2)
		return t1;
	else 
		return t2;
	
}
//Function that implements the entire tournament
Team * tournament(Team ** team, int numTeams){
	//This condition checks to see if the number of teams is  a  power of two or not. If it is not a power of 2, it displays a message and returns null.
	int num1 = numTeams;
	if(num1 == 0 || num1 == 1){
		printf("The number of teams is invalid");
		return NULL;
	}
	while(num1 != 1){
		if(num1%2 != 0){
			printf("The number of teams is invalid");
			return NULL;
		}
		num1 = num1/2;
	}
	//Implements the logic of the tournament
	int size = (numTeams-1), n = numTeams, j = 0, k = 0; //j is a tracker to keep a track of the empty spaces in the array. k is a tracker that is used to pick up teams for rounds 2 onwards 
	Team * arr[size]; //Define an array of numTeams-1 to hold the winners of each round
	//Each round will numTeams/2 games numTeams/2 winners	
	//printf("%d\n",size);
	//printf("n:%d\n",numTeams);
	while(n > 1){
		for(int i = 0; i < n; i=i+2){
			if(n == numTeams){
				arr[j] = game(team[i],team[i+1]);				
				j++;
			}
			else{
				arr[j] = game(arr[k],arr[k+1]);
				j++;
				k = k+2;
			}
		}
		n = n/2;		
	}
	Team * winner = arr[size-1]; //The last element of the array is tournament winner
	return winner;
}
#endif
