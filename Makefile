CC=gcc
default: equeen

equeen: equeen.c
	${CC} $+ -o $@ -g -Wall

debug: equeen.c
	${CC} $+ -o $@ -g -Wall -DDEBUG

clean:
	if [ -f equeen ]
	then
	rm equeen
	fi
