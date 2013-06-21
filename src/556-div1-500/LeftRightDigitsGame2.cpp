
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

string mem[60][60][2][2];
int n;
string D, L;

string rec(int Dlen, int Lstart, bool lOVER, bool rOK){
	if(mem[Dlen][Lstart][lOVER][rOK] != "yet") return mem[Dlen][Lstart][lOVER][rOK];
	if(Dlen == 0){
		if(!lOVER && !rOK) return mem[Dlen][Lstart][lOVER][rOK] = string(1, '9'+1); 
		return mem[Dlen][Lstart][lOVER][rOK] = "";
	}
	
	string ans(Dlen, '9'+1);
	REP(i, Dlen){
		string Dl = D.substr(0, i);
		string Dr = D.substr(i+1, Dlen-i-1);
		string Ll = L.substr(Lstart+1, i);
		string Lr = L.substr(Lstart+1+i, Dlen-i-1);
		
		if(!lOVER && D[i] < L[Lstart]) continue;
		bool lover = (lOVER || D[i] > L[Lstart]);
		bool rok = (Dr > Lr || (Dr==Lr && rOK));
		
		string tmp = rec(i, Lstart+1, lover, rok);
		if(tmp != "" && tmp[0] == '9' + 1) continue;
		
		chmin(ans, D[i] + tmp + Dr);
	}
	
	return mem[Dlen][Lstart][lOVER][rOK] = ans;
}

class LeftRightDigitsGame2 {
public:
   string minNumber( string digits, string lowerBound ) {
	REP(i, 60) REP(j, 60) REP(k, 2) REP(l, 2) mem[i][j][k][l] = "yet";
	n = SZ(digits);
	D = digits, L = lowerBound;
	string res = rec(n, 0, false, true);
	if(res[0] == '9'+1) return "";
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
			string digits             = "565";
			string lowerBound         = "556";
			string expected__         = "556";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string digits             = "565";
			string lowerBound         = "566";
			string expected__         = "655";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string digits             = "565";
			string lowerBound         = "656";
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string digits             = "9876543210";
			string lowerBound         = "5565565565";
			string expected__         = "5678943210";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string digits             = "8016352";
			string lowerBound         = "1000000";
			string expected__         = "1086352";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string digits             = "5";
			string lowerBound         = "5";
			string expected__         = "5";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			string digits             = "222";
			string lowerBound         = "222";
			string expected__         = "222";

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string digits             = ;
			string lowerBound         = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = LeftRightDigitsGame2().minNumber(digits, lowerBound);
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
// You are playing a solitaire game called Left-Right Digits Game. This game uses a deck of N cards. Each card has a single digit written on it. These digits are given as characters in the string digits. More precisely, the i-th character of digits is the digit written on the i-th card from the top of the deck (both indices are 0-based).

The game is played as follows. First, you place the topmost card (whose digit is the 0-th character of digits) on the table. Then, you pick the cards one-by-one from the top of the deck. For each card, you have to place it either to the left or to the right of all cards that are already on the table.

After all of the cards have been placed on the table, they now form an N-digit number. You are given a string lowerBound that represents an N-digit number. The primary goal of the game is to arrange the cards in such a way that the number X shown on the cards will be greater than or equal to lowerBound. If there are multiple ways to satisfy the primary goal, you want to make the number X as small as possible.

Return the smallest possible value of X you can achieve, as a string containing N digits. If it is impossible to achieve a number which is greater than or equal to lowerBound, return an empty string instead.

DEFINITION
Class:LeftRightDigitsGame2
Method:minNumber
Parameters:string, string
Returns:string
Method signature:string minNumber(string digits, string lowerBound)


NOTES
-lowerBound has no leading zeros. This means that any valid number X should also have no leading zeros (since otherwise it will be smaller than lowerBound).


CONSTRAINTS
-digits will contain between 1 and 50 characters, inclusive.
-Each character of digits will be between '0' and '9', inclusive.
-lowerBound will contain the same number of characters as digits.
-Each character of lowerBound will be between '0' and '9', inclusive.
-The first character of lowerBound will not be '0'.


EXAMPLES

0)
"565"
"556"

Returns: "556"

You can achieve exactly 556. The solution is as follows:

Place the first card on the table.
Place the second card to the right of all cards on the table.
Place the last card to the left of all cards on the table.


1)
"565"
"566"

Returns: "655"



2)
"565"
"656"

Returns: ""

The largest number you can achieve is 655, but it is still less than 656.

3)
"9876543210"
"5565565565"

Returns: "5678943210"



4)
"8016352"
"1000000"

Returns: "1086352"



*/

// END CUT HERE
