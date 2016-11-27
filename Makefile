CC:=gcc
CFLAGS:=-Wall -ansi -pedantic -g
BIN:=ep5

#make binaries

$(BIN):hex.o
	$(CC) $(CFLAGS) -o $@ $^

#make objects

%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

#make objects with headers

%.o:%.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

#make clean

clean:
	rm -f $(BIN)
	rm -f hex.o
