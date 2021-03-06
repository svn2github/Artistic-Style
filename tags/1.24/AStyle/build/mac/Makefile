# Make file for GCC compiler on Mac OS X
# The license.html file describes the conditions under which this software may be distributed.

# to test on Linux use "make  linux=1"

# list of source files
SRC = astyle_main.cpp \
      ASBeautifier.cpp \
      ASFormatter.cpp \
      ASEnhancer.cpp \
      ASResource.cpp

# source directories
vpath %.cpp ../../src
vpath %.h   ../../src

# NOTE for java compiles the environment variable $JAVA_HOME must be set
# example: export JAVA_HOME=/usr/lib/jvm/java-6-sun-1.6.0.00
ifndef JAVA_HOME
    JAVA_HOME = /usr/lib/jvm/java-6-sun-1.6.0.16
endif

# set prefix if not defined on the command line
ifndef prefix
    prefix=/usr
endif
SYSCONF_PATH=$(prefix)/share/astyle

# define macros
dylib = dylib
dynamiclib = -dynamiclib
bindir = bin
objdir = obj
ipath=$(prefix)/bin
CBASEFLAGS = -W -Wall -fno-rtti -fno-exceptions
JAVAINCS   = -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux
CXX = g++
INSTALL=install -o $(USER) -g $(USER)

# for testing on linux
ifdef linux
    dylib = so
    dynamiclib = -shared
endif

##################################################

# define compile options for each build
CFLAGS   = -DNDEBUG -O3 $(CBASEFLAGS)
CFLAGSd  = -g $(CBASEFLAGS)
CFLAGSs  = -DNDEBUG -DASTYLE_LIB -O3 -fPIC $(CBASEFLAGS)
CFLAGSsd = -DASTYLE_LIB -g -fPIC $(CBASEFLAGS)
CFLAGSa  = -DNDEBUG -DASTYLE_LIB -O3 $(CBASEFLAGS)
CFLAGSad = -DASTYLE_LIB -g $(CBASEFLAGS)
CFLAGSsj  = -DNDEBUG -DASTYLE_JNI -O3 -fPIC $(CBASEFLAGS) $(JAVAINCS)
CFLAGSsjd = -DASTYLE_JNI -g -fPIC $(CBASEFLAGS) $(JAVAINCS)

# object files are built from the source list $(SRC)
# a suffix is added for each build
OBJ   = $(patsubst %.cpp,$(objdir)/%.o,$(SRC))
OBJd  = $(patsubst %.cpp,$(objdir)/%_d.o,$(SRC))
OBJs  = $(patsubst %.cpp,$(objdir)/%_s.o,$(SRC))
OBJsd = $(patsubst %.cpp,$(objdir)/%_sd.o,$(SRC))
OBJa  = $(patsubst %.cpp,$(objdir)/%_a.o,$(SRC))
OBJad = $(patsubst %.cpp,$(objdir)/%_ad.o,$(SRC))
OBJsj  = $(patsubst %.cpp,$(objdir)/%_sj.o,$(SRC))
OBJsjd = $(patsubst %.cpp,$(objdir)/%_sjd.o,$(SRC))

# define object file rule (with the suffix) for each build

# OBJ
$(objdir)/%.o:  %.cpp  astyle.h  astyle_main.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGS) -c -o $@ $<

# OBJd
$(objdir)/%_d.o:  %.cpp  astyle.h  astyle_main.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGSd) -c -o $@ $<

# OBJs
$(objdir)/%_s.o:  %.cpp  astyle.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGSs) -c -o $@ $<

# OBJsd
$(objdir)/%_sd.o:  %.cpp  astyle.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGSsd) -c -o $@ $<

# OBJa
$(objdir)/%_a.o:  %.cpp  astyle.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGSa) -c -o $@ $<

# OBJad
$(objdir)/%_ad.o:  %.cpp  astyle.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGSad) -c -o $@ $<

# OBJsj
$(objdir)/%_sj.o:  %.cpp  astyle.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGSsj) -c -o $@ $<

# OBJsjd
$(objdir)/%_sjd.o:  %.cpp  astyle.h
	@ mkdir -p $(objdir)
	$(CXX) $(CFLAGSsjd) -c -o $@ $<

##################################################
# define build dependencies for each command

release:  astyle
astyle:  $(OBJ)
	@ mkdir -p $(bindir)
	$(CXX) -o $(bindir)/$@ $^
	strip $(bindir)/$@
	@ echo

debug:  astyled
astyled:  $(OBJd)
	@ mkdir -p $(bindir)
	$(CXX) -o $(bindir)/$@ $^
	@ echo

shared:  libastyle.$(dylib)
libastyle.$(dylib):  $(OBJs)
	@ mkdir -p $(bindir)
	$(CXX) $(dynamiclib) -o $(bindir)/$@ $^
	@ echo

shareddebug:  libastyled.$(dylib)
libastyled.$(dylib):  $(OBJsd)
	@ mkdir -p $(bindir)
	$(CXX) $(dynamiclib) -o $(bindir)/$@ $^
	@ echo

static:  libastyle.a
libastyle.a:  $(OBJa)
	@ mkdir -p $(bindir)
	ar crs $(bindir)/$@ $^
	@ echo

staticdebug:  libastyled.a
libastyled.a:  $(OBJad)
	@ mkdir -p $(bindir)
	ar crs $(bindir)/$@ $^
	@ echo

java:  libastylej.$(dylib)
libastylej.$(dylib):  $(OBJsj)
	@ mkdir -p $(bindir)
	$(CXX) $(dynamiclib) -o $(bindir)/$@ $^
	@ echo

javadebug:  libastylejd.$(dylib)
libastylejd.$(dylib):  $(OBJsjd)
	@ mkdir -p $(bindir)
	$(CXX) $(dynamiclib) -o $(bindir)/$@ $^
	@ echo

all:  release debug shared shareddebug static staticdebug

javaall:  java javadebug

clean:
	rm -f $(objdir)/*.o $(bindir)/*astyle*

cleanobj:
	rm -f $(objdir)/*.o
	
install:
	$(INSTALL) -m 755 -d $(ipath)
	@$(INSTALL) -m 755 $(bindir)/astyle  $(ipath)

	$(INSTALL) -m 755 -d $(SYSCONF_PATH)
	@for files in ../../doc/*.html  ../../doc/*.css; \
	do \
		$(INSTALL)  -m 644  $$files  $(SYSCONF_PATH); \
	done

uninstall:
	rm -f $(ipath)/astyle
	rm -rf $(SYSCONF_PATH)
