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

class ColorfulRabbits {
	public:
	int getMinimum(vector <int> replies) {
		bool used[60]; MSET(used, false);
        int res = 0;
        REP(i, SZ(replies)){
            if(used[i]) continue;
            used[i] = true;
            int cnt = replies[i]+1;
            int tmp = replies[i];
            res += cnt;
            FOR(j, i+1, SZ(replies)){
                if(tmp == 0) break;
                if(replies[j]+1 == cnt){
                    used[j] = true;
                    tmp--;
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
			int replies[]             = { 1, 1, 2, 2 } ;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum(vector <int>(replies, replies + (sizeof replies / sizeof replies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int replies[]             = { 0 } ;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum(vector <int>(replies, replies + (sizeof replies / sizeof replies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int replies[]             = { 2, 2, 44, 2, 2, 2, 444, 2, 2 } ;
			int expected__            = 499;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum(vector <int>(replies, replies + (sizeof replies / sizeof replies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 3: {
			int replies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum(vector <int>(replies, replies + (sizeof replies / sizeof replies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 4: {
			int replies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum(vector <int>(replies, replies + (sizeof replies / sizeof replies[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int replies[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ColorfulRabbits().getMinimum(vector <int>(replies, replies + (sizeof replies / sizeof replies[0])));
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
// Cat Pochi visited a town of rabbits and asked some of the rabbits the following question: 
"How many rabbits in this town other than yourself have the same color as you?". 
The rabbits all replied truthfully, and no rabbit was asked the question more than once. 
You are given the rabbits' replies in the vector <int> replies. 
Return the minimum possible number of rabbits in this town. 


DEFINITION
Class:ColorfulRabbits
Method:getMinimum
Parameters:vector <int>
Returns:int
Method signature:int getMinimum(vector <int> replies)


CONSTRAINTS
-replies will contain between 1 and 50 elements, inclusive. 
-Each element of replies will be between 0 and 1,000,000, inclusive. 


EXAMPLES

0)
{ 1, 1, 2, 2 }


Returns: 5

If there are 2 rabbits with a color and 3 rabbits with another color, 
Pochi can get this set of replies. 




1)
{ 0 }


Returns: 1

A poor lonely rabbit. 


2)
{ 2, 2, 44, 2, 2, 2, 444, 2, 2 }


Returns: 499



*/

// END CUT HERE
