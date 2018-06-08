# interval_scheduling

This is a dynamic programming solution to the weighted activity scheduling problem.
* Given a sequence of n activities, each with a start time, finish time, and weight, find the schedule that maximizes the total weight.

The algorithm is as follows:
* sort the activities by finish time
* for each activity
    * q = last non-overlapping activity
    * opt(j) =  max{ opt(j-1), w_j + opt(q)}

To run this program, do ```./payoff_sched < <input>```

This was originally coded in C++, but I ran into a problem regarding C++ being a pass by value language, resulting in poor runtimes. An easy fix would be to pass a reference instead of the value and will be explored in the future.