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
#define PB push_back

#define INF (1<<30)-1

class BallsSeparating {
	public:
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
        int n = SZ(red);
		if(n < 3) return -1;
        VI r, g, b;
        int res = INF;

        REP(i, n){
            REP(j, n){
                REP(k, n){
                    if(i==j || j==k || k==i) continue;
                    int tmp = 0;
                    REP(c, n){
                        if(c == i) tmp += green[c] + blue[c];
                        else if(c == j) tmp += red[c] + blue[c];
                        else if(c == k) tmp += green[c] + red[c];
                        else tmp += red[c] + green[c] + blue[c] - max(red[c], max(green[c], blue[c]));
                    }

                    res = min(res, tmp);
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
			int red[]                 = {1, 1, 1};
			int green[]               = {1, 1, 1};
			int blue[]                = {1, 1, 1};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int red[]                 = {5};
			int green[]               = {6};
			int blue[]                = {8};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int red[]                 = {4, 6, 5, 7};
			int green[]               = {7, 4, 6, 3};
			int blue[]                = {6, 5, 3, 8};
			int expected__            = 37;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int red[]                 = {7, 12, 9, 9, 7};
			int green[]               = {7, 10, 8, 8, 9};
			int blue[]                = {8, 9, 5, 6, 13};
			int expected__            = 77;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int red[]                 = {842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799};
			int green[]               = {268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141};
			int blue[]                = {662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103};
			int expected__            = 7230607;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
          int red[]                 = {2, 5, 5};
          int green[]               = {1, 4, 4};
          int blue[]                = {1, 4, 4};
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int red[]                 = ;
			int green[]               = ;
			int blue[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = BallsSeparating().minOperations(vector <int>(red, red + (sizeof red / sizeof red[0])), vector <int>(green, green + (sizeof green / sizeof green[0])), vector <int>(blue, blue + (sizeof blue / sizeof blue[0])));
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
// There are N boxes numbered from 0 to N-1, inclusive. For each i, box i contains red[i] red balls, green[i] green balls, and blue[i] blue balls.


Fox Ciel wants to separate the balls by colors. In each operation, she can pick a single ball from some box and put it into another box. She considers the balls to be separated if no box contains balls of more than one color.


Return the minimal number of operations required to separate the balls. If this is impossible, return -1.


DEFINITION
Class:BallsSeparating
Method:minOperations
Parameters:vector <int>, vector <int>, vector <int>
Returns:int
Method signature:int minOperations(vector <int> red, vector <int> green, vector <int> blue)


CONSTRAINTS
-red, green and blue will each contain between 1 and 50 elements, inclusive.
-red, green and blue will contain the same number of elements.
-Each element of red, green and blue will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{1, 1, 1}
{1, 1, 1}
{1, 1, 1}

Returns: 6

One way to separate the balls in six operations is as follows:

Move a red ball from box 1 to box 0.
Move a red ball from box 2 to box 0.
Move a green ball from box 0 to box 1.
Move a green ball from box 2 to box 1.
Move a blue ball from box 0 to box 2.
Move a blue ball from box 1 to box 2.

The pictures on the left and on the right show the initial and the final states of the balls, respectively.



?


1)
{5}
{6}
{8}

Returns: -1

It is impossible to separate the balls.

2)
{4, 6, 5, 7}
{7, 4, 6, 3}
{6, 5, 3, 8}

Returns: 37



3)
{7, 12, 9, 9, 7}
{7, 10, 8, 8, 9}
{8, 9, 5, 6, 13}

Returns: 77



4)
{842398, 491273, 958925, 849859, 771363, 67803, 184892, 391907, 256150, 75799}
{268944, 342402, 894352, 228640, 903885, 908656, 414271, 292588, 852057, 889141}
{662939, 340220, 600081, 390298, 376707, 372199, 435097, 40266, 145590, 505103}

Returns: 7230607



*/

// END CUT HERE
