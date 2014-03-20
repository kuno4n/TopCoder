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

class ORSolitaire {
public:
   int getMinimum( vector <int> numbers, int goal ) {
       int n = SZ(numbers);
       int res = 100;
       REP(i, 31) if((1<<i) & goal){
           int cnt = 0;
           REP(j, n) if(((1<<i) & numbers[j]) && (numbers[j] & goal) == numbers[j]) cnt++;
           chmin(res, cnt);
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
			int numbers[]             = {1, 2, 4};
			int goal                  = 7;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int numbers[]             = {1, 2, 4, 7, 8};
			int goal                  = 7;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int numbers[]             = {12571295, 2174218, 2015120};
			int goal                  = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int numbers[]             = {5,2,4,52,62,9,8,3,1,11,6};
			int goal                  = 11;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int numbers[]             = {503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346};
			int goal                  = 510;
			int expected__            = 5;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int numbers[]             = ;
			int goal                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int numbers[]             = ;
			int goal                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int numbers[]             = ;
			int goal                  = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ORSolitaire().getMinimum(vector <int>(numbers, numbers + (sizeof numbers / sizeof numbers[0])), goal);
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
// Note that the memory limit for all tasks in this SRM is 256 MB.
This problem statement contains subscripts that may not display properly if viewed outside of the applet.

Manao is playing a solitaire game called OR-solitaire. In this game, the player starts with a number X = 0 and should obtain the number goal in one or more moves. The set of valid moves is determined by a vector <int> numbers. In each move, the player chooses some element of numbers and replaces X with the bitwise OR of X and the chosen element.

Fox Ciel wants Manao to stop playing OR-solitaire and move on with his life. She decided to erase some of the elements from numbers in such a way that it becomes impossible to complete the game. Return the minimum number of elements that need to be removed to achieve this.

DEFINITION
Class:ORSolitaire
Method:getMinimum
Parameters:vector <int>, int
Returns:int
Method signature:int getMinimum(vector <int> numbers, int goal)


NOTES
-If a and b are single bits then a | b is defined as max(a, b). For two integers, A and B, in order to calculate A | B, they need to be represented in binary: A = (an...a1)2, B = (bn...b1)2 (if the lengths of their representations are different, the shorter one is prepended with the necessary number of leading zeroes). Then A | B = C = (cn...c1)2, where ci = ai | bi. For example, 10 | 3 = (1010)2 | (0011)2 = (1011)2 = 11.


CONSTRAINTS
-numbers will contain between 1 and 50 elements, inclusive.
-Each element of numbers will be between 1 and 1,000,000,000.
-The elements in numbers will be distinct.
-goal will be between 1 and 1,000,000,000.


EXAMPLES

0)
{1, 2, 4}
7

Returns: 1

The goal of the game is to obtain X = 7 from X = 0. The possible moves are to replace X with bitwise OR of X and 1, bitwise OR of X and 2 and bitwise OR of X and 4. X = 7 can be obtained only by using each of the three moves at least once, so removing any single element from numbers will make the game impossible to finish.

1)
{1, 2, 4, 7, 8}
7

Returns: 2

In this example, Fox Ciel should remove the number 7 and one of the numbers 1, 2, 4.

2)
{12571295, 2174218, 2015120}
1

Returns: 0

There is no need to remove elements from numbers, since the game cannot be completed in its initial version.

3)
{5,2,4,52,62,9,8,3,1,11,6}
11

Returns: 3



4)
{503, 505, 152, 435, 491, 512, 1023, 355, 510, 500, 502, 255, 63, 508, 509, 511, 60, 250, 254, 346}
510

Returns: 5



*/

// END CUT HERE
