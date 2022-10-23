#include "trap.h"

int main() {
	char *s2 = "";
	char *s3 = "\0";
	char *s4 = "\n";
	char *s5 = "abcdef\n";
	char *s6 = "abcdef";
	char *s7 = "abcdef\0";
	
	assert(strlen(s2) == 0);
	assert(strlen(s3) == 0);
	assert(strlen(s4) == 1);
	assert(strlen(s5) == 7);
	assert(strlen(s6) == 6);
	assert(strlen(s7) == 6);
	return 0;
}

