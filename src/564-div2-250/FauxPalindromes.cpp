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

class FauxPalindromes {
    bool check(string s){
        REP(i, SZ(s)){
            int j = SZ(s) - i - 1;
            if(s[i] != s[j]) return false;
        }
        return true;
    }
    
	public:
	string classifyIt(string word) {
        if(check(word)) return "PALINDROME";
        string s = "";
        s += word[0];
        FOR(i, 1, SZ(word)){
            if(word[i-1] != word[i]) s += word[i];
        }
        if(check(s)) return "FAUX";
        
        return "NOT EVEN FAUX";
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
			string word               = "ANA";
			string expected__         = "PALINDROME";

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string word               = "AAAAANNAA";
			string expected__         = "FAUX";

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string word               = "LEGENDARY";
			string expected__         = "NOT EVEN FAUX";

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string word               = "XXXYTYYTTYX";
			string expected__         = "FAUX";

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string word               = "TOPCOODEREDOOCPOT";
			string expected__         = "PALINDROME";

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string word               = "TOPCODEREDOOCPOT";
			string expected__         = "FAUX";

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string word               = "XXXXYYYYYZZXXYYY";
			string expected__         = "NOT EVEN FAUX";

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string word               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string word               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string word               = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FauxPalindromes().classifyIt(word);
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
// A word is a palindrome if it can be read the same forwards and backwards. For example, the strings "ANA", "AAXAA", "Z" and "XYYYYYX" are palindromes (quotes for clarity).

A word is a faux palindrome if, after replacing every group of consecutive equal letters with a single instance of the letter, the resulting word is a palindrome. For example, the string "AAAAANNAA" is a faux palindrome. A detailed explanation why this is a faux palindrome is given below in Example 1.
Other examples of faux palindromes are the strings "AAAAAAAAAAAAAAAXA and "XYX". Note that every palindrome is also a faux palindrome.

You are given a string word. You are asked to classify it.
If word is a palindrome, return "PALINDROME" (quotes for clarity, returned values are case sensitive).
If word is not a palindrome but is a faux palindrome, return "FAUX".
In case word is not a faux palindrome, return "NOT EVEN FAUX".



DEFINITION
Class:FauxPalindromes
Method:classifyIt
Parameters:string
Returns:string
Method signature:string classifyIt(string word)


CONSTRAINTS
-word will contain between 1 and 50 characters, inclusive.
-The characters in word will be upper case letters between 'A' and 'Z', inclusive (quotes for clarity).


EXAMPLES

0)
"ANA"

Returns: "PALINDROME"

"ANA" reads the same from left to right and right to left.

1)
"AAAAANNAA"

Returns: "FAUX"

This is obviously not a palindrome. Now suppose that we replace each group of consecutive equal letters by a single copy of that letter. That is, we change "AAAAA" to "A", "NN" to "N", and "AA" to "A". In this way we will obtain the new string "ANA", which is a palindrome. Hence the original string is a faux palindrome.

2)
"LEGENDARY"

Returns: "NOT EVEN FAUX"

The word "LEGENDARY" already does not contain any group of consecutive equal letters and it is not a palindrome.

3)
"XXXYTYYTTYX"

Returns: "FAUX"

After replacing the groups of consecutive equal letters with a single letter, the string becomes "XYTYTYX". "XYTYTYX" is a palindrome.

4)
"TOPCOODEREDOOCPOT"

Returns: "PALINDROME"

This word contains some groups of consecutive equal letters, but it is already a palindrome without replacing them by single letters.

5)
"TOPCODEREDOOCPOT"

Returns: "FAUX"



6)
"XXXXYYYYYZZXXYYY"

Returns: "NOT EVEN FAUX"



*/

// END CUT HERE
