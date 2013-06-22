
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

int n;
int G[55][55];
int INF = (1<<29);

class TravelOnMars {
public:
   int minTimes( vector <int> range, int startCity, int endCity ) {
	n = SZ(range);
	REP(i, 55) REP(j, 55) G[i][j] = INF;
	REP(i, n) G[i][i] = 0;
	REP(i, n) for(int j = 1; j <= range[i]; j++){
		chmin(G[i][(i+j)%n], 1);
		chmin(G[i][(i-j+100*n)%n], 1);
	}
	REP(k, n) REP(i, n) REP(j, n) chmin(G[i][j], G[i][k]+G[k][j]);
	return G[startCity][endCity];
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
			int range[]               = {2,1,1,1,1,1};
			int startCity             = 1;
			int endCity               = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TravelOnMars().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int range[]               = {2,1,1,1,1,1};
			int startCity             = 4;
			int endCity               = 1;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TravelOnMars().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int range[]               = {2,1,1,2,1,2,1,1};
			int startCity             = 2;
			int endCity               = 6;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TravelOnMars().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int range[]               = {3,2,1,1,3,1,2,2,1,1,2,2,2,2,3};
			int startCity             = 6;
			int endCity               = 13;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TravelOnMars().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int range[]               = ;
			int startCity             = ;
			int endCity               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravelOnMars().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int range[]               = ;
			int startCity             = ;
			int endCity               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravelOnMars().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int range[]               = ;
			int startCity             = ;
			int endCity               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TravelOnMars().minTimes(vector <int>(range, range + (sizeof range / sizeof range[0])), startCity, endCity);
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
// Bob recently went to Mars.

There are N cities on Mars. The cities all lie on a circular railroad and they are numbered 0 through N-1 along the railroad. More precisely, there is a railroad segment that connects cities N-1 and 0, and for each i (0 <= i <= N-2) there is a railroad segment that connects cities i and i+1. Trains travel along the railroad in both directions.

You are given a vector <int> range with N elements. For each i: the set of cities that are reachable from city i by a direct train is precisely the set of cities that are within the distance range[i] of city i. (The distance between two cities is the smallest number of railroad segments one needs to travel in order to get from one city to the other. For example, if N=17 and range[2]=3, the cities directly reachable from city 2 are the cities {16,0,1,2,3,4,5}.)

You are also given ints startCity and endCity. Bob starts his tour in the city startCity and wants to end it in the city endCity. Calculate and return the minimum number of succesive direct trains he needs to take.

DEFINITION
Class:TravelOnMars
Method:minTimes
Parameters:vector <int>, int, int
Returns:int
Method signature:int minTimes(vector <int> range, int startCity, int endCity)


CONSTRAINTS
-range will contain N elements, where N is between 2 and 50, inclusive.
-Each element of range will be between 1 and 50, inclusive.
-startCity will be between 0 and N-1, inclusive.
-endCity will be between 0 and N-1, inclusive.
-startCity and endCity will be different.


EXAMPLES

0)
{2,1,1,1,1,1}
1
4

Returns: 2

Bob wants to get from city 1 to city 4.
The optimal solution is to travel from city 1 to city 0, and then (as range[0]=2) from city 0 to city 4.

1)
{2,1,1,1,1,1}
4
1

Returns: 3

This is the same test case as Example 0, only startCity and endCity have been swapped. Note that the answer is now 3 instead of 2.

2)
{2,1,1,2,1,2,1,1}
2
6

Returns: 3

Bob starts in city 2. There are two optimal routes: (2->3->5->6) and (2->1->0->6).

3)
{3,2,1,1,3,1,2,2,1,1,2,2,2,2,3}
6
13

Returns: 4



*/

// END CUT HERE
