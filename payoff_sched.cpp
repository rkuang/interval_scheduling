#include <iostream>
#include <vector>
#include "payoff_sched.hpp"

using namespace std;

int main() {
    vector<Activity *> activities;
    int start, end, payoff;
    while (cin >> start >> end >> payoff) {
        activities.push_back(new Activity(start, end, payoff));
    }

    sort(activities.begin(), activities.end(), ActivityComparator());

    int n = activities.size();
    int opt[n+1];
    opt[0] = 0;

    vector<Activity *> opt_sched[n+1];

    int q;
    for (int i=0; i<n; i++) {
        q = lastNonOverlapping(activities, i);
        if (opt[i] >= activities[i]->payoff+opt[q]) {
            opt[i+1] = opt[i];
            opt_sched[i+1] = opt_sched[i];
        } else {
            opt[i+1] = activities[i]->payoff+opt[q];
            opt_sched[i+1] = opt_sched[q];
            opt_sched[i+1].push_back(activities[i]);
        }
    }

    cout << "Maximum Payoff: " << opt[n] << endl;
    vector<Activity *>::iterator it;
    for (it=opt_sched[n].begin(); it!=opt_sched[n].end(); it++) {
        cout << (*it)->start << " " << (*it)->end << " " << (*it)->payoff << endl;
    }

    return 0;
}