
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl

int p, q, x, y;
int TH = 4000000;
LL memo[4000100];

class InfiniteSequence2 {

	LL rec(LL i){
		if(i<=0) return 1;
		if(i<TH && memo[i]>=0) return memo[i];
		LL res = rec(i/p-x) + rec(i/q-y);
		if(i<TH) memo[i] = res;
		return res;
	}

public:
   long long calc( long long N, int P, int Q, int X, int Y ) {
	   p = P;
	   q = Q;
	   x = X;
	   y = Y;
	   REP(i, TH) memo[i] = -1;
	   return rec(N);
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
			long long n               = 10000000;
			int p                     = 2;
			int q                     = 3;
			int x                     = 10000000;
			int y                     = 10000000;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 12;
			int p                     = 2;
			int q                     = 3;
			int x                     = 1;
			int y                     = 0;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 0;
			int p                     = 2;
			int q                     = 2;
			int x                     = 0;
			int y                     = 0;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 123;
			int p                     = 45;
			int q                     = 67;
			int x                     = 8;
			int y                     = 9;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long n               = ;
			int p                     = ;
			int q                     = ;
			int x                     = ;
			int y                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long n               = ;
			int p                     = ;
			int q                     = ;
			int x                     = ;
			int y                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			int p                     = ;
			int q                     = ;
			int x                     = ;
			int y                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = InfiniteSequence2().calc(n, p, q, x, y);
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
NOTE: This problem statement contains subscripts that may not display properly if viewed outside of the applet.


Let's consider an infinite sequence A defined as follows:

Ai = 1 for all i <= 0;
Ai = A[i/p]-x + A[i/q]-y for all i >= 1, where [x] denotes the floor function of x. (see Notes)


You will be given n, p, q, x and y. Return the n-th element of A (index is 0-based).

DEFINITION
Class:InfiniteSequence2
Method:calc
Parameters:long long, int, int, int, int
Returns:long long
Method signature:long long calc(long long n, int p, int q, int x, int y)


NOTES
-[x] denotes the floor function of x which returns the highest integer less than or equal to x. For example, [3.4] = 3, [0.6] = 0.


CONSTRAINTS
-n will be between 0 and 10^13, inclusive.
-p and q will both be between 2 and 10^9, inclusive.
-x and y will both be between 0 and 10^9, inclusive.


EXAMPLES

0)
10000000
2
3
10000000
10000000

Returns: 2

A[10000000] = A[-5000000] + A[-6666667] = 2.

1)
12
2
3
1
0

Returns: 8



2)
0
2
2
0
0

Returns: 1

A[0] = 1.

3)
123
45
67
8
9

Returns: 2



*/

// END CUT HERE
