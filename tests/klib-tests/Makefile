.PHONY: all run gdb clean latest $(ALL)

RESULT = .result
$(shell > $(RESULT))

COLOR_RED   = \033[1;31m
COLOR_GREEN = \033[1;32m
COLOR_NONE  = \033[0m

# if ALL is not provided, it will be all test_filename in dir tests
ALL = $(basename $(notdir $(shell find tests/. -name "*.c"))) # ALL = recursion add

ECHO_STRING = "NAME = $*\nSRCS = $<\nLIBS += klib\ninclude $${AM_HOME}/Makefile"

all: $(addprefix Makefile., $(ALL)) # all: Makefile.recursion Makefile.add
	@echo "added by chenyinhua, In all: $$ALL = " $(ALL)

$(ALL): %: Makefile.% # recursion add:  %: Makefile.%   

# Makefile.recursion Makefile.add: tests/recursion.c tests/add.c latest
Makefile.%: tests/%.c latest 
	# we create Makefile.recursion and Makefile.add here
	# their contents are 
	# NAME = recursion 
	# SRCS = tests/recursion.c 
	# LIBS += klib 
	# include ${AM_HOME}/Makefile
	@/bin/echo -e $(ECHO_STRING) > $@
	@echo "ARCH = $(ARCH)"
	@echo "MAKECMDGOALS = $(MAKECMDGOALS)"
	# if make -s -f Makefile.recursion ARCH=$(ARCH) $(MAKECMDGOALS); then 
	# -s: Silent operation; do not print the commands as they are executed.
	# -f: Use file as a makefile.
	# Notice, the argument of %14s here is $*, which is the stem of $@
	# Here, we actually execute the Makefile in ${AM_HOME}/Makefile
	@if make -s -f $@ ARCH=$(ARCH) $(MAKECMDGOALS); then \
		printf "[%14s] $(COLOR_GREEN)PASS!$(COLOR_NONE)\n" $* >> $(RESULT); \
	else \
		printf "[%14s] $(COLOR_RED)FAIL!$(COLOR_NONE)\n" $* >> $(RESULT); \
	fi
	-@rm -f Makefile.$* # all Makefile.% are deleted here

run: all
	# after all outputs are printed to .resut, we cat .result, and then rm .result
	@cat $(RESULT)
	@rm $(RESULT)

gdb: all

clean:
	rm -rf Makefile.* build/

latest: # just a fake target
