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
int binary = 0;
int number;
int retval = 1;
int digit;
int count = 0;
int decimal = 0;
byte ascii_value;
    
retval = read(STDIN_FILENO, &ascii_value, 1);
    
while (retval == 1) {
	count++;
    digit = ascii_value - offset;
    binary = (binary << 1) + digit;
    retval = read(0, &ascii_value, 1);
 }
 
 for (int i = (count - 1); i >= 0; i--) {
 	number = binary / pow(10,i);
 	decimal += number * pow(2, i);
 }
 
 if (ascii_value != '0' && ascii_value != '1' && ascii_value != '\n') {
 	fprintf(stderr, "Error Detected!\n");
    return 1;
 } else if (decimal > pow(2,32)) {
 	fprintf(stderr, "Error Detected!\n");
    return 1;
 } else {
	printf("%u\n", decimal);
	return 0;
}

}/********************************/
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
int binary = 0;
int number;
int retval = 1;
int digit;
int count = 0;
int decimal = 0;
byte ascii_value;
    
retval = read(STDIN_FILENO, &ascii_value, 1);
    
while (retval == 1) {
	count++;
    digit = ascii_value - offset;
    binary = (binary << 1) + digit;
    retval = read(0, &ascii_value, 1);
 }
 
 for (int i = (count - 1); i >= 0; i--) {
 	number = binary / pow(10,i);
 	decimal += number * pow(2, i);
 }
 
 if (ascii_value != '0' && ascii_value != '1' && ascii_value != '\n') {
 	fprintf(stderr, "Error Detected!\n");
    return 1;
 } else if (decimal > pow(2,32)) {
 	fprintf(stderr, "Error Detected!\n");
    return 1;
 } else {
	printf("%u\n", decimal);
	return 0;
}

}
