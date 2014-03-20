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
#define mp make_pair
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; }

string a, b, c;
int na, nb, nc;
int findA[2510], findB[2510];
int dp1[2510][2510], dp2[2510][2510];

class WinterAndReindeers {
public:
   int getNumber( vector <string> allA, vector <string> allB, vector <string> allC ) {
       a = b = c = "";
       REP(i, SZ(allA)) a += allA[i];
       REP(i, SZ(allB)) b += allB[i];
       REP(i, SZ(allC)) c += allC[i];
       na = SZ(a), nb = SZ(b), nc = SZ(c);
       REP(i, 2510) findA[i] = findB[i] = -1;
       REP(i, na) if(a[i] == c[0]){
           int ptr1 = i+1, ptr2 = 1;
           while(ptr1 < na && ptr2 < nc){
               if(a[ptr1] == c[ptr2]) ptr1++, ptr2++;
               else ptr1++;
           }
           if(ptr2 == nc) findA[i] = ptr1-1;
       }
       REP(i, nb) if(b[i] == c[0]){
           int ptr1 = i+1, ptr2 = 1;
           while(ptr1 < nb && ptr2 < nc){
               if(b[ptr1] == c[ptr2]) ptr1++, ptr2++;
               else ptr1++;
           }
           if(ptr2 == nc) findB[i] = ptr1-1;
       }
       
       MSET(dp1, 0), MSET(dp2, 0);
       for(int i = 1; i <= na; i++) for(int j = 1; j <= nb; j++){
           if(a[i-1] == b[j-1]) dp1[i][j] = dp1[i-1][j-1] + 1;
           else dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]);
       }
       reverse(ALL(a)), reverse(ALL(b));
       for(int i = 1; i <= na; i++) for(int j = 1; j <= nb; j++){
           if(a[i-1] == b[j-1]) dp2[i][j] = dp2[i-1][j-1] + 1;
           else dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
       }
       int res = 0;
       REP(i, na) REP(j, nb) if(findA[i] >= 0 && findB[j] >= 0) chmax(res, nc + dp1[i][j] + dp2[na-findA[i]-1][nb-findB[j]-1]);
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
			string allA[]             = {"X"};
			string allB[]             = {"X", "Y"};
			string allC[]             = {"X"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string allA[]             = {"ABCXD"};
			string allB[]             = {"BCDEF"};
			string allC[]             = {"CD"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string allA[]             = {"WE", "LOVE"};
			string allB[]             = {"WORKING", "FOR", "SANTA"};
			string allC[]             = {"JK"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string allA[]             = {"ABCDE"};
			string allB[]             = {"CDEAB"};
			string allC[]             = {"B"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string allA[]             = {"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"};
			string allB[]             = {"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"};
			string allC[]             = {"AXBADXBBAB", "CDD"};
			int expected__            = 23;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string allA[]             = ;
			string allB[]             = ;
			string allC[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string allA[]             = ;
			string allB[]             = ;
			string allC[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string allA[]             = ;
			string allB[]             = ;
			string allC[]             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = WinterAndReindeers().getNumber(vector <string>(allA, allA + (sizeof allA / sizeof allA[0])), vector <string>(allB, allB + (sizeof allB / sizeof allB[0])), vector <string>(allC, allC + (sizeof allC / sizeof allC[0])));
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
It's winter time! Time to play some games.




Four reindeers are playing the following game.
The first three of them choose three non-empty strings: A, B, and C. (The strings are not necessarily distinct.)
Then, the fourth one (and it happens to be the youngest one) finds a string S that satisfies the following conditions:



S is a subsequence of A. (I.e., either S equals A, or S can be obtained from A by removing some of its characters.)


S is a subsequence of B.


C is a (contiguous) substring of S.


There is no string longer than S that satisfies the previous three conditions.





You are given three vector <string>s allA, allB and allC.
Concatenate all elements of allA, allB and allC to obtain strings A, B and C, respectively.
Return the length of the string S.
If there is no such string, return 0.


DEFINITION
Class:WinterAndReindeers
Method:getNumber
Parameters:vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int getNumber(vector <string> allA, vector <string> allB, vector <string> allC)


CONSTRAINTS
-allA, allB and allC will each contain between 1 and 50 elements, inclusive.
-Each element of allA, allB and allC will contain between 1 and 50 characters, inclusive.
-Each element of allA, allB and allC will consist only of uppercase English letters ('A'-'Z').


EXAMPLES

0)
{"X"}
{"X", "Y"}
{"X"}

Returns: 1

In this case, A = "X", B = "XY", C = "X". The longest possible string that satisfies conditions from the statement is "X". Thus, the answer is 1.

1)
{"ABCXD"}
{"BCDEF"}
{"CD"}

Returns: 3

The longest possible string in this case is "BCD".

2)
{"WE", "LOVE"}
{"WORKING", "FOR", "SANTA"}
{"JK"}

Returns: 0

No string satisfies all criteria in this case. Thus, the answer is 0.

3)
{"ABCDE"}
{"CDEAB"}
{"B"}

Returns: 2



4)
{"ABCABDEGAXAHDJBAAHFJDXBB", "ABHFHCDALFDJDBBA", "BABBAXAXXX"}
{"ABLOCBAXBAHAJDXBIJKA", "JBABCDAHKFIUDALPJAH", "AABACX"}
{"AXBADXBBAB", "CDD"}

Returns: 23



*/

// END CUT HERE
