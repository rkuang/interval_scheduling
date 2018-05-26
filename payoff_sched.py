#!/usr/bin/env python3
import sys
import fileinput

def lastNonOverlapping(activities, i):
    val = -1
    left = 0
    right = i
    while (left <= right):
        mid = left + int((right-left)/2)
        if activities[mid][1] > activities[i][0]:
            right = mid - 1
        else:
            val = mid
            left = mid + 1
    return val+1

def printSchedule(opt_sched, i):
    out = []
    while opt_sched[i][1] != 0:
        out.append(opt_sched[i][0])
        i = opt_sched[i][1]
    out.append(opt_sched[i][0])
    for i in range(len(out)-1, -1, -1):
        print(out[i][0], out[i][1], out[i][2])

def main():
    activities = []
    for line in fileinput.input():
        line = line.strip('\n')
        line = line.split()
        activities.append((int(line[0]), int(line[1]), int(line[2])))

    activities.sort(key=lambda x: x[1])

    n = len(activities)
    opt = [None] * (n+1)
    opt[0] = 0

    opt_sched = [(None, None)] * (n+1)
    # print(opt_sched)

    q = 0
    for i in range(n):
        q = lastNonOverlapping(activities, i)
        if (opt[i] >= activities[i][2] + opt[q]):
            opt[i+1] = opt[i]
            opt_sched[i+1] = opt_sched[i]
        else:
            opt[i+1] = activities[i][2] + opt[q]
            opt_sched[i+1] = (activities[i], q)
            # opt_sched[i+1].append(activities[i])

    print("Maximum Payoff:", opt[n])
    printSchedule(opt_sched, n)

main()
# print(activities)