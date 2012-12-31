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

bool isPrime(long long l){
    if(l < 2) return false;
    for(LL i=2; i*i<=l; i++)
        if(l%i == 0 )
            return false;
    return true;
}

string c, s;

class ColorfulCards {
	public:
	vector <int> theCards(int N, string colors) {
		s = "", c = colors;
        FOR(i, 1, N+1) if(isPrime(i)) s+='R'; else s+='B';
        
        int minPossible[SZ(colors)];
        int maxPossible[SZ(colors)];
        
        int ptr = 0;
        REP(i, SZ(colors)){
            while(colors[i] != s[ptr]) ptr++;
            minPossible[i] = ++ptr;
        }
        
        ptr = SZ(s)-1;
        for(int i=SZ(colors)-1; i>=0; i--){
            while(colors[i] != s[ptr]) ptr--;
            maxPossible[i] = ptr+1;
            ptr--;
        }
        
        VI res(SZ(colors));
        REP(i, SZ(colors)) {
            if(minPossible[i] == maxPossible[i]) res[i] = minPossible[i];
            else res[i] = -1;
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
			int N                     = 5;
			string colors             = "RRR";
			int expected__[]          = {2, 3, 5 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 7;
			string colors             = "BBB";
			int expected__[]          = {1, 4, 6 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 6;
			string colors             = "RBR";
			int expected__[]          = {-1, 4, 5 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 58;
			string colors             = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
			int expected__[]          = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int N                     = 495;
			string colors             = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
			int expected__[]          = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			string colors             = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = ColorfulCards().theCards(N, colors);
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
// Rabbit Hanako has N cards numbered 1 through N. Each card's number is written on its front side. The back side of each card is colored red if the number is prime, and blue if it is not prime.


Cat Taro has chosen a subset of these cards and arranged them face down in a row. The cards are sorted in increasing order from left to right. He wants Hanako to guess the numbers written on the cards. Hanako can only see the colored back side of each card. You are given a string colors, where the i-th character is 'R' if the i-th card from the left is red, and 'B' if it is blue.


Return a vector <int> containing exactly K elements, where K is the number of characters in colors. The i-th element of the return must be the number written on the i-th card if it can be uniquely determined. Otherwise, the i-th element must be -1. It is guaranteed that there exists at least one sequence that matches colors.


DEFINITION
Class:ColorfulCards
Method:theCards
Parameters:int, string
Returns:vector <int>
Method signature:vector <int> theCards(int N, string colors)


NOTES
-A positive integer number is called prime if it has exactly two divisors, 1 and itself. By convention, 1 is not considered to be a prime number.


CONSTRAINTS
-N will be between 1 and 1,000, inclusive.
-colors will contain between 1 and 50 characters, inclusive.
-Each character in colors will be 'R' or 'B'.
-There will exist at least one sequence that matches colors.


EXAMPLES

0)
5
"RRR"

Returns: {2, 3, 5 }

The numbers written on these cards are primes less than or equal to 5, so the only possibility is {2, 3, 5}.


1)
7
"BBB"

Returns: {1, 4, 6 }

The numbers written on these cards are not primes less than or equal to 7, so the only possibility is {1, 4, 6}.


2)
6
"RBR"

Returns: {-1, 4, 5 }

There are two possibilities:
{2, 4, 5}
{3, 4, 5}


3)
58
"RBRRBRBBRBRRBBRRBBBRRBBBRR"

Returns: {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 }



4)
495
"RBRRBRBBRBRRBBRRBBBRRBBBRR"

Returns: {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }



*/

// END CUT HERE
