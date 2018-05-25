#ifndef PAYOFF_SCHED_H
#define PAYOFF_SCHED_H

#include <algorithm>

using namespace std;

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

int lastNonOverlapping(const vector<Activity *> activities, int i) {
    int val = -1;

    int left = 0;
    int right = i;
    int mid;
    while (left <= right) {
        mid = left + (right-left)/2;
        if (activities[mid]->end > activities[i]->start)
            right = mid - 1;
        else {
            val = mid;
            left = mid + 1;
        }
    }
    return val+1;
}

#endif