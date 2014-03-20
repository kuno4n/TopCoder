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

const int MAX_N = 1000;
int par[MAX_N];  //親
int _rank[MAX_N]; //木の深さ

// n要素で初期化
void init(int n){
    REP(i, n){
        par[i] = i;
        _rank[i] = 0;
    }
}
//木の根を求める
int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}
//xとyの属する集合を結合
void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(_rank[x] < _rank[y]) par[x] = y;
    else{
        par[y] = x;
        if(_rank[x] == _rank[y]) _rank[x]++;
    }
}



const int INF = (1<<29);
int res;
int h, w;
vector < VI > a;

class PalindromeMatrix {
public:
   int minChange( vector <string> A, int rowCount, int columnCount ) {
       res = INF;
       h = SZ(A);
       w = SZ(A[0]);
       a.clear();
       a = vector< VI > (h, VI (w, 0));
       REP(i, h) REP(j, w) a[i][j] = (A[i][j] == '1');
       int cc[20];
       MSET(cc, 0);
       REP(i, columnCount) cc[i] = 1;
       sort(cc, cc+w);
       int res = INF;
       do{
           int dp[10][20];
           REP(i, 10) REP(j, 20) dp[i][j] = INF;
           dp[0][0] = 0;
           REP(i, h/2) REP(j, rowCount+1) if(dp[i][j] != INF){
               REP(k, 4){
                   int up = (k & 1);
                   int lo = ((k>>1) & 1);
                   int cnt = 0;
                   int table[w*2][2]; MSET(table, 0);
                   init(w*2);
                   REP(y, w) if(cc[y]) unite(y, w+y);
                   if(up) REP(y, w) unite(y, w-1-y);
                   if(lo) REP(y, w) unite(w+y, w+(w-1-y));
                   REP(y, w) table[find(y)][a[i][y]]++;
                   REP(y, w) table[find(w+y)][a[h-1-i][y]]++;
                   REP(y, w*2) cnt += min(table[y][0], table[y][1]);
                   chmin(dp[i+1][j+up+lo], dp[i][j]+cnt);
               }
           }
           chmin(res, dp[h/2][rowCount]);
       }while(next_permutation(cc, cc+w ));
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
			string A[]                = {"0000"
,"1000"
,"1100"
,"1110"};
			int rowCount              = 2;
			int columnCount           = 2;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string A[]                = {"0000"
,"1000"
,"1100"
,"1110"};
			int rowCount              = 3;
			int columnCount           = 2;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string A[]                = {"01"
,"10"};
			int rowCount              = 1;
			int columnCount           = 1;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string A[]                = {"1110"
,"0001"};
			int rowCount              = 0;
			int columnCount           = 0;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string A[]                = {"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"};
			int rowCount              = 2;
			int columnCount           = 3;
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string A[]                = {"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"};
			int rowCount              = 5;
			int columnCount           = 9;
			int expected__            = 14;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 6: {
			string A[]                = {"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"};
			int rowCount              = 6;
			int columnCount           = 8;
			int expected__            = 31;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 9: {
			string A[]                = ;
			int rowCount              = ;
			int columnCount           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = PalindromeMatrix().minChange(vector <string>(A, A + (sizeof A / sizeof A[0])), rowCount, columnCount);
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


Fox Ciel has a matrix A that consists of N rows by M columns.
Both N and M are even.
Each element of the matrix is either 0 or 1.
The rows of the matrix are numbered 0 through N-1 from top to bottom, the columns are numbered 0 through M-1 from left to right.
The element in row i, column j is denoted A(i, j).
You are given a vector <string> A that describes the matrix A.
The character A[i][j] is '1' if A(i, j)=1 and it is '0' otherwise.



A palindrome is a string that reads the same forwards and backwards.
For example, "1001" and "0111001110" are palindromes while "1101" and "000001" are not.



Some rows and some columns in Ciel's matrix may be palindromes.
For example, in the matrix below both row 0 and column 3 are palindromes.
(Row 0 is the palindrome "0000", column 3 is the palindrome "0110".)


0000
0011
0111
1110



You are also given two ints: rowCount and columnCount.
Ciel wants her matrix A to have at least rowCount rows that are palindromes, and at the same time at least columnCount columns that are palindromes.
If this is currently not the case, she can change A by changing some of the elements (from '0' to '1' or vice versa).
Compute and return the smallest possible number of elements she needs to change in order to reach her goal.


DEFINITION
Class:PalindromeMatrix
Method:minChange
Parameters:vector <string>, int, int
Returns:int
Method signature:int minChange(vector <string> A, int rowCount, int columnCount)


CONSTRAINTS
-N and M will be between 2 and 14, inclusive.
-N and M will be even.
-A will contain N elements.
-Each element of A will contain M characters.
-Each character of A will be either '0' or '1'.
-rowCount will be between 0 and N.
-columnCount will be between 0 and M.


EXAMPLES

0)
{"0000"
,"1000"
,"1100"
,"1110"}
2
2

Returns: 1

An optimal solution is to change A(3, 0) to 0. Then we will have palindromes in two rows (0 and 3), and in two columns (0 and 3).

1)
{"0000"
,"1000"
,"1100"
,"1110"}
3
2

Returns: 3

This is similar to the previous example, but in this case we must have three row palindromes. 
An optimal solution is to change A(1, 0), A(2, 0) and A(3, 0) to 0.

2)
{"01"
,"10"}
1
1

Returns: 1



3)
{"1110"
,"0001"}
0
0

Returns: 0

Here, we do not have to change A at all.

4)
{"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"
,"01010101"}
2
3

Returns: 8



5)
{"000000000000"
,"011101110111"
,"010001010101"
,"010001010101"
,"011101010101"
,"010101010101"
,"010101010101"
,"011101110111"
,"000000000000"
,"000000000000"}
5
9

Returns: 14



6)
{"11111101001110"
,"11000111111111"
,"00010101111001"
,"10110000111111"
,"10000011010010"
,"10001101101101"
,"00101010000001"
,"10111010100100"
,"11010011110111"
,"11100010110110"
,"00100101010100"
,"01001011001000"
,"01010001111010"
,"10100000010011"}
6
8

Returns: 31



*/

// END CUT HERE
