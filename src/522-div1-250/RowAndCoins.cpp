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

class RowAndCoins {
	public:
	string getWinner(string cells) {
		if(cells[0]=='B' && cells[SZ(cells)-1]=='B') return "Bob";
        return "Alice";
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
			string cells              = "ABBB";
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cells              = "BBBB";
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cells              = "BA";
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cells              = "BABBABBB";
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string cells              = "ABABBBABAABBAA";
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string cells              = "BBBAAABBAAABBB";
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string cells              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string cells              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string cells              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = RowAndCoins().getWinner(cells);
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
// Alice and Bob play the following game. 
The game board consists of some cells in a row. 
Each cell is marked either 'A' or 'B'. 
At the beginning, there are no coins placed on the board ? all the cells are empty. 
Alice and Bob take alternating turns. 
Alice plays first. 
In each turn, the current player chooses some contiguous empty cells and places a coin onto each of the chosen cells. 
The player must always choose at least one cell. 
The player must never choose all empty cells. 
In other words, after each turn there must be at least one empty cell. 

The following picture shows two examples of placing coins: 



The game ends when there is only one cell left without a coin. 
If that cell is marked 'A', Alice wins. 
Otherwise, Bob wins. 
You are given a string cells representing the row of cells. 
Assuming that both players aim to win and play optimally, return a string containing the name of the winner. 


DEFINITION
Class:RowAndCoins
Method:getWinner
Parameters:string
Returns:string
Method signature:string getWinner(string cells)


CONSTRAINTS
-cells will contain between 2 and 14 characters, inclusive. 
-Each character in cells will be either 'A' or 'B'. 


EXAMPLES

0)
"ABBB"

Returns: "Alice"

Alice can win by placing coins on three cells marked 'B' in her first turn. 


1)
"BBBB"

Returns: "Bob"

2)
"BA"

Returns: "Alice"



3)
"BABBABBB"

Returns: "Bob"

4)
"ABABBBABAABBAA"

Returns: "Alice"



5)
"BBBAAABBAAABBB"

Returns: "Bob"



*/

// END CUT HERE
