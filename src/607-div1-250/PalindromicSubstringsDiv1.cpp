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

double dp1[

class PalindromicSubstringsDiv1 {
	public:
	double expectedPalindromes(vector <string> S1, vector <string> S2) {
		string s = "";
        REP(i, SZ(S1)) s += S1[i];
        REP(i, SZ(S2)) s += S2[i];
        int n = SZ(s);
        
        double res = 0.0;
        REP(i, n){
            double p = 1.0;
            for(int j = 0; i-j >= 0 && i+j < n; j++){
                int a = i-j;
                int b = i+j;
                if((s[a] == '?' || s[b] == '?') && a != b) p /= 26;
                else if(s[a] != s[b]) break;
                res += p;
            }
        }
        
        REP(i, n){
            double p = 1.0;
            for(int j = 0; i-j >= 0 && i+j+1 < n; j++){
                int a = i-j;
                int b = i+j+1;
                if(s[a] == '?' || s[b] == '?') p /= 26;
                else if(s[a] != s[b]) break;
                res += p;
            }
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string S1[]               = {"a","a",""};
			string S2[]               = {"a"};
			double expected__         = 6.0;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S1[]               = {"z??"};
			string S2[]               = {};
			double expected__         = 3.115384615384615;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S1[]               = {"ab","c"};
			string S2[]               = {"??","a?"};
			double expected__         = 7.315088757396449;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S1[]               = {};
			string S2[]               = {"?"};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S1[]               = {"ab?def","?"};
			string S2[]               = {"f??a"};
			double expected__         = 12.545971779699588;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string S1[]               = ;
			string S2[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string S1[]               = ;
			string S2[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S1[]               = ;
			string S2[]               = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = PalindromicSubstringsDiv1().expectedPalindromes(vector <string>(S1, S1 + (sizeof S1 / sizeof S1[0])), vector <string>(S2, S2 + (sizeof S2 / sizeof S2[0])));
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
// Marco likes strings.
In particular, he likes strings that have a lot of palindromic substrings.
For example, he really likes the string "aaa" because it has 6 palindromic substrings: "a" occurs three times, "aa" occurs twice, and "aaa" occurs once.

Right now, Marco has a string S composed of lowercase letters and question marks.
You are to reconstruct S from the given vector <string>s S1 and S2 as follows:

Concatenate all elements of S1 to make a string A.
Concatenate all elements of S2 to make a string B.
Finally, concatenate A and B to get S.



Marco is going to replace every question mark in S with a random lowercase letter ('a' - 'z').
Return the expected number of palindromic substrings in the resulting string.

DEFINITION
Class:PalindromicSubstringsDiv1
Method:expectedPalindromes
Parameters:vector <string>, vector <string>
Returns:double
Method signature:double expectedPalindromes(vector <string> S1, vector <string> S2)


NOTES
-For each question mark, the letter used to replace it is chosen uniformly at random. That is, the probability of choosing any particular letter is 1/26. All random choices are mutually independent.
-A palindromic string is a string that reads the same forwards and backwards.
-Your return value must have an absolute or a relative error of less than 1e-9.


CONSTRAINTS
-S1 and S2 will contain no more than 50 elements.
-Each element of S1 and S2 will contain no more than 50 characters.
-S will contain at least 1 character.
-S will contain only lowercase letters ('a' - 'z') and question marks ('?').


EXAMPLES

0)
{"a","a",""}
{"a"}

Returns: 6.0

This is the example given in the statement.

1)
{"z??"}
{}

Returns: 3.115384615384615

There are 26^2 = 676 equally likely possibilities for the letters used to replace the question marks.
Here are all possible outcomes:

The string "zzz" has 6 palindromic substrings.
Each of the 25 strings "zaz", "zbz", ..., "zyz" has 4 palindromic substrings.
Each of the 25 strings "zza", "zzb", ..., "zzy" has 4 palindromic substrings.
Each of the 25 strings "zaa", "zbb", ..., "zyy" has 4 palindromic substrings.
Each of the remaining 600 possible strings only has the 3 single-letter palindromic substrings.

The expected number of palindromic substrings can be computed simply as the average over all 676 possible cases.
Hence, the correct return value is (6 + 75*4 + 600*3) / 676.

2)
{"ab","c"}
{"??","a?"}

Returns: 7.315088757396449



3)
{}
{"?"}

Returns: 1.0



4)
{"ab?def","?"}
{"f??a"}

Returns: 12.545971779699588



*/

// END CUT HERE
