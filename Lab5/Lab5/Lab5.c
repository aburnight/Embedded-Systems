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
int i = 0; //holds the count of the strobe
int j = 0; //holds count for 5bit cycle 

ISR(INT0_vect){ //interrupt for magnetic card reader
	//determine rise or fall
	if ((PORTD & 0x04) == 0x00){ //if int0 pin is pulled low 
		//initialize external interrupt 1 on falling edge
		//this will be used to determine when a new data bit is passed
		EIMSK = EIMSK | (1<<INT1);  
	} 
	else {
		EIMSK = EIMSK & 0xFD; //disable int1 external interrupt
		i = 0; //reset counter
	
	}
	//enable/disable interrupt for data
	//reset i 
} 

ISR(INT1_vect){//interrupt for data from magnetic card reader
	//counter for number 
	//second counter for place in conversion
	//while in i range
	//collect binary, convert five bits at a time 
	i++; //increment counter
}

char readNextChar(){
	
}

void main(void){
	
	DDRD = 0x00; //Set PD2 (INT0), PD3 (INT1) as input
	
	sei(); //enable global interrupt
	
	//initialize external interrupt 0 
	//this will be used to determine when a card enters magnetic card reader
	EIMSK = EIMSK | 1<<INT0; //enable external interrupt 0
	EICRA = EICRA | 1<<ISC00; //any logic change interrupt
	//set interrupt 1 on falling edge
	EICRA = EICRA | 1<<ISC11;

    
	while(1)
    {	
        //TODO:: Please write your application code 
 
    }
}