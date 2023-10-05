ALL = main
all: $(ALL)

main: main.c randArray1.c randArray10.c randArray100.c
	gcc -o $@ $^ -lm

%.o: %.c
	gcc -c $<

clean:
	rm -f *.s *.o output erro

distclean: clean
	rm -f $(ALL)