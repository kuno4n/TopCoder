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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class TaroFriends {
	public:
	int getNumber(vector <int> c, int X) {
        LL a = 2e15;
		int n = SZ(c);
        sort(ALL(c));
        int res = c[n-1]-c[0];
        for(int i = 1; i < n; i++) chmin(res, max(c[n-1]-X, c[i-1]+X) - min(c[0]+X, c[i]-X));
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
			int coordinates[]         = {-3, 0, 1};
			int X                     = 3;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int coordinates[]         = {4, 7, -7};
			int X                     = 5;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int coordinates[]         = {-100000000, 100000000};
			int X                     = 100000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int coordinates[]         = {3, 7, 4, 6, -10, 7, 10, 9, -5};
			int X                     = 7;
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int coordinates[]         = {-4, 0, 4, 0};
			int X                     = 4;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int coordinates[]         = {7};
			int X                     = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
          int coordinates[]         = {1, 1};
			int X                     = 100000000;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
          int coordinates[]         = {1,2};
			int X                     = 100000000;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			int coordinates[]         = ;
			int X                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TaroFriends().getNumber(vector <int>(coordinates, coordinates + (sizeof coordinates / sizeof coordinates[0])), X);
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
// 
Cat Taro likes to play with his cat friends.
Each of his friends currently sits on some coordinate on a straight line that goes from the left to the right.
When Taro gives a signal, each of his friends must move exactly X units to the left or to the right.




You are given an vector <int> coordinates and the int X.
For each i, the element coordinates[i] represents the coordinate of the i-th cat before the movement.
Return the smallest possible difference between the positions of the leftmost cat and the rightmost cat after the movement.


DEFINITION
Class:TaroFriends
Method:getNumber
Parameters:vector <int>, int
Returns:int
Method signature:int getNumber(vector <int> coordinates, int X)


CONSTRAINTS
-coordinates will contain between 1 and 50 elements, inclusive.
-Each element of coordinates will be between -100,000,000 and 100,000,000, inclusive.
-X will be between 0 and 100,000,000, inclusive.


EXAMPLES

0)
{-3, 0, 1}
3

Returns: 3

The difference 3 is obtained if the cats move from {-3,0,1} to {0,-3,-2}.




1)
{4, 7, -7}
5

Returns: 4

The difference 4 is obtained if the cats move from {4,7,-7} to {-1,2,-2}.




2)
{-100000000, 100000000}
100000000

Returns: 0



3)
{3, 7, 4, 6, -10, 7, 10, 9, -5}
7

Returns: 7



4)
{-4, 0, 4, 0}
4

Returns: 4



5)
{7}
0

Returns: 0



*/

// END CUT HERE
