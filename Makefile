CC=gcc
default: equeen

equeen: equeen.c
	${CC} $+ -o $@ -g -Wall

clean:
	if [ -f equeen ]
	then
	rm equeen
	fi
