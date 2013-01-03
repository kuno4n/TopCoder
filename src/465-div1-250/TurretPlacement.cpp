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
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
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

#define EPS 1e-9

class TurretPlacement {
	public:
	long long count(vector <int> x, vector <int> y) {
		int n = SZ(x);
        LL res = 0;
        REP(i, n){
            FOR(j, i+1, n){
                LL diff = (int)(sqrt((double)(x[i]-x[j])*(x[i]-x[j]) + (double)(y[i]-y[j])*(y[i]-y[j]) + EPS)*2);
                res += (diff)*(diff-1)/2;
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
			int x[]                   = {0,2};
			int y[]                   = {0,2};
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = TurretPlacement().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {0,1,2};
			int y[]                   = {0,1,0};
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = TurretPlacement().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {1,2,3,0};
			int y[]                   = {-1,-5,-7,100};
			long long expected__      = 65137;

			clock_t start__           = clock();
			long long received__      = TurretPlacement().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {9998,-10000,10000,0};
			int y[]                   = {9998,10000,10000,0};
			long long expected__      = 2799564895LL;

			clock_t start__           = clock();
			long long received__      = TurretPlacement().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TurretPlacement().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TurretPlacement().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TurretPlacement().count(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])));
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet. 

The celebrated general Archibald Waving took charge of the third army in the occidental front. After losing the first two armies, Waving has become obsessed with finding the optimal way to construct the army's two gun towers. The towers have square-shaped bases. It is possible to construct towers of various sizes, and hence the size of the base square may also vary. However, only those bases are allowed whose sides are of integer length. Each tower may be centered only at points picked from a given set of points described by vector <int>s x and y where the i-th point is (x[i], y[i]). Moreover, the areas of the bases of the towers should not overlap (the squares are allowed to touch each other). Note that in order to achieve this, you may select squares whose sides are not parallel to the co-ordinate axes. 

Waving wants to know the number of ways in which he can position and construct the two towers. Two ways are considered different if at least one of the picked center points differs or if at least one of the picked square side sizes differs. Since it is possible to shoot in all directions from a tower, two ways differing only in the orientation of the base squares are not considered different. Help Waving by returning the total number of different ways to place the two towers. 


DEFINITION
Class:TurretPlacement
Method:count
Parameters:vector <int>, vector <int>
Returns:long long
Method signature:long long count(vector <int> x, vector <int> y)


CONSTRAINTS
-x and y will contain between 2 and 50 elements, inclusive.
-y will contain as many elements as x.
-Each element of x and y will be between -10000 and 10000, inclusive.
-Each of the points described by x and y will be unique.


EXAMPLES

0)
{0,2}
{0,2}

Returns: 10

There are 10 different size combinations that can be used for the two towers as detailed in the following image. Note that in some cases it is necessary to orient towers in a way such that their sides are not paralel to the coordinate axis.


1)
{0,1,2}
{0,1,0}

Returns: 8



2)
{1,2,3,0}
{-1,-5,-7,100}

Returns: 65137



3)
{9998,-10000,10000,0}
{9998,10000,10000,0}

Returns: 2799564895



*/

// END CUT HERE
