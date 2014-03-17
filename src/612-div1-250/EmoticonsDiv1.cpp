#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <cstdarg>
#include <sys/time.h>
#include <fstream>
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
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }


int dp[1500];
const int INF = (1<<29);

class EmoticonsDiv1 {
public:
    int printSmiles( int smiles ) {
        REP(i, 1500) dp[i] = INF;
        dp[1] = 0;
        for(int i = 1; i < 1100; i++){
            REP(j, i){
                for(int k = 0; i-j+i*k < 1500; k++){
                    chmin(dp[i-j+i*k], dp[i] + 1 + j + k);
                }
            }
        }
        return dp[smiles];
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
			int smiles                = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int smiles                = 4;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int smiles                = 6;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int smiles                = 18;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int smiles                = 11;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int smiles                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int smiles                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int smiles                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EmoticonsDiv1().printSmiles(smiles);
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
// You are very happy because you advanced to the next round of a very important programming contest.
You want your best friend to know how happy you are.
Therefore, you are going to send him a lot of smile emoticons.
You are given an int smiles: the exact number of emoticons you want to send.

You have already typed one emoticon into the chat.
Then, you realized that typing is slow.
Instead, you will produce the remaining emoticons using copy, paste, and possibly some deleting.

You can only do three different operations:

Copy all the emoticons you currently have into the clipboard.
Paste all emoticons from the clipboard.
Delete one emoticon from the message.

Each operation takes precisely one second.
Copying replaces the old content of the clipboard.
Pasting does not empty the clipboard.
You are not allowed to copy just a part of the emoticons you already have.
You are not allowed to delete an emoticon from the clipboard.

Return the smallest number of seconds in which you can turn the one initial emoticon into smiles emoticons.

DEFINITION
Class:EmoticonsDiv1
Method:printSmiles
Parameters:int
Returns:int
Method signature:int printSmiles(int smiles)


CONSTRAINTS
-smiles will be between 2 and 1000, inclusive.


EXAMPLES

0)
2

Returns: 2

First use copy, then use paste. The first operation copies one emoticon into the clipboard, the second operation pastes it into the message, so now you have two emoticons and you are done.

1)
4

Returns: 4

One optimal solution is to copy the initial emoticon and then to paste it three times. Another optimal solution is to copy the one emoticon, paste it, copy the two emoticons you currently have, and paste two more.

2)
6

Returns: 5


Copy. This puts one emoticon into the clipboard.
Paste. You now have 2 emoticons in the message.
Copy. The clipboard now contains 2 emoticons.
Paste. You now have 4 emoticons in the message.
Paste. You now have 6 emoticons in the message and you are done.


3)
18

Returns: 8



4)
11

Returns: 8

Sometimes we actually do delete an emoticon in the optimal solution.

*/

// END CUT HERE
