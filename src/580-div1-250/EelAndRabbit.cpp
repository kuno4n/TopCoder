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

class EelAndRabbit {
	public:
	int getmax(vector <int> l, vector <int> t) {
        int res = 0;
		REP(i, SZ(l)) REP(j, SZ(t)){
            int tmp = 0;
            REP(k, SZ(l)) if((t[k]<=t[i] && t[i]<=t[k]+l[k]) || (t[k]<=t[j] && t[j]<=t[k]+l[k])) tmp++;
            res = max(res, tmp);
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
			int l[]                   = {2, 4, 3, 2, 2, 1, 10};
			int t[]                   = {2, 6, 3, 7, 0, 2, 0};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int l[]                   = {1, 1, 1};
			int t[]                   = {2, 0, 4};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int l[]                   = {1};
			int t[]                   = {1};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int l[]                   = {8, 2, 1, 10, 8, 6, 3, 1, 2, 5};
			int t[]                   = {17, 27, 26, 11, 1, 27, 23, 12, 11, 13};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int l[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int l[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int l[]                   = ;
			int t[]                   = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EelAndRabbit().getmax(vector <int>(l, l + (sizeof l / sizeof l[0])), vector <int>(t, t + (sizeof t / sizeof t[0])));
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
// Rabbit went to a river to catch eels.
All eels are currently swimming down the stream at the same speed.
Rabbit is standing by the river, downstream from all the eels.


Each point on the river has a coordinate.
The coordinates increase as we go down the stream.
Initially, Rabbit is standing at the origin, and all eels have non-positive coordinates.


You are given two vector <int>s: l and t.
These describe the current configuration of eels.
The speed of each eel is 1 (one).
For each i, the length of eel number i is l[i].
The head of eel number i will arrive at the coordinate 0 precisely at the time t[i].
Therefore, at any time T the eel number i has its head at the coordinate T-t[i], and its tail at the coordinate T-t[i]-l[i].


Rabbit may only catch an eel when some part of the eel (between head and tail, inclusive) is at the same coordinate as the rabbit.
Rabbit can catch eels at most twice.
Each time he decides to catch eels, he may catch as many of the currently available eels as he wants.
(That is, he can only catch eels that are in front of him at that instant, and he is allowed and able to catch multiple eels at once.)


Return the maximal total number of eels Rabbit can catch.

DEFINITION
Class:EelAndRabbit
Method:getmax
Parameters:vector <int>, vector <int>
Returns:int
Method signature:int getmax(vector <int> l, vector <int> t)


CONSTRAINTS
-l will contain between 1 and 50 elements, inclusive.
-Each element of l will be between 1 and 1,000,000,000, inclusive.
-l and t will contain the same number of elements.
-Each element of t will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{2, 4, 3, 2, 2, 1, 10}
{2, 6, 3, 7, 0, 2, 0}

Returns: 6

Rabbit can catch 6 eels in the following way:

At time 2, catch Eel 0, Eel 4, Eel 5, and Eel 6.
At time 8, catch Eel 1 and Eel 3.



1)
{1, 1, 1}
{2, 0, 4}

Returns: 2

No two eels are in front of Rabbit at the same time, so Rabbit can catch at most two eels.

2)
{1}
{1}

Returns: 1



3)
{8, 2, 1, 10, 8, 6, 3, 1, 2, 5}
{17, 27, 26, 11, 1, 27, 23, 12, 11, 13}

Returns: 7



*/

// END CUT HERE
