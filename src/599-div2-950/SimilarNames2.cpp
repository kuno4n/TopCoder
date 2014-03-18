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

//vector <string> names;
//int n;
//int now;
//VI G[55];
const int MOD = 1000000007;
//LL memo[55][55];
//
//void add(LL &a, LL b){
//    a = (a + b) % MOD;
//}
//void mul(LL &a, LL b){
//    a = (a * b) % MOD;
//}
//
long long modFact(int n){
    long long res = 1;
    while(n>1){
        res = (res*n) % MOD;
        n--;
    }
    return res;
}
//
//void maketree(int node){
//    while(now < n){
//        string s1 = names[node];
//        string s2 = names[now];
//        if(s2.substr(0, SZ(s1)) != s1) return;
//        G[node].push_back(now);
//        now++;
//        maketree(now-1);
//    }
//}
//
//void rec(int node){
//    memo[node][0] = memo[node][1] = 1;
//    REP(i, SZ(G[node])){
//        rec(G[node][i]);
//        for(int j = 1; j < 52; j++) {
//            add(memo[node][j], memo[G[node][i]][j]);
//        }
//        for(int j = 2; j < 52; j++) {
//            add(memo[node][j], memo[G[node][i]][j-1]);
//        }
//    }
//}

LL dp[55][55];

class SimilarNames2 {
public:
   int count( vector <string> _names, int L ) {
//       names = _names;
//       names.push_back("");
//       sort(ALL(names));
//       n = SZ(names);
//       now = 1;
//       REP(i, 55) G[i].clear();
//       maketree(0);
//       
//       MSET(memo, 0);
//       rec(0);
//       
//       LL res = 0;
//       REP(i, SZ(G[0])) add(res, memo[G[0][i]][L]);
//       mul(res, modFact(n-1-L));
//       return res;
       
       int n = SZ(_names);
       MSET(dp, 0);
       REP(i, 55) dp[i][1] = 1;
       for(int l = 2; l < 55; l++) REP(i, n) REP(j, n) if(i != j && _names[j].find(_names[i]) == 0) dp[i][l] = ( dp[i][l] + dp[j][l-1]) %  MOD;
       LL res = 0;
       REP(i, n) res = (res + dp[i][L]) % MOD;
       res = (res * modFact(n-L)) % MOD;
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
			string names[]            = {"kenta", "kentaro", "ken"};
			int L                     = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string names[]            = {"hideo", "hideto", "hideki", "hide"};
			int L                     = 2;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string names[]            = {"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"};
			int L                     = 3;
			int expected__            = 24;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string names[]            = {"taro", "jiro", "hanako"};
			int L                     = 2;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string names[]            = {"alice", "bob", "charlie"};
			int L                     = 1;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string names[]            = {"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
 "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"};
			int L                     = 3;
			int expected__            = 276818566;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string names[]            = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string names[]            = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string names[]            = ;
			int L                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = SimilarNames2().count(vector <string>(names, names + (sizeof names / sizeof names[0])), L);
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
// Fox Ciel has a list of names on her computer. In this problem, a name is simply a non-empty string
of lowercase letters. All names in her list are distinct.


One day, when she left her seat, she forgot to lock her computer.
Then, Lun the mischievous dog appeared, and randomly shuffled the order of the names in her list.


Now, Ciel has to restore the original order of names using her memory. You are given a vector <string> names
and an int L. names contains all names in the shuffled list in the order they appear.
L describes Ciel's memory of the original list. She remembers that, for each i between 0 and
L-2, inclusive, the i-th (0-indexed) name in the original list was a prefix of the (i+1)-th name.


Let X be the number of possible orders of the names in the original list that are consistent
with Ciel's memory. Calculate and return the value (X modulo 1,000,000,007). X can be 0, which means
Ciel's memory is inconsistent with the names in the list.

DEFINITION
Class:SimilarNames2
Method:count
Parameters:vector <string>, int
Returns:int
Method signature:int count(vector <string> names, int L)


NOTES
-A prefix of a string is the result of erasing zero or more characters from the right end of that string.


CONSTRAINTS
-names will contain between 2 and 50 elements, inclusive.
-Each element of names will contain between 1 and 50 characters, inclusive.
-Each character of each element of names will be a lowercase letter ('a'-'z').
-Elements of names will be distinct.
-L will be between 1 and n, inclusive, where n is the number of elements in names.


EXAMPLES

0)
{"kenta", "kentaro", "ken"}
2

Returns: 3

Here, Ciel's list contains 3 names. She remembers that the 0-th name was a prefix of the 1-st name in the original list. Here are the all possible orders of names in the original list:

ken, kenta, kentaro
ken, kentaro, kenta
kenta, kentaro, ken

Note that it is possible that the order of the names in the original list coincides with that of the shuffled list.

1)
{"hideo", "hideto", "hideki", "hide"}
2

Returns: 6

Again, she remembers that the 0-th name was a prefix of the 1-st name in the original list. The only thing we can be sure is that the 0-th name was "hide".

2)
{"aya", "saku", "emi", "ayane", "sakura", "emika", "sakurako"}
3

Returns: 24

This time, she remembers not only the fact that the 0-th name was a prefix of the 1-st name, but also the fact that the 1-st name was a prefix of the 2-nd name. The first 3 names should be "saku", "sakura", "sakurako" in this order.

3)
{"taro", "jiro", "hanako"}
2

Returns: 0

No name is a prefix of another name in this case, so her memory is inconsistent.

4)
{"alice", "bob", "charlie"}
1

Returns: 6

L = 1 means that she actually remembers nothing.

5)
{"ryota", "ryohei", "ryotaro", "ryo", "ryoga", "ryoma", "ryoko", "ryosuke", "ciel", "lun",
 "ryuta", "ryuji", "ryuma", "ryujiro", "ryusuke", "ryutaro", "ryu", "ryuhei", "ryuichi", "evima"}
3

Returns: 276818566



*/

// END CUT HERE
