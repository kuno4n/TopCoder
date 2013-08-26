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

const int MOD = 1000000007;

string f(string A, string B, string C, string S){
    return A + S + B + S + C;
}

int cnt(string S, string F){
    int res = 0;
    REP(i, SZ(S)) if(S.substr(i, SZ(F)) == F) res++;
    return res;
}


class AkariDaisukiDiv1 {
	public:
	int countF(string A, string B, string C, string S, string F, int k) {
		LL res[70]; MSET(res, 0);
        int turn;
        for(turn = 1; SZ(S) < 60; turn++){
            S = f(A, B, C, S);
            res[turn] = cnt(S, F);
        }
        string ST = S.substr(0, 55);
        string ED = S.substr(SZ(S)-55, 55);
        int d;
        for(; turn < 70; turn++){
            d = 0;
            
            string A_ST = A + ST;
            string ED_B_ST = ED + B + ST;
            string ED_C = ED + C;
            
            for(int i = 0; i < SZ(A); i++)
                if(A_ST.substr(i, SZ(F)) == F) d++;
            for(int i = 55-SZ(F)+1; i < 55+SZ(B); i++)
                if(ED_B_ST.substr(i, SZ(F)) == F) d++;
            for(int i = 55-SZ(F)+1; i < 55+SZ(C)-SZ(F)+1; i++)
                if(ED_C.substr(i, SZ(F)) == F) d++;
            res[turn] = (res[turn-1]*2 + d) % MOD;
            
            ST = A+ST;
            ST = ST.substr(0, 55);
            ED = ED+C;
            ED = ED.substr(SZ(ED)-55, 55);
        }
        if(k < 70) return res[k];
        LL c = res[69];
        for(; turn <= k; turn++) c = (c*2 + d) % MOD;
        return c;
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
			string Waai               = "a";
			string Akari              = "b";
			string Daisuki            = "c";
			string S                  = "x";
			string F                  = "axb";
			int k                     = 2;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string Waai               = "a";
			string Akari              = "b";
			string Daisuki            = "c";
			string S                  = "x";
			string F                  = "abcdefghij";
			int k                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string Waai               = "a";
			string Akari              = "a";
			string Daisuki            = "a";
			string S                  = "b";
			string F                  = "aba";
			int k                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string Waai               = "a";
			string Akari              = "b";
			string Daisuki            = "c";
			string S                  = "d";
			string F                  = "baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba";
			int k                     = 58;
			int expected__            = 191690599;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string Waai               = "a";
			string Akari              = "x";
			string Daisuki            = "y";
			string S                  = "b";
			string F                  = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
			int k                     = 49;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string Waai               = "waai";
			string Akari              = "akari";
			string Daisuki            = "daisuki";
			string S                  = "usushio";
			string F                  = "id";
			int k                     = 10000000;
			int expected__            = 127859200;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string Waai               = "vfsebgjfyfgerkqlr";
			string Akari              = "ezbiwls";
			string Daisuki            = "kjerx";
			string S                  = "jbmjvaawoxycfndukrjfg";
			string F                  = "bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs";
			int k                     = 1575724;
			int expected__            = 483599313;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

                
            case 7: {
                string Waai               = "a";
                string Akari              = "b";
                string Daisuki            = "c";
                string S                  = "x";
                string F                  = "cccbaaa";
                int k                     = 4;
                int expected__            = 1;
                
                clock_t start__           = clock();
                int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
            case 8: {
                string Waai               = "a";
                string Akari              = "b";
                string Daisuki            = "c";
                string S                  = "x";
                string F                  = "cccbaaa";
                int k                     = 5;
                int expected__            = 3;
                
                clock_t start__           = clock();
                int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }
/*      case 8: {
			string Waai               = ;
			string Akari              = ;
			string Daisuki            = ;
			string S                  = ;
			string F                  = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string Waai               = ;
			string Akari              = ;
			string Daisuki            = ;
			string S                  = ;
			string F                  = ;
			int k                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = AkariDaisukiDiv1().countF(Waai, Akari, Daisuki, S, F, k);
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
Consider the following function:
f(X) = Waai + X + Akari + X + Daisuki
Here, X is a string and + denotes string concatenation.
Waai, Akari and Daisuki are constant non-empty strings.



You are given 5 strings Waai, Akari, Daisuki, S and F, and a  int k. 
Compute how many times F occurs in f^k(S) as its substring. (The notation f^k(S) means that f is applied to S exactly k times in a row. See Notes for a formal definition.) Since the number can be quite large, compute the number modulo 1,000,000,007.


DEFINITION
Class:AkariDaisukiDiv1
Method:countF
Parameters:string, string, string, string, string, int
Returns:int
Method signature:int countF(string Waai, string Akari, string Daisuki, string S, string F, int k)


NOTES
-Formally, we have f^1(X)=f(X) and for k greater than one we have f^k(X)=f(f^(k-1)(X)).
-String A is substring of B if A can be obtained by erasing some (possibly zero) characters from the beginning of B and some (possibly zero) characters from the end of B.


CONSTRAINTS
-Waai, Akari, Daisuki, S, and F will contain between 1 and 50 characters, inclusive.
-Each character of Waai, Akari, Daisuki, S, and F will be a lowercase letter ('a'-'z').
-k will be between 1 and 10,000,000, inclusive.


EXAMPLES

0)
"a"
"b"
"c"
"x"
"axb"
2

Returns: 2

S = "x",
f(S) = "axbxc",
f^2(S) = f("axbxc") = "aaxbxcbaxbxcc".
This string contains the substring "axb" twice.

1)
"a"
"b"
"c"
"x"
"abcdefghij"
1

Returns: 0

The answer can be zero.

2)
"a"
"a"
"a"
"b"
"aba"
2

Returns: 4

S = "b",
f(S) = "ababa",
f^2(S) = f("ababa") = "aababaaababaa".
This string contains the substring "aba" four times. You must count overlapping substrings.

3)
"a"
"b"
"c"
"d"
"baadbdcbadbdccccbaaaadbdcbadbdccbaadbdcba"
58

Returns: 191690599



4)
"a"
"x"
"y"
"b"
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
49

Returns: 1



5)
"waai"
"akari"
"daisuki"
"usushio"
"id"
10000000

Returns: 127859200



6)
"vfsebgjfyfgerkqlr"
"ezbiwls"
"kjerx"
"jbmjvaawoxycfndukrjfg"
"bgjfyfgerkqlrvfsebgjfyfgerkqlrvfsebgjfyfgerkqlrvfs"
1575724

Returns: 483599313

*/

// END CUT HERE
