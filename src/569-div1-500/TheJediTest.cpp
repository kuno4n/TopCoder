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

class TheJediTest {
	public:
	int minimumSupervisors(vector <int> students, int K) {
		int n =SZ(students);
        
        students.push_back(0);
        int res = 0;
        FOR(i, 1, n+1){
            int tmp = students[i-1]/K;
            res += tmp;
            students[i-1] -= tmp*K;
            if(students[i-1] == 0) continue;
            
            res++;
            int remain = K;
            remain -= students[i-1];
            students[i-1] = 0;
            int tmp2 = min(remain, students[i]);
            remain -= tmp2;
            students[i] -= tmp2;
            
            if(remain > 0 && i<n){
                int tmp3 = min(remain, students[i+1]);
                remain -= tmp3;
                students[i+1] -= tmp3;
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
			int students[]            = {3, 6, 3};
			int K                     = 4;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int students[]            = {1, 1, 1, 1};
			int K                     = 4;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int students[]            = {0, 0, 0, 0};
			int K                     = 12345;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int students[]            = {15, 0, 13, 4, 29, 6, 2};
			int K                     = 7;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int students[]            = {1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68};
			int K                     = 114;
			int expected__            = 102138;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
          int students[]            = {7};
			int K                     = 3;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
          int students[]            = {100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000,100000000};
			int K                     = 1;
			int expected__            = 2000000000;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
          int students[]            = {6};
			int K                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
      }
            case 8: {
                int students[]            = {0, 0};
                int K                     = 1000;
                int expected__            = 0;
                
                clock_t start__           = clock();
                int received__            = TheJediTest().minimumSupervisors(vector <int>(students, students + (sizeof students / sizeof students[0])), K);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
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
// A long time ago in a galaxy far, far away the Jedi Academy conducted a test to detect children with high Force sensitivy which would then be trained to become Jedi. The test was conducted in the Jedi Temple which had several floors. For each i, students[i] children have initially gathered at floor i (0-based). A Jedi could only manage to cope with at most K children located at the same floor. So, if there were between K+1 and 2K children at a floor, two Jedi would be required there; if there were between 2K+1 and 3K children, three Jedi were neccessary and so on.

To minimize the number of Jedi needed to supervise the test, it was decided to relocate some children. However, to avoid the mess, each child was only allowed to be relocated by at most one floor, i.e. he or she could stay on the same floor, go one floor down or go one floor up. Note that it is not possible to go a floor down from the first floor or a floor up from the last floor.

Determine and return the minimum number of Jedi supervisors needed after the relocation.

DEFINITION
Class:TheJediTest
Method:minimumSupervisors
Parameters:vector <int>, int
Returns:int
Method signature:int minimumSupervisors(vector <int> students, int K)


CONSTRAINTS
-students will contain between 1 and 20 elements, inclusive.
-Each element of students will be between 0 and 100,000,000, inclusive.
-K will be between 1 and 100,000,000, inclusive.


EXAMPLES

0)
{3, 6, 3}
4

Returns: 3

If the children stay the way they are, 4 Jedi will be required. A possible solution with only 3 observers needed is to send all the children to floor 1. Another optimal solution is to send one child from floor 1 to floor 0 and the others to floor 2.

1)
{1, 1, 1, 1}
4

Returns: 2

A single observer can watch four children. However, to gather at the same floor, at least one child would have to move more than one floor away from his or her initial location.

2)
{0, 0, 0, 0}
12345

Returns: 0

For the Jedi Academy, a bad day it was.

3)
{15, 0, 13, 4, 29, 6, 2}
7

Returns: 10

An optimal solution is to gather the children from floor 0 and floor 2 at floor 1, move the children from floor 3 and one child from floor 5 to floor 4 and move the children from the last floor 6 down to floor 5. The quantities of students at each floor will be {0, 28, 0, 0, 34, 7, 0}.

4)
{1284912, 1009228, 9289247, 2157, 2518, 52781, 2, 2818, 68}
114

Returns: 102138



*/

// END CUT HERE
