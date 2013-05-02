
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
#include <queue>

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
#define OUT(A) cout << #A << " = "<< A << endl


string int2str(LL a){
    stringstream ss;
    ss << a;
    string res;
    ss >> res;
    return res;
}

long long _Pow(long long x, long long y){
    long long r=1, a=x;
    while(y > 0){
        if((y&1) == 1) r = r*a;
        a = a*a;
        y /= 2;
    }
    return r;
}

class MagicalSource {
public:
   long long calculate( long long x ) {

	   LL mul = 1;
	   LL res = -1;

	   while(mul <= x){
		   if(x % mul == 0) res = x / mul;
		   mul = mul*10 + 1;
	   }

	   return res;

	   //string s = int2str(x);
	   //
	   //for(int i=1; i <= SZ(s); i++){
		  // int kuri = 0;
		  // string cands = "";
		  // REP(j, i){
			 //  LL sum = kuri;
			 //  for(int k = 0; k < SZ(cands) && k < SZ(s) - i; k++){
				//   sum += cands[k] - '0';
			 //  }
			 //  LL tmp = s[SZ(s)-1-j] - '0';
			 //  tmp = (tmp + 10000 -sum) % 10;
			 //  sum += tmp;

			 //  string tmps = ""; tmps.PB(tmp+'0');
			 //  cands = tmps + cands;
			 //  kuri = sum / 10;
		  // }
		  // stringstream ss;
		  // ss << cands;
		  // LL cand;
		  // ss >> cand;
		  // LL tmp = cand, tmp2 = cand;
		  // while(tmp <= x && tmp != 0){
			 //  if(tmp == x) return cand;
			 //  tmp2 *= 10;
			 //  tmp += tmp2;
		  // }
	   //}
	   //return -1;
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
			long long x               = 1371110974;
			long long expected__      = 1234;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long x               = 111111;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long x               = 10989;
			long long expected__      = 99;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long x               = 120;
			long long expected__      = 120;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long x               = 109999999989LL;
			long long expected__      = 99;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 5: {
			long long x               = 999999999988LL;
			long long expected__      = 90909090908;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 6: {
			long long x               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long x               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = MagicalSource().calculate(x);
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
// Rick firmly believes that there are magical patterns related to some numbers. This belief is the result of his own tendency to find odd patterns everywhere. He has recently thought that some numbers have a "magical source". For example, the number 1371110974 has a magical source equal to 1234 because of the following process:


        1234
+      12340
+     123400
+    1234000
+   12340000
+  123400000
+ 1234000000
------------
  1371110974

Formally, 1234 is a magical source of 1371110974 because there exists a number n such that the sum of a sequence of n numbers, where the i-th number (0-indexed) is 1234 multipled by 10^i, is equal to 1371110974. Note that by this definition, a positive number is a magical source of itself.

Given a positive long long x, return its  minimum positive magical source.

DEFINITION
Class:MagicalSource
Method:calculate
Parameters:long long
Returns:long long
Method signature:long long calculate(long long x)


CONSTRAINTS
-x will be between 1 and 1000000000000 (10^12), inclusive.


EXAMPLES

0)
1371110974

Returns: 1234

This is the example from the statement.

1)
111111

Returns: 1



2)
10989

Returns: 99



3)
120

Returns: 120

Note that a number is always a magical source of itself.

4)
109999999989

Returns: 99



*/

// END CUT HERE
