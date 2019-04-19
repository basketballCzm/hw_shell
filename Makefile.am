AUTOMAKE_OPTIONS = foreign
AM_CPPFLAGS = 

bin_PROGRAMS=msgsend maintest

msgsend_SOURCES=msgsend.cpp
msgsend_LDADD= 

maintest_SOURCES=maintest.cpp code/msgreceive.cpp code/funcmap.cpp code/typesmap.cpp testfunc.cpp
maintest_LDADD= -lpthread