
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


class TheBrickTowerMediumDivOne {
public:
   vector <int> find( vector <int> h ) {
	VI res; int n =SZ(h);
	bool used[n]; REP(i, n) used[i] = false;
	int mn = 0;
	REP(i, n) if(h[i] < h[mn]) mn = i;
	int now = h[0];
	REP(i, mn) if(h[i] <= now) now = h[i], used[i] = true, res.PB(i);
	res.PB(mn);	used[mn] = true;
	vector<pair<int, int> > a;
	REP(i, n) if(!used[i]) a.PB(make_pair(h[i], i));
	sort(ALL(a));
	REP(i, SZ(a)) res.PB(a[i].second);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			int heights[]             = {4, 7, 5};
			int expected__[]          = {0, 2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivOne().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int heights[]             = {4, 4, 4, 4, 4, 4, 4};
			int expected__[]          = {0, 1, 2, 3, 4, 5, 6 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivOne().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int heights[]             = {2, 3, 3, 2};
			int expected__[]          = {0, 3, 1, 2 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivOne().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int heights[]             = {13, 32, 38, 25, 43, 47, 6};
			int expected__[]          = {0, 6, 3, 1, 2, 4, 5 };

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivOne().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int heights[]             = {5,3,4,7,1,2,6};
			int expected__[]          = {0,1,4,5,2,6,3};

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivOne().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
      case 5: {
			int heights[]             = {50,60,20,70,30,10,40};
			int expected__[]          = {0,2,5,4,6,1,3};

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivOne().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
/*      case 6: {
			int heights[]             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = TheBrickTowerMediumDivOne().find(vector <int>(heights, heights + (sizeof heights / sizeof heights[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
John and Brus just built some towers using toy bricks.
They now have n towers numbered 0 through n-1.
For each i, the height of the i-th tower (0-based index) is given in heights[i].



John and Brus want to arrange their towers into a line.
That is, the bottoms of the towers will all stand on the same line.
John and Brus don't like it when a tower falls down and knocks over another tower while falling.
To avoid this, they have to put their towers sufficiently far apart.
More precisely, the distance between any two neighboring towers must be at least equal to the maximum of their heights.
John and Brus would like to minimize the distance between the first and the last tower in the line.



You are given the vector <int> heights.
Return a vector <int> containing exactly n elements: the order in which the towers should be placed on the line.
For each i, the i-th element of the return value should be the number of the tower that will be placed i-th on the line.
If there is a tie (multiple solutions give the same minimal distance), return the lexicographically smallest order.



DEFINITION
Class:TheBrickTowerMediumDivOne
Method:find
Parameters:vector <int>
Returns:vector <int>
Method signature:vector <int> find(vector <int> heights)


NOTES
-A vector <int> A is lexicographically smaller than a vector <int> B if it contains a smaller element at the first position where these vector <int>s differ.


CONSTRAINTS
-heights will contain between 1 and 47 elements, inclusive.
-Each element of heights will be between 1 and 47 inclusive.


EXAMPLES

0)
{4, 7, 5}

Returns: {0, 2, 1 }

There are six possible orderings, but only four of them have optimal distance 12 between the first and the last towers:

{0, 2, 1}
{1, 0, 2}
{1, 2, 0}
{2, 0, 1}

Among these orderings {0, 2, 1} is the lexicographically smallest one.


1)
{4, 4, 4, 4, 4, 4, 4}

Returns: {0, 1, 2, 3, 4, 5, 6 }

Towers may have equal heights.

2)
{2, 3, 3, 2}

Returns: {0, 3, 1, 2 }

Towers of height 2 have to be neighboring in the optimal ordering.

3)
{13, 32, 38, 25, 43, 47, 6}

Returns: {0, 6, 3, 1, 2, 4, 5 }

*/

// END CUT HERE
