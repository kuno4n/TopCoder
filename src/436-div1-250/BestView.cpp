
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

//double EPS = 1e-9;

VI cal(VI h){
	VI res(SZ(h), 0);
	for(int i = 0; i < SZ(h)-1; i++){
		LL x = 0, y = -1;
		for(int j = i+1; j < SZ(h); j++){
			LL x2 = j-i, y2 = h[j]-h[i];
			if(x2*y < x*y2){
				res[i]++;
				x = x2;
				y = y2;
			}
		}
	}
	return res;
}

class BestView {
public:
   int numberOfBuildings( vector <int> h ) {
//	int res = 0;
//	int n = SZ(h);
//	REP(i, n){
//		int tmp = 0;
//		int tmp1 = 0;
//		int tmp2 = 0;
//		for(int j = i-1; j >= 0; j--){
//			bool can = true;
//			double a = (double)(h[j] - h[i])/(i-j);
//			double aa = h[i];
//			for(int k = i-1; k > j; k--){
//				aa += a;
//				if(aa <= h[k]+EPS) can = false;
//			}
//			if(can) tmp1++;
//		}
//		tmp += tmp1;
//		for(int j = i+1; j < n; j++){
//			bool can = true;
//			double a = (double)(h[j] - h[i])/(j-i);
//			double aa = h[i];
//			for(int k = i+1; k < j; k++){
//				aa += a;
//				if
//				(aa <= h[k]+EPS) can = false;
//			}
//			if(can) tmp2++;
//		}
//		tmp += tmp2;
//		res = max(res, tmp);
//	}
//	return res;
	
	VI a = cal(h);
	reverse(ALL(h));
	VI b = cal(h);
	reverse(ALL(b));
	int res = 0;
	REP(i, SZ(h)) res = max(res, a[i] + b[i]);
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
			int heights[]             = {10};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int heights[]             = {5,5,5,5};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int heights[]             = {1,2,7,3,2};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int heights[]             = {1,5,3,2,6,3,2,6,4,2,5,7,3,1,5};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int heights[]             = {1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int heights[]             = {244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int heights[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BestView().numberOfBuildings(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
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
// There are several skyscrapers arranged in a row.  You're interested in finding the one from which the maximal number of other skyscrapers can be seen.  The i-th skyscraper can be represented as a line segment on a plane with endpoints (i, 0) and (i, heights[i]).  A skyscraper can be seen from the roof of another skyscraper if a line segment connecting their roofs does not intersect with or touch any other skyscraper.  Return the maximal number of other skyscrapers that can be seen from the roof of some skyscraper.

DEFINITION
Class:BestView
Method:numberOfBuildings
Parameters:vector <int>
Returns:int
Method signature:int numberOfBuildings(vector <int> heights)


CONSTRAINTS
-heights will contain between 1 and 50 elements, inclusive. 
-Each element of heights will be between 1 and 1,000,000,000, inclusive.


EXAMPLES

0)
{10}

Returns: 0

There's only a single skyscraper, so you can see no other skyscrapers from its roof.


1)
{5,5,5,5}

Returns: 2

From each skyscraper, you can only see its adjacent neighbors.

2)
{1,2,7,3,2}

Returns: 4

You can see all the other skyscrapers from the central one.

3)
{1,5,3,2,6,3,2,6,4,2,5,7,3,1,5}

Returns: 7

You can see seven skyscrapers from the skyscraper with height 7:


4)
{1000000000,999999999,999999998,999999997,999999996,1,2,3,4,5}

Returns: 6

You can see 6 skyscrapers from the skyscraper with height 999999996 - the nearest one to the left and all 5 skyscrapers to the right.

5)
{244645169,956664793,752259473,577152868,605440232,569378507,111664772,653430457,454612157,397154317}

Returns: 7



*/

// END CUT HERE
