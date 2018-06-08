CPP = g++
FLAGS =

all: payoff_sched

payoff_sched.o: payoff_sched.cpp payoff_sched.hpp
	$(CPP) $(FLAGS) -c -o $@ $<

payoff_sched: payoff_sched.o
	$(CPP) $(FLAGS) -o $@ $^

clean:
	rm -f *.o payoff_sched

.PHONY: clean
