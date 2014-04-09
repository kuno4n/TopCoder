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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

//string INF = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";

//string dp[55][55][55];
string dp[55][55];


class MergeStrings {
public:
   string getmin( string S, string A, string B ) {
//       REP(i, 55) REP(j, 55) REP(k, 55) dp[i][j][k] = INF;
//       
//       dp[0][0][0] = "";
//       REP(i, SZ(S)) REP(j, SZ(A)+1) REP(k, SZ(B)+1) if(dp[i][j][k] != INF){
//           if(S[i] == '?'){
//               if(j != SZ(A)) chmin(dp[i+1][j+1][k], dp[i][j][k] + A[j]);
//               if(k != SZ(B)) chmin(dp[i+1][j][k+1], dp[i][j][k] + B[k]);
//           }
//           else{
//               if(j != SZ(A) && S[i] == A[j]) chmin(dp[i+1][j+1][k], dp[i][j][k] + A[j]);
//               if(k != SZ(B) && S[i] == B[k]) chmin(dp[i+1][j][k+1], dp[i][j][k] + B[k]);
//           }
//       }
//       
//       if(dp[SZ(S)][SZ(A)][SZ(B)] == INF) return "";
//       return dp[SZ(S)][SZ(A)][SZ(B)];
       
       REP(i, 55) REP(j, 55) dp[i][j] = string(1, 'Z'+1);
       dp[0][0] = "";
       REP(i, SZ(A)+1) REP(j, SZ(B)+1){
           if(i < SZ(A) && ((i+j) < SZ(S) && (S[i+j] == A[i] || S[i+j] == '?'))) chmin(dp[i+1][j], dp[i][j]+A[i]);
           if(j < SZ(B) && ((i+j) < SZ(S) && (S[i+j] == B[j] || S[i+j] == '?'))) chmin(dp[i][j+1], dp[i][j]+B[j]);
       }
       return dp[SZ(A)][SZ(B)] == string(1, 'Z'+1) ? "" : dp[SZ(A)][SZ(B)];
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
			string S                  = "??CC??";
			string A                  = "ABC";
			string B                  = "BCC";
			string expected__         = "ABCCBC";

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "WHAT?";
			string A                  = "THE";
			string B                  = "WA";
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "PARROT";
			string A                  = "PARROT";
			string B                  = "";
			string expected__         = "PARROT";

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "???????????";
			string A                  = "AZZAA";
			string B                  = "AZAZZA";
			string expected__         = "AAZAZZAAZZA";

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "????K??????????????D???K???K????????K?????K???????";
			string A                  = "KKKKKDKKKDKKDDKDDDKDKK";
			string B                  = "KDKDDKKKDDKDDKKKDKDKKDDDDDDD";
			string expected__         = "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK";

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string S                  = ;
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string S                  = ;
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			string A                  = ;
			string B                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = MergeStrings().getmin(S, A, B);
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
// Guts is a slow loris who likes to play with strings.

String C is obtained by shuffling strings A and B if we can create C by repeatedly taking either the first character of A or the first character of B. Formally, string C is obtained by shuffling strings A and B if length(C) = length(A) + length(B) and there are sequences of integers X and Y such that:

length(X) = length(A) and length(Y) = length(B).
For each valid i, X[i] < X[i+1].
For each valid i, Y[i] < Y[i+1].
For each valid i and j, X[i] != Y[j].
For each valid i, C[X[i]] = A[i].
For each valid i, C[Y[i]] = B[i].


You are given strings S, A, and B. Strings A and B contain only letters, string S can also contain multiple copies of the '?' (question mark) character. The '?' is a wildcard that represents any single letter. Guts wants to shuffle strings A and B in such a way that the resulting string matches S.

Replace each '?' with a letter in such a way that the resulting string S can be obtained by shuffling A and B. Return the resulting string S. If there are multiple solutions, return the lexicographically smallest one. If there is no solution, return an empty string instead.

DEFINITION
Class:MergeStrings
Method:getmin
Parameters:string, string, string
Returns:string
Method signature:string getmin(string S, string A, string B)


NOTES
-Given two distinct strings X and Y such that length(X)=length(Y), the lexicographically smaller one is the one that has a character with a smaller ASCII value on the first position on which they differ.


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-The number of characters in S will be same as the total number of characters of A and B.
-Each character in S will be an uppercase letter ('A'-'Z') or '?'.
-Each character in A and B will be an uppercase letter ('A'-'Z').


EXAMPLES

0)
"??CC??"
"ABC"
"BCC"

Returns: "ABCCBC"

Out of all strings that can be obtained by shuffling "ABC" and "BCC", only two match "??CC??": the strings "ABCCBC" and "BACCBC". The string "ABCCBC" is the lexicographically smaller of the two.

1)
"WHAT?"
"THE"
"WA"

Returns: ""

None of the strings obtained by shuffling "THE" and "WA" matches "WHAT?".

2)
"PARROT"
"PARROT"
""

Returns: "PARROT"

One of A and B may sometimes be empty.

3)
"???????????"
"AZZAA"
"AZAZZA"

Returns: "AAZAZZAAZZA"



4)
"????K??????????????D???K???K????????K?????K???????"
"KKKKKDKKKDKKDDKDDDKDKK"
"KDKDDKKKDDKDDKKKDKDKKDDDDDDD"

Returns: "KDKDKDKKKDDKDDKKKDKDKKDKDDDKDDDKKDKKKDKKDDKDDDKDKK"



*/

// END CUT HERE
