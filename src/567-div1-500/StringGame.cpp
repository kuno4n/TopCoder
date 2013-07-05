
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

class StringGame {
public:
   vector <int> getWinningStrings( vector <string> S ) {
	int n = SZ(S), m = SZ(S[0]);
	int have[n][30]; MSET(have, 0);
	REP(i, n) REP(j, m) have[i][S[i][j]-'a']++;
	
	VI res;
	REP(i, n){
		bool win[n]; REP(j, n) win[j] = false; win[i] = true;
		REP(cnt, n){
			REP(j, 26){
				bool ok = true;
				REP(k, n) if(!win[k]) ok &= (have[i][j] >= have[k][j]);
				if(ok) REP(k, n) if(have[i][j] > have[k][j]) win[k] = true;
			}
		}
		bool ok = true;
		REP(j, n) ok &= win[j];
		if(ok) res.push_back(i);
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			string S[]                = {"a", "b", "c", "d"};
			int expected__[]          = {0, 1, 2, 3 };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings(vector <string>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string S[]                = {"aabbcc", "aaabbb", "aaaccc"};
			int expected__[]          = {1, 2 };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings(vector <string>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string S[]                = {"ab", "ba"};
			int expected__[]          = { };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings(vector <string>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string S[]                = {"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"};
			int expected__[]          = {1, 3, 4 };

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings(vector <string>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string S[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings(vector <string>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 5: {
			string S[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings(vector <string>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string S[]                = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = StringGame().getWinningStrings(vector <string>(S, S + (sizeof S / sizeof S[0])));
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// Manao has invented a new unusual two-player game which he calls the String Game. The game is played on a set of strings of the same length comprised of lowercase English letters.

In the beginning, the first player chooses a string X from the set and permutes its characters in any way he wants. He also chooses a permutation of the English alphabet. After that, the second player may permute the characters in each of the strings in the set, except for X. Now X is lexicographically compared to each of the other strings in the set using the permuted English alphabet. If X is strictly smaller than each of the other strings, the first player wins. Otherwise, the second player does.

In order to compare two different strings A and B, first it is necessary to find the first position at which these strings differ. Let the characters at this position in A and B be a and b. If a stands earlier than b in the permuted alphabet, then A is lexicographically smaller than B, otherwise B is lexicographically smaller than A. For example, with alphabet {b, a, c, d, ..., z}, the string "aba" is lexicographically smaller than the string "aab" because 'b' stands earlier than 'a' in the alphabet.

You are given a vector <string> S, the set of strings on which the String Game is played. Determine all strings which, when chosen by the first player, allow him to win if both he and his opponent play optimally. That is, the first player always permutes the string X and the alphabet optimally, and then the second player permutes all the other strings optimally. Return a vector <int> containing the sorted list of all 0-based indices of all such strings.

DEFINITION
Class:StringGame
Method:getWinningStrings
Parameters:vector <string>
Returns:vector <int>
Method signature:vector <int> getWinningStrings(vector <string> S)


NOTES
-The return value may sometimes be an empty vector <int>.


CONSTRAINTS
-S will contain between 2 and 50 elements, inclusive.
-Each element of S will be between 1 and 50 characters long, inclusive.
-All elements of S will be of equal length.
-Each element of S will consist of lowercase letters ('a'-'z') only.
-The elements of S will be distinct.


EXAMPLES

0)
{"a", "b", "c", "d"}

Returns: {0, 1, 2, 3 }

For each of the given strings, Manao can choose the alphabet which begins with the string's only character and his string will be lexicographically smallest.

1)
{"aabbcc", "aaabbb", "aaaccc"}

Returns: {1, 2 }

Manao can win if he chooses the string "aaabbb" or "aaaccc". For "aaabbb", he can choose permutation of the alphabet {b, a, c, ..., z} and make his string "bbbaaa". For "aaaccc", the permutation can be {c, a, b, d, ..., z} and the string itself can be "cccaaa". In both cases, regardless of which permutations the opponent chooses, the two other strings will always be lexicographically larger than Manao's string.

2)
{"ab", "ba"}

Returns: { }

Note that the first player's string should be strictly smaller than the opponent's strings.

3)
{"xaocxsss", "oooxsoas", "xaooosss", "xaocssss", "coxaosxx"}

Returns: {1, 3, 4 }



*/

// END CUT HERE
