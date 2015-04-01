/*
 * Lab5.c
 *
 * Created: 3/30/2015 11:36:34 PM
 *  Author: Alexis Burnight, Laura Shepherd
 */ 

#ifndef F_CPU
#define F_CPU 80000000UL //8MHz Clock Speed
#endif


#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h> //for accessing the ids and pins
#include <avr/interrupt.h>
#include <stdbool.h>
#include <string.h>
//#include "hd44780.h"
//#include "hd44780_settings.h"

const char access_id[29][10]= {
	"1265469449", 
	"1234554321",
	"1357924680",
	"1370098918",
	"1556125764",
	"1599245712",
	"1603003392",
	"1660347388",
	"1911163115",
	"2010201100",
	"2324080403",
	"2378803078",
	"2644491662",
	"2828282828",
	"3399273048",
	"3461119678",
	"4224515259",
	"4301660491",
	"6458312500",
	"6873235917",
	"7349082118",
	"8187558266",
	"8675309000",
	"8728552571",
	"8903217238",
	"9021090210",
	"9668874210",
	"9876543210"
};  

const char access_pin[29][4] = {
	"4321", 
	"9449",
	"4680", 
	"8918", 
	"5764", 
	"5712", 
	"3392", 
	"7388", 
	"3115", 
	"1100", 
	"0403", 
	"3078", 
	"1662", 
	"2828", 
	"3048", 
	"9678", 
	"5269", 
	"0491", 
	"2500", 
	"5917", 
	"2118", 
	"8266", 
	"9000", 
	"2571", 
	"7238", 
	"0210", 
	"4210",
	"3210"
};

char currentID[10] = {}; //holds the id from the scanned card
char pin[4] = {}; //holds the entered pin
char bitString[5] = {}; //holds the 5bit values
bool startID = false; 
bool endID = true; 
int i = 0; //id counter
int j = 0; //5 bit counter
int k = 0; //index of id and pin

ISR(INT0_vect){ //interrupt for magnetic card reader
	//readNextBit((PORTD masked with data pin, send 1 for low, 0 for high)); 
} 

void verifyID(){
	bool validID = false;
	while (validID == false && k < 29){ //loop to determine if found
		if (strcmp(currentID, access_id[k]) == 0){
			validID = true;
			//print LCD valid
			//verify pin
		}
		else {
			k++;
		}
	}
	if (validID == false){
		//print invalid ID
	}
}

//add number based on five bit
char addToID (){
	if (strcmp(bitString, "00001") == 0){
		return '0';
	}
	else if (strcmp(bitString, "10000") == 0){
		return '1';
	}
	else if (strcmp(bitString, "01000") == 0){
		return '2';
	}
	else if (strcmp(bitString, "11001") == 0){
		return '3';
	}
	else if (strcmp(bitString, "00100") == 0){
		return '4';
	}
	else if (strcmp(bitString, "10101") == 0){
		return '5';
	}
	else if (strcmp(bitString, "01101") == 0){
		return '6';
	}
	else if (strcmp(bitString, "11100") == 0){
		return '7';
	}
	else if (strcmp(bitString, "00010") == 0){
		return '8';
	}
	else if (strcmp(bitString, "10011") == 0 ){
		return '9';
	}
	else if(strcmp(bitString, "11010")){
		return ';';
	}
	else if (strcmp(bitString, "11111")){
		return '?'; 	
	}
	return '*'; 
}

void nextBit(int dataPin){
	if(startID == false){ //determine start of data segment  
		bitString[j] = dataPin; 
		j++; 
		if(j==1 && dataPin != 1){
			j=0; //the start of data segment has not begun  
		}
		if(j==5 && addToID() == ';'){
			j=0; //reset 5bit string counter
			startID = true; 
			i = 0; 
			endID = false; 
		}
	}
	else if (i<10){
		bitString[j] = dataPin; 
		j++; 
		if(j==5){
			j=0; //reset 5bit string counter
			currentID[i] = addToID(); 
			i++; //increment position in ID string
		}
	}
	else if (endID != true){
		bitString[j] = dataPin; 
		j++; 
		if(j==5){
			j = 0; 
			if(addToID() == '?') {
				endID = true; 
			}
		}
	}
}

//error in reading card print to LCD
void readError(){
	
}

int main(void){
	
	DDRD = 0x00; //Set PD2 (INT0), PD3 (INT1) as input
	
	sei(); //enable global interrupt

	//initialize external interrupt 0 
	//this will be used to determine when a card enters magnetic card reader
	EIMSK = EIMSK | 1<<INT0; //enable external interrupt 0
	EICRA = EICRA | 1<<ISC01; //enable on falling edge
	
	//initialize LCD
	//board_init(); 
	//lcd_init(); 
	//lcd_clrscr(); 
	//lcd_puts("Hello World..."); 

    
	while(1)
    {	
        //TODO:: Please write your application code 
 
    }
	return 0; 
}