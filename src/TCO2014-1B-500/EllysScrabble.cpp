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

class EllysScrabble {
	public:
	string getMin(string letters, int maxDistance) {
		int n = SZ(letters);
        bool used[n]; MSET(used, false);
        string res = "";
        REP(i, n){
            char tmp = 'Z' + 1;
            int ptr = -1;
            for(int j = max(0, i - maxDistance); j <= min(n-1, i + maxDistance); j++){
                if(j == i - maxDistance && !used[j]){
                    tmp = letters[j];
                    ptr = j;
                    break;
                }
                else{
                    if(tmp > letters[j] && !used[j]){
                        tmp = letters[j];
                        ptr = j;
                    }
                }
            }
            used[ptr] = true;
            res += tmp;
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
			string letters            = "TOPCODER";
			int maxDistance           = 3;
			string expected__         = "CODTEPOR";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string letters            = "ESPRIT";
			int maxDistance           = 3;
			string expected__         = "EIPRST";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string letters            = "BAZINGA";
			int maxDistance           = 8;
			string expected__         = "AABGINZ";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string letters            = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int maxDistance           = 9;
			string expected__         = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string letters            = "GOODLUCKANDHAVEFUN";
			int maxDistance           = 7;
			string expected__         = "CADDGAHEOOFLUKNNUV";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string letters            = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int maxDistance           = 6;
			string expected__         = "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string letters            = "ABRACADABRA";
			int maxDistance           = 2;
			string expected__         = "AABARACBDAR";

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string letters            = ;
			int maxDistance           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string letters            = ;
			int maxDistance           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string letters            = ;
			int maxDistance           = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysScrabble().getMin(letters, maxDistance);
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
// Elly is playing Scrabble with her family. The exact rules of the game are not important for this problem. You only need to know that Elly has a holder that contains a row of N tiles, and that there is a single letter on each of those tiles. (Tiles are small square pieces of wood. A holder is a tiny wooden shelf with room for precisely N tiles placed in a row.)

While Elly waits for the other players, she entertains herself in the following way. She slightly taps the table, causing the tiles on her holder jump a little and some of them switch places.
Formally, suppose that Elly has N tiles. There are N positions on the holder, we will label them 0 through N-1 from left to right.
When Elly taps the table, the tiles on her holder will form some permutation of their original order.
You are given an int maxDistance with the following meaning: in the permutation that Elly produces by tapping the table, no tile will be more than maxDistance positions away from its original position (in either direction).

For example, suppose that before a tap the letters in Elly's holder formed the string "TOPCODER" when read from left to right.
If maxDistance is 3, one possible string after Elly taps the table is "CODTEPOR".
This can happen in the following way:

The letter 'T' at position 0 moves three positions to the right (to position 3).
The letter 'O' at position 1 remains on its initial position (position 1).
The letter 'P' at position 2 moves three positions to the right (to position 5).
The letter 'C' at position 3 moves three positions to the left (to position 0).
The letter 'O' at position 4 moves two positions to the right (to position 6).
The letter 'D' at position 5 moves three positions to the left (to position 2).
The letter 'E' at position 6 moves two positions to the left (to position 4).
The letter 'R' at position 7 remains on its initial position (position 7).

Note that the letter 'D' (at position 5) cannot move to position 1, because this would require it to move more than the maximal distance 3.

It turns out that the string "CODTEPOR" is the lexicographically smallest one Elly can get from "TOPCODER" with a single tap and maxDistance = 3. Now you want to write a program that, given the string letters and the int maxDistance, returns the lexicographically smallest string the girl can get after a single tap.

DEFINITION
Class:EllysScrabble
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string letters, int maxDistance)


NOTES
-Given two different strings A and B of equal length, the lexicographically smaller one is the one that contains a smaller character at the first position where they differ.


CONSTRAINTS
-letters will contain between 1 and 50 characters, inclusive.
-letters will contain only uppercase letters from the English alphabet ('A'-'Z').
-maxDistance will be between 1 and 9, inclusive.


EXAMPLES

0)
"TOPCODER"
3

Returns: "CODTEPOR"

The example from the problem statement.

1)
"ESPRIT"
3

Returns: "EIPRST"

In this example the letters 'E', 'P', 'R', and 'T' stay on their initial places, and the letters 'S' and 'I' swap. Since the distance between them is exactly 3 (which also happens to be the maximal distance they can move), this is a valid final configuration.

2)
"BAZINGA"
8

Returns: "AABGINZ"

Note that the maximal distance may be greater than the number of letters Elly has. In such cases, the lexicographically smallest result is, obviously, the sorted sequence of letters.

3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
9

Returns: "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

As the input letters are already sorted, we can assume they'll just fall back to their initial places.

4)
"GOODLUCKANDHAVEFUN"
7

Returns: "CADDGAHEOOFLUKNNUV"



5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
6

Returns: "AAAADDEIBWAEUIODWADSBIAJWODIAWDOPOAWDUOSPWW"



6)
"ABRACADABRA"
2

Returns: "AABARACBDAR"


The letter 'A' at position 0 remains on its initial place (position 0).
The letter 'B' at position 1 moves one position to the right (to position 2).
The letter 'R' at position 2 moves two positions to the right (to position 4).
The letter 'A' at position 3 moves two positions to the left (to position 1).
The letter 'C' at position 4 moves two positions to the right (to position 6).
The letter 'A' at position 5 moves two positions to the left (to position 3).
The letter 'D' at position 6 moves two positions to the right (to position 8).
The letter 'A' at position 7 moves two positions to the left (to position 5).
The letter 'B' at position 8 moves one position to the left (to position 7).
The letter 'R' at position 9 moves one position to the right (to position 10).
The letter 'A' at position 10 moves one position to the left (to position 9).


*/

// END CUT HERE
