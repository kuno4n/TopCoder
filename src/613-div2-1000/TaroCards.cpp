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


LL dp[55][55][1<<10];

int bitcnt(LL n)
{
    int c;
    for(c=0;n!=0;c++,n&=n-1) ;
    return c;
}

class TaroCards {
public:
   long long getNumber( vector <int> f, vector <int> s, int K ) {
       MSET(dp, 0);
       int n = SZ(f);
       vector<pair<int, int> > v;
       REP(i, n) v.push_back(make_pair(f[i]-1, s[i]-1));
       sort(ALL(v));
       REP(i, n) f[i] = v[i].first, s[i] = v[i].second;
       
       dp[0][0][0] = 1;
       if(s[0] == 0) dp[0][1][1] = 1;
       else dp[0][2][1|(1<<s[0])] = 1;
       
       for(int i = 1; i < min(10, n); i++) REP(j, 52) REP(k, (1<<10)){
           dp[i][j][k] += dp[i-1][j][k];
           int nk = (k | (1<<i) | (1<<s[i]));
           int nj = bitcnt(nk);
           dp[i][nj][nk] += dp[i-1][j][k];
       }
       
       for(int i = 10; i < n; i++) REP(j, 52) REP(k, (1<<10)){
           dp[i][j][k] += dp[i-1][j][k];
           int nj = j + 1 + !((1<<s[i])&k);
           int nk = (k | (1<<s[i]));
           dp[i][nj][nk] += dp[i-1][j][k];
       }
       
       if(K > 50) K = 50;
       LL res = 0;
       REP(j, K+1) REP(k, (1<<10)) res += dp[n-1][j][k];
//       REP(j, K+1) REP(k, (1<<10)) if(dp[n-1][j][k]){
//           OUT(j);
//           OUT(k);
//           OUT(dp[n-1][j][k]);
//       }
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
			int first[]               = {1, 2};
			int second[]              = {2, 3};
			int K                     = 2;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int first[]               = {3, 1, 2};
			int second[]              = {1, 1, 1};
			int K                     = 3;
			long long expected__      = 8;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int first[]               = {4, 2, 1, 3};
			int second[]              = {1, 2, 3, 4};
			int K                     = 5;
			long long expected__      = 16;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int first[]               = {1, 2, 3, 4, 5, 6, 7};
			int second[]              = {2, 1, 10, 9, 3, 2, 2};
			int K                     = 3;
			long long expected__      = 17;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int first[]               = {1};
			int second[]              = {2};
			int K                     = 1;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int first[]               = {6, 20, 1, 11, 19, 14, 2, 8, 15, 21, 9, 10, 4, 16, 12, 17, 13, 22, 7, 18, 3, 5};
			int second[]              = {4, 5, 10, 7, 6, 2, 1, 10, 10, 7, 9, 4, 5, 9, 5, 10, 10, 3, 6, 6, 4, 4};
			int K                     = 14;
			long long expected__      = 2239000;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int first[]               = ;
			int second[]              = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int first[]               = ;
			int second[]              = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int first[]               = ;
			int second[]              = ;
			int K                     = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = TaroCards().getNumber(vector <int>(first, first + (sizeof first / sizeof first[0])), vector <int>(second, second + (sizeof second / sizeof second[0])), K);
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
Cat Taro has N cards.
Exactly two integers are written on each card.
You are given two vector <int>s first and second, each with N elements.
For each i, the element first[i] represents the first integer on the i-th card, and the element second[i] represents the second integer on the i-th card.




It is known that for each x from 1 to N, inclusive, there is exactly one card with the first integer equal to x.
In other words, all elements of first represent a permutation of integers from 1 to N, inclusive.
On the other hand, second may contain duplicates, but all elements of second are only between 1 and 10, inclusive.




You are also given an int K. Taro wants to choose some subset of the cards (possibly none or all of them) in such a way that the total number of different integers written on the cards is less than or equal to K. Return the total number of ways to do that.


DEFINITION
Class:TaroCards
Method:getNumber
Parameters:vector <int>, vector <int>, int
Returns:long long
Method signature:long long getNumber(vector <int> first, vector <int> second, int K)


CONSTRAINTS
-first will contain between 1 and 50 elements, inclusive.
-first and second will contain the same number of elements.
-first will represent a permutation of integers between 1 and N, inclusive, where N is the number of elements in first.
-Each element of second will be between 1 and 10, inclusive.
-K will be between 1 and 2N, inclusive, where N is the number of elements in first.


EXAMPLES

0)
{1, 2}
{2, 3}
2

Returns: 3

In this case, there are four subsets of cards:


None of the cards. The number of different integers is 0.


Only the first card. The number of different integers is 2.


Only the second card. The number of different integers is 2.


Both the first and the second card. The number of different integers is 3.


However, the last subset has too many different integers. Thus, the answer is 3.

1)
{3, 1, 2}
{1, 1, 1}
3

Returns: 8



2)
{4, 2, 1, 3}
{1, 2, 3, 4}
5

Returns: 16



3)
{1, 2, 3, 4, 5, 6, 7}
{2, 1, 10, 9, 3, 2, 2}
3

Returns: 17



4)
{1}
{2}
1

Returns: 1



5)
{6, 20, 1, 11, 19, 14, 2, 8, 15, 21, 9, 10, 4, 16, 12, 17, 13, 22, 7, 18, 3, 5}
{4, 5, 10, 7, 6, 2, 1, 10, 10, 7, 9, 4, 5, 9, 5, 10, 10, 3, 6, 6, 4, 4}
14

Returns: 2239000



*/

// END CUT HERE
