
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

int MOD = 1000000007;
LL dp[1000005];


long long modPow(long long x, long long y){
    long long r=1, a=x%MOD;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

class TrafficCongestion {
public:
   int theMinCars( int t ) {
	MSET(dp, 0);
	dp[0] = dp[1] = 1;
	for(int i = 2; i <= t; i++) dp[i] = (dp[i-2] + modPow(2, i-1)) % MOD;
	return dp[t];
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
			int treeHeight            = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int treeHeight            = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int treeHeight            = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int treeHeight            = 585858;
			int expected__            = 548973404;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int treeHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int treeHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int treeHeight            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TrafficCongestion().theMinCars(treeHeight);
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
// There are some cities and some roads connecting them together.
The road network has the topology of a perfect binary tree (see below for a picture), in which the cities are nodes and the roads are edges.

You are given the int treeHeight giving the height of the tree.
(The height of a perfect binary tree is the number of edges on the path between the root node and any leaf node.)
Thus, there are 2^(treeHeight+1)-1 cities and 2^(treeHeight+1)-2 roads in total.

The picture below shows how the road network looks like when treeHeight = 2.



We want to send some cars into the road network.
Each car will be traveling from its starting city to its destination city without visiting the same city twice.
(Note that the route of each car is uniquely determined by its starting and its destination city.)
It is possible for the starting city to be equal to the destination city, in that case the car only visits that single city.

Our goal is to send out the cars in such a way that each city will be visited by exactly one car.
Let X be the smallest number of cars we need in order to do so.
Compute and return the value X modulo 1,000,000,007.

DEFINITION
Class:TrafficCongestion
Method:theMinCars
Parameters:int
Returns:int
Method signature:int theMinCars(int treeHeight)


CONSTRAINTS
-treeHeight will be between 0 and 1,000,000, inclusive.


EXAMPLES

0)
1

Returns: 1

In this case, one car can visit all the cities.



1)
2

Returns: 3

Here is one way to visit all cities exactly once by three cars:




2)
3

Returns: 5



3)
585858

Returns: 548973404



*/

// END CUT HERE
