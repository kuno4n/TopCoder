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

const int mo = 1000000007;
LL dp[40][1300]; // dp[見終わった番号][LISnumber]
LL C[1300][1300];

void makepas(){
    MSET(C, 0);
    C[0][0] = C[1][0] = C[1][1] = 1;
    for(int i=2; i<1300; i++){
        C[i][0] = 1;
        C[i][i] = 1;
        for(int j=1; j<i; j++){
            C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mo;
        }
    }
}


void add(LL &a, LL b){
    a = (a+b) % mo;
}

LL H(int n , int m){
    if(m <= 0) return 0;
    return C[n+m-1][m-1];
}

class LISNumber {
	public:
	int count(vector <int> ca, int K) {
        makepas();
        MSET(dp, 0);
        int s = ca[0];
        dp[0][s] = 1;
        for(int i = 1; i < SZ(ca); i++){
            REP(j, 1300) if(dp[i-1][j] > 0) for(int k = j; k <= j+ca[i]; k++){ // 番号iを追加したときに、LISnumberがj->kに増える場合を考える
                int p = k-j;     // ca[i]個の番号iのうち、p個、LISnumberを増やすために使う
                int q = ca[i]-p; // ca[i]個の番号iのうち、q個、LISnumberを増やさないように使う
                add(dp[i][k], dp[i-1][j] * C[j][q] % mo * H(p, s-j+1+q) % mo);
            }
            s += ca[i];
        }
        return dp[SZ(ca)-1][K];
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
			int cardsnum[]            = {1, 1, 1};
			int K                     = 2;
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int cardsnum[]            = {2};
			int K                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int cardsnum[]            = {36, 36, 36, 36, 36};
			int K                     = 36;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int cardsnum[]            = {3, 2, 11, 5, 7};
			int K                     = 20;
			int expected__            = 474640725;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int cardsnum[]            = {31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26};
			int K                     = 58;
			int expected__            = 12133719;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int cardsnum[]            = {27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5, 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7, 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9};
			int K                     = 116;
			int expected__            = 516440918;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int cardsnum[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int cardsnum[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int cardsnum[]            = ;
			int K                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LISNumber().count(vector <int>(cardsnum, cardsnum + (sizeof cardsnum / sizeof cardsnum[0])), K);
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
// Let A be a sequence of integers.
The LISNumber of A is the smallest positive integer L such that A can be obtained by concatenating L strictly increasing sequences.
For example, the LISNumber of A = {1, 4, 4, 2, 6, 3} is 4, since we can obtain A as {1, 4} + {4} + {2, 6} + {3}, and there is no way to create A by concatenating 3 (or fewer) strictly increasing sequences.
The LISNumber of a strictly increasing sequence is 1.

You have N types of cards.
For each i, 0 <= i < N, you have cardsnum[i] cards of the i-th type.
Each card of the i-th type contains the number i.

You are given the vector <int> cardsnum and an int K.
You want to arrange all the cards you have into a row in such a way that the resulting sequence of integers has LISNumber K.
Note that you must use all the cards you have, you can only choose their order.

Let X be the number of different valid sequences you can produce.
Compute and return the number X, modulo 1,000,000,007.

DEFINITION
Class:LISNumber
Method:count
Parameters:vector <int>, int
Returns:int
Method signature:int count(vector <int> cardsnum, int K)


CONSTRAINTS
-cardsnum will contain between 1 and 36 elements, inclusive.
-Each element of cardsnum will be between 1 and 36, inclusive.
-K will be between 1 and 1296, inclusive.


EXAMPLES

0)
{1, 1, 1}
2

Returns: 4

In this case, there are 3 types of cards and you have one of each. Among the 6 sequences you can make, the following 4 have LISNumber 2:

{0, 2, 1}
{1, 0, 2}
{1, 2, 0}
{2, 0, 1}



1)
{2}
1

Returns: 0

The only sequence you can make is {0, 0} and its LISNumber is 2.

2)
{36, 36, 36, 36, 36}
36

Returns: 1

Only the sequence {0, 1, 2, 3, 4, 0, 1, 2, 3, 4, ... (36 times) ... } has LISNumber 36.

3)
{3, 2, 11, 5, 7}
20

Returns: 474640725



4)
{31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26}
58

Returns: 12133719



5)
{27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9}
116

Returns: 516440918



*/

// END CUT HERE
