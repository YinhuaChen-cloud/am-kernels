#include "trap.h"

#define BUFLEN 128
char buf[BUFLEN];

//const char *regs[] = {
//  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
//  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
//  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
//  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
//};

//typedef struct MyContext {
//  // TODO: fix the order of these members to match trap.S
//	uintptr_t gpr[32]; // NOTE: no order need among gprs, restoring process will do it self
//  uintptr_t mcause, mstatus, mepc;
//  void *pdir;
//} MyContext;

int main() {
	const char *s2 = "The equation is 0x%lx + 0x%lx = 0x%lx Good!";
	const char *s3 = "%ld + %ld = %ld";
	const char *s4 = "\t5\t7\t%s\t8\n";
	const char *s5 = "0x%lx";
	const char *s6 = "0x%lx";
	const char *s7 = "0x%lx";

	sprintf(buf, s2, 0x1234567800000000, 0x0000000012345678, 0x1234567812345678);
	assert(strcmp(buf, "The equation is 0x1234567800000000 + 0x12345678 = 0x1234567812345678 Good!") == 0);
	
	sprintf(buf, s3, 1234567800000000, 12345678, 1234567812345678);
	assert(strcmp(buf, "1234567800000000 + 12345678 = 1234567812345678") == 0);
 
	sprintf(buf, s4, "omg");
	assert(strcmp(buf, "\t5\t7\tomg\t8\n") == 0);

//	MyContext c;
//
//	for(int i = 0; i < 32; i++) {
//		c.gpr[i] = i;
//	}
//	c.mcause = 0xdeadbeaf12345678;
//	c.mstatus = 0x1234567812345678;
//	c.mepc = 0xdeadbeafdeadbeef;
	uint64_t a1 = 0xdeadbeaf12345678;
	uint64_t a2 = 0x1234567812345678;
	uint64_t a3 = 0xdeadbeafdeadbeef;

	sprintf(buf, s5, a1);
	assert(strcmp(buf, "0xdeadbeaf12345678") == 0);

	sprintf(buf, s6, a2);
	assert(strcmp(buf, "0x1234567812345678") == 0);

	sprintf(buf, s7, a3);
	assert(strcmp(buf, "0xdeadbeafdeadbeef") == 0);

	return 0;
}

