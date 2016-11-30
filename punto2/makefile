planetas.png: prob.py planetas.dat
			python prob.py
planetas.dat: planetas.c
		gcc planetas.c -lm
		./a.out > planetas.dat
.PHONY: clean
clean:
	rm -f a.out planetas.dat planetas.png
