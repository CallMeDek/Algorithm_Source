#include <stdio.h>
#include "tournament.h"

int main(int argc, char** argv) 
{
	int teams[] = {"France", "Germany", "Brazil", "Colombia", "Argentina", "Belgium", "Netherlands", "Costarica"};
	tournament(teams, sizeof(teams) / sizeof(char*));
	return 0;
}

