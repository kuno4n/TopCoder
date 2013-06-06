
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
#include <numeric>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl

int n;
LL MOD = 1000000007;
LL dp[400][400];
LL res[400];

void mul(LL *a, LL *b){
    LL tmp[n]; MSET(tmp, 0);
    REP(i, n) REP(j, n) tmp[(i+j)%n] = (tmp[(i+j)%n] + (a[i] * b[j])%MOD) % MOD;
    REP(i, n) a[i] = tmp[i];
}

void _pow(LL x){
    LL wk[n];
    MSET(res, 0); MSET(wk, 0);
    res[0] = 1;
    REP(i, n) wk[i] = dp[n][i];
    while(x){
        if(x&1) mul(res, wk);
        mul(wk, wk);
        x >>= 1;
    }
}

class PenguinEmperor {
public:
    int countJourneys( int numCities, long long daysPassed ) {
        n = numCities; MSET(dp, 0);
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            REP(j, n){
                dp[i][(j+i)%n] = (dp[i][(j+i)%n] + dp[i-1][j]) % MOD;
                if((j+i)%n != (j-i+n)%n) dp[i][(j-i+n)%n] = (dp[i][(j-i+n)%n] + dp[i-1][j]) % MOD;
            }
        }
        _pow(daysPassed/numCities);
        mul(res, dp[daysPassed%numCities]);
        return res[0];
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
			int numCities             = 3;
			long long daysPassed      = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numCities             = 4;
			long long daysPassed      = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numCities             = 5;
			long long daysPassed      = 36;
			int expected__            = 107374182;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numCities             = 300;
			long long daysPassed      = 751;
			int expected__            = 413521250;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numCities             = 300;
			long long daysPassed      = 750;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int numCities             = 350;
			long long daysPassed      = 1000000000000000000LL;
			int expected__            = 667009739;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			int numCities             = 5;
			long long daysPassed      = 7;
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int numCities             = ;
			long long daysPassed      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int numCities             = ;
			long long daysPassed      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			int numCities             = ;
			long long daysPassed      = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PenguinEmperor().countJourneys(numCities, daysPassed);
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
// 
Percy would like to become the Penguin Emperor. First, he must go on a long journey to prove himself worthy.



There are several cities in Penguin Empire.
All the cities lie on a circle around the great mountain.
The cities are numbered 0 through numCities-1 in the clockwise direction around the mountain.



Percy lives in city 0 and that is where he will begin his journey. On the first day he will travel to a city adjacent to city 0. On the second day he will travel to another city two cities away from his current city. And so on: for each k, on the k-th day he will travel to a new city k cities away. Each day, Percy can choose a new direction of travel: either clockwise or counter-clockwise around the mountain.







You are given the int numCities representing the number of cities in the Penguin Empire. You are also given a long long daysPassed representing the number of days that have passed since Percy's journey began. Compute and return the number of journeys that take daysPassed days and return home to city 0. Two journeys are considered different if there is some k such that after k days the traveler is in different cities. As the number of journeys can be quite large, please return the result modulo 1,000,000,007.


DEFINITION
Class:PenguinEmperor
Method:countJourneys
Parameters:int, long long
Returns:int
Method signature:int countJourneys(int numCities, long long daysPassed)


CONSTRAINTS
-numCities will be between 2 and 350, inclusive.
-daysPassed will be between 1 and 10^18, inclusive.


EXAMPLES

0)
3
2

Returns: 2

There are two ways to have a Journey that returns home after two days.

0 -> 1 -> 0 where directions are CW-CW
0 -> 2 -> 0 where directions are CCW-CCW

CW = clockwise
CCW = counter-clockwise

1)
4
3

Returns: 2

There are two ways to have a Journey that returns home after three days.

0 -> 1 -> 3 -> 0 where directions are CW-CW-CCW or CW-CCW-CCW
0 -> 3 -> 1 -> 0 where directions are CCW-CCW-CW or CWW-CW-CW

CW = clockwise
CCW = counter-clockwise

2)
5
36

Returns: 107374182



3)
300
751

Returns: 413521250



4)
300
750

Returns: 0



5)
350
1000000000000000000

Returns: 667009739



6)
5
7

Returns: 12



*/

// END CUT HERE
