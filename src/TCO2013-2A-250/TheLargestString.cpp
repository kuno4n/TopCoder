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

string dp[50];

class TheLargestString {
	public:
	string find(string s, string t) {
		REP(i, 50) dp[i] = "";
        REP(i, SZ(s)){
            string dp_next[50];
            for(int j = 1; j <= SZ(s); j++){
                if(SZ(dp[j-1]) != 2*(j-1)) continue;
                string tmp = "";
                tmp += dp[j-1].substr(0, j-1);
                tmp.push_back(s[i]);
                tmp += dp[j-1].substr(j-1, j-1);
                tmp += t[i];
                dp_next[j] = max(dp[j], tmp);
            }
            REP(i, 50) dp[i] = max(dp[i], dp_next[i]);
        }
        string res = "";
        REP(i, 50) res = max(res, dp[i]);
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
			string s                  = "ab";
			string t                  = "zy";
			string expected__         = "by";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "abacaba";
			string t                  = "zzzaaaa";
			string expected__         = "cbaaaa";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "x";
			string t                  = "x";
			string expected__         = "xx";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "abbabbabbababaaaabbababab";
			string t                  = "bababbaabbbababbbbababaab";
			string expected__         = "bbbbbbbbbbbbbbbbbbaaab";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			string s                  = "bba";
			string t                  = "aaa";
			string expected__         = "bbaaaa";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 5: {
			string s                  = "bba";
			string t                  = "bbz";
			string expected__         = "bbbb";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			string s                  = "bba";
			string t                  = "cbz";
			string expected__         = "bc";

			clock_t start__           = clock();
			string received__         = TheLargestString().find(s, t);
			return verify_case(casenum__, expected__, received__, clock()-start__);
      }
            case 7: {
                string s                  = "bba";
                string t                  = "cdz";
                string expected__         = "bd";
                
                clock_t start__           = clock();
                string received__         = TheLargestString().find(s, t);
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
// John has two strings s and t of equal length.
He can choose a set of positions (possibly empty) and erase characters at these positions in both s and t.
Then he writes down the concatenation of what remained of the strings: first the letters we kept from s, in their original order, then the letters we kept from t, again in their original order.


Return the lexicographically largest string John can get at the end.


DEFINITION
Class:TheLargestString
Method:find
Parameters:string, string
Returns:string
Method signature:string find(string s, string t)


NOTES
-String A is lexicographically smaller than string B if either A is a proper prefix of B, or if there is an integer i such that the first i characters of A match the first i characters of B, and character i+1 of A is smaller than character i+1 of B.


CONSTRAINTS
-s will contain between 1 and 47 characters, inclusive.
-s and t will contain the same number of characters.
-s will contain only lowercase English characters ('a'-'z').
-t will contain only lowercase English characters ('a'-'z').


EXAMPLES

0)
"ab"
"zy"

Returns: "by"

There are four options here:

Do not erase anything. The resulting string would be "abzy".
Erase both first characters. The resulting string would be "by".
Erase both last characters. The resulting string would be "az".
Erase all characters. The resulting string would be empty.

Among all possible results "by" is the lexicographically largest one.


1)
"abacaba"
"zzzaaaa"

Returns: "cbaaaa"



2)
"x"
"x"

Returns: "xx"



3)
"abbabbabbababaaaabbababab"
"bababbaabbbababbbbababaab"

Returns: "bbbbbbbbbbbbbbbbbbaaab"



*/

// END CUT HERE
