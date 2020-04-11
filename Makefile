
BINFILE := vector

CFLAGS := -O2 -g -Wall



vector: obj obj/points.o
	gcc $(CFLAGS) -c -o obj/vector.o src/vector.c
	gcc $(CFLAGS) -c -o obj/main.o src/main.c
	gcc obj/* -o $(BINFILE) -lm

obj/points.o: src/points.c
	gcc $(CFLAGS) -c -o obj/points.o src/points.c

src/points.c:
	python3 genpoints.py > src/points.c

obj:
	mkdir $@

clean:
	rm -f obj/*
	rm -f $(BINFILE)
