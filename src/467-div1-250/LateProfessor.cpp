#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset((x), (a), (int)sizeof(x))
#define VI vector < int >
#define LL long long 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class LateProfessor {
	public:
	double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival) {
        LL turn = waitTime + walkTime;
        LL NGend = turn - lateTime;
        if(NGend <= waitTime) return 0.0;
        
        int time = bestArrival/turn;
        bestArrival -= turn*time;
        worstArrival -= turn*time;
        
		int all = worstArrival - bestArrival;
        if(all == 0){
            if(bestArrival > waitTime && worstArrival <= NGend) return 1.0;
            else return 0.0;
        }
        
        int endtime = worstArrival/turn;
        LL NG = (NGend - waitTime) * (endtime + 1);
        if(bestArrival > NGend) NG -= (NGend - waitTime);
        else NG -= max(0, bestArrival-waitTime);
        worstArrival -= turn*endtime;
        if(worstArrival < waitTime) NG -= (NGend - waitTime);
        else NG -= max(0LL, NGend-worstArrival);
        
        return (double)NG/all;
	}
};

// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int waitTime              = 20;
			int walkTime              = 30;
			int lateTime              = 10;
			int bestArrival           = 0;
			int worstArrival          = 50;
			double expected__         = 0.4;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int waitTime              = 20;
			int walkTime              = 30;
			int lateTime              = 10;
			int bestArrival           = 30;
			int worstArrival          = 100;
			double expected__         = 0.42857142857142855;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int waitTime              = 20;
			int walkTime              = 40;
			int lateTime              = 50;
			int bestArrival           = 0;
			int worstArrival          = 300;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int waitTime              = 101;
			int walkTime              = 230;
			int lateTime              = 10;
			int bestArrival           = 654;
			int worstArrival          = 17890;
			double expected__         = 0.6637270828498492;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int waitTime              = 20;
			int walkTime              = 30;
			int lateTime              = 10;
			int bestArrival           = 90;
			int worstArrival          = 90;
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int waitTime              = 1000;
			int walkTime              = 600;
			int lateTime              = 1;
			int bestArrival           = 17000;
			int worstArrival          = 17000;
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int waitTime              = ;
			int walkTime              = ;
			int lateTime              = ;
			int bestArrival           = ;
			int worstArrival          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int waitTime              = ;
			int walkTime              = ;
			int lateTime              = ;
			int bestArrival           = ;
			int worstArrival          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int waitTime              = ;
			int walkTime              = ;
			int lateTime              = ;
			int bestArrival           = ;
			int worstArrival          = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = LateProfessor().getProbability(waitTime, walkTime, lateTime, bestArrival, worstArrival);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}

/*
// PROBLEM STATEMENT
// Punctuality is not exactly one of Dr. Wesley's strengths.  His student John always shows up for class at the scheduled starting time, but he never knows when Dr. Wesley will arrive.  This is a problem for John because he cannot stay in the same place doing nothing for a long period of time.  Therefore, he has come up with the following method to reduce the amount of time he spends waiting by the classroom door.

John arrives at time 0.
John waits for Dr. Wesley to arrive.
If after waitTime seconds Dr. Wesley has not arrived yet, John goes to take a walk for walkTime seconds.
John therefore arrives back to the classroom exactly at time waitTime + walkTime. 
If Dr. Wesley has not arrived yet, John waits another waitTime seconds and then proceeds to take a new walk. The process is repeated until John becomes aware that Dr. Wesley has arrived.

Overall, John stands in front of the class door from time 0 to time waitTime, inclusive, then from time walkTime + waitTime to time walkTime + 2*waitTime, inclusive, and so on. At all other time moments he walks outside.


This has solved John's patience issues, but it has caused a new problem.  When John returns from a walk, if Dr. Wesley is already in the classroom, it will appear that John has arrived late to class.  Dr. Wesley does not like that, and he will deny John access to the class if he arrives lateTime or more seconds after the time at which Dr. Wesley arrived.

There are multiple variables that affect Dr. Wesley's arrival time, but for the purpose of the problem, assume that the arrival time will be a real number chosen uniformly from bestArrival to worstArrival, inclusive. Return the probability that John will be denied access to Dr. Wesley's class.

DEFINITION
Class:LateProfessor
Method:getProbability
Parameters:int, int, int, int, int
Returns:double
Method signature:double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival)


NOTES
-The returned value must have an absolute or relative error less than 1e-9.


CONSTRAINTS
-waitTime, walkTime, lateTime and worstArrival will each be between 1 and 10000000, inclusive.
-bestArrival will be between 0 and worstArrival, inclusive.


EXAMPLES

0)
20
30
10
0
50

Returns: 0.4

The professor will arrive at some random moment between 0 and 50 seconds, inclusive. During this interval, these are John's activities:
He waits from time 0 to time 20, inclusive.
He takes a walk between times 20 and 50, non-inclusive.
He arrives back at time 50.

John will only be too late if the professor arrives while he is away, and more than 10 seconds before he returns.
This only happens if the professor arrives strictly between times 20 and 40. The probability that this will happen is (40-20)/(50-0) = 0.4.

1)
20
30
10
30
100

Returns: 0.42857142857142855

If the professor arrives between 30 and 40 seconds or between 70 and 90 seconds, John will be late to the class.

2)
20
40
50
0
300

Returns: 0.0

John's walking time is 40 seconds. Hence, even if the professor arrives while John is taking a walk, John will always be less than 50 seconds late.

3)
101
230
10
654
17890

Returns: 0.6637270828498492



4)
20
30
10
90
90

Returns: 1.0

Dr. Wesley will always arrive at time 90 seconds. John will arrive at time 100 seconds after taking two different walks. Since the time difference is equal to 10 seconds, John will be too late.

5)
1000
600
1
17000
17000

Returns: 0.0



*/

// END CUT HERE
