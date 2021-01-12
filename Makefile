a.out: main.o fun_stack.o parser.o store.o alex.o
	$(CC) $^
main.o: parser.h
parser.o: parser.h alex.h fun_stack.h store.h
alex.o: alex.h
store.o: store.h
fun_stack.o: fun_stack.h

