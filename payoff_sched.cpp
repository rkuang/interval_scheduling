#include <iostream>
#include <vector>
#include "payoff_sched.hpp"

using namespace std;

int main() {
    vector<Activity*> activities;
    int start, end, payoff;
    while (cin >> start >> end >> payoff) {
        activities.push_back(new Activity(start, end, payoff));
    }

    sort(activities.begin(), activities.end(), ActivityComparator());

    return 0;
}