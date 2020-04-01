all: fileCompressor.c
	gcc fileCompressor.c -o fileCompressor

clean:
	rm fileCompressor; rm db

debug: fileCompressor.c
	gcc -ggdb fileCompressor.c -o db

everything: clean all debug
	echo "done making everything"

run: fileCompressor
	./fileCompressor
