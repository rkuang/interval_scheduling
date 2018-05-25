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

    vector<Activity *> out[n+1];

    int q;
    for (int i=0; i<n; i++) {
        q = lastNonOverlapping(activities, i);
        // opt[i+1] = max(opt[i], activities[i]->payoff+opt[q]);
        if (opt[i] >= activities[i]->payoff+opt[q]) {
            opt[i+1] = opt[i];
            out[i+1] = out[i];
        } else {
            opt[i+1] = activities[i]->payoff+opt[q];
            out[i+1] = out[q];
            out[i+1].push_back(activities[i]);
        }
    }

    cout << "Maximum Payoff: " << opt[n] << endl;
    vector<Activity *>::iterator it;
    for (it=out[n].begin(); it!=out[n].end(); it++) {
        cout << (*it)->start << " " << (*it)->end << " " << (*it)->payoff << endl;
    }

    return 0;
}