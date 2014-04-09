#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class AmebaDiv1 {
public:
   int count( vector <int> X ) {
       set<int> s;
       REP(i, SZ(X)){
           if(s.count(X[i]) == 0) s.erase(X[i]*2);
           s.insert(X[i]);
       }
       return SZ(s);
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
			int X[]                   = {3,2,1};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AmebaDiv1().count(vector <int>(X, X + (sizeof X / sizeof X[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int X[]                   = {2,2,2,2,2,2,4,2,2,2};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AmebaDiv1().count(vector <int>(X, X + (sizeof X / sizeof X[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int X[]                   = {1,2,4,8,16,32,64,128,256,1024,2048};
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = AmebaDiv1().count(vector <int>(X, X + (sizeof X / sizeof X[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int X[]                   = {854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = AmebaDiv1().count(vector <int>(X, X + (sizeof X / sizeof X[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int X[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AmebaDiv1().count(vector <int>(X, X + (sizeof X / sizeof X[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int X[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AmebaDiv1().count(vector <int>(X, X + (sizeof X / sizeof X[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int X[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AmebaDiv1().count(vector <int>(X, X + (sizeof X / sizeof X[0])));
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
// Monte-Carlo is an amoeba. Amoebas can feed on gel: whenever an amoeba encounters a piece of gel that is exactly as big as the amoeba, the amoeba will consume the gel and thus double its size.

Initially, the size of Monte-Carlo was some unknown positive integer. During its lifetime, Monte-Carlo encountered several gels and consumed the ones it could.

You are given a vector <int> X. The elements of X are the sizes of gels Monte-Carlo encountered, in chronological order.

Let S be the set of all possible final sizes of Monte-Carlo. Compute and return the number of positive integers that do not belong into S.

DEFINITION
Class:AmebaDiv1
Method:count
Parameters:vector <int>
Returns:int
Method signature:int count(vector <int> X)


NOTES
-It is possible to prove that the answer for any test case is finite and fits into a 32-bit signed integer type.


CONSTRAINTS
-X will contain between 1 and 200 integers, inclusive.
-Each element of X will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{3,2,1}

Returns: 2

Here are a few possibilities how Monte-Carlo's life could have looked like:

Monte-Carlo started with size 1, ignored gel #0, ignored gel #1, consumed gel #2 and thus reached size 2.
Monte-Carlo started with size 3, consumed gel #0 and thus reached size 6, and then ignored the next two gels (as they were too small).
Monte-Carlo started with size 47 and ignored all three gels.

All final sizes except for 1 and 3 are possible.

1)
{2,2,2,2,2,2,4,2,2,2}

Returns: 2

If Monte-Carlo starts with size 2, its life will look as follows: First, it will consume gel #0 and thus grow to 4. Later, after ignoring a few gels, Monte-Carlo will consume gel #6 (the one with size 4) and thus grow to 8.

It can be shown that for this X Monte-Carlo's final size can never be 2 or 4. 

2)
{1,2,4,8,16,32,64,128,256,1024,2048}

Returns: 11



3)
{854,250,934,1000,281,250,281,467,854,562,934,1000,854,500,562}

Returns: 7



*/

// END CUT HERE
