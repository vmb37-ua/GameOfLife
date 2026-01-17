prog: game.c
	gcc -o prog game.c `sdl2-config --cflags --libs`

clean:
	rm -f *.o