/********************************/
/* Program Name: ascii2bin      */
/* Author: Megumi Ikeda         */
/* Date: 3/2/21                 */
/********************************/
/* Description: Convert ASCII digits to a number */
/* Validation Checks:           */
/* each ASCII input character is one of the following characters: '0', '1', or '\n' */
/* calculated number does not exceed 2^32 */
/* Enhancements: N/A            */
/********************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

int offset = 0x30;
int number;
int retval = 1;
int digit;
byte ascii_value;

retval = read(STDIN_FILENO, &ascii_value, 1);

while (retval == 1) {
	digit = ascii_value - offset;
	if (digit == 0 || digit == 1) {
		number = (number << 1) + digit;
		retval = read(0, &ascii_value, 1);		
	} else {
		return 1;
		void exit(int status);
	}
 }

if (number > pow(2,32)) {
 	fprintf(stderr, "Error Detected!\n");
	return 1;
 } else {
	printf("%u\n", number);
	return 0;
}

}
















































