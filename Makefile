# $Id: Makefile,v 1.4 2016-09-21 16:56:20-07 - - $

GPP      = g++ -std=gnu++14 -g -O0 -Wall -Wextra
MKDEP    = g++ -std=gnu++14 -MM
VALGRIND   = valgrind --leak-check=full --show-reachable=yes

MKFILE   = Makefile
DEPFILE  = Makefile.dep
SOURCES  = main.cpp astree.cpp lyutils.cpp auxlib.cpp
GENSRCS  = yyparse.cpp yylex.cpp
HEADERS  = stringset.h oc.h auxlib.h lyutils.h astree.h
OBJECTS  = ${SOURCES:.cpp=.o} ${GENSRCS:.cpp=.o}
EXECBIN    = oc
SRCFILES   = ${HEADERS} ${SOURCES} ${MKFILE}
SMALLFILES = ${DEPFILE} foo.oc foo1.oh foo2.oh
SUBMITS    = ${SRCFILES} README parser.y scanner.l

LSOURCES = scanner.l
YSOURCES = parser.y
CLGEN	 = yylex.cpp
HYGEN	 = yyparse.h
CYGEN	 = yyparse.cpp
LREPORT	 = yylex.output
YREPORT	 = yyparse.output


all : ${EXECBIN}

${EXECBIN} : ${OBJECTS}
	${GPP} ${OBJECTS} -o ${EXECBIN}

%.o : %.cpp
	${GPP} -c $<

${CLGEN} : ${LSOURCES}
	flex -outfile=${CLGEN} ${LSOURCES} 2>${LREPORT}
	- grep -v '^ ' ${LREPORT}

${CYGEN} ${HYGEN} : ${YSOURCES}
	bison --defines=${HYGEN} --output=${CYGEN} ${YSOURCES}

ci :
	cid + ${SRCFILES}

clean :
	-rm ${OBJECTS} ${DEPFILE}x
spotless : clean
	- rm ${EXECBIN} Listing.ps Listing.pdf test.out test.err

${DEPFILE} :
	${MKDEP} ${SOURCES} >${DEPFILE}

dep :
	- rm ${DEPFILE}
	${MAKE} --no-print-directory ${DEPFILE}

include ${DEPFILE}

test : ${EXECBIN}
	${EXECBIN} * * * >test.out 2>&1

lis : test
	mkpspdf Listing.ps ${SRCFILES} ${DEPFILE} test.out

again : ${SRCFILES}
	make --no-print-directory spotless dep ci test lis

checks:
	/afs/cats.ucsc.edu/courses/cmps104a-wm/bin/checksource ${SOURCES}

reset :
	git reset HEAD --hard
	git clean -f

submit:
	submit cmps104a-wm.f16 asg1 ${SUBMITION}
