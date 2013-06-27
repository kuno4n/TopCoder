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

string calc(string s, bool l){
    int n = SZ(s);
    if(n == 1) return s;
    if(l){
        char mn = '9'+1;
        REP(i, n) chmin(mn, s[i]);
        if(mn == s[n-1]) return s[n-1] + calc(s.substr(0, n-1), true);
        else return calc(s.substr(0, n-1), true) + s[n-1];
    }
    else{
        if(s[n-1] == '0') return calc(s.substr(0, n-1), false) + s[n-1];
        else{
            char mn = '9'+1;
            REP(i, n-1) if(s[i] != '0') chmin(mn, s[i]);
            if(mn >= s[n-1]) return s[n-1] + calc(s.substr(0, n-1), true);
            else return calc(s.substr(0, n-1), false) + s[n-1];
        }
    }
}

class LeftRightDigitsGame {
	public:
	string minNumber(string digits) {
		return calc(digits, false);
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
			string digits             = "565";
			string expected__         = "556";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame().minNumber(digits);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string digits             = "9876543210";
			string expected__         = "1234567890";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame().minNumber(digits);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string digits             = "8016352";
			string expected__         = "1086352";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame().minNumber(digits);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

case 3: {
			string digits             = "000010";
			string expected__         = "100000";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame().minNumber(digits);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 4: {
			string digits             = "0000110";
			string expected__         = "1000010";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame().minNumber(digits);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
     case 5: {
			string digits             = "000120";
			string expected__         = "100020";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame().minNumber(digits);
			return verify_case(casenum__, expected__, received__, clock()-start__);
     }
		
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
// You are playing a solitaire game called Left-Right Digits Game. This game uses a deck of N cards. Each card has a single digit written on it. These digits are given as characters in the string digits. More precisely, the i-th character of digits is the digit written on the i-th card from the top of the deck (both indices are 0-based).

The game is played as follows. First, you place the topmost card (whose digit is the 0-th character of digits) on the table. Then, you pick the cards one-by-one from the top of the deck. For each card, you have to place it either to the left or to the right of all cards that are already on the table.

After all of the cards have been placed on the table, they now form an N-digit number. This number must not have leading zeros; i.e., the leftmost card on the table must not be a '0'. The goal of the game is to make this N-digit number as small as possible.

Return the smallest possible resulting number you can achieve in this game as a string.

DEFINITION
Class:LeftRightDigitsGame
Method:minNumber
Parameters:string
Returns:string
Method signature:string minNumber(string digits)


CONSTRAINTS
-digits will contain between 1 and 50 characters, inclusive.
-Each character of digits will be between '0' and '9', inclusive.
-digits will contain at least one character that is not '0'.


EXAMPLES

0)
"565"

Returns: "556"

The solution is as follows.

Place the first card on the table.
Place the second card to the right of all cards on the table.
Place the last card to the left of all cards on the table.


1)
"9876543210"

Returns: "1234567890"

The resulting number cannot have leading zeros.

2)
"8016352"

Returns: "1086352"



*/

// END CUT HERE
