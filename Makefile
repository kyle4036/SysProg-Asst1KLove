all: fileCompressor.c
	gcc fileCompressor fileCompressor.c

clean: fileCompressor db
	rm fileCompressor; rm db

debug: fileCompressor.c
	gcc -ggdb db fileCompressor.c

fileCompressor:
	touch fileCompressor

db:
	touch db

run:
	./fileCompressor
