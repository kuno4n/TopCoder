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
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

class LittleElephantAndXor {
	public:
	long long getNumber(int A, int B, int C) {
        LL dp[35][2][2][2]; MSET(dp, 0);
        
        dp[34][0][0][0] = 1;
        
        for(int bit = 34; bit > 0; bit--){
            int a = ((LL)A>>(bit-1)) & 1;
            int b = ((LL)B>>(bit-1)) & 1;
            int c = ((LL)C>>(bit-1)) & 1;
            REP(i, 2) REP(j, 2) REP(k, 2){ // dp[bit][i][j][k]からbit-1に配る。 i==1 は、bit桁目ですでにAより小さい、ということ
                REP(x, 2) REP(y, 2){
                    int z = x ^ y;
                    if((i || x<=a) && (j || y<=b) && (k || z<=c)){ //bit-1桁目に、Aがx, Bがy, Cがzと置けるか？
                        dp[bit-1][i|(x<a)][j|(y<b)][k|(z<c)] += dp[bit][i][j][k];
                    }
                }
            }
        }
        
        LL res = 0;
        REP(i, 2) REP(j, 2) REP(k, 2) res += dp[0][i][j][k];
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
			int A                     = 2;
			int B                     = 2;
			int C                     = 1;
			long long expected__      = 5;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int A                     = 4;
			int B                     = 7;
			int C                     = 3;
			long long expected__      = 20;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int A                     = 10;
			int B                     = 10;
			int C                     = 5;
			long long expected__      = 57;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int A                     = 774;
			int B                     = 477;
			int C                     = 447;
			long long expected__      = 214144;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int A                     = 1000000000;
			int B                     = 1000000000;
			int C                     = 500000000;
			long long expected__      = 468566946385621507LL;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int A                     = ;
			int B                     = ;
			int C                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndXor().getNumber(A, B, C);
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
Little Elephant from the Zoo of Lviv likes integers.




You are given three ints A, B and C. Return the number of ordered pairs (X,Y) of integers such that 0 <= X <= A, 0 <= Y <= B, and the value (X XOR Y) is less than or equal to C.


DEFINITION
Class:LittleElephantAndXor
Method:getNumber
Parameters:int, int, int
Returns:long long
Method signature:long long getNumber(int A, int B, int C)


NOTES
-XOR (exclusive or) is a binary operation, performed on two numbers in binary notation. First, the shorter number is prepended with leading zeroes until both numbers have the same number of digits (in binary). Then, the result is calculated as follows: for each bit where the numbers differ the result has 1 in its binary representation. It has 0 in all other positions.
-For example 42 XOR 7 is performed as follows. First, the numbers are converted to binary: 42 is 101010 and 7 is 111. Then the shorter number is prepended with leading zeros until both numbers have the same number of digits. This means 7 becomes 000111. Then 101010 XOR 000111 = 101101 (the result has ones only in the positions where the two numbers differ). Then the result can be converted back to decimal notation. In this case 101101 = 45, so 42 XOR 7 = 45.


CONSTRAINTS
-A, B and C will each be between 1 and 1,000,000,000 (109), inclusive.


EXAMPLES

0)
2
2
1

Returns: 5

There are 9 possible pairs in this case:

0 XOR 0 = 0
0 XOR 1 = 1
0 XOR 2 = 2
1 XOR 0 = 1
1 XOR 1 = 0
1 XOR 2 = 3
2 XOR 0 = 2
2 XOR 1 = 3
2 XOR 2 = 0

Among them, only 5 have XOR less than or equal to 1. Note that (0,1) and (1,0) are two different pairs.

1)
4
7
3

Returns: 20



2)
10
10
5

Returns: 57



3)
774
477
447

Returns: 214144



4)
1000000000
1000000000
500000000

Returns: 468566946385621507



*/

// END CUT HERE
