#include "trap.h"

#define BUFLEN 128
char buf[BUFLEN];

int main() {
	const char *s2 = "The equation is 0x%lx + 0x%lx = 0x%lx Good!";
	const char *s3 = "%ld + %ld = %ld";

	sprintf(buf, s2, 0x1234567800000000, 0x0000000012345678, 0x1234567812345678);
	assert(strcmp(buf, "The equation is 0x1234567800000000 + 0x12345678 = 0x1234567812345678 Good!") == 0);
	
	sprintf(buf, s3, 1234567800000000, 12345678, 1234567812345678);
	assert(strcmp(buf, "1234567800000000 + 12345678 = 1234567812345678") == 0);

	return 0;
}

