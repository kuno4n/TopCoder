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

class MinimumSquare {
public:
   long long minArea( vector <int> x, vector <int> y, int K ) {
       int n = SZ(x);
       LL res = (1LL << 62);
       REP(i, n) REP(j, n){
           LL x1 = min(x[i], x[j]);
           LL y1 = min(y[i], y[j]);
           vector<LL> v;
           REP(k, n) if(x[k] >= x1 && y[k] >= y1) v.push_back(max(x[k]-x1+2, y[k]-y1+2) );
           sort(ALL(v));
           if(SZ(v) >= K) chmin(res, v[K-1]*v[K-1]);
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
			int x[]                   = {0, 3};
			int y[]                   = {0, 7};
			int K                     = 2;
			long long expected__      = 81;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-4, 3, 1};
			int y[]                   = {3 , -1, -2};
			int K                     = 2;
			long long expected__      = 16;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {0, 0, 1, 1, 2, 2};
			int y[]                   = {0, 1, 0, 1, 0, 1};
			int K                     = 4;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000};
			int y[]                   = {1000000000, 0, -1000000000, 1000000000, 0, -1000000000};
			int K                     = 3;
			long long expected__      = 4000000008000000004LL;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232};
			int y[]                   = {-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874};
			int K                     = 8;
			long long expected__      = 1695545329;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
          int x[]                   = {0,0,9,-9};
          int y[]                   = {9,-9,0,0};
			int K                     = 4;
			long long expected__      = 400;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MinimumSquare().minArea(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), K);
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
// There are N points in the plane. You are given their description as two vector <int>s, x and y, with N elements each. The N points have coordinates (x[0],y[0]), (x[1],y[1]), ..., (x[N-1],y[N-1]).

You want to draw a single square onto the plane. The vertices of the square must have integer coordinates, and the sides of the square must be parallel to the coordinate axes. There is one additional constraint: at least K of the N given points must lie strictly inside the square (i.e., not on its boundary).

You are given x, y, and the int K. Return the smallest possible area of a square that satisfies the constraints above.

DEFINITION
Class:MinimumSquare
Method:minArea
Parameters:vector <int>, vector <int>, int
Returns:long long
Method signature:long long minArea(vector <int> x, vector <int> y, int K)


CONSTRAINTS
-x will contain between 2 and 100 elements, inclusive.
-y will contain the same number of elements as x.
-K will be between 1 and the number of elements in x, inclusive.
-All points will be pairwise distinct.
-Each element of x will be between -1,000,000,000 and 1,000,000,000, inclusive.
-Each element of y will be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{0, 3}
{0, 7}
2

Returns: 81

The square we seek must contain both given points. One optimal solution is the square with opposite corners at (-1,-1) and (8,8).

1)
{-4, 3, 1}
{3 , -1, -2}
2

Returns: 16



2)
{0, 0, 1, 1, 2, 2}
{0, 1, 0, 1, 0, 1}
4

Returns: 9



3)
{1000000000, 1000000000, 1000000000, -1000000000, -1000000000, -1000000000}
{1000000000, 0, -1000000000, 1000000000, 0, -1000000000}
3

Returns: 4000000008000000004

In this case one of the optimal solutions is a square that contains all six points.

4)
{-47881, 28623, 1769, -38328, -16737, 16653, -23181, 37360, 41429, 26282, 254, 728, 8299, -41080, -29498, 17488, -23937, -11, 33319, 25232}
{-46462, 48985, -43820, -19587, -33593, -28337, 13667, -48131, -5568, -2332, -41918, -31370, -3695, 42599, -37788, -40096, 39049, 25045, -2122, 3874}
8

Returns: 1695545329



*/

// END CUT HERE
