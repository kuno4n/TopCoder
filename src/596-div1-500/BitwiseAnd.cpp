
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



class BitwiseAnd {
public:
   vector<long long> lexSmallest( vector<long long> s, int N ) {
	
	LL tab[55][70];
	int n = SZ(s);
	vector<long long> res; res.clear();
	REP(i, n) FOR(j, i+1, n) if((s[i] & s[j]) == 0) return res;
	REP(i, n) FOR(j, i+1, n) FOR(k, j+1, n) if(((s[i] & s[j]) & s[k]) > 0) return res;
	
	MSET(tab, 0);
	REP(i, n) REP(j, 60){
		if((1LL<<j) & s[i]) tab[i][j]++;
	}
	REP(i, n) FOR(j, i+1, n) REP(k, 60) if(tab[i][k] && tab[j][k]){
		tab[i][k]++;
		tab[j][k]++;
	}
	REP(i, n){
		int cnt = 0;
		REP(j, 60) if(tab[i][j] == 1) cnt++;
		if(cnt < N-n) return res;
	}
	REP(_, N-n){
		LL tmp = 0;
		bool used[50]; MSET(used, false);
		int one = N - SZ(s) -1;
		int ptr = -1;
		while(1){
			bool ok = true;
			REP(i, SZ(s)) ok &= used[i];
			if(ok && (one == 0)) break;
			
			ptr++;
			if(ptr >= 60) return res;
			
			if(one){
				bool zero = true;
				REP(i, SZ(s)) zero &= (tab[i][ptr] == 0);
				if(zero){
					tmp += (1LL<<ptr);
					one--;
					tab[SZ(s)][ptr]++;
					continue;
				}
			}
			REP(i, SZ(s)) if(tab[i][ptr] == 1 && !used[i]){
				used[i] = true;
				tab[i][ptr]++;
				tab[SZ(s)][ptr] = 2;
				tmp += (1LL<<ptr);
				
			}
			
		}
		s.push_back(tmp);
	}
	
	sort(ALL(s));
	return s;
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

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, clock_t elapsed) { 
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
			long long subset[]        = {14, 20};
			int N                     = 3;
			long long expected__[]    = {14, 18, 20};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			long long subset[]        = {11, 17, 20};
			int N                     = 4;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			long long subset[]        = {99, 157};
			int N                     = 4;
			long long expected__[]    = {99, 157, 262, 296};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			long long subset[]        = {1152921504606846975LL};
			int N                     = 3;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			long long subset[]        = {};
			int N                     = 5;
			long long expected__[]    = {15, 113, 402, 676, 840};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 5: {
			long long subset[]        = {1, 3, 5, 7, 9, 11};
			int N                     = 6;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

      case 6: {
			long long subset[]        = {29915513979715620, 146367284310704203, 198493264368804864, 288230558092231760, 360289930878212130};
			int N                     = 10;
			long long expected__[]    = {4205461, 147334567170184, 5631699246448896, 29915513979715620, 146367284310704203, 198493264368804864, 288230558092231760, 360289930878212130, 577599919634776576, 581193205005942784};

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
/*      case 7: {
			long long subset[]        = ;
			int N                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 8: {
			long long subset[]        = ;
			int N                     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = BitwiseAnd().lexSmallest(vector<long long>(subset, subset + (sizeof subset / sizeof subset[0])), N);
			return verify_case(casenum__, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
For non-negative integers A and B, let A&B denote the bitwise AND operation.
That is, for each i, the i-th bit of A&B in binary representation is 1 if and only if the i-th bits of A and B are 1.



We call a set of non-negative integers S cool if the following conditions are satisfied.


For any two distinct elements A, B in S, A&B > 0.
For any three distinct elements A, B, C in S, A&B&C = 0.



You are given a vector<long long> subset and an int N.
All elements in subset are distinct.
Compute a cool set with N distinct elements such that the cool set contains each element of subset and each element is between 1 and 2^60 - 1, inclusive.
Return one such cool set as a vector<long long> with elements in increasing order.
If there are multiple solutions, return the lexicographically smallest one.
If there are no such cool sets, return an empty vector<long long> instead.




DEFINITION
Class:BitwiseAnd
Method:lexSmallest
Parameters:vector<long long>, int
Returns:vector<long long>
Method signature:vector<long long> lexSmallest(vector<long long> subset, int N)


CONSTRAINTS
-N will be between 3 and 50, inclusive.
-subset will contain between 0 and N elements, inclusive.
-Each element of subset will be between 1 and 2^60 - 1, inclusive.
-All the elements in subset will be distinct.
-Elements in subset will be sorted in increasing order.


EXAMPLES

0)
{14, 20}
3

Returns: {14, 18, 20 }

There are several possible cool sets.
For example, the following sets are cool and each of them contains all the elements of subset.

{14, 18, 20}
{14, 20, 26}
{14, 20, 50}
...
  
Among these sets, the first one is the lexicographically smallest one.



1)
{11, 17, 20}
4

Returns: { }

There is no cool set because (11&20) equals 0.

2)
{99, 157}
4

Returns: {99, 157, 262, 296 }



3)
{1152921504606846975}
3

Returns: { }

The element in subset equals to 2^60-1.
Note that each element of your cool set should be less than or equal to 2^60-1. 

4)
{}
5

Returns: {15, 113, 402, 676, 840 }



5)
{1, 3, 5, 7, 9, 11}
6

Returns: { }



*/

// END CUT HERE
