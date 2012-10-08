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


string _10to2(long long l){
    if (l == 0) return "0";
    string res = "";
    while(l != 1){
        if ( l & 1 ) res = '1' + res;
        else res = '0' + res;
        l >>= 1;
    }
    return '1' + res;
}

class NumberMagicEasy {
	public:
	int theNumber(string answer) {
		LL card[5] = {0, 0, 0, 0, 0};
        card[1] += 1<<1;
        card[1] += 1<<2;
        card[1] += 1<<3;
        card[1] += 1<<4;
        card[1] += 1<<5;
        card[1] += 1<<6;
        card[1] += 1<<7;
        card[1] += 1<<8;
        card[2] += 1<<1;
        card[2] += 1<<2;
        card[2] += 1<<3;
        card[2] += 1<<4;
        card[2] += 1<<9;
        card[2] += 1<<10;
        card[2] += 1<<11;
        card[2] += 1<<12;
        card[3] += 1<<1;
        card[3] += 1<<2;
        card[3] += 1<<5;
        card[3] += 1<<6;
        card[3] += 1<<9;
        card[3] += 1<<10;
        card[3] += 1<<13;
        card[3] += 1<<14;
        card[4] += 1<<1;
        card[4] += 1<<3;
        card[4] += 1<<5;
        card[4] += 1<<7;
        card[4] += 1<<9;
        card[4] += 1<<11;
        card[4] += 1<<13;
        card[4] += 1<<15;
        
        
        
        
        
        LL tmp=((1<<16) -1);
        tmp--;
        for(int i=1; i<=4; i++){
            if(answer[i-1] == 'Y') tmp &= card[i];
            if(answer[i-1] == 'N') tmp &= ~card[i];
        }
        for(int i=1; i<=16; i++){
            if(tmp == 1<<i) return i;
        }
        return 16;
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
			string answer             = "YNYY";
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string answer             = "YNNN";
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string answer             = "NNNN";
			int expected__            = 16;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string answer             = "YYYY";
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string answer             = "NYNY";
			int expected__            = 11;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string answer             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string answer             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string answer             = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = NumberMagicEasy().theNumber(answer);
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
// NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.


Taro shows a magic trick to Hanako.



Taro: Hello Hanako. I'll show you a magic trick. Please imagine a positive integer less than or equal to 16.
Hanako: OK. I imagined it.
Taro: (Taro shows card 1 to Hanako.) Does this card contain your number?
Hanako: Yes.
Taro: (Taro shows card 2 to Hanako.) Does this card contain your number?
Hanako: No.
Taro: (Taro shows card 3 to Hanako.) Does this card contain your number?
Hanako: Yes.
Taro: (Taro shows card 4 to Hanako.) Does this card contain your number?
Hanako: Yes.
Taro: Your number is 5!




(Card 1 contains 1, 2, 3, 4, 5, 6, 7 and 8. Card 2 contains 1, 2, 3, 4, 9, 10, 11 and 12. Card 3 contains 1, 2, 5, 6, 9, 10, 13 and 14. Card 4 contains 1, 3, 5, 7, 9, 11, 13 and 15.)


Your task is to write a program that simulates this magic trick. You are given Hanako's answers in the string answer. The i-th character is 'Y' if she answered "yes" to the i-th question, and 'N' if she answered "no" to the i-th question. Return the integer Hanako imagined.

DEFINITION
Class:NumberMagicEasy
Method:theNumber
Parameters:string
Returns:int
Method signature:int theNumber(string answer)


CONSTRAINTS
-answer will contain exactly 4 characters.
-Each character in answer will be 'Y' or 'N'.


EXAMPLES

0)
"YNYY"

Returns: 5

The example from the statement.

1)
"YNNN"

Returns: 8

8 is the only number that exists on the first card and does not exist on any other cards.

2)
"NNNN"

Returns: 16



3)
"YYYY"

Returns: 1



4)
"NYNY"

Returns: 11



*/

// END CUT HERE
