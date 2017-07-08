#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "info.h"

void printChar(void);
int statsRoll(void);
void raceBonus(void);

int ac, hp, prof, passPerception; 
int stats[6], savThrows[6], skills[18], cash[5];
char charName[] = "Blaze Dankstorm";
race charRace;

int main(void) {
	//printNames(races);
	srand(time(NULL));
	
	//Assigning a race
	charRace = races[rand()%9];
	
	//Rolling stats
	int i;
	for(i=0;i<6;i++){
		stats[i] = statsRoll();
	}	
	raceBonus();
	
	printChar();
	
	return 0;
}


//Rolls stats dice like in the game - 4d6, then take out the smallest d6
int statsRoll(void){
	int smallest, total=0, i, y;
	int alreadySkipped = 0;
	
	int rolls[4] = {rand()%6+1, rand()%6+1, rand()%6+1, rand()%6+1};
	
	smallest = rolls[0];
	for(i=0;i<4;i++){
		if(rolls[i] < smallest)
			smallest = rolls[i];
	}
	
	for(y=0;y<4;y++){
		if(rolls[y] == smallest && alreadySkipped != 1) {
			alreadySkipped = 1;
			continue;
		}
		
		total += rolls[y];
	}
	
	return total;
}

//Adding race bonuses (not sub-races)
void raceBonus(void){
	switch(charRace){
		case "Dragonborn" :
			stats[0] += 2;
			stats[5] += 1;
			break;
		case "Dwarf" :
			stats[2] += 2;
			break;
		case "Elf" :
			stats[1] += 2;
			break;
		case "Gnome" :
			stats[3] += 2;
			break;
		case "Half-elf" :
			stats[5] += 2;
			break;
		case "Half-orc" :
			stats[0] += 2;
			stats[2] += 1;
			break;
		case "Halfling" :
			stats[1] += 2;
			break;
		case "Human" :
			//Hopefully this increases all stats by 1
			int i;
			for(i=0;i<6;i++){
				stats[i]++;
			}
			break;
		case "Tiefling" :
			stats[3] += 1;
			stats[5] += 2;
			break;
	}
}

//Debugging stuff
void printChar(void){
	printf("%s\n\n",charName);
	
	printf("%s\n", charRace);
	printf("Str: %d\n", stats[0]);
	printf("Dex: %d\n", stats[1]);
	printf("Con: %d\n", stats[2]);
	printf("Int: %d\n", stats[3]);
	printf("Wis: %d\n", stats[4]);
	printf("Cha: %d\n", stats[5]);
}