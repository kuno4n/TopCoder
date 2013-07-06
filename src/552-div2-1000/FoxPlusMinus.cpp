
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

class FoxPlusMinus {
public:
   vector <int> maximize( vector <int> first, int N ) {
	int n = SZ(first); 
	sort(ALL(first));
	VI res(n);
	
	if(N < n){
		res[N] = first[n-1];
		for(int ptr = 0, i = 0; ptr < n; ptr++, i++){
			if(ptr == N) ptr++;
			if(ptr < n) res[ptr] = first[i];
		}
		return res;
	}
	
	if(n % 2 == 0){
		if(N % 2 == 0){
			int i, j;
			for(i = 0, j = n/2; i < n; i+=2, j++) res[i] = first[j];
			
			for(i = 1, j = n/2-1; i < n && i < N-n; i+=2, j--) res[i] = first[j];
			for(j = 0; i < n; i+=2, j++) res[i] = first[j];
		}
		else{
			int i, j;
			for(i = 0, j = n/2-1; i < n && i < N-n; i+=2, j--) res[i] = first[j];
			for(j = 0; i < n; i+=2, j++) res[i] = first[j];
			
			for(i = 1, j = n/2; i < n; i+=2, j++) res[i] = first[j];
		}
	}
	else{
		if((N+1) % (n+1) == 0){
			for(int i = 0, j = n/2; i < n; i+=2, j++) res[i] = first[j];
			for(int i = 1, j = n/2-1; i < n; i+=2, j--) res[i] = first[j];
		}
		else{
			N = N % (n+1);
			res[N] = first[n-1];
			for(int ptr = 0, i = 0; ptr < n; ptr++, i++){
				if(ptr == N) ptr++;
				if(ptr < n) res[ptr] = first[i];
			}
		}
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
			int first[]               = {1, 2};
			int N                     = 2;
			int expected__[]          = {2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int first[]               = {1, 2, 3};
			int N                     = 3;
			int expected__[]          = {2, 1, 3 };

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int first[]               = {-3, 1, -4, 1, -5, 9, -2};
			int N                     = 10;
			int expected__[]          = {-5, -4, 9, -3, -2, 1, 1 };

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int first[]               = {2, 7, -1, 8, -2, -8};
			int N                     = 10;
			int expected__[]          = {2, -1, 7, -2, 8, -8 };

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			int first[]               = {-10, -20, -30};
			int N                     = 1;
			int expected__[]          = {-30, -10, -20 };

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			int first[]               = {1, 2, 4, 9, 7, 3};
			int N                     = 13;
			int expected__[]          = {3, 4, 2, 7, 1, 9 };

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 6: {
			int first[]               = {-4112039, 51143992, 941422315, -153492958, 499218832, 543599293, 132059490, -434243951, -95819234, 1552938, -857192847, 481950390, 401099286, 71482395, -711450593, 8101919};
			int N                     = 884142312;
			int expected__[]          = {51143992, 8101919, 71482395, 1552938, 132059490, -4112039, 401099286, -95819234, 481950390, -153492958, 499218832, -434243951, 543599293, -711450593, 941422315, -857192847 };

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 7: {
			int first[]               = ;
			int N                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			int first[]               = ;
			int N                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 9: {
			int first[]               = ;
			int N                     = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = FoxPlusMinus().maximize(vector <int>(first, first + (sizeof first / sizeof first[0])), N);
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
// Fox Jiro is interested in sequences of intetegers. Today he considers the sequence given to you as the vector <int> first. Let K be the number of elements of first. Jiro chooses some permutation of first. Let's call this permutation F. An infinite sequence of integers A is defined as follows:

for all i, 0 <= i < K, A[i] = F[i].
Otherwise, A[i] = A[i-K] - A[i-K+1] + ... + (-1)^(K-1) * A[i-1].

In addition to first, Jiro has a int N.
His goal is to maximize the value of A[N].
Return a vector <int> containing the best choice of F.
If there are multiple permutations of first maximizing the value of A[N], return the lexicographically smallest one.

DEFINITION
Class:FoxPlusMinus
Method:maximize
Parameters:vector <int>, int
Returns:vector <int>
Method signature:vector <int> maximize(vector <int> first, int N)


NOTES
-A vector <int> A is lexicographically smaller than a vector <int> B if A contains a smaller number at the first index where they differ.


CONSTRAINTS
-first will contain between 1 and 50 elements, inclusive.
-Each element of first will be between -1,000,000,000 and 1,000,000,000, inclusive.
-N will be between 0 and 1,000,000,000, inclusive.


EXAMPLES

0)
{1, 2}
2

Returns: {2, 1 }

A[2] will be 1 if F = {2, 1}, and it will be -1 if F = {1, 2}.

1)
{1, 2, 3}
3

Returns: {2, 1, 3 }

{3, 1, 2} also maximizes A[3] but {2, 1, 3} is lexicographically smaller.

2)
{-3, 1, -4, 1, -5, 9, -2}
10

Returns: {-5, -4, 9, -3, -2, 1, 1 }



3)
{2, 7, -1, 8, -2, -8}
10

Returns: {2, -1, 7, -2, 8, -8 }



4)
{-10, -20, -30}
1

Returns: {-30, -10, -20 }



5)
{1, 2, 4, 9, 7, 3}
13

Returns: {3, 4, 2, 7, 1, 9 }



6)
{-4112039, 51143992, 941422315, -153492958, 499218832, 543599293, 132059490, -434243951,
 -95819234, 1552938, -857192847, 481950390, 401099286, 71482395, -711450593, 8101919}
884142312

Returns: {51143992, 8101919, 71482395, 1552938, 132059490, -4112039, 401099286, -95819234, 481950390, -153492958, 499218832, -434243951, 543599293, -711450593, 941422315, -857192847 }



*/

// END CUT HERE
