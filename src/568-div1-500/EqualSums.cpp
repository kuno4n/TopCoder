
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

int MOD = 1000000007;
int n, num[100];
bool visited[50];
vector <string> b;

bool complete(int i){
	if(i < n) visited[i] = true;
	REP(jj, n){
		int j = (i < n) ? jj+n : jj;
		char c = (i < n) ? b[i][j-n] : b[j][i-n];
		if(c == '-') continue;
		int next = (c - '0') - num[i];
		if(next < 0) return false;
		if(num[j] != -1){
			if(next != num[j]) return false;
		}
		else{
			num[j] = next;
			if(!complete(j)) return false;
		}
	}
	return true;
}

class EqualSums {
public:
   int count( vector <string> board ) {
	n = SZ(board); b = board;
	LL allcnt = 1, nonZcnt = 1;
	REP(i, 50) visited[i] = false;
	
	REP(r, n){
		if(visited[r]) continue;
		LL z = 0, nz = 0;
		for(int i = 0; i <= 9; i++){
			MSET(num, -1);
			num[r] = i;
			if(!complete(r)) continue;
			if(std::count(num, num+n, 0)) z++;
			else nz++;
		}
		allcnt = (allcnt * (z + nz)) % MOD;
		nonZcnt = (nonZcnt * nz) % MOD;
	}
	return (allcnt - nonZcnt + MOD) % MOD;
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
			string board[]            = {"1-",
 "-2"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			;return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string board[]            = {"123",
 "4--",
 "--9"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string board[]            = {"9--",
 "-9-",
 "--9"};
			int expected__            = 271;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string board[]            = {"11",
 "12"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string board[]            = {"-4--",
 "-0-2",
 "--1-",
 "4---"}
;
			int expected__            = 10;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string board[]            = {"--2",
 "02-",
 "-10"}
;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string board[]            = {"----------1---------------0-----7-----------------",
 "-----4--------------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------2----------1-------------------------------",
 "-----4--------------------------------------------",
 "-----3--------------------------------------------",
 "-6----------5-------------------------------------",
 "-------------------------------7---5----------6---",
 "--------6-------------6-4---6---------------7-----",
 "-------------4----------------5-------------------",
 "3------------------------------------------6------",
 "3------------------------------------------6------",
 "-------------4----------------5-------------------",
 "---------------2-------------------------3--------",
 "--2------------------------------------------2----",
 "---8---------------1-------------------3----------",
 "---------------3----------------------------------",
 "----7----------------5---0-----------------------5",
 "----------------5-------------------------3-----1-",
 "----------1---------------0-----7-----------------",
 "-------------5----------------6-------------------",
 "-7----------6-------------------------------------",
 "---8---------------1-------------------3----------",
 "-----------------------3--------------------------",
 "----8----------------6---1-----------------------6",
 "------------------------------------------4-----2-",
 "-----------5---------------5----------------------",
 "-----------------------------6--------------------",
 "----8----------------6---1-----------------------6",
 "----------------5-------------------------3-----1-",
 "-------------------------------6---4--2-------5---",
 "-6----------5-------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------------5----------------6-------------------",
 "-----3--------------------------------------------",
 "---------------2-------------------------3--------",
 "---------4---------------------------6------------",
 "-------------------------------6---4--2-------5---",
 "------2-------------1------------22---------------",
 "--------5-------------5-3---5---------------6-----",
 "-----------5--3------------5----------------------",
 "--2------------------------------------------2----",
 "---------5---------------------------7------------",
 "-------------4----------------5-------------------",
 "-----------------5------------------4---6------2--",
 "-------------------------------6---4--2-------5---",
 "-----------------------2--------------------------",
 "----------------6-------------------------4-----2-", 
 "-------------------------------6---4--2-------5---",
 "--------5-------------5-3---5---------------6-----"};
			int expected__            = 45094393;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string board[]            = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = EqualSums().count(vector <string>(board, board + (sizeof board / sizeof board[0])));
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
// Let A be a matrix with N rows and N columns and P be a permutation of integers from 0 to N-1. Consider the following sum: Sum(A, P) = A[0, P[0]] + A[1, P[1]] + ... + A[N-1, P[N-1]], where A[i, j] is the element of A in row i and column j (all indices in this problem are 0-based). The matrix A is called nice if Sum(A, P) is always equal to the same value disregarding of the choice of permutation P.

Fox Ciel wants to draw a nice matrix on the blackboard. She is given a vector <string> board. It contains N elements and each element contains N characters. If j-th character of board[i] is a digit '0', '1', '2', ..., '9', then A[i, j] must be equal to this digit. If j-th character of board[i] is '-', then A[i, j] can be equal to any non-negative integer (it is allowed to be greater than 9).

Let T be the number of different matrices that satisfy all Ciel's requirements (the constraints will guarantee that the number of such matrices is finite). Compute and return the value of (T modulo 1,000,000,007).


DEFINITION
Class:EqualSums
Method:count
Parameters:vector <string>
Returns:int
Method signature:int count(vector <string> board)


CONSTRAINTS
-board will contain between 1 and 50 elements, inclusive.
-Each element of board will contain exactly N characters, where N is the number of elements in board.
-Each character in board will be one of '-', '0', '1', '2', ..., '9'.
-The number of matrices that satisfy all Ciel's requirements will be finite.


EXAMPLES

0)
{"1-",
 "-2"}

Returns: 4

The sum A[0, 1] + A[1, 0] must be equal to 3.

1)
{"123",
 "4--",
 "--9"}

Returns: 1



2)
{"9--",
 "-9-",
 "--9"}

Returns: 271



3)
{"11",
 "12"}

Returns: 0

There are no nice matrices that match the given board, so T = 0.

4)
{"-4--",
 "-0-2",
 "--1-",
 "4---"}


Returns: 10



5)
{"--2",
 "02-",
 "-10"}


Returns: 0



6)
{"----------1---------------0-----7-----------------",
 "-----4--------------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------2----------1-------------------------------",
 "-----4--------------------------------------------",
 "-----3--------------------------------------------",
 "-6----------5-------------------------------------",
 "-------------------------------7---5----------6---",
 "--------6-------------6-4---6---------------7-----",
 "-------------4----------------5-------------------",
 "3------------------------------------------6------",
 "3------------------------------------------6------",
 "-------------4----------------5-------------------",
 "---------------2-------------------------3--------",
 "--2------------------------------------------2----",
 "---8---------------1-------------------3----------",
 "---------------3----------------------------------",
 "----7----------------5---0-----------------------5",
 "----------------5-------------------------3-----1-",
 "----------1---------------0-----7-----------------",
 "-------------5----------------6-------------------",
 "-7----------6-------------------------------------",
 "---8---------------1-------------------3----------",
 "-----------------------3--------------------------",
 "----8----------------6---1-----------------------6",
 "------------------------------------------4-----2-",
 "-----------5---------------5----------------------",
 "-----------------------------6--------------------",
 "----8----------------6---1-----------------------6",
 "----------------5-------------------------3-----1-",
 "-------------------------------6---4--2-------5---",
 "-6----------5-------------------------------------",
 "--------5-------------5-3---5---------------6-----",
 "-------------5----------------6-------------------",
 "-----3--------------------------------------------",
 "---------------2-------------------------3--------",
 "---------4---------------------------6------------",
 "-------------------------------6---4--2-------5---",
 "------2-------------1------------22---------------",
 "--------5-------------5-3---5---------------6-----",
 "-----------5--3------------5----------------------",
 "--2------------------------------------------2----",
 "---------5---------------------------7------------",
 "-------------4----------------5-------------------",
 "-----------------5------------------4---6------2--",
 "-------------------------------6---4--2-------5---",
 "-----------------------2--------------------------",
 "----------------6-------------------------4-----2-", 
 "-------------------------------6---4--2-------5---",
 "--------5-------------5-3---5---------------6-----"}

Returns: 45094393



*/

// END CUT HERE
