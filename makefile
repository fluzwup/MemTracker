CPP =    g++ -Wall -traditional -fms-extensions
CC =    gcc -ansi

# -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC 
#
OBJDIR = ./obj

COMMAND =	memtest

OBJS = \
	   tracker.o \
	   trackerpp.o \
	   MemTracker.o \
	   test.o
	   


DEFINES	 = 

LIBDIRS	 = 
CFLAGS	  = -ggdb 
#CFLAGS	  = -O2 -DNDEBUG 

# -g    for debugging
# -O    for Optimal code. Cannot use both!

LIBRARIES      = -lstdc++ 

#
# Rule sets
#

#.cpp.o:
%.o: %.cpp
	$(CPP) -c $(CFLAGS) $< -o $@
	chmod a+rw $@

#.c.o:
%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	chmod a+rw $@

all: ${COMMAND}

${COMMAND}: $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@

clean:
	rm -f $(OBJS) ${COMMAND} *.errlog

# end of Makefile.customer
#

