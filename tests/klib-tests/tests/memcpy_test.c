#include "trap.h"

int main() {
	uint32_t data1[] = {0, 1124, 332132, 123, 0};
	uint32_t data2[] = {0, 1124, 332132, 12313, 5};

	assert(memcmp(data1, data2, 12) == 0);
	assert(memcmp(data1, data2, 16) != 0);
	assert(memcmp(data1, data2, 20) != 0);

//	printf("cyh\n");

	memcpy(data1, data2, 16);
	assert(memcmp(data1, data2, 16) == 0);
	assert(memcmp(data1, data2, 20) != 0);

//	printf("ygh\n");

	memcpy(data1, data2, 20);
	assert(memcmp(data1, data2, 20) == 0);

//	printf("zsh\n");

	char *str1 = "NES\x1A";
	char str2 [20];
	memcpy(str2, str1, 5);
	assert(memcmp(str1, str2, 5) == 0);

//	printf("finish\n");

	return 0;
}

