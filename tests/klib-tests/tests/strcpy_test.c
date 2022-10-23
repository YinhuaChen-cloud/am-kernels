#include "trap.h"
#define N 20
char data[N];

void check_str(char *data, const char *content, int n){
	const char *p = content;
	char *q = data;
	while(*p && p-content < n){
		assert(*p == *q);
		p++;
		q++;
	}
	if(p - content < n)
		assert(*p == *q);
}

int main() {
	strcpy(data, "");
	assert(data[0] == 0);

	strcpy(data, "abcdef");
	check_str(data, "abcdef", 100);

	strcpy(data, "abcdef");
	check_str(data, "abcdef", 7);
	
	strcpy(data, "abc&^$@#$");
	check_str(data, "abcdef", 3);
  
	strcpy(data, "01234567890123456789");
	check_str(data, "01234567890123456789", 20);

	return 0;
}

