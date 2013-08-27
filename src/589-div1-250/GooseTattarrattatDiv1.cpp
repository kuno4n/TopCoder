
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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 


    const int MAX_N = 1000;
	int par[MAX_N];  //e
	int rank_[MAX_N]; //–Ø‚Ì[‚³
    
	// n—v‘f‚Å‰Šú‰»
	void init(int n){
        REP(i, n){
			par[i] = i;
            rank_[i] = 0;
		}
	}
	//–Ø‚Ìª‚ð‹‚ß‚é
	int find(int x){
		if(par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	//x‚Æy‚Ì‘®‚·‚éW‡‚ðŒ‹‡
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rank_[x] < rank_[y]) par[x] = y;
		else{
			par[y] = x;
			if(rank_[x] == rank_[y]) rank_[x]++;
		}
	}
	//x‚Æy‚ª“¯‚¶W‡‚É‘®‚·‚é‚©
	bool same(int x, int y){
		return find(x) == find(y);
	}


class GooseTattarrattatDiv1 {
public:
   int getmin( string S ) {
	int cnt[30];
	MSET(cnt, 0);
	int n = SZ(S);
	
	REP(i, n) cnt[S[i]-'a']++;
	
	init(26);
	for(int i = 0, j = n-1; i < j; i++, j--) if(S[i] != S[j]) unite(S[i]-'a', S[j]-'a');
	
	VI v[26];
	REP(i, 26) v[find(i)].PB(i);
	
	int res = 0;
	REP(i, 26){
		int sum = 0;
		int mx = 0;
		REP(j, SZ(v[i])) sum += cnt[v[i][j]], chmax(mx, cnt[v[i][j]]);
		res += sum - mx;
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
			string S                  = "geese";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "tattarrattat";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "xyyzzzxxx";
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag";
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "abaabb";
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			string S                  = "aaabbccccb";
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 6: {
			string S                  = "clqnblvnxhbiprzcrd";
			// clqnblvnx
			// drczrpibh
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 7: {
			string S                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = GooseTattarrattatDiv1().getmin(S);
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
// Goose Tattarrattat has a string S of lowercase letters.
Tattarrattat wants to change her string into a palindrome: a string that reads the same forwards and backwards.
(For example, "racecar" is a palindrome.)

She will do this in a series of steps.
In each step, Tattarrattat will choose two letters of the alphabet: X and Y.
She will then change each X in her string into a Y.
Changing each single character takes 1 second.

For example, if S="goose" and Tattarrattat chooses X='o' and Y='e' in the next step, the step will take 2 seconds (because there are two 'o's in S) and after the step she would have S="geese".

You are given the string S.
Return the smallest number of seconds in which Tattarrattat can change S into a palindrome.

DEFINITION
Class:GooseTattarrattatDiv1
Method:getmin
Parameters:string
Returns:int
Method signature:int getmin(string S)


NOTES
-Tattarrattat must always change all occurrences of the chosen letter into the other one; she is not allowed to change only some of the occurrences.


CONSTRAINTS
-S will contain between 1 and 50 characters, inclusive.
-Each character in S will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"geese"

Returns: 2

There are many ways how Tattarrattat can change this S into a palindrome.
For example, she could do it in two steps as follows:

Change all 'g's to 'e's: this takes 1 second and produces the string "eeese".
Change all 'e's to 's's: this takes 4 seconds and produces the string "sssss".

This way took her 1+4 = 5 seconds.
However, there are faster ways.
The best one only takes 2 seconds.
For example, she can first change all 'g's to 'e's (1 second), and then change all 's's to 'e's (1 second), obtaining the palindrome "eeeee".

1)
"tattarrattat"

Returns: 0

This string is already a palindrome so no changes are needed.

2)
"xyyzzzxxx"

Returns: 2



3)
"xrepayuyubctwtykrauccnquqfuqvccuaakylwlcjuyhyammag"

Returns: 11



4)
"abaabb"

Returns: 3



*/

// END CUT HERE
