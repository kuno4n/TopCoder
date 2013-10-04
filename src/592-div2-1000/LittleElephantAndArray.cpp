
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
#define VL vector < LL >
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(), (v).end()
#define FIT(it,v) for (typeof((v).begin()) it = (v).begin(); it != (v).end(); it++)
#define OUT(A) cout << #A << " = "<< (A) << endl
#define OUT2(A, B) cout << "(" << #A << ", " << #B << ") = (" << (A) << ", "<< (B) << ")" << endl
template<class T> void chmin(T &t, T f) { if (t > f) t = f; } 
template<class T> void chmax(T &t, T f) { if (t < f) t = f; } 

const int MOD = 1000000007;
void add(LL &a, LL b){
	a = (a + b) % MOD;
}
string int2str(LL a){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    return res;
}
LL str2int(string s){
    LL res = 0;
    REP(i, SZ(s)){
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

LL prv_val[1<<16], prv_res[1<<16];
LL nxt_val[1<<16], nxt_res[1<<16];
int pn, n;

class LittleElephantAndArray {
public:
   int getNumber( long long A, int N ) {
	
	for(int i = 0; i <= N; i ++){
		MSET(nxt_val, 0); MSET(nxt_res, 0);
		LL B = A + i;
		string s = int2str(B);
		n = (1<<SZ(s));
		for(int j = 1; j < n; j++){
			REP(k, SZ(s)) if(j & (1<<k)){
				nxt_val[j] *= 10;
				nxt_val[j] += s[k]-'0';
			}
		}
		sort(nxt_val, nxt_val+n);
		if(i == 0){
			for(int j = 1; j < n; j++) nxt_res[j] = nxt_res[j-1] + 1;
		}
		else{
			int ptr = 0;
			for(int j = 1; j < n; j++){
				add(nxt_res[j], nxt_res[j-1]);
				while(ptr < pn-1 && prv_val[ptr+1] <= nxt_val[j]) ptr++;
				add(nxt_res[j], prv_res[ptr]);
			}
		}
//		REP(i, n) prv_val[i] = nxt_val[i], prv_res[i] = nxt_res[i];
		swap(prv_val, nxt_val);
		swap(prv_res, nxt_res);
		pn = n;
	}
	
	return prv_res[pn-1];

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
			long long A               = 1;
			int N                     = 9;
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = LittleElephantAndArray().getNumber(A, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long A               = 10;
			int N                     = 2;
			int expected__            = 15;

			clock_t start__           = clock();
			int received__            = LittleElephantAndArray().getNumber(A, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long A               = 4747774;
			int N                     = 1;
			int expected__            = 8369;

			clock_t start__           = clock();
			int received__            = LittleElephantAndArray().getNumber(A, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long A               = 6878542150015LL;
			int N                     = 74;
			int expected__            = 977836619;

			clock_t start__           = clock();
			int received__            = LittleElephantAndArray().getNumber(A, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			long long A               = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndArray().getNumber(A, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			long long A               = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndArray().getNumber(A, N);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long A               = ;
			int N                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = LittleElephantAndArray().getNumber(A, N);
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
Little Elephant from the Zoo of Lviv likes sequences of integers.




You are given a long long A and an int N.
Little Elephant has the sequence S = (A, A+1, ..., A+N).
Little Elephant now wants to erase some digits from some of the numbers.
He may erase multiple digits from the same number, but he will not erase any of the numbers completely.
After erasing some digits from a number the gaps disappear.
For example, by erasing the middle digit of the number 147 Little Elephant obtains the number 17 (and not two separate numbers 1 and 7).




It is allowed for some number to contain leading zeroes after erasings.
For example, from the number 1047 Little Elephant may create, among other possibilities, the number 047 or the number 47.
These are two different ways of erasing. 
They are both allowed and the numbers they produce have the same value.




Two ways of erasing the digits are considered different if there is some position in some element of S that was erased in one of the cases and was not erased in the other one.
For example, if S = (11, 12), there are two different ways to change it to (1, 2).
(In one of them we erase the first and in the other we erase the second digit of the number 11.)




After erasing the digits, Little Elephant wants to obtain a non-decreasing sequence.
Let R be the number of different ways to do that.
Return R modulo 1,000,000,007.


DEFINITION
Class:LittleElephantAndArray
Method:getNumber
Parameters:long long, int
Returns:int
Method signature:int getNumber(long long A, int N)


CONSTRAINTS
-A will be between 1 and 1,000,000,000,000,000 (10^15), inclusive.
-N will be between 0 and 100, inclusive.


EXAMPLES

0)
1
9

Returns: 1



1)
10
2

Returns: 15



2)
4747774
1

Returns: 8369



3)
6878542150015
74

Returns: 977836619



*/

// END CUT HERE
