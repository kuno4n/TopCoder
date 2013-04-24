
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


	   double sum[2500][2500];


class TheSwapsDivOne {
public:
   double find( vector <string> sequence, int k ) {
	   string s = "";
	   REP(i, SZ(sequence)) s += sequence[i];
	   int n = SZ(s);
	   int a = n*(n-1)/2;
	   double p = 1.0, q = 0.0;
	   REP(i, k){
		   double np, nq;
		   np = p*(a-n+1)/a + q*(n-1)/a;
		   nq = p/a + q*(a-1)/a;
		   p = np;
		   q = nq;
	   }

	   double tab[n];
	   REP(i, n) tab[i] = 0.0;
	   REP(i, n) REP(j, n){
		   if(i == j) tab[i] += p * (s[j]-'0');
		   else tab[i] += q * (s[j]-'0');
	   }

	   REP(i, n) sum[i][0] = tab[i];
	   REP(i, n) FOR(j, 1, n-i) sum[i][j] = sum[i][j-1] + tab[i+j];

	   double res = 0.0;
	   REP(i, n) REP(j, n-i){
		   res += sum[i][j];
	   }

	   return res/(a+n);

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
	
	static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
	double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }
	
	int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (topcoder_fequ(expected, received)) {
			verdict = "PASSED";
			double rerr = moj_relative_error(expected, received); 
			if (rerr > 0) {
				sprintf(buf, "relative error %.3e", rerr);
				info.push_back(buf);
			}
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
			string sequence[]         = {"4", "77"};
			int k                     = 1;
			double expected__         = 10.0;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string sequence[]         = {"4", "77"};
			int k                     = 47;
			double expected__         = 10.0;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string sequence[]         = {"1", "1", "1", "1", "1", "1", "1"};
			int k                     = 1000000;
			double expected__         = 3.0;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string sequence[]         = {"572685085149095989026478064633266980348504469", "19720257361", "9", "69"};
			int k                     = 7;
			double expected__         = 98.3238536775161;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string sequence[]         = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string sequence[]         = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string sequence[]         = ;
			int k                     = ;
			double expected__         = ;

			clock_t start__           = clock();
			double received__         = TheSwapsDivOne().find(vector <string>(sequence, sequence + (sizeof sequence / sizeof sequence[0])), k);
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
// John has a sequence of digits.
He and Brus will now play with the sequence.


First, John will repeat the following operation k times:
He will choose two different positions in the sequence, and swap the elements at those positions.
(John makes each choice uniformly at random.
That is, each time John chooses two positions, each pair of different positions has the same probability of being chosen.)


Afterwards, Brus will randomly choose a non-empty contiguous subsequence of John's sequence.
He will compute the sum of all elements in the chosen subsequence and he will write it down on a piece of paper.
(Brus also makes his choice uniformly at random.
That is, each possible contiguous subsequence has the same probability of being chosen.)


You are given a vector <string> sequence.
Concatenate all elements of sequence to get the string s.
For each i, the i-th character of s is a digit ('0'-'9') representing the digit at index i in John's original sequence.


Return the expected value of the sum Brus writes down.

DEFINITION
Class:TheSwapsDivOne
Method:find
Parameters:vector <string>, int
Returns:double
Method signature:double find(vector <string> sequence, int k)


NOTES
-The returned value must be accurate to within a relative or absolute value of 1E-9.


CONSTRAINTS
-sequence will contain between 2 and 47 elements, inclusive.
-Each element of sequence will contain between 1 and 47 characters, inclusive.
-Each element of sequence will consist of only decimal digits ('0'-'9').
-k will be between 1 and 1,000,000, inclusive.


EXAMPLES

0)
{"4", "77"}
1

Returns: 10.0

There are three equally likely swaps John might make.
If the first two elements are swapped, John will get the sequence {7,4,7}.
Then Brus chooses one of the six possible subsequences.
Their sums are 7, 4, 7, 11, 11 and 18.
Thus the expected value is (7 + 4 + 7 + 11 + 11 + 18)/6 = 29/3.

If the first and the last elements are swapped, the sequence becomes {7,7,4}, and the subsequence sums are 7, 7, 4, 14, 11 and 18.
The expected value in this case is (7 + 7 + 4 + 14 + 11 + 18)/6 = 61/6.

When the last two elements are swapped, the sequence doesn't change and the expected value is equal to 61/6 as well.
Finally, the overall expected value is equal to (29/3 + 61/6 + 61/6)/3 = 10.


1)
{"4", "77"}
47

Returns: 10.0



2)
{"1", "1", "1", "1", "1", "1", "1"}
1000000

Returns: 3.0



3)
{"572685085149095989026478064633266980348504469", "19720257361", "9", "69"}
7

Returns: 98.3238536775161



*/

// END CUT HERE
