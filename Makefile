all: fileCompressor.c Huffman.o lList.o
	gcc fileCompressor.c Huffman.o -o fileCompressor

clean:
	rm fileCompressor; rm db; rm Huffman.o;rm lList.o

debug: fileCompressor.c Huffman.o
	gcc -ggdb fileCompressor.c Huffman.o -o db

Huffman.o: Huffman.c lList.o
	gcc -c Huffman.c lList.o

lList.o: lList.c
	gcc -c lList.c

everything: clean all debug
	echo "done making everything"

run: fileCompressor
	./fileCompressor

test1: fileCompressor
	./fileCompressor -R -b ./

test2: fileCompressor
	./fileCompressor -b brownFox
