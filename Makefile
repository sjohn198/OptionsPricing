C++C = clang++
CFLAGS = -Wall -g

put_call_parity: put_call_parity.o
	$(C++C) ${CFLAGS} -o put_call_parity put_call_parity.o

put_call_parity.o: put_call_parity.cpp
	$(C++C) $(CFLAGS) -c put_call_parity.cpp