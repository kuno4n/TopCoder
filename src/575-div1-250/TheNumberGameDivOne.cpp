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

class TheNumberGameDivOne {
	public:
	string find(long long n) {
        string res;
		if(n&1) res = "Brus";
        else if(n&(n-1)) res = "John";
        else{
            int cnt = -1;
            while(n != 0){
                cnt++;
                n >>= 1;
            }
            if(cnt&1) res = "Brus";
            else res = "John";
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
			long long n               = 6;
			string expected__         = "John";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long n               = 2;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long n               = 747;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long n               = 128;
			string expected__         = "Brus";

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
            case 4: {
                long long n               = 1;
                string expected__         = "Brus";
                
                clock_t start__           = clock();
                string received__         = TheNumberGameDivOne().find(n);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 5: {
                long long n               = 4;
                string expected__         = "John";
                
                clock_t start__           = clock();
                string received__         = TheNumberGameDivOne().find(n);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 6: {
                long long n               = 8;
                string expected__         = "Brus";
                
                clock_t start__           = clock();
                string received__         = TheNumberGameDivOne().find(n);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 7: {
                long long n               = 16;
                string expected__         = "John";
                
                clock_t start__           = clock();
                string received__         = TheNumberGameDivOne().find(n);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }

		// custom cases

/*      case 4: {
			long long n               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long n               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find(n);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long n               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = TheNumberGameDivOne().find(n);
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
// John and Brus play a game with a number.
The game starts with a positive integer n.
The two players take alternating turns, John starts.
Each move looks as follows:
Let C be the current value of the integer.
The current player has to choose a positive divisor of the number C, other than 1 and C.
Once he chooses the divisor, he has to subtract it from C.
The result is the new number with which the other player now starts his move.
If a player cannot make a valid move, he loses the game.


For example, if they start with n=15, one possible gameplay can look as follows:

John takes the number 15, chooses its divisor 3, and decreases the number to 15-3 = 12.
Brus takes the number 12, chooses its divisor 4, and decreases the number to 12-4 = 8.
John takes the number 8, chooses its divisor 2, and decreases the number to 8-2 = 6.
Brus takes the number 6, chooses its divisor 3, and decreases the number to 6-3 = 3.
John takes the number 3, and as there are no divisors other than 1 and 3, he has no valid move and thus he loses the game.



You are given the long long n.
Assume that both players use the optimal strategy while playing the game.
Return "John" (quotes for clarity) if John wins the game and "Brus" otherwise.


DEFINITION
Class:TheNumberGameDivOne
Method:find
Parameters:long long
Returns:string
Method signature:string find(long long n)


CONSTRAINTS
-n will be between 1 and 10^18, inclusive.


EXAMPLES

0)
6

Returns: "John"

John has two possible moves: either decrease 6 by 2 or decrease 6 by 3.
If he chooses the second option, Brus will have no possible moves, hence John will win the game.

1)
2

Returns: "Brus"



2)
747

Returns: "Brus"



3)
128

Returns: "Brus"



*/

// END CUT HERE
