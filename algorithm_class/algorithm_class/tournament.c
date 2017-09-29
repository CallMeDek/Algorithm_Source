#include <stdio.h>
#include "tournament.h"

void tournament(char** team_list, int team_number)
{
	char** winner_list = (char**)calloc(team_number, sizeof(char*));
	char** list;
	int i, j, count;

	for (i = team_number; i > 2; i /= 2)
	{
		count = 0;

		if (i == team_number) list = team_list;
		else list = winner_list;

		for (j = 0; j < i; j += 2)
		{
			winner_list[count++] = match(list[j], list[j + 1]);
		}

		result(winner_list, i / 2);
	}

	printf("The winner is %s !!\n", match(winner_list[0], winner_list[1]));
	free(winner_list);
}

char* tournament_recursive(char** team_list, int start, int end)
{
	if (start == end) return team_list[start];

	int middle = (start + end) / 2;
	char* left = tournament_recursive(team_list, start, middle);
	char* right = tournament_recursive(team_list, middle+1, end);
	return match(left, right);
}

char* match(char* team1, char* team2)
{
	srand(time(NULL));

	if (rand() % 2) return team1;
	return team2;
}

void result(char** survived_teams, int len)
{
	char* round;
	char buffer[5];
	int i;

	if (len * 2 == 4) round = " the semifinal ";
	else if (len * 2 == 8) round = "the quarterfinal ";
	else round = strcat(" the round of ", sprintf(buffer, "%d", len * 2));

	printf("The result of %s is ...\n", round);
	for (i = 0; i < len; i++)
	{
		printf("%s ", survived_teams[i]);
	}
	printf("is survived.\n");
}