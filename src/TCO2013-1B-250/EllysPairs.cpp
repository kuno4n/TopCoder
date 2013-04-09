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

class EllysPairs {
	public:
	int getDifference(vector <int> k) {
		int mx = 0, mn = 10000;
        sort(ALL(k));
        REP(i, SZ(k)/2){
            int a = k[i] + k[SZ(k)-1-i];
            mx = max(mx, a);
            mn = min(mn, a);
        }
        return mx - mn;
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
			int knowledge[]           = {2, 6, 4, 3};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int knowledge[]           = {1, 1, 1, 1, 1, 1};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int knowledge[]           = {4, 2, 4, 2, 1, 3, 3, 7};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int knowledge[]           = {5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int knowledge[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int knowledge[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int knowledge[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EllysPairs().getDifference(vector <int>(knowledge, knowledge + (sizeof knowledge / sizeof knowledge[0])));
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
// In one of her subjects at the university, Elly and her classmates have to prepare projects. The professor wants the students to work in pairs (groups of two). Each student must belong to exactly one pair and each pair should produce one project. You may assume that the number of people in the class is even.

You are given a vector <int> knowledge. Each element of knowledge is the amount of knowledge of one of the students. The quality of a project is the total knowledge of the students that work on it. That is, if students i and j form one of the pairs, the quality of their project will be knowledge[i] + knowledge[j].

This creates some problems. If there is a really strong group, their project will be of really high quality. The professor will then compare the other projects to it and will be disappointed by them, giving low grades to the other pairs. Thus, the students want to form the groups in such way that the difference between the quality of the best project and the quality of the worst project is as small as possible.

Return that minimal difference in the quality between the best and the worst project if the students split into pairs in the best possible way.

DEFINITION
Class:EllysPairs
Method:getDifference
Parameters:vector <int>
Returns:int
Method signature:int getDifference(vector <int> knowledge)


CONSTRAINTS
-knowledge will contain between 2 and 50 elements, inclusive.
-The number of elements of knowledge will be even.
-Each element of knowledge will be between 1 and 1000, inclusive.


EXAMPLES

0)
{2, 6, 4, 3}

Returns: 1

Here obviously grouping the two best people in the class (with knowledge 6 and 4) doesn't make sense.
If 6 pairs with 3 and 4 pairs with 2 they will get qualities of 9 and 6, respectively, leading to difference 3.
However, there is an even better grouping: 2 with 6 and 4 with 3 for qualities of 8 and 7, respectively. The difference then would be only 1.


1)
{1, 1, 1, 1, 1, 1}

Returns: 0

Some or even all students can have the same knowledge.

2)
{4, 2, 4, 2, 1, 3, 3, 7}

Returns: 2



3)
{5, 1, 8, 8, 13, 7, 6, 2, 1, 9, 5, 11, 3, 4}

Returns: 3



*/

// END CUT HERE
