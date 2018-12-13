#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-lncurses
CXXFLAGS=-lncurses

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ncurses_learn

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ncurses_learn: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/ncurses_learn ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I/usr/include/ncursesw -include /usr/include/ncursesw/curses.h -include /usr/include/ncursesw/cursesapp.h -include /usr/include/ncursesw/cursesf.h -include /usr/include/ncursesw/cursesm.h -include /usr/include/ncursesw/cursesp.h -include /usr/include/ncursesw/cursesw.h -include /usr/include/ncursesw/cursslk.h -include /usr/include/ncursesw/eti.h -include /usr/include/ncursesw/etip.h -include /usr/include/ncursesw/form.h -include /usr/include/ncursesw/menu.h -include /usr/include/ncursesw/nc_tparm.h -include /usr/include/ncursesw/ncurses.h -include /usr/include/ncursesw/ncurses_dll.h -include /usr/include/ncursesw/panel.h -include /usr/include/ncursesw/term.h -include /usr/include/ncursesw/term_entry.h -include /usr/include/ncursesw/termcap.h -include /usr/include/ncursesw/tic.h -include /usr/include/ncursesw/unctrl.h -std=c++14 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
