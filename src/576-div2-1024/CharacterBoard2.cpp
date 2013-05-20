
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
#include <numeric>
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

LL MOD = 1000000009LL;

//LL cnt(vector <string> vs){
//	LL res = 1;
//	REP(c, SZ(vs[0])){
//		char ch = '?';
//		REP(r, SZ(vs)){
//			if(vs[r][c] != '?'){
//				if(ch != '?' && ch != vs[r][c]) return 0;
//				ch = vs[r][c];
//			}
//		}
//		if(ch == '?') res *= 26;
//		res %= MOD;
//	}
//	return res;
//}

long long modPow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = (r*a) % MOD;
        a = (a*a) % MOD;
        y /= 2;
    }
    return r;
}

string s;

class CharacterBoard2 {
public:
   int countGenerators( vector <string> fragment, int W, int i0, int j0 ) {
	
	LL res = 0;
	for(int len = 1; len <= W; len++){
		LL tmp = 1;
		map <int, char> m;
		REP(i, SZ(fragment)) REP(j, SZ(fragment[0])){
			int idx = ((LL)W*(i0+i) + j0 + j) % len;
			if(m.count(idx)){
				if(m[idx] != fragment[i][j]) tmp = 0;
			}
			else{
				m[idx] = fragment[i][j];
			}
		}
		tmp = (tmp * modPow(26, len-SZ(m))) % MOD;
		res = (res + tmp) % MOD;
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
			string fragment[]         = {"dea",
 "abc"};
			int W                     = 7;
			int i0                    = 1;
			int j0                    = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string fragment[]         = {"xyxxy"};
			int W                     = 6;
			int i0                    = 1;
			int j0                    = 0;
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string fragment[]         = {"gogogo",
 "jijiji",
 "rarara"};
			int W                     = 6;
			int i0                    = 0;
			int j0                    = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string fragment[]         = {"abababacac",
 "aaacacacbb",
 "ccabababab"};
			int W                     = 882;
			int i0                    = 10;
			int j0                    = 62;
			int expected__            = 361706985;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string fragment[]         = {"asjkffqw",
 "basjkffq",
 "qbasjkff",
 "qqbasjkf"};
			int W                     = 9031;
			int i0                    = 9024;
			int j0                    = 1959;
			int expected__            = 173947456;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string fragment[]         = ;
			int W                     = ;
			int i0                    = ;
			int j0                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string fragment[]         = ;
			int W                     = ;
			int i0                    = ;
			int j0                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string fragment[]         = ;
			int W                     = ;
			int i0                    = ;
			int j0                    = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = CharacterBoard2().countGenerators(vector <string>(fragment, fragment + (sizeof fragment / sizeof fragment[0])), W, i0, j0);
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
// Manao has a matrix X with 10,000 rows and W columns. He likes to fill it with characters; he even has developed an algorithm for this task. First, he chooses a string S consisting of at most W lowercase letters. The string S is called the generator. Then, he applies the algorithm described by the following pseudocode:

cur := 0
for i := 0 to 9999
  for j := 0 to W - 1
    X[i][j] := S.charAt(cur)
    cur := (cur + 1) mod length(S)


Manao has recently found a matrix X in his notepad.
He wonders whether it was generated using the above algorithm.
You are given:

a vector <string> fragment that contains a rectangular submatrix of X,
the int W: the width of X,
and two ints i0 and j0: the coordinates of the upper left corner of your submatrix within X.

In other words, for all valid i, j we have fragment[i][j] = X[i + i0][j + j0].
Count how many different generators Manao could have used to create a matrix X that contains the fragment you were given.
Return this number modulo 1,000,000,009.

DEFINITION
Class:CharacterBoard2
Method:countGenerators
Parameters:vector <string>, int, int, int
Returns:int
Method signature:int countGenerators(vector <string> fragment, int W, int i0, int j0)


CONSTRAINTS
-fragment will contain N elements, where N is between 1 and 10, inclusive.
-Each element of fragment will be M characters long, where M is between 1 and 10, inclusive.
-Each element of fragment will consist of lowercase letters ('a'-'z') only.
-W will be between M and 10,000, inclusive.
-i0 will be between 0 and 10,000 - N, inclusive.
-j0 will be between 0 and W - M, inclusive.


EXAMPLES

0)
{"dea",
 "abc"}
7
1
1

Returns: 1

Manao has a matrix with 10000 rows and 7 columns. We know that it looks as follows:


???????
?dea???
?abc???
???????
...


The only string of length at most 7 which could generate such matrix is "abcde".

1)
{"xyxxy"}
6
1
0

Returns: 28

The given information is:

??????
xyxxy?
??????
...


The corresponding generator could be "xyx", "yxyxx", or a string of form "xyxxy?", where '?' stands for any lowercase letter.

2)
{"gogogo",
 "jijiji",
 "rarara"}
6
0
0

Returns: 0

No generator could create this matrix using the given algorithm.

3)
{"abababacac",
 "aaacacacbb",
 "ccabababab"}
882
10
62

Returns: 361706985



4)
{"asjkffqw",
 "basjkffq",
 "qbasjkff",
 "qqbasjkf"}
9031
9024
1959

Returns: 173947456



*/

// END CUT HERE
