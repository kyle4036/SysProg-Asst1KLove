all: fileCompressor.c Huffman.o
	gcc fileCompressor.c -o fileCompressor

clean:
	rm fileCompressor; rm db; rm Huffman.o

debug: fileCompressor.c Huffman.o
	gcc -ggdb fileCompressor.c Huffman.o -o db

Huffman.o: Huffman.c
	gcc -c Huffman.c

everything: clean all debug
	echo "done making everything"

run: fileCompressor
	./fileCompressor

test1: fileCompressor
	./fileCompressor -R -b ./
