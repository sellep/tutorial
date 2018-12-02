CC=g++
TIME=/usr/bin/time

all: clean 
	$(CC)        src/main.c -o bin/native_linked_list
	$(CC) -DTAIL src/main.c -o bin/tailed_linked_list

test:
	@rm -rf test/*

	@for count in 100 250 500 750 1000 2500 5000 7500 10000 25000 50000 75000 100000 250000 ; do \
		echo $$count >> test/elements ; \
		$(TIME) -a -o test/native -f "%U,%S" bin/./native_linked_list $$count ; \
		$(TIME) -a -o test/tailed -f "%U,%S" bin/./tailed_linked_list $$count ; \
	done

	@echo "elements,native user,native kernel,tailed user,tailed kernel" >> test/times
	@paste -d ',' test/elements test/native test/tailed >> test/times
	@column -t -s, test/times
clean:
	@mkdir -p bin test
	@rm -rf bin/*

.PHONY: test