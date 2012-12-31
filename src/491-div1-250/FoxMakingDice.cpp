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

class FoxMakingDice {
	public:
	long long theCount(int N, int K) {
		LL table[2010] = {0};
        FOR(i, 7, 2005){
            table[i] = (i-1)/2;
            if(i-N >= 2) table[i] -= min(table[i], (LL)i-N-1);
        }
        
        REP(i, 2010) table[i] = (table[i]*(table[i]-1)*(table[i]-2))/3;
        LL res = 0;
        FOR(i, K, 2010) res += table[i];
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int N                     = 6;
			int K                     = 7;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int K                     = 7;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 1000;
			int K                     = 1;
			long long expected__      = 20625666000LL;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 456;
			int K                     = 123;
			long long expected__      = 879075732;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 913;
			int K                     = 1014;
			long long expected__      = 4506149340LL;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FoxMakingDice().theCount(N, K);
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
// Fox Jiro likes dice. He wants to make his own dice. Each die he wants to make is a cube. Each of the 6 faces has an integer between 1 and N, inclusive. No two faces have same number. Also the following condition must be satisfied: for all faces, the sum of the numbers on opposite faces must be equal and the sum must be greater than or equal to K.

He realized that there are many ways to make such dice. He wants to know how many ways there are. Please help Jiro to make a program that is given two integers N and K and returns the number of different dice satisfying the condition mentioned above.

Two dice are considered the same if you can rotate one to form the other.


DEFINITION
Class:FoxMakingDice
Method:theCount
Parameters:int, int
Returns:long long
Method signature:long long theCount(int N, int K)


NOTES
-The answer will always fit in a signed 64-bit integer.


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-K will be between 1 and 2,000, inclusive.


EXAMPLES

0)
6
7

Returns: 2

You can make normal dice. There are two ways to arrange the numbers.

1)
5
7

Returns: 0

You cannot make 6 sided dice with 5 numbers.

2)
1000
1

Returns: 20625666000



3)
456
123

Returns: 879075732



4)
913
1014

Returns: 4506149340



*/

// END CUT HERE
