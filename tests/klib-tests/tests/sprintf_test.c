#include "trap.h"

#define BUFLEN 128
char buf[BUFLEN];

int main() {
	const char *s2 = "The equation is %d + %d = %d Good!";
	const char *s3 = "%d + %d = %s";
	const char *s4 = "Hex equation: %x + %x = %x";
//	const char *s5 = "%05x + %05x = %05x"; TODO: we do not implement 0-filled function
//	const char *s6 = "%0d + %0d = %s";

	sprintf(buf, s2, 123, 321, 123 + 321);
	assert(strcmp(buf, "The equation is 123 + 321 = 444 Good!") == 0);
	
	sprintf(buf, s3, 3, 4, "seven");
	assert(strcmp(buf, "3 + 4 = seven") == 0);

	sprintf(buf, s4, 0xa, 0xb, 0x15);
	assert(strcmp(buf, "Hex equation: a + b = 15") == 0);

//	sprintf(buf, s5, 0xa, 0xb, 0x15);
//	assert(strcmp(buf, "a + b = 15") == 0);
//	
//	sprintf(buf, s6, 3, 4, "seven");
//	assert(strcmp(buf, "3 + 4 = seven") == 0);
	return 0;
}

