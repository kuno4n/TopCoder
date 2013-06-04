
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

bool OK(string s, int k){
	int n= SZ(s);
	int num;
	for(int i=1; i<=n; i++){
		if(n%i) continue;
		int len = n/i;
		bool ok = true;
		for(int ii = len; ii < n; ii += len){
			REP(j, len) if(s[ii+j] != s[ii+j-len]) ok = false;
		}
		if(ok) num = i;
	}
	if(num == k) return true;
	else return false;
}

class MagicWords {
public:
   int count( vector <string> S, int K ) {
	int res = 0;
	REP(i, SZ(S)) S[i] += '0'+i;
	sort(ALL(S));
	do{
		string s;
		REP(i, SZ(S)) s += S[i].substr(0, SZ(S[i])-1);
		if(OK(s, K)) res++;
	}while(next_permutation(ALL(S)));
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
			string S[]                = {"CAD","ABRA","ABRA"};
			int K                     = 1;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S[]                = {"AB","RAAB","RA"};
			int K                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S[]                = {"AA","AA","AAA","A"};
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S[]                = {"AA","AA","AAA","A","AAA","AAAA"};
			int K                     = 15;
			int expected__            = 720;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S[]                = {"ABC","AB","ABC","CA"};
			int K                     = 3;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S[]                = {"A","B","C","A","B","C"};
			int K                     = 1;
			int expected__            = 672;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string S[]                = {"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAB"};
			int K                     = 1;
			int expected__            = 40320;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string S[]                = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S[]                = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string S[]                = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MagicWords().count(vector <string>(S, S + (sizeof S / sizeof S[0])), K);
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
// Consider a string T containing exactly L characters.  The string T(i) is a cyclic shift of T starting from position i (0 <= i < L).  T(i) contains exactly the same number of characters as T.  For each j between 0 and L-1, inclusive, character j of T(i) is equal to character (i+j)%L of T.  Let's call T a magic word if there are exactly K positions i such that T(i) = T.

You are given a vector <string> S containing exactly N words.  For each permutation p = (p[0], p[1], ..., p[N-1]) of integers between 0 and N-1, inclusive, we can define a string generated by this permutation as a concatenation S[p[0]] + S[p[1]] + ... + S[p[N-1]].  Return the number of permutations that generate magic words.  All indices in this problem as 0-based.


DEFINITION
Class:MagicWords
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> S, int K)


CONSTRAINTS
-S will contain between 1 and 8 elements, inclusive.
-Each element of S will contain between 1 and 20 characters, inclusive.
-Each element of S will contain only uppercase letters ('A'-'Z').
-K will be between 1 and 200, inclusive.


EXAMPLES

0)
{"CAD","ABRA","ABRA"}
1

Returns: 6

Every permutation generates a magic word here.

1)
{"AB","RAAB","RA"}
2

Returns: 3

The magic words are "ABRAABRA" and "RAABRAAB". The first word is generated only by the permutation (0, 1, 2), and the second word is generated by the two permutations (1, 2, 0) and (2, 0, 1).

2)
{"AA","AA","AAA","A"}
1

Returns: 0

All permutations generate the string "AAAAAAAA" and it clearly is not a magic word because all its cyclic shifts are the same as the original string.

3)
{"AA","AA","AAA","A","AAA","AAAA"}
15

Returns: 720

4)
{"ABC","AB","ABC","CA"}
3

Returns: 0



5)
{"A","B","C","A","B","C"}
1

Returns: 672



6)
{"AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAA",
 "AAAAAAAAAAAAAAAAAAAB"}
1

Returns: 40320



*/

// END CUT HERE
