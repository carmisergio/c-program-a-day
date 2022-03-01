all: helloworld inefficientprimes excommunicado random squaremeters

clean:
	rm -r build

helloworld: helloworld.c
	mkdir -p build
	gcc helloworld.c -o build/helloworld

inefficientprimes: inefficientprimes.c
	mkdir -p build
	gcc inefficientprimes.c -o build/inefficientprimes

excommunicado: excommunicado.c
	mkdir -p build
	gcc excommunicado.c -o build/excommunicado

random: random.c
	mkdir -p build
	gcc random.c -o build/random
	
squaremeters: squaremeters.c
	mkdir -p build
	gcc squaremeters.c -o build/squaremeters

