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

LL dp[1570000];

class YetAnotherTwoTeamsProblem {
	public:
	long long count(vector <int> skill) {
		int n = SZ(skill);
        sort(ALL(skill));
        int sum = accumulate(ALL(skill), 0);
        MSET(dp, 0);
        REP(i, 1570000) if(sum < i*2) dp[i] = 1;
        REP(i, n) REP(j, 1500000) if(sum > j*2) dp[j] += dp[j+skill[i]];
        return dp[0];
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
			int skill[]               = {5, 4, 7, 6};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int skill[]               = {1, 1, 1, 1, 1};
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int skill[]               = {1, 2, 3, 5, 10};
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int skill[]               = {1, 2, 3, 4, 10};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int skill[]               = {999, 999, 999, 1000, 1000, 1001, 999, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 999, 1000, 512, 511, 1001, 1001, 1001, 1001, 1001, 1000};
			long long expected__      = 17672631900LL;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int skill[]               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int skill[]               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int skill[]               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = YetAnotherTwoTeamsProblem().count(vector <int>(skill, skill + (sizeof skill / sizeof skill[0])));
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
// Manao is the coach of a soccer team. There are N boys numbered from 0 to N-1 on the team. Each of them has some level of soccer skill. Manao would like to divide the boys into two teams for today's training. The division should satisfy the following conditions:

Each boy is assigned to a team.
The total skill of first team is strictly greater than the total skill of the second team.
For each player P in the first team: if we were to move P into the second team, the total skill of the first team would become strictly smaller than the total skill of the second team.

The total skill of a team is the sum of skills of the boys on that team.

You are given a vector <int> skill containing N elements. The i-th element in skill is the skill of boy i. Manao is interested in the number of ways to perform such a division into teams. Please compute and return this number.

DEFINITION
Class:YetAnotherTwoTeamsProblem
Method:count
Parameters:vector <int>
Returns:long long
Method signature:long long count(vector <int> skill)


CONSTRAINTS
-skill will contain between 2 and 50 elements, inclusive.
-Each element of skill will be between 1 and 60,000, inclusive.


EXAMPLES

0)
{5, 4, 7, 6}

Returns: 2

The two possible divisions are:

Boys 0 and 2 against boys 1 and 3.
Boys 2 and 3 against boys 0 and 1.


1)
{1, 1, 1, 1, 1}

Returns: 10

Manao can put any three boys on the first team.

2)
{1, 2, 3, 5, 10}

Returns: 5

The possible choices of the first team are:

Boys 0 and 4.
Boys 1 and 4.
Boys 2 and 4.
Boys 3 and 4.
Boys 0, 1, 2 and 3.


3)
{1, 2, 3, 4, 10}

Returns: 0



4)
{999, 999, 999, 1000, 1000, 1001, 999, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
 1000, 1000, 1000, 999, 1000, 512, 511, 1001, 1001, 1001, 1001, 1001, 1000}

Returns: 17672631900



*/

// END CUT HERE
