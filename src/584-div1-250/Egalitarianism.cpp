
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
#include <numeric>
//#include "cout.h"

using namespace std;

#define SZ(x) ((int)x.size())
#define MSET(x,a) memset(x, a, (int)sizeof(x))
#define PB push_back
#define VI vector < int >
#define PII pair < int, int >
#define LL long long
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

int INF = (1<<29);

class Egalitarianism {
public:
   int maxDifference( vector <string> isF, int d ) {
	int n = SZ(isF);
	int g[n][n];
	REP(i, n) REP(j, n) g[i][j] = INF;
//	REP(i, n) g[i][i] = 0;
	REP(i, n) REP(j, n) if(isF[i][j] == 'Y') g[i][j] = g[j][i] = 1;
	
	REP(k, n) REP(i, n) REP(j, n) chmin(g[i][j], g[i][k]+g[k][j]);
	
	int mx = -1;
	REP(i, n) FOR(j, i+1, n) chmax(mx, g[i][j]);
	if(mx == INF) return -1;
	else return mx * d;
	
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
			string isFriend[]         = {"NYN",
 "YNY",
 "NYN"};
			int d                     = 10;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string isFriend[]         = {"NN",
 "NN"};
			int d                     = 1;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string isFriend[]         = {"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"};
			int d                     = 1000;
			int expected__            = 3000;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string isFriend[]         = {"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"};
			int d                     = 584;
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string isFriend[]         = {"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"};
			int d                     = 5;
			int expected__            = 20;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string isFriend[]         = {"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}
;
			int d                     = 747;
			int expected__            = 2988;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string isFriend[]         = {"NY",
 "YN"};
			int d                     = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases
      case 7: {
			string isFriend[]         = {"NYY","YNY","YYN"};
			int d                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string isFriend[]         = ;
			int d                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = Egalitarianism().maxDifference(vector <string>(isFriend, isFriend + (sizeof isFriend / sizeof isFriend[0])), d);
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
// A kingdom has n citizens. Each one has some amount of money, a number of dollars denoted by a non-negative integer.

Citizens are numbered from 0 to n-1. Some citizens have friends. Their friendship network is described by a vector <string> called isFriend, such that if isFriend[i][j] == 'Y', the citizens numbered i and j are friends, and if isFriend[i][j] == 'N', these citizens are not friends.

The king decrees the following:

Each citizen's amount of money must be within d dollars of the amount of money belonging to any of his friends. In other words, a citizen with x dollars must not have any friends with less than x-d dollars or more than x+d dollars.

Given the number of citizens and their friendship network, what is the greatest possible money difference between any two people (not necessarily friends) in this kingdom? If there is a finite answer, return it. Otherwise, return -1.

DEFINITION
Class:Egalitarianism
Method:maxDifference
Parameters:vector <string>, int
Returns:int
Method signature:int maxDifference(vector <string> isFriend, int d)


CONSTRAINTS
-n will be between 2 and 50, inclusive.
-d will be between 0 and 1,000, inclusive.
-isFriend will contain exactly n elements.
-Each element of isFriend will contain exactly n characters, each of which is either 'Y' or 'N'.
-For any i, isFriend[i][i] = 'N'.
-For any i and j, isFriend[i][j] = isFriend[j][i].


EXAMPLES

0)
{"NYN",
 "YNY",
 "NYN"}
10

Returns: 20

The kingdom has three citizens. Citizens 0 and 1 are friends. Also, citizens 1 and 2 are friends. The greatest possible money difference between any two citizens is $20, as in the following configuration: citizen 0 has $100; citizen 1 has $110; citizen 2 has $120.

1)
{"NN",
 "NN"}
1

Returns: -1

Since citizens 0 and 1 are not friends, there are no constraints between them.

2)
{"NNYNNN",
 "NNYNNN",
 "YYNYNN",
 "NNYNYY",
 "NNNYNN",
 "NNNYNN"}
1000

Returns: 3000



3)
{"NNYN",
 "NNNY",
 "YNNN",
 "NYNN"}
584

Returns: -1



4)
{"NYNYYYN",
 "YNNYYYN",
 "NNNNYNN",
 "YYNNYYN",
 "YYYYNNN",
 "YYNYNNY",
 "NNNNNYN"}
5

Returns: 20



5)
{"NYYNNNNYYYYNNNN",
 "YNNNYNNNNNNYYNN",
 "YNNYNYNNNNYNNNN",
 "NNYNNYNNNNNNNNN",
 "NYNNNNYNNYNNNNN",
 "NNYYNNYNNYNNNYN",
 "NNNNYYNNYNNNNNN",
 "YNNNNNNNNNYNNNN",
 "YNNNNNYNNNNNYNN",
 "YNNNYYNNNNNNNNY",
 "YNYNNNNYNNNNNNN",
 "NYNNNNNNNNNNNNY",
 "NYNNNNNNYNNNNYN",
 "NNNNNYNNNNNNYNN",
 "NNNNNNNNNYNYNNN"}

747

Returns: 2988



6)
{"NY",
 "YN"}
0

Returns: 0



*/

// END CUT HERE
