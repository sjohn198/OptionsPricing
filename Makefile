C++C = clang++
CFLAGS = -Wall -g

put_call_parity: put_call_parity.o util.o
	$(C++C) ${CFLAGS} -o put_call_parity put_call_parity.o util.o

put_call_parity.o: put_call_parity.cpp
	$(C++C) $(CFLAGS) -c put_call_parity.cpp

bsm_probabalistic: bsm_probabalistic.o util.o
	$(C++C) ${CFLAGS} -o bsm_probabalistic bsm_probabalistic.o util.o

bsm_probabalistic.o: bsm_probabalistic.cpp
	$(C++C) $(CFLAGS) -c bsm_probabalistic.cpp

util.o: util.cpp
	$(C++C) $(CFLAGS) -c util.cpp