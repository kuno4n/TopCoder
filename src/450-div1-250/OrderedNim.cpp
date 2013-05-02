
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

class OrderedNim {
public:
   string winner( vector <int> layout ) {
	   bool A[52];
	   int n = SZ(layout);
	   A[n-1] = true;
	   for(int i = n-2; i >= 0; i--){
		   if(layout[i] == 1) A[i] = !A[i+1];
		   else A[i] = true;
	   }
	   if(A[0]) return "Alice";
	   else return "Bob";
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
			int layout[]              = {5};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int layout[]              = {1,2};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int layout[]              = {2,1};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int layout[]              = {10,9,8,7,6,5,4,3,2,1};
			string expected__         = "Alice";

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int layout[]              = {1,1,1,1};
			string expected__         = "Bob";

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int layout[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int layout[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int layout[]              = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = OrderedNim().winner(vector <int>(layout, layout + (sizeof layout / sizeof layout[0])));
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
// Nim is a game in which two players take turns removing stones from heaps.  On each turn, a player must choose a single heap and remove one or more stones from that heap.  The player who takes the last stone wins.

Alice and Bob are bored with playing Nim over and over again, so they've decided to create a new variation called Ordered Nim.  Ordered Nim differs from regular Nim in the following way.  The heaps are numbered 0 through n-1 (where n is the number of heaps), and a player can only remove stones from a heap if all the lower-numbered heaps are empty.

You are given a vector <int> layout, where the i-th element (0-indexed) is the number of stones in heap i at the beginning of the game.  Alice will take the first turn.  Determine who will win the game, assuming both players play optimally.  Return "Alice" if Alice will win, or "Bob" if Bob will win (all quotes for clarity).

DEFINITION
Class:OrderedNim
Method:winner
Parameters:vector <int>
Returns:string
Method signature:string winner(vector <int> layout)


CONSTRAINTS
-layout will contain between 1 and 50 elements, inclusive.
-Each element of layout will be between 1 and 1000000000, inclusive.


EXAMPLES

0)
{5}

Returns: "Alice"

Alice takes all 5 stones and wins.

1)
{1,2}

Returns: "Bob"

According to the rules of the game, Alice is not allowed to take stones from heap 1 because heap 0 is not empty.  Her only option is to take the one stone from heap 0.  Heap 0 will then be empty, so Bob can take both stones from heap 1 to win the game.

2)
{2,1}

Returns: "Alice"



3)
{10,9,8,7,6,5,4,3,2,1}

Returns: "Alice"



4)
{1,1,1,1}

Returns: "Bob"

*/

// END CUT HERE
