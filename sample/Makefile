###############################################################################
### @file:    Makefile
### @author:  Doug McGeehan (djmvfb@mst.edu)
### @date:    5 March 2012
###############################################################################

###############################################################################
# Begin make macro definitions
#

# CXX Macro for the location of the GNU C compiler
CXX=/usr/bin/cc

# FLAGS Macro for the common flags of the GNU C compiler
FLAGS=-lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE -g

# XFLAGS Macro for common compilation flags of the GNU C compiler
XFLAGS=-c ${FLAGS}

# .SUFFIXES Macro allows utilization of make's very own suffix rules
.SUFFIXES=.c

# SOURCES Macro for all source files in this project
SOURCES=$(wildcard *${.SUFFIXES})

# HEADERS Macro for all header files in this project
HEADERS=$(wildcard *.h)

# OBJECTS Macro containing all objects for this project
OBJECTS=${SOURCES:%${.SUFFIXES}=%.o}

# FINALEXEC Macro defines the name of the final executable
FINALEXEC=solution

#
# End make macro definitions
###############################################################################
# Begin make target and dependency definitions
#

# This utilizes the make suffix rules by compiling each source files into an
#  object file.
%.o: %.c
	${CXX} ${XFLAGS} $< -o $@

# When $ make is called on the command line, call the all target
default: all

# When $ make all is called on the command line, call the solution target
all: solution

# In order to build the fully-linked solution, all compiled objects are needed
solution: ${OBJECTS}
	${CXX} ${FLAGS} ${OBJECTS} -o ${FINALEXEC}

# Clean up all files created from past calls to make
clean:
	-@rm -f core >/dev/null 2>&1
	-@rm -f solution >/dev/null 2>&1
	-@rm -f ${OBJECTS} >/dev/null 2>&1

#
# End make target and dependency definitions
###############################################################################
