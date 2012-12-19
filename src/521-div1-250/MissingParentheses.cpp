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

class MissingParentheses {
	public:
	int countCorrections(string par) {
		int res = 0;
        int cnt = 0;
        REP(i, SZ(par)){
            if(par[i] == '(') cnt++;
            else cnt--;
            if(cnt == -1){
                res++;
                cnt++;
            }
        }
        res += cnt;
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
			string par                = "(()(()";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string par                = "()()(()";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string par                = "(())(()())";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string par                = "())(())((()))))()((())))()())())())()()()";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string par                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string par                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MissingParentheses().countCorrections(par);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string par                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MissingParentheses().countCorrections(par);
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
// 
Given a string of parentheses, you must turn it into a well formed string by inserting as few parentheses as possible, at any position (you cannot delete or change any of the existing parentheses).

A well formed string of parentheses is defined by the following rules:

    The empty string is well formed.
    If s is a well formed string, (s) is a well formed string.
    If s and t are well formed strings, their concatenation st is a well formed string.

As examples, "(()())", "" and "(())()" are well formed strings and "())(", "()(" and ")" are malformed strings.

Given a string par of parentheses, return the minimum number of parentheses that need to be inserted to make it into a well formed string.


DEFINITION
Class:MissingParentheses
Method:countCorrections
Parameters:string
Returns:int
Method signature:int countCorrections(string par)


CONSTRAINTS
-par will contain between 1 and 50 characters, inclusive.
-Each character of par will be an opening or closing parenthesis, i.e., '(' or ')'.


EXAMPLES

0)
"(()(()"

Returns: 2

The string below is a possible well formed string you can get to by inserting the two closing parentheses marked.

(())(())
   ^   ^


1)
"()()(()"

Returns: 1

You can fix the string by inserting a single closing parenthesis at the end.

2)
"(())(()())"

Returns: 0

The input string is well formed, so no insertion is needed.

3)
"())(())((()))))()((())))()())())())()()()"

Returns: 7



*/

// END CUT HERE
