#include "trap.h"

int main() {
	uint32_t data1[] = {0, 1124, 332132, 123, 0};
	uint32_t data2[] = {0, 1124, 332132, 12313, 0};
	assert(memcmp(data1, data2, 12) == 0);
	assert(memcmp(data1, data2, 16) != 0);
	assert(memcmp(data1, data2, 20) != 0);

	return 0;
}

