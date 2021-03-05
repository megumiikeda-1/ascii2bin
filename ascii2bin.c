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

#define byte unsigned char
#define MAX_INT (1 << 32)

int main (int argc, char * argv[], char ** envp) {

int offset = 0x30;
int number = 0;
int retval = 1;
int digit;
byte ascii_value;

retval = read(STDIN_FILENO, &ascii_value, 1);

while ( (retval == 1) && (ascii_value != '\n') ) {
	if ( (ascii_value == '0') || (ascii_value == '1') ) {
		digit = ascii_value - offset;
		number = (number << 1) + digit;
		printf("%u\n", number);
		retval = read(0, &ascii_value, 1);				
	} else {
		return 1;
		void exit(int status);
	}
 }

if (number > MAX_INT) {
 	fprintf(stderr, "Error Detected!\n");
	return 1;
 } else {
	printf("%u\n", number);
	return 0;
}

}

















































