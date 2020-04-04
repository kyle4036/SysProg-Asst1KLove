all: fileCompressor.c Huffman.o lList.o
	gcc fileCompressor.c Huffman.o lList.o -o fileCompressor

clean:
	rm fileCompressor; rm db; rm Huffman.o; rm lList.o; rm lListTest;rm hTree.o

debug: fileCompressor.c d_Huffman.o d_lList.o
	gcc -ggdb fileCompressor.c Huffman.o lList.o -o db

Huffman.o: Huffman.c lList.o
	gcc -c Huffman.c

hTree.o: hTree.c lList.o
	gcc -c hTree.c

lList.o: lList.c
	gcc -c lList.c

d_Huffman.o: Huffman.c d_lList.o
	gcc -ggdb -c Huffman.c

d_hTree.o: hTree.c d_lList.o
	gcc -ggdb -c hTree.c

d_lList.o: lList.c
	gcc -ggdb -c lList.c

everything: clean all debug
	echo "done making everything"

run: fileCompressor
	./fileCompressor

test1: fileCompressor
	./fileCompressor -R -b ./

test2: fileCompressor
	./fileCompressor -b brownFox

testlList: lListTest
	gdb lListTest

lListTest: lListTest.c lList.o
	gcc -ggdb lListTest.c lList.o -o lListTest
