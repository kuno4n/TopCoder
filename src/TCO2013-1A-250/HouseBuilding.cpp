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

class HouseBuilding {
	public:
	int getMinimum(vector <string> area) {
		int res = 100000;
        REP(i, 10){
            for(int j = -1; j <= 1; j++){
                int ii = i + j;
                int tmp = 0;
                REP(x, SZ(area)){
                    REP(y, SZ(area[0])){
                        int mintmp = abs(i - area[x][y] + '0');
                        mintmp = min(mintmp, abs(ii - area[x][y] + '0'));
                        tmp += mintmp;
                    }
                }
                res = min(res, tmp);
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
			string area[]             = {"10",
 "31"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string area[]             = {"54454",
 "61551"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string area[]             = {"989"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string area[]             = {"90"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string area[]             = {"5781252",
 "2471255",
 "0000291",
 "1212489"};
			int expected__            = 53;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string area[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = HouseBuilding().getMinimum(vector <string>(area, area + (sizeof area / sizeof area[0])));
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
// Manao is building a new house. He already purchased a rectangular area where he will place the house. The basement of the house should be built on a level ground, so Manao will have to level the entire area. The area is leveled if the difference between the heights of its lowest and highest square meter is at most 1. Manao wants to measure the effort he needs to put into ground leveling.

You are given a vector <string> area. Each character in area denotes the height at the corresponding square meter of Manao's area. Using 1 unit of effort, Manao can change the height of any square meter on his area by 1 up or down. Return the minimum total effort he needs to put to obtain a leveled area.


DEFINITION
Class:HouseBuilding
Method:getMinimum
Parameters:vector <string>
Returns:int
Method signature:int getMinimum(vector <string> area)


CONSTRAINTS
-area will contain between 1 and 50 elements, inclusive.
-Each element of area will be between 1 and 50 characters long, inclusive.
-All elements of area will be of the same length.
-Each element of area will contain digits ('0'-'9') only.


EXAMPLES

0)
{"10",
 "31"}

Returns: 2

The given area is not leveled, because the minimum height is 0 and the maximum height is 3. Manao needs to reduce the height of lower left square by 2.

1)
{"54454",
 "61551"}

Returns: 7

In the optimal solution each square will have height either 4 or 5. To reach such a configuration, Manao should reduce the height of one square from 6 to 5, and increase the heights of two other squares from 1 to 4.

2)
{"989"}

Returns: 0

The area is already leveled.

3)
{"90"}

Returns: 8



4)
{"5781252",
 "2471255",
 "0000291",
 "1212489"}

Returns: 53



*/

// END CUT HERE
