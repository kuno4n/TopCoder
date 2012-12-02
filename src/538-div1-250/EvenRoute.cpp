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

class EvenRoute {
	public:
	string isItPossible(vector <int> x, vector <int> y, int wantedParity) {
		int numodd = 0;
        int numeven = 0;
        int N = SZ(x);
        
        REP(i, N){
            if((x[i]+y[i])%2) numodd++;
            else numeven++;
        }
        
        if(numodd == 0){
            if(wantedParity) return "CANNOT";
            else return "CAN";
        }
        
        if(numeven == 0){
            if(wantedParity) return "CAN";
            else return "CANNOT";
        }
        
        return "CAN";
        
        
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int x[]                   = {-1,-1,1,1};
			int y[]                   = {-1,1,1,-1};
			int wantedParity          = 0;
			string expected__         = "CAN";

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int x[]                   = {-5,-3,2};
			int y[]                   = {2,0,3};
			int wantedParity          = 1;
			string expected__         = "CAN";

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int x[]                   = {1001, -4000};
			int y[]                   = {0,0};
			int wantedParity          = 1;
			string expected__         = "CAN";

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int x[]                   = {11, 21, 0};
			int y[]                   = {-20, 42, 7};
			int wantedParity          = 0;
			string expected__         = "CANNOT";

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int x[]                   = {0, 6};
			int y[]                   = {10, -20};
			int wantedParity          = 1;
			string expected__         = "CANNOT";

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int x[]                   = ;
			int y[]                   = ;
			int wantedParity          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int x[]                   = ;
			int y[]                   = ;
			int wantedParity          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int x[]                   = ;
			int y[]                   = ;
			int wantedParity          = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = EvenRoute().isItPossible(vector <int>(x, x + (sizeof x / sizeof x[0])), vector <int>(y, y + (sizeof y / sizeof y[0])), wantedParity);
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
// Fox Ciel has stumbled upon a new problem: In this problem you will visit some points with integer coordinates in the Cartesian plane. Initially, you are located at the point (0,0). In each step, you can move from your current point to one of the four directly adjacent points.
I.e., if you are at (x,y), you can move to one of the points (x,y+1), (x,y-1), (x+1,y), and (x-1,y).

You are given two vector <int>s x and y, each containing N elements.
Together, x and y describe N distinct points in the Cartesian plane:
for 0 <= i < N, point i has the coordinates (x[i],y[i]).

The goal is to find a sequence of steps that satisfies the following criteria:
The starting point is (0,0).
The sequence visits each of the N given points at least once.
The sequence finishes in one of the given points.


Mr. K claims to have solved this problem but Ciel does not believe him. Ciel has prepared a method to verify Mr. K's claims. Given an int wantedParity, the parity of the number of steps in the sequence found by Mr. K, Ciel will find if it is possible to find a sequence that follows the previously mentioned conditions and a new one:

The parity of the total number of steps is wantedParity. In other words, if wantedParity=0 then the total number of steps must be even, and if wantedParity=1 then the total number of steps must be odd.


Return "CAN" (quotes for clarity) if at least one such sequence of steps exists, and "CANNOT" otherwise.

DEFINITION
Class:EvenRoute
Method:isItPossible
Parameters:vector <int>, vector <int>, int
Returns:string
Method signature:string isItPossible(vector <int> x, vector <int> y, int wantedParity)


CONSTRAINTS
-wantedParity will be 0 or 1.
-x will contain between 1 and 50 elements, inclusive.
-y will contain the same number of elements as x.
-Each element of x and y will be between -1000000 and 1000000, inclusive.
-No point in the input will be equal to (0,0).
-No pair of points in the input will be equal.


EXAMPLES

0)
{-1,-1,1,1}
{-1,1,1,-1}
0

Returns: "CAN"

A possible sequence containing an even number of steps:
2 steps: (0,0) -> (-1,-1).
2 steps: (-1,-1) -> (-1,1).
2 steps: (-1,1) -> (1,1).
2 steps: (1,1) -> (1,-1).


1)
{-5,-3,2}
{2,0,3}
1

Returns: "CAN"

A possible sequence containing an odd number of steps:

7 steps: (0,0) -> (-5,2).
4 steps: (-5,2) -> (-3,0).
8 steps: (-3,0) -> (2,3).



2)
{1001, -4000}
{0,0}
1

Returns: "CAN"

The shortest sequence that visits all the given points is the sequence that first goes to (1001,0) and then to (-4000,0).
Note that this sequence does not have an odd amount of steps.
However, there is a longer sequence with an odd number of steps: (0,0) -> (-4000,0) -> (1001, 0).

3)
{11, 21, 0}
{-20, 42, 7}
0

Returns: "CANNOT"



4)
{0, 6}
{10, -20}
1

Returns: "CANNOT"



*/

// END CUT HERE
