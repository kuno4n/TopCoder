
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

class LittleElephantAndIntervalsDiv1 {
public:
   long long getNumber( int M, vector <int> L, vector <int> R ) {
	bool used[1010]; MSET(used, false);
	reverse(ALL(L)); reverse(ALL(R));
	int n = SZ(L);
	
	int cnt = 0;
	REP(i, n){
		bool a = false;
		for(int j = L[i]; j <= R[i]; j++) if(!used[j]){
			a = true;
			used[j] = true;
		}
		if(a) cnt++;
	}
	
	return (1LL<<cnt);
	
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			int M                     = 4;
			int L[]                   = {1, 2, 3};
			int R[]                   = {1, 2, 3};
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber(M, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int M                     = 3;
			int L[]                   = {1, 1, 2};
			int R[]                   = {3, 1, 3};
			long long expected__      = 4;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber(M, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int M                     = 1000;
			int L[]                   = {47};
			int R[]                   = {747};
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber(M, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int M                     = 42;
			int L[]                   = {5, 23, 4, 1, 15, 2, 22, 26, 13, 16, 28, 13, 27, 9, 18, 4, 10, 3, 4, 4, 3, 4, 1, 18, 18, 2, 38, 4, 10, 12, 3, 30, 11, 38, 2, 13, 1, 13, 18, 16, 13, 2, 14, 27, 13, 3, 26, 19, 5, 10};
			int R[]                   = {30, 41, 17, 1, 21, 6, 28, 30, 15, 19, 31, 28, 35, 27, 30, 13, 31, 5, 8, 25, 40, 10, 3, 26, 23, 9, 40, 8, 40, 23, 12, 37, 35, 39, 11, 34, 10, 21, 22, 21, 24, 5, 39, 27, 17, 16, 26, 35, 25, 36};
			long long expected__      = 256;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber(M, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 4: {
			int M                     = 1000;
			int L[]                   = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			int R[]                   = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber(M, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 5: {
			int M                     = ;
			int L[]                   = ;
			int R[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber(M, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int M                     = ;
			int L[]                   = ;
			int R[]                   = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndIntervalsDiv1().getNumber(M, vector <int>(L, L + (sizeof L / sizeof L[0])), vector <int>(R, R + (sizeof R / sizeof R[0])));
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
Little Elephant from the Zoo of Lviv has some balls arranged in a row. Each ball can be painted in one of two possible colors: black or white. Initially all the balls are painted white. 




You are given an int M, which represents the number of balls in the row. 
The balls are numbered from left to right, starting from 1. 
You are also given two vector <int>s L and R. 
To repaint balls, Little Elephant wants to use a robot. 
The robot will paint the balls in several consecutive stages.
For each i, the i-th stage (1-based index) will look as follows:
First, the robot will choose one of the two colors: white or black.
Then, the robot will paint the balls with indices from L[i-1] to R[i-1], inclusive, using the chosen color.
(Painting a ball covers all previous layers of paint.)




Return the number of different colorings Little Elephant can get after the last stage. (Two colorings are considered different if there exists some ball that is white in one coloring and black in the other one).


DEFINITION
Class:LittleElephantAndIntervalsDiv1
Method:getNumber
Parameters:int, vector <int>, vector <int>
Returns:long long
Method signature:long long getNumber(int M, vector <int> L, vector <int> R)


CONSTRAINTS
-M will be between 1 and 1,000, inclusive. 
-L will contain between 1 and 50 elements, inclusive.
-R will contain the same number of elements as L.
-Each element of R will be between 1 and M, inclusive.
-i-th element of L will be between 1 and R[i], inclusive.


EXAMPLES

0)
4
{1, 2, 3}
{1, 2, 3}

Returns: 8

In the three stages the robot will choose the color for balls number 1, 2, and 3. The choices are independent of each other. The last, fourth ball will always remain white. Thus there are 2*2*2 = 8 different colorings.

1)
3
{1, 1, 2}
{3, 1, 3}

Returns: 4



2)
1000
{47}
{747}

Returns: 2



3)
42
{5, 23, 4, 1, 15, 2, 22, 26, 13, 16, 28, 13, 27, 9, 18, 4, 10, 3, 4, 4, 3, 4, 1, 18, 18, 2, 38, 4, 10, 12, 3, 30, 11, 38, 2, 13, 1, 13, 18, 16, 13, 2, 14, 27, 13, 3, 26, 19, 5, 10}
{30, 41, 17, 1, 21, 6, 28, 30, 15, 19, 31, 28, 35, 27, 30, 13, 31, 5, 8, 25, 40, 10, 3, 26, 23, 9, 40, 8, 40, 23, 12, 37, 35, 39, 11, 34, 10, 21, 22, 21, 24, 5, 39, 27, 17, 16, 26, 35, 25, 36}

Returns: 256



*/

// END CUT HERE
