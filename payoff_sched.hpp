#ifndef PAYOFF_SCHED_H
#define PAYOFF_SCHED_H

class Activity {
    public:
        int start;
        int end;
        int payoff;

        Activity(int _start, int _end, int _payoff) {
            start = _start;
            end = _end;
            payoff = _payoff;
        }
        
};

struct ActivityComparator {
    bool operator() (const Activity *a1, const Activity *a2) const {
        return a1->end < a2->end;
    };
};

#endif