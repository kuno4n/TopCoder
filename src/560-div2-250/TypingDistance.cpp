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

class TypingDistance {
	public:
	int minDistance(string keyboard, string word) {
		map<char, int> m;
        REP(i, SZ(keyboard)) m[keyboard[i]] = i;
        
        int res = 0;
        for(int i=1; i<SZ(word); i++){
            res += abs(m[word[i]] - m[word[i-1]]);
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
			string keyboard           = "qwertyuiop";
			string word               = "potter";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string keyboard           = "tc";
			string word               = "tctcttccctccccttc";
			int expected__            = 9;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string keyboard           = "a";
			string word               = "aaaaaaaaaaa";
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string keyboard           = "kwadrutove";
			string word               = "rowerowe";
			int expected__            = 39;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string keyboard           = "qwertyuiopasdfghjklzxcvbnm";
			string word               = "topcodersingleroundmatchgoodluckhavefun";
			int expected__            = 322;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string keyboard           = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string keyboard           = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string keyboard           = ;
			string word               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TypingDistance().minDistance(keyboard, word);
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
Jakub is trying out a one-dimensional keyboard.
It consists of a single row of keys. 
The distance between any two adjacent keys is 1.
Each key contains a distinct letter of the English alphabet.
Jakub uses only one finger to type on the keyboard.
He wonders what is the smallest total distance he will have to move his finger while typing a given word.



For example, if the keyboard's only row is "qwertyuiop", and Jakub wants to type the word "potter", he will have to move his finger from 'p' to 'o' (distance 1), from 'o' to 't' (distance 4), from 't' to 't' (distance 0), from 't' to 'e' (distance 2) and from 'e' to 'r' (distance 1), for a total distance of 1 + 4 + 0 + 2 + 1 = 8.



You are given a string keyboard and a string word, describing the keyboard and the word Jakub wants to write. Return the minimum distance he will have to move his finger in order to type the word on the keyboard.


DEFINITION
Class:TypingDistance
Method:minDistance
Parameters:string, string
Returns:int
Method signature:int minDistance(string keyboard, string word)


NOTES
-When moving the finger from the i-th key to the j-th key, the distance covered by the move can be computed as |i-j|, that is, the positive difference between i and j.


CONSTRAINTS
-keyboard will contain between 1 and 26 characters, inclusive.
-Each character in keyboard will be a different lowercase letter of the English alphabet ('a'-'z').
-word will contain between 1 and 50 characters, inclusive.
-Each character in word will be present in keyboard.


EXAMPLES

0)
"qwertyuiop"
"potter"

Returns: 8

The example from the problem statement.

1)
"tc"
"tctcttccctccccttc"

Returns: 9



2)
"a"
"aaaaaaaaaaa"

Returns: 0



3)
"kwadrutove"
"rowerowe"

Returns: 39



4)
"qwertyuiopasdfghjklzxcvbnm"
"topcodersingleroundmatchgoodluckhavefun"

Returns: 322



*/

// END CUT HERE
