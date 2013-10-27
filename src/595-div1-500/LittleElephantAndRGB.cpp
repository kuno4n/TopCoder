
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


int A[2510]; // A[i] : c‚ªiˆÈ~‚ÅAgood‚È[c,d]‚Ì”
int B[2510][2510]; // B[i][j] : c‚ªiˆÈ~‚ÅAÅ‰‚ÉjŒÂˆÈã‘±‚­[c,d]‚Ì”
int C[2510][2510]; // C[i][j] : c‚ªiˆÈ~‚ÅAÅ‰‚ÉjŒÂˆÈã‘±‚«A‚©‚Â‚Ç‚±‚©‚Ågood‚È[c,d]‚Ì”

class LittleElephantAndRGB {
public:
   long long getNumber( vector <string> list, int m) {
	string s = "";
	REP(i, SZ(list)) s += list[i];
	LL n = SZ(s);
	
	MSET(A, 0); MSET(B, 0); MSET(C, 0);
	
	REP(c, n){
		int first_cnt = 0;
		int cur_cnt = 0;
		bool first_G = true;
		bool cur_ok = false;
		for(int d = c; d < n; d++){
			if(s[d] == 'G'){
				if(first_G) first_cnt++;
				cur_cnt++;
				if(cur_cnt >= m) cur_ok = true;
			}
			else{
				first_G = false;
				cur_cnt = 0;
			}
			if(cur_ok) A[c]++, C[c][first_cnt]++;
			B[c][first_cnt]++;
		} 
		for(int i = 2500; i >= 0; i--) B[c][i] += B[c][i+1], C[c][i] += C[c][i+1];
	}
	for(int i = 2500; i >= 0; i--){
		A[i] += A[i+1];
		REP(j, 2510){
			B[i][j] += B[i+1][j];
			C[i][j] += C[i+1][j];
		}
	}
	
	
	LL res = 0;
	for(int a = 0; a < n-1; a++){
		int cur_cnt = 0;
		int cur_ok = false;
		for(int b = a; b < n-1; b++){
			if(s[b] == 'G'){
				cur_cnt++;
				if(cur_cnt >= m) cur_ok = true;
			}
			else cur_cnt = 0;
			
			if(cur_ok) res += (LL)(n-b-1)*(n-b)/2;
			else{
				res += (LL)A[b+1];
				res += (LL)B[b+1][max(0, m-cur_cnt)];
				res -= (LL)C[b+1][max(0, m-cur_cnt)];
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
			string list[]             = {"GRG"};
			int minGreen              = 2;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string list[]             = {"GG", "GG"};
			int minGreen              = 3;
			long long expected__      = 9;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string list[]             = {"GRBGRBBRG"};
			int minGreen              = 2;
			long long expected__      = 11;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string list[]             = {"RRBRBBRRR", "R", "B"};
			int minGreen              = 1;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string list[]             = {"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"};
			int minGreen              = 4;
			long long expected__      = 12430;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string list[]             = ;
			int minGreen              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string list[]             = ;
			int minGreen              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string list[]             = ;
			int minGreen              = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = LittleElephantAndRGB().getNumber(vector <string>(list, list + (sizeof list / sizeof list[0])), minGreen);
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
Little Elephant from the Zoo of Lviv likes strings that consist of characters 'R', 'G' and 'B'. You are given a vector <string> list. Concatenate all elements of list to get the string S of length N. The characters in S are numbered from 0 to N-1, inclusive.




You are also given int minGreen. Little Elephant thinks that string is nice if and only if it contains a substring of at least minGreen consecutive characters 'G'. For example, if minGreen = 2, then strings "GG", "GGRGBB" and "RRRGRBGGG" are nice, but "G", "GRG", "BBRRGRGB" are not.




Little Elephant wants to know the number of quadruples of integers (a,b,c,d) such that:

Each of a, b, c, d is between 0 and N-1, inclusive.
a <= b and c <= d. (Both a..b and c..d are valid ranges of values.)
b < c. (The entire range a..b lies before the range c..d.)
The string T = S[a..b] + S[c..d] is nice.

Compute and return the number of such quadruples (a,b,c,d).


DEFINITION
Class:LittleElephantAndRGB
Method:getNumber
Parameters:vector <string>, int
Returns:long long
Method signature:long long getNumber(vector <string> list, int minGreen)


CONSTRAINTS
-list will contain between 1 and 50 elements, inclusive.
-Each element of list will contain between 1 and 50 characters, inclusive.
-Each element of list will consist only of characters 'R', 'G' and 'B'.
-minGreen will be between 1 and 2500, inclusive.


EXAMPLES

0)
{"GRG"}
2

Returns: 1

The only valid quadruple is (0,0,2,2).
For this quadruple we have S[a..b]="G" and S[c..d]="G", thus T = "GG".

1)
{"GG", "GG"}
3

Returns: 9

There are 3 valid quadruples such that T="GGGG" and 6 quadruples such that T="GGG".

2)
{"GRBGRBBRG"}
2

Returns: 11

One of the valid quadruples is (0,0,3,5).
This quadruple corresponds to the nice string T="GGRB".

3)
{"RRBRBBRRR", "R", "B"}
1

Returns: 0



4)
{"GRGGGRBRGG", "GGGGGGGG", "BRGRBRB"}
4

Returns: 12430



*/

// END CUT HERE
