
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


string int2str(LL a){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    return res;
}

class TheNumberGame {
	public:
	string determineOutcome(int A, int B) {
        string a = int2str(A);
        string b = int2str(B);
        if(a.find(b) != a.npos) return "Manao wins";
        reverse(ALL(b));
        if(a.find(b) != a.npos) return "Manao wins";
        
        return "Manao loses";
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
			int A                     = 45;
			int B                     = 4;
			string expected__         = "Manao wins";

			clock_t start__           = clock();
			string received__         = TheNumberGame().determineOutcome(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 45;
			int B                     = 5;
			string expected__         = "Manao wins";

			clock_t start__           = clock();
			string received__         = TheNumberGame().determineOutcome(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 99;
			int B                     = 123;
			string expected__         = "Manao loses";

			clock_t start__           = clock();
			string received__         = TheNumberGame().determineOutcome(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 2356236;
			int B                     = 5666;
			string expected__         = "Manao loses";

			clock_t start__           = clock();
			string received__         = TheNumberGame().determineOutcome(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
            case 4: {
                int A                     = 1234567;
                int B                     = 6543;
                string expected__         = "Manao wins";
                
                clock_t start__           = clock();
                string received__         = TheNumberGame().determineOutcome(A, B);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }

		// custom cases

/*      case 4: {
			int A                     = ;
			int B                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGame().determineOutcome(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int A                     = ;
			int B                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGame().determineOutcome(A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGame().determineOutcome(A, B);
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
// Manao has recently invented a brand new game called The Number Game. He usually plays this game against his friend.

Initially, Manao has an integer A and his friend has an integer B. Note that neither A nor B contain a zero digit in their base 10 representation. The players make moves alternatively with Manao starting first. In each move, the player can either reverse his current number, or he can divide it by 10 (using integer division).
For example, if the current number is 12849, the player can either reverse it to obtain 94821, or he can divide it by 10 to obtain 1284.
Note that we always round down when using integer division.
Also note that each player is only allowed to change his own number, and not the number of the other player.

If after some move the players' numbers become equal, Manao is declared the winner. If after 1000 moves (that is, 500 moves by Manao and 500 by his friend) Manao has not won, he loses. Given A and B, determine whether Manao would win if both players play optimally. Return "Manao wins" or "Manao loses" accordingly.

DEFINITION
Class:TheNumberGame
Method:determineOutcome
Parameters:int, int
Returns:string
Method signature:string determineOutcome(int A, int B)


CONSTRAINTS
-A will be between 1 and 999,999,999, inclusive.
-B will be between 1 and 999,999,999, inclusive.
-A and B will not contain a zero digit in base 10 representation.
-A and B will be distinct.


EXAMPLES

0)
45
4

Returns: "Manao wins"

Manao can win in one move by dividing his number by 10.

1)
45
5

Returns: "Manao wins"

There are several possible scenarios this game can follow:

Manao divides by 10 and obtains 4. Now his opponent can reverse his number and obtain 5 again. Obviously, no matter what Manao does in his next 499 moves, his opponent can evade him.
Manao reverses his number and obtains 54. His opponent reverses his 5. Manao divides 54 by 10 and obtains 5, thus making the numbers equal
Manao reverses his number and obtains 54. His opponent divides by 10 and obtains zero. Manao will win in three moves, dividing his number by 10 twice.

Obviously, Manao will not choose to divide by 10 in his first move and will win.

2)
99
123

Returns: "Manao loses"

No matter how Manao plays, the opponent can perform reverse moves until the end of the game.

3)
2356236
5666

Returns: "Manao loses"



*/

// END CUT HERE
