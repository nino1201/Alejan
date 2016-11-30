biologos: biologos.pdf
		evince biologos.pdf
biologos.pdf: prob.py biologos.dat
			python prob.py
biologos.dat: biologos.c
		gcc biologos.c -lm
		./a.out > biologos.dat
.PHONY: clean
clean:
	rm -f a.out biologos.dat biologos.pdf
