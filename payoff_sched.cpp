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

    int q;
    for (int i=0; i<n; i++) {
        q = lastNonOverlapping(activities, i);
        opt[i+1] = max(opt[i], activities[i]->payoff+opt[q]);
    }

    cout << "Maximum Payoff:\t" << opt[n] << endl;

    return 0;
}