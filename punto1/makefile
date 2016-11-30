sismos.png: prob.py sismos.dat
			python prob.py
sismos.dat: sismos.c
		gcc sismos.c -lm
		./a.out > sismos.dat
.PHONY: clean
clean:
	rm -f a.out sismos.dat sismos.png
