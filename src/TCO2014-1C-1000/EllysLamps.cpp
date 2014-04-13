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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class EllysLamps {
	public:
	int getMin(string lamps) {
		int n = SZ(lamps);
        int res = 0;
        bool N = false;
        bool used = false;
        int Y = 0;
        REP(i, n){
            if(lamps[i] == 'N'){
                if(Y > 0){
                    res++;
                    used = true;
                }
                else used = false;
                Y = 0;
                N = true;
            }
            else{
                Y++;
                if(N && !used){
                    res++;
                    Y = 0;
                }
                else if(Y == 3){
                    res++;
                    Y = 0;
                }
                N = false;
            }
        }
        return res;
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
	
	int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
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
			string lamps              = "YNNYN";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string lamps              = "NNN";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string lamps              = "YY";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string lamps              = "YNYYYNNNY";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string lamps              = "YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY";
			int expected__            = 13;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string lamps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string lamps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string lamps              = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysLamps().getMin(lamps);
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
// Elly has a row of N lamps, conveniently numbered from 0 to N-1. Some of them are initially lit and the rest are not. She can control the lamps using a controller. On the controller there is a row of N buttons. Clicking the button with index i changes the state of lamp i: it goes off, if it was on, and it goes on if it was off.

Unfortunately the controller has some defects. Each of the buttons correctly changes the state of the corresponding lamp. However, it is possible that some of the buttons also change the state of one or both adjacent lamps as well. This means that pressing the button with index i has the following effects:

The state of lamp i changes.
If there is a lamp with index i-1, its state might change.
If there is a lamp with index i+1, its state might change.

The girl does not initially know which lamps change their state when each of the buttons is pressed. She knows, however, that every time she clicks a particular button, the same set of lamps will change their states.

Elly wants to reach a configuration in which the number of lamps that are turned on is minimized. Help her determine how many of them will remain lit in the worst possible case. (That is, for the worst possible way how the buttons change the state of the lamps.) She can use each of the buttons as many times as she likes, in any order she likes.

You will be given a string lamps, which gives information about the initial state of the lamps. The i-th character of lamps will be 'Y' if the i-th lamp is lit, and 'N', if it is not. Return the minimal number of lit lamps the girl can get in the worst possible case.

DEFINITION
Class:EllysLamps
Method:getMin
Parameters:string
Returns:int
Method signature:int getMin(string lamps)


NOTES
-The defects in the switches might not be symmetric. This means that if a lamp with index i happens to change the state of lamp i+1, this does not necessarily mean that the using the switch of lamp i+1 changes the state of lamp i.


CONSTRAINTS
-lamps will contain between 1 and 50 elements, inclusive.
-Each element of lamps will be either 'Y' or 'N'.


EXAMPLES

0)
"YNNYN"

Returns: 2

In this case Elly will only make things worse (or the same) by pressing buttons. For example, suppose that:

buttons 0 and 1 each change the state of both lamps 0 and 1
buttons 2 and 3 each change the state of both lamps 2 and 3
button 4 only changes the state of lamp 4

In this situation, Elly cannot reach any configuration with fewer than two lit lamps.

1)
"NNN"

Returns: 0

Obviously, with no initially lit lamps, Elly can just sit and relax.

2)
"YY"

Returns: 0

If one of the lamps influences the other one, then Elly can use it and turn both off with one button press. Otherwise, each button changes the state of its lamp only, thus Elly can turn them both off by pressing both buttons.

3)
"YNYYYNNNY"

Returns: 3



4)
"YNYYYYNYNNYYNNNNNNYNYNYNYNNYNYYYNY"

Returns: 13



*/

// END CUT HERE
