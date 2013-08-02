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


bool dp[4000010];
int INF = (1<<29);

class JumpFurther {
	public:
	int furthest(int N, int badStep) {
		MSET(dp, false);
        dp[0] = true;
        int mx = 0;
        for(int i = 1; i <= N; i++) for(int j = mx, cnt = 0; j >= 0 && cnt < 30000; j--, cnt++){
            if(dp[j] && j+i != badStep){
                dp[j+i] = true;
                chmax(mx, j+i);
            }
        }
        
        return mx;
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
			int N                     = 2;
			int badStep               = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 2;
			int badStep               = 1;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 3;
			int badStep               = 3;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 1313;
			int badStep               = 5858;
			int expected__            = 862641;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 1;
			int badStep               = 757065;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int N                     = 4;
			int badStep               = 6;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int N                     = ;
			int badStep               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int badStep               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = JumpFurther().furthest(N, badStep);
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
Little Fox Jiro is standing at the bottom of a long flight of stairs.
The bottom of the stairs has number 0, the bottommost step has number 1, the next step has number 2, and so on.
The staircase is so long that Jiro is guaranteed not to reach its top.


Jiro will now perform N consecutive actions.
The actions are numbered 1 through N, in order.
When performing action X, Jiro chooses between two options: either he does nothing, or he jumps exactly X steps up the stairs.
In other words, if Jiro starts performing action X standing on step Y, he will end it either on step Y, or on step Y+X.


For example, if N=3, Jiro will make three consecutive choices: whether or not to jump 1 step upwards, 2 steps upwards, and then 3 steps upwards.


One of the steps is broken.
The number of this step is badStep.
Jiro cannot jump onto this step.


You are given the ints N and badStep.
Compute and return the number of the topmost step that can be reached by Jiro.




DEFINITION
Class:JumpFurther
Method:furthest
Parameters:int, int
Returns:int
Method signature:int furthest(int N, int badStep)


CONSTRAINTS
-N will be between 1 and 2,000, inclusive.
-badStep will be between 1 and 4,000,000, inclusive.


EXAMPLES

0)
2
2

Returns: 3

The optimal strategy is to jump upwards twice: from step 0 to step 1, and then from step 1 to step 3. This trajectory avoids the broken step.

1)
2
1

Returns: 2

In this case step 1 is broken, so Jiro cannot jump upwards as his first action. The optimal strategy is to first stay on step 0, and then to jump from step 0 to step 2.

2)
3
3

Returns: 5



3)
1313
5858

Returns: 862641



4)
1
757065

Returns: 1



*/

// END CUT HERE
