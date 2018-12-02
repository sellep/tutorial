CC=g++
TIME=/usr/bin/time

all: clean 
	$(CC)         src/main.cpp -o bin/native_linked_list
	$(CC) -DTAIL  src/main.cpp -o bin/tailed_linked_list
	$(CC) -DARRAY src/main.cpp -o bin/array_list

test:
	@rm -rf test/*

	@for count in 100 250 500 750 1000 2500 5000 7500 10000 25000 50000 75000 100000 250000 ; do \
		echo $$count >> test/elements ; \
		$(TIME) -a -o test/native -f "%U,%S" bin/./native_linked_list $$count ; \
		$(TIME) -a -o test/tailed -f "%U,%S" bin/./tailed_linked_list $$count ; \
		$(TIME) -a -o test/array -f "%U,%S" bin/./array_list $$count ; \
	done

	@echo "elems,native user,native kern,tailed user,tailed kern,array user,array kern" >> test/times
	@paste -d ',' test/elements test/native test/tailed test/array >> test/times
	@column -t -s, test/times
clean:
	@mkdir -p bin test
	@rm -rf bin/*

.PHONY: test