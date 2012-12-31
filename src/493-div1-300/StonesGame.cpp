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

class StonesGame {
	public:
	string winner(int N, int M, int K, int L) {
		set<int> win; win.clear();
        REP(i, K){
            if(L-(K-1)+i < 1 || L+i > N) continue;
            int p = L-(K-1)+i*2;
            win.insert(p);
        }
        if(win.find(M) != win.end()) return "Romeo";
        
        bool check = true;
        REP(i, K){
            if(M-(K-1)+i < 1 || M+i > N) continue;
            int p = M-(K-1)+i*2;
            if(1<=p && p<=N && win.find(p) == win.end()) check = false;
        }
        if(check) return "Strangelet";
        
        return "Draw";
        
        
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
			int N                     = 3;
			int M                     = 1;
			int K                     = 1;
			int L                     = 2;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 5;
			int M                     = 1;
			int K                     = 2;
			int L                     = 2;
			string expected__         = "Romeo";

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 5;
			int M                     = 5;
			int K                     = 2;
			int L                     = 3;
			string expected__         = "Strangelet";

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 5;
			int M                     = 5;
			int K                     = 2;
			int L                     = 2;
			string expected__         = "Draw";

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 1000000;
			int M                     = 804588;
			int K                     = 705444;
			int L                     = 292263;
			string expected__         = "Romeo";

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int N                     = 1000000;
			int M                     = 100000;
			int K                     = 500000;
			int L                     = 600000;
			string expected__         = "Strangelet";

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int N                     = ;
			int M                     = ;
			int K                     = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StonesGame().winner(N, M, K, L);
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
// Romeo and his friend Strangelet are playing a game. There are N stones in a row, all of which are black except for the M-th one, which is white (all positions in this problem are 1-based). The players alternate turns, and Romeo plays first. On each turn, a player must choose exactly K consecutive stones, one of which must be white, and reverse their order. The winner is the first player who puts the white stone in the L-th position.

Return "Romeo" if Romeo can win regardless of how Strangelet plays, and return "Strangelet" if Strangelet can win regardless of Romeo's strategy.  Otherwise, return "Draw" since neither player can win if both players play optimally.  All quotes are for clarity only.

DEFINITION
Class:StonesGame
Method:winner
Parameters:int, int, int, int
Returns:string
Method signature:string winner(int N, int M, int K, int L)


CONSTRAINTS
-N will be between 2 and 1,000,000,  inclusive.
-M, K and L will each be between 1 and N, inclusive.
-M and L will be different.


EXAMPLES

0)
3
1
1
2

Returns: "Draw"

There are three stones and the stone in position 1 is white.  To win the game, a player must put the white stone in position 2.  However, since K is 1, each player can only choose a single stone to reverse, so it is impossible to move the white stone from its original position.  Therefore, neither player can win.

1)
5
1
2
2

Returns: "Romeo"

Romeo can win on his first move by reversing the order of the first two stones.

2)
5
5
2
3

Returns: "Strangelet"

Romeo's only possible move is to reverse the last two stones.  This puts the white stone in position 4.  Strangelet can then reverse the third and fourth stones, putting the white stone in position 3 and winning the game.

3)
5
5
2
2

Returns: "Draw"

This is similar to the previous example, but here, the white stone must be moved to position 2.  As in the previous example, Romeo's first move will put the white stone in position 4.  This time, Strangelet will then move it back to position 5 because otherwise, Romeo would move it to position 2 and win.  This sequence of moves will repeat infinitely and neither player will win.

4)
1000000
804588
705444
292263

Returns: "Romeo"

5)
1000000
100000
500000
600000

Returns: "Strangelet"



*/

// END CUT HERE
