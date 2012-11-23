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

class StrIIRec {
//    void swap(string& s, int i, int j){
//        char tmp = s[i];
//        s[i] = s[j];
//        s[j] = tmp;
//        return;
//    }
    void plus(string& s){
        for(int i=SZ(s)-2; i>=0; i--){
            for(int j=SZ(s)-1; j>i; j--){
                if(s[i]<s[j]){
                    swap(s[i], s[j]);
                    return;
                }
            }
        }
        return;
    }
    int count(string s){
        int res = 0;
        for(int i=0; i<SZ(s)-1; i++){
            for(int j=i+1; j<SZ(s); j++){
                if(s[i] > s[j]) res++;
            }
        }
        return res;
    }
    
	public:
	string recovstr(int n, int minInv, string minStr) {
        string s = minStr;
        REP(i, n){
            if(s.find('a'+i) == -1) s+=('a'+i);
        }
        for(; count(s)<minInv; ){
            plus(s);
        }
        
        
        
        return s;
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
			int n                     = 2;
			int minInv                = 1;
			string minStr             = "ab";
			string expected__         = "ba";

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 9;
			int minInv                = 1;
			string minStr             = "efcdgab";
			string expected__         = "efcdgabhi";

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 11;
			int minInv                = 55;
			string minStr             = "debgikjfc";
			string expected__         = "kjihgfedcba";

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 15;
			int minInv                = 0;
			string minStr             = "e";
			string expected__         = "eabcdfghijklmno";

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 9;
			int minInv                = 20;
			string minStr             = "fcdebiha";
			string expected__         = "fcdehigba";

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			int n                     = 16;
			int minInv                = 64;
			string minStr             = "k";
			string expected__         = "kabcdopnmljihgfe";

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			int n                     = ;
			int minInv                = ;
			string minStr             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int minInv                = ;
			string minStr             = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = StrIIRec().recovstr(n, minInv, minStr);
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
// For a given string S of length n an inversion is a pair of integers (i, j) such that 0 <= i < j <= n-1 and S[i] > S[j]. (That is, the character at 0-based index i is greater than the character at 0-based index j.) For example, the string "abcab" has 3 inversions: (1, 3), (2, 3), and (2, 4).

Given are ints n and minInv, and a string minStr.
We will consider all strings that are permutations of the first n lowercase English letters.
That is, these strings have length n and contain each of the first n letters exactly once.
Out of these strings, return the lexicographically smallest string R with the following two properties:

The number of inversions in R is at least minInv.
The string R is not lexicographically smaller than minStr.

If there is no such string, return an empty string instead.


DEFINITION
Class:StrIIRec
Method:recovstr
Parameters:int, int, string
Returns:string
Method signature:string recovstr(int n, int minInv, string minStr)


NOTES
-A string A is lexicographically smaller than a string B if A is a prefix of B or A contains a smaller character at the first position where the strings differ.


CONSTRAINTS
-n will be between 1 and 20, inclusive.
-minInv will be between 0 and n*(n-1)/2, inclusive.
-minStr will contain between 1 and n characters, inclusive.
-Each character in minStr will be one of the first n lowercase Latin letters.
-All characters in minStr will be unique.


EXAMPLES

0)
2
1
"ab"

Returns: "ba"

You must find the lexicographically smallest string that has at least 1 inversion and is not lexicographically smaller than "ab".

1)
9
1
"efcdgab"

Returns: "efcdgabhi"

2)
11
55
"debgikjfc"

Returns: "kjihgfedcba"

"kjihgfedcba" is the only string that has at least 55 inversions.

3)
15
0
"e"

Returns: "eabcdfghijklmno"

4)
9
20
"fcdebiha"

Returns: "fcdehigba"

*/

// END CUT HERE
