
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
#include <queue>
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
#define OUT(A) cout << #A << " = "<< A << endl

int n, m;
int res;
VI win;
set < VI > s;

void dfs(int t1, int t2, int w){
	win[t1] += w;
	win[t2] += 2-w;
	if(t1 == n-2 && t2 == n-1){
		VI tmp = win;
		sort(ALL(tmp), greater<int>());
		if(tmp[0] == m && s.count(tmp) == 0){
			s.insert(tmp);
			res++;	
		}
	}
	else{
		REP(i, 3){
			if(t2 == n-1) dfs(t1+1, t1+2, i);
			else dfs(t1, t2+1, i);
		}
	}
	win[t1] -= w;
	win[t2] -= 2-w;
	return;
}

class TheBasketballDivOne {
public:
   int find( int N, int M ) {
	   n = N; m = M;
	   res = 0;
	   win.clear(); 
	   s.clear();
	   REP(i, n) win.PB(0);
	   REP(i, 3) dfs(0, 1, i);
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
			int n                     = 2;
			int m                     = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = TheBasketballDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 3;
			int m                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TheBasketballDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 3;
			int m                     = 3;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheBasketballDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 4;
			int m                     = 6;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = TheBasketballDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int n                     = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBasketballDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int n                     = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBasketballDivOne().find(n, m);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int m                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheBasketballDivOne().find(n, m);
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
John and Brus have an interest in team sports tournaments.
They are currently investigating a basketball tournament.
Basketball is a team sport in which two teams of five players try to score points against one another by placing a ball through a ten foot high hoop.
Basketball is one of the most popular and widely viewed sports in the world.



There are n teams in the tournament. Each pair of teams plays exactly two games against each other. Each game results in one team winning.  There are no draws.
After the tournament is over, the team with the highest total number of wins takes 1st place, the team with the second highest number of wins takes 2nd place, and so on.



A sequence of integers W1, W2, ..., Wn is called a W-sequence if there exists a tournament where the team that took i-th place has exactly Wi total wins (for all i between 1 and n, inclusive).
Given ints n and m, return the number of W-sequences consisting of n integers where W1 = m.


DEFINITION
Class:TheBasketballDivOne
Method:find
Parameters:int, int
Returns:int
Method signature:int find(int n, int m)


CONSTRAINTS
-n will be between 2 and 5, inclusive.
-m will be between 1 and 9, inclusive.


EXAMPLES

0)
2
1

Returns: 1

The only possible W-sequence is (1, 1).

1)
3
1

Returns: 0

There is no valid outcome where the winning team has just one win.

2)
3
3

Returns: 2

The two possible sequences are (3, 2, 1) and (3, 3, 0).

3)
4
6

Returns: 5



*/

// END CUT HERE
