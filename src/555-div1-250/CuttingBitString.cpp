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

class CuttingBitString {
    
    bool isPow5(string s){
        if(s[0] == '0') return false;
        LL l = 0;
        REP (i, SZ(s)) {
            l <<= 1;
            if (s[i] == '1') l++;
        }
        if (l <= 0 ) return false;
        int p = 0;
        while (!(l%5)){
            l/=5;
            p++;
        }
        if (l == 1) return true;
        else return false;
    }
    
    int dp[60];

	public:
	int getmin(string S) {
        REP(i, 60) dp[i] = 1000;
        
        REP(i, SZ(S)){
            if(isPow5(S.substr(0, i+1))) dp[i] = 1;
            REP(j, i){
                if(dp[j] != 1000 & isPow5(S.substr(j+1, i-j)))
                    dp[i] = min(dp[i], dp[j]+1);
            }
        }
        if(dp[SZ(S)-1] == 1000) return -1;
        return dp[SZ(S)-1];
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
			string S                  = "101101101";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "1111101";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "00000";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "110011011";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "1000101011";
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "111011100110101100101110111";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CuttingBitString().getmin(S);
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
// We are in a distant future.
After the downfall of mankind, the Earth is now ruled by fairies.
The "Turing game Online" website is hot among fairies right now.
On this website, everyone can play the programming puzzle "Turing game".

Fairies love powers of 5, that is, the numbers 1, 5, 25, 125, 625, and so on.
In the Turing game, the player is given a string of bits (zeros and ones).
The ideal situation is when the string is represents a power of 5 in binary, with no leading zeros.
If that is not the case, the fairy player tries to cut the given string into pieces, each piece being a binary representation of a power of 5, with no leading zeros.
Of course, it may be the case that even this is impossible.
In that case, the fairy player becomes depressed, and bad things happen when a fairy gets depressed.
You, as one of the surviving humans, are in charge of checking the bit strings to prevent the bad things from happening.

You are given a string S that consists of characters '0' and '1' only.
S represents the string given to a player of the Turing game.
Return the smallest positive integer K such that it is possible to cut S into K pieces, each of them being a power of 5.
If there is no such K, return -1 instead.

DEFINITION
Class:CuttingBitString
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be either '0' or '1'.


EXAMPLES

0)
"101101101"

Returns: 3

We can split the given string into three "101"s.
Note that "101" is 5 in binary.

1)
"1111101"

Returns: 1

"1111101" is 5^3.

2)
"00000"

Returns: -1

0 is not a power of 5.

3)
"110011011"

Returns: 3

Split it into "11001", "101" and "1".

4)
"1000101011"

Returns: -1



5)
"111011100110101100101110111"

Returns: 5



*/

// END CUT HERE
