#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
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
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl


bool isPal(string s){
    for(int i=0, j=SZ(s)-1; i<j; i++, j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}

class ThePalindrome {
	public:
	int find(string s) {
        REP(i,SZ(s)){
            if(isPal(s.substr(i))) return SZ(s)+i;
        }
        return -1;
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
			string s                  = "abab";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ThePalindrome().find(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s                  = "abacaba";
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = ThePalindrome().find(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s                  = "qwerty";
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = ThePalindrome().find(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s                  = "abdfhdyrbdbsdfghjkllkjhgfds";
			int expected__            = 38;

			clock_t start__           = clock();
			int received__            = ThePalindrome().find(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThePalindrome().find(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThePalindrome().find(s);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ThePalindrome().find(s);
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
// John and Brus are studying string theory at the university.  Brus likes palindromes very much.  A palindrome is a word that reads the same forward and backward.  John would like to surprise Brus by taking a string s, and appending 0 or more characters to the end of s to obtain a palindrome.  He wants that palindrome to be as short as possible.  Return the shortest possible length of a palindrome that John can generate.

DEFINITION
Class:ThePalindrome
Method:find
Parameters:string
Returns:int
Method signature:int find(string s)


CONSTRAINTS
-s will contain between 1 and 50 characters, inclusive.
-Each character of s will be a lowercase letter ('a' - 'z').


EXAMPLES

0)
"abab"

Returns: 5

"ababa" is the shortest palindrome that John can get.

1)
"abacaba"

Returns: 7

Already a palindrome.

2)
"qwerty"

Returns: 11

All characters are different.

3)
"abdfhdyrbdbsdfghjkllkjhgfds"

Returns: 38



*/

// END CUT HERE
