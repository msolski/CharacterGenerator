#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "info.h"

void printNames(race[]);
int statsRoll(void);
void printArray(int[]);

int ac, hp, prof, passPerception; 
int stats[6], savThrows[6], skills[18], cash[5];
char charName[100];
race charRace;

int main(void) {
	//printNames(races);
	srand(time(NULL));
	charRace = races[rand()%9];
	
	//Rolling stats
	int i;
	for(i=0;i<6;i++){
		stats[i] = statsRoll();
	}	
	
	printArray(stats);
	
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

//Debugging stuff
void printNames(race races[]){
	int i;
	
	for(i=0;i<9;i++){
		printf("%s\n",races[i].name);	
	}
	
}

void printArray(int intArray[]){
	int i;
	
	for(i=0;i<6;i++){
		printf("%d\n",intArray[i]);
	}
}