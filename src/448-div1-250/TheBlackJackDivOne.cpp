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

double res;
int c[14];

void dfs(int sum, int addnum, int remainnum, double p){
    if(sum >= 21){
        res += addnum * p;
        return;
    }
    for(int i = 1; i <= 13; i++){
        if(c[i] == 0) continue;
        c[i]--;
        int sumtmp = sum;
        if(i == 1) sumtmp += 11;
        else if(i >= 2 && i <= 9) sumtmp += i;
        else sumtmp += 10;
        dfs(sumtmp, addnum+1, remainnum-1, p * (double)(c[i]+1)/remainnum);
        c[i]++;
    }
    return;
}

class TheBlackJackDivOne {
	public:
	double expected(vector <string> cards) {
        int sum = 0;
        res = 0.0;
        for(int i = 1; i <= 13; i++) c[i] = 4;
        REP(i, SZ(cards)){
            if(cards[i][0] >= '2' && cards[i][0] <= '9') {
                sum += cards[i][0] - '0';
                c[cards[i][0]-'0']--;
            }
            else if(cards[i][0] == 'A'){
                sum += 11;
                c[1]--;
            }
            else if(cards[i][0] == 'T'){
                sum += 10;
                c[10]--;
            }
            else if(cards[i][0] == 'J'){
                sum += 10;
                c[11]--;
            }
            else if(cards[i][0] == 'Q'){
                sum += 10;
                c[12]--;
            }
            else if(cards[i][0] == 'K'){
                sum += 10;
                c[13]--;
            }
        }
		int remainnum = 52 - SZ(cards);
        dfs(sum, 0, remainnum, 1.0);
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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string cards[]            = {"JS"};
			double expected__         = 2.105854341736695;

			clock_t start__           = clock();
			double received__         = TheBlackJackDivOne().expected(vector <string>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string cards[]            = {"KD", "8S"};
			double expected__         = 1.08;

			clock_t start__           = clock();
			double received__         = TheBlackJackDivOne().expected(vector <string>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string cards[]            = {"KD", "2S", "2C", "2D", "2H"};
			double expected__         = 1.0;

			clock_t start__           = clock();
			double received__         = TheBlackJackDivOne().expected(vector <string>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string cards[]            = {"AS", "KS", "9S", "JC", "2D"};
			double expected__         = 0.0;

			clock_t start__           = clock();
			double received__         = TheBlackJackDivOne().expected(vector <string>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string cards[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheBlackJackDivOne().expected(vector <string>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string cards[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheBlackJackDivOne().expected(vector <string>(cards, cards + (sizeof cards / sizeof cards[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string cards[]            = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheBlackJackDivOne().expected(vector <string>(cards, cards + (sizeof cards / sizeof cards[0])));
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
John and Brus are training for a card game tournament.
There they will be playing Black Jack.
Black Jack is played using a standard deck containing 52 distinct cards.
Each card can be represented as a two-character string where the first character is the rank ('2' - '9' for ranks Two through Nine, 'T' for Ten, 'J' for Jack, 'Q' for Queen, 'K' for King and 'A' for Ace) and the second character is the suit ('S' for Spades, 'C' for Clubs, 'D' for Diamonds and 'H' for Hearts).
For example, the Jack of Spades can be represented as "JS" and the Nine of Hearts as "9H".



Each time a player receives a card from the deck, his score increases by the card's value.
Ranks Two through Ten have values of 2 - 10, respectively.
Jacks, Queens and Kings each have a value of 10, and Aces have a value of 11.



Brus randomly shuffles the full card deck and gives John one or more cards from the top of the deck.
You are given a vector <string> cards, where each element represents a single card given to John in this initial step.
John will then take extra cards from the top of the deck, one by one, until his score is greater than or equal to 21.
Return the expected number of extra cards that John will take.



DEFINITION
Class:TheBlackJackDivOne
Method:expected
Parameters:vector <string>
Returns:double
Method signature:double expected(vector <string> cards)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-cards will contain between 1 and 50 elements, inclusive.
-Each element of cards will contain exactly two characters, where the first character is '2'-'9', 'T', 'J', 'Q', 'K' or 'A', and the second character is 'S', 'C', 'D' or 'H'.
-All elements of cards will be distinct.


EXAMPLES

0)
{"JS"}

Returns: 2.105854341736695



1)
{"KD", "8S"}

Returns: 1.08

John will take the second extra card only if the first one is Two.

2)
{"KD", "2S", "2C", "2D", "2H"}

Returns: 1.0

The same situation, but here there are no Twos left in the deck.

3)
{"AS", "KS", "9S", "JC", "2D"}

Returns: 0.0

Here John's score is already more than 21.

*/

// END CUT HERE
