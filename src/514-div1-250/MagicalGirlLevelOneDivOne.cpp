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

class MagicalGirlLevelOneDivOne {
	public:
	string isReachable(vector <int> jumpTypes, int x, int y) {
        OUT((-7)%4);
		REP(i, SZ(jumpTypes)){
            int a = jumpTypes[i]%2;
            if(!a) return "YES";
            if( a && !((x^y)&1)) return "YES";
        }
        
        return "NO";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int jumpTypes[]           = {2};
			int x                     = 5;
			int y                     = 4;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = MagicalGirlLevelOneDivOne().isReachable(vector <int>(jumpTypes, jumpTypes + (sizeof jumpTypes / sizeof jumpTypes[0])), x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int jumpTypes[]           = {3};
			int x                     = 5;
			int y                     = 4;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = MagicalGirlLevelOneDivOne().isReachable(vector <int>(jumpTypes, jumpTypes + (sizeof jumpTypes / sizeof jumpTypes[0])), x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int jumpTypes[]           = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
			int x                     = 1000000000;
			int y                     = -999999999;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = MagicalGirlLevelOneDivOne().isReachable(vector <int>(jumpTypes, jumpTypes + (sizeof jumpTypes / sizeof jumpTypes[0])), x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int jumpTypes[]           = {999999999};
			int x                     = 999999999;
			int y                     = 0;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = MagicalGirlLevelOneDivOne().isReachable(vector <int>(jumpTypes, jumpTypes + (sizeof jumpTypes / sizeof jumpTypes[0])), x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int jumpTypes[]           = ;
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MagicalGirlLevelOneDivOne().isReachable(vector <int>(jumpTypes, jumpTypes + (sizeof jumpTypes / sizeof jumpTypes[0])), x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int jumpTypes[]           = ;
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MagicalGirlLevelOneDivOne().isReachable(vector <int>(jumpTypes, jumpTypes + (sizeof jumpTypes / sizeof jumpTypes[0])), x, y);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int jumpTypes[]           = ;
			int x                     = ;
			int y                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MagicalGirlLevelOneDivOne().isReachable(vector <int>(jumpTypes, jumpTypes + (sizeof jumpTypes / sizeof jumpTypes[0])), x, y);
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
// Magical Girls are girls who have magical powers. They fight against evil witches to protect the Earth.

You, one of the Magical Girls, are at point (0, 0) of the plane. You find another Magical Girl at (x, y) and she seems to be injured. So you decide to go to point (x, y) to help her.

You can move only by n-knight jump. For a positive integer n, the n-knight jump is 8 types of moves. You can go from (0, 0) to (n, 1), (n, -1), (-n, 1), (-n, -1), (1, n), (-1, n), (1, -n) or (-1, -n) by using n-knight jump once.

You are given a vector <int> jumpTypes containing the valid n-knight jumps you can perform. You can only use an n-knight jump if jumpTypes contains n. Return "YES" if you can reach (x, y) with the n-knight jumps of given numbers. Otherwise return "NO" (all quotes for clarity). You can use each n-knight jump as many times as you want.


DEFINITION
Class:MagicalGirlLevelOneDivOne
Method:isReachable
Parameters:vector <int>, int, int
Returns:string
Method signature:string isReachable(vector <int> jumpTypes, int x, int y)


CONSTRAINTS
-jumpTypes will contain between 1 and 50 elements, inclusive.
-Each element of jumpTypes will be between 1 and 1,000,000,000, inclusive.
-All elements of jumpTypes will be distinct.
-x and y will each be between -1,000,000,000 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2}
5
4

Returns: "YES"

(0,?0)?->?(2,?1)?->?(4,?2)?->?(5,?4)

1)
{3}
5
4

Returns: "NO"



2)
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
1000000000
-999999999

Returns: "YES"



3)
{999999999}
999999999
0

Returns: "NO"



*/

// END CUT HERE
