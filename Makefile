C++C = clang++
CFLAGS = -Wall -g

all: bin/bsm_probabalistic bin/put_call_parity

bin/put_call_parity: obj/put_call_parity.o obj/util.o
	$(C++C) ${CFLAGS} -o $@ obj/put_call_parity.o obj/util.o

obj/put_call_parity.o: put_call_parity.cpp
	$(C++C) $(CFLAGS) -o $@ -c put_call_parity.cpp

bin/bsm_probabalistic: obj/bsm_probabalistic.o obj/util.o
	$(C++C) ${CFLAGS} -o $@ obj/bsm_probabalistic.o obj/util.o

obj/bsm_probabalistic.o: bsm_probabalistic.cpp
	$(C++C) $(CFLAGS) -o $@ -c bsm_probabalistic.cpp

obj/util.o: util.cpp
	$(C++C) $(CFLAGS) -o $@ -c util.cpp