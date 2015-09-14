CC=gcc
default: equeen

equeen: equeen.c
	${CC} $+ -o $@ -Wall

debug: equeen.c
	${CC} $+ -o equ-debug -g -Wall -DDEBUG
