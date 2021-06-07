all:pageLoader.o page.o

test:test.e

test.e: pageLoader.o page.o test.o
g++ pageLoader.o page.o test.o test.o -lcurlpp -lcurl -o test.e


test.o: test.cpp
g++ test.cpp - c - o page.o

page.o: page.cpp page.hpp
g++ page.cpp -c -o page.o

pageLoader .o:pageLoader.cpp pageLoader.hpp
g++ pageLoader.cpp -c -o pageLoader.o

clean:
rm * .o * .e 


