
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

class ShippingCubes {
public:
   int minimalCost( int N ) {
	   int res = 202;
	   REP(i,N+1){
		   REP(j,N+1){
			   REP(k,N+1){
				   if(i*j*k == N) res = min(res, i+j+k);
			   }
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
			int N                     = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ShippingCubes().minimalCost(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 6;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ShippingCubes().minimalCost(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 7;
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = ShippingCubes().minimalCost(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 200;
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = ShippingCubes().minimalCost(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShippingCubes().minimalCost(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShippingCubes().minimalCost(N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShippingCubes().minimalCost(N);
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
// You want to ship N cubes abroad. The size of each cube is 1 x 1 x 1.
You can only ship the cubes by filling them into a single cuboid box.
The cost of shipping a cuboid box with dimensions a x b x c is equal to (a+b+c).



You can't leave any empty space in the box, because the cubes would shift and get damaged during the transfer.


You are given an int N.
Return the minimal cost of shipping N cubes.


DEFINITION
Class:ShippingCubes
Method:minimalCost
Parameters:int
Returns:int
Method signature:int minimalCost(int N)


CONSTRAINTS
-N will be between 1 and 200, inclusive.


EXAMPLES

0)
1

Returns: 3

The only way is to use a box with dimensions 1 x 1 x 1.

1)
6

Returns: 6

This time one optimal solution is to send a box with dimensions 1 x 2 x 3. The cost of sending this box is 1+2+3 = 6. Any other option is at least as expensive as this one. For example, sending a box with dimensions 6 x 1 x 1 has the cost 6+1+1 = 8.

2)
7

Returns: 9



3)
200

Returns: 18



*/

// END CUT HERE
