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

class EllysSortingTrimmer {
	public:
	string getMin(string S, int L) {
        int n = SZ(S);
		for(int i = n-L; i >= 0; i--) sort(S.begin()+i, S.begin()+i+L);
        string res = "";
        REP(i, L) res += S[i];
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
			string S                  = "ABRACADABRA";
			int L                     = 5;
			string expected__         = "AAAAA";

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "ESPRIT";
			int L                     = 3;
			string expected__         = "EIP";

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "BAZINGA";
			int L                     = 7;
			string expected__         = "AABGINZ";

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
			int L                     = 13;
			string expected__         = "ABCDEFGHIJKLM";

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "GOODLUCKANDHAVEFUN";
			int L                     = 10;
			string expected__         = "AACDDEFGHK";

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD";
			int L                     = 21;
			string expected__         = "AAAAAAAAABBDDDDDDDEEI";

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string S                  = "TOPCODER";
			int L                     = 3;
			string expected__         = "CDT";

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string S                  = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string S                  = ;
			int L                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EllysSortingTrimmer().getMin(S, L);
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
// Elly has a string S of uppercase letters and a magic device that can modify the string. The strength of the device is an int L.

The device is used in the following way. The user enters a 0-based index i such that 0 <= i <= length(S)-L. The device then performs the following changes:

It leaves the first i characters (i.e., characters with indices 0 through i-1) untouched.
It rearranges the next L characters (i.e., characters with indices i through i+L-1) into alphabetical order.
It erases all the remaining characters (i.e., characters with indices i+L and more). Note that for i=length(S)-L no characters are erased.

The girl can use this "sorting trimmer" as many times as she likes. After each use she is left with the new version of the string.

In the examples below we use brackets to highlight the region that shall be sorted. For example, "ABRA[CADAB]RA" means that L=5 and Elly chose i=4. The device keeps the letters in front of the brackets, sorts the letters in the brackets, and throws away the rest.

Here is one way how Elly could have used a device with L = 5, starting with the string S = "ABRACADABRA":

"ABRAC[ADABR]A" -> "ABRACAABDR"
"ABR[ACAAB]DR" -> "ABRAAABC"
"A[BRAAA]BC" -> "AAAABR"


You are given the string S and the int L. Return the lexicographically smallest string Elly can obtain.

DEFINITION
Class:EllysSortingTrimmer
Method:getMin
Parameters:string, int
Returns:string
Method signature:string getMin(string S, int L)


NOTES
-A string A is lexicographically smaller than string B if A contains a smaller character in the first position where they differ. In case one of the strings ends before they have a different character, the shorter one is considered smaller.


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-L will be between 2 and |S|, inclusive, where |S| denotes the number of characters in S.
-S will consist of uppercase characters of the English alphabet, only ('A'-'Z').


EXAMPLES

0)
"ABRACADABRA"
5

Returns: "AAAAA"

Please note that the example in the problem statement does not obtain the lexicographically smallest string. In fact, it is optimal to start by using the device on the last five characters of the string, transforming it from ABRACA[DABRA] to ABRACAAABDR.

1)
"ESPRIT"
3

Returns: "EIP"

We can obtain the answer in the following steps:

ES[PRI]T -> ESIPR
E[SIP]R -> EIPS
[EIP]S -> EIP
 

2)
"BAZINGA"
7

Returns: "AABGINZ"

We can use the sorting trimmer on the entire word.

3)
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
13

Returns: "ABCDEFGHIJKLM"

Even though the string is already sorted, shorter strings are considered lexicographically smaller, so we can use the device once to make the string as short as possible.

4)
"GOODLUCKANDHAVEFUN"
10

Returns: "AACDDEFGHK"



5)
"AAAWDIUAOIWDESBEAIWODJAWDBPOAWDUISAWDOOPAWD"
21

Returns: "AAAAAAAAABBDDDDDDDEEI"



6)
"TOPCODER"
3

Returns: "CDT"



*/

// END CUT HERE
