#ifndef TOURNI_FILE
#define TOURNI_FILE

//Definition of struct Player
typedef struct{
	int team;
	char * first;
	char * last;
	int number;
	int offensive;
	int defensive;
}Player;

//Definition of struct Team
typedef struct Team{
	char * name;
	Player * players;
	void (*delete)(struct Team *);
}Team;

//Function Declaration
Player * draftPlayers(char * filename, int team, int num_players);
Team * newTeam(char * name, Player * players);
Team * game(Team *, Team *);
Team * tournament(Team **, int);

#endif
