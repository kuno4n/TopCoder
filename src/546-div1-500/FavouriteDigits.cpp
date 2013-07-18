
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



int L;
string org;

LL cal(string s){
	if(s[0] == '0'){
		s = "1" + s;
		REP(i, SZ(s)) if(s[i] == '?') s[i] = '0';
		return str2int(s);
	}
	if(s[0] != '?'){
		REP(i, SZ(s)) if(s[i] == '?') s[i] = '0';
		return str2int(s);
	}
	
	string res(SZ(s), '9');
	string tmp = s;
	REP(i, SZ(tmp)) if(tmp[i] == '?') tmp[i] = '0';
	REP(i, SZ(tmp)) if(s[i] == '?'){
		if(org[i] != '9') tmp[i] = org[i]+1;
		if(tmp >= org) chmin(res, tmp);
		tmp[i] = org[i];
		if(tmp >= org) chmin(res, tmp);
		if(res[i] == org[i]) return str2int(res);
	}
	
	return str2int(res);
	
}



class FavouriteDigits {
public:
   long long findNext( long long N, int digit1, int count1, int digit2, int count2 ) {
	org = "0" + int2str(N);
	L = SZ(org);
	string str = "";
	REP(i, count1) str.push_back(digit1+'0');
	REP(i, count2) str.push_back(digit2+'0');
	while(SZ(str) < L) str.push_back('?');
	sort(ALL(str));
	
	LL res = (1LL<<60);
	
	do{
		chmin(res, cal(str));
	}while(next_permutation(ALL(str)));
	
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
			long long N               = 47;
			int digit1                = 1;
			int count1                = 0;
			int digit2                = 2;
			int count2                = 0;
			long long expected__      = 47;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long N               = 47;
			int digit1                = 5;
			int count1                = 0;
			int digit2                = 9;
			int count2                = 1;
			long long expected__      = 49;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long N               = 47;
			int digit1                = 5;
			int count1                = 0;
			int digit2                = 3;
			int count2                = 1;
			long long expected__      = 53;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long N               = 47;
			int digit1                = 2;
			int count1                = 1;
			int digit2                = 0;
			int count2                = 2;
			long long expected__      = 200;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long N               = 123456789012345LL;
			int digit1                = 1;
			int count1                = 2;
			int digit2                = 2;
			int count2                = 4;
			long long expected__      = 123456789012422LL;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long N               = 92;
			int digit1                = 1;
			int count1                = 1;
			int digit2                = 0;
			int count2                = 0;
			long long expected__      = 100;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

      case 6: {
			long long N               = 999;
			int digit1                = 0;
			int count1                = 8;
			int digit2                = 4;
			int count2                = 0;
			long long expected__      = 100000000;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
      case 7: {
			long long N               = 999;
			int digit1                = 1;
			int count1                = 1;
			int digit2                = 1;
			int count2                = 0;
			long long expected__      = 1000;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
/*      case 8: {
			long long N               = ;
			int digit1                = ;
			int count1                = ;
			int digit2                = ;
			int count2                = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = FavouriteDigits().findNext(N, digit1, count1, digit2, count2);
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
Tetka Rapotacka just heard a juicy rumor about one of her neighbors: poor Jachym has lost N kacky (their local monetary unit) on a slot machine yesterday.
Tetka Rapotacka now plans to share this rumor with everyone, including Tetka Klepetacka.
Tetka Rapotacka has two favourite digits: digit1 and digit2.
She only likes numbers that contain at least count1 occurrences of digit1 and at least count2 occurrences of digit2.
When gossiping, she only uses numbers she likes.
So if she does not like the number N, she will increase it until she finds a number that she likes.


You are given the long long N and the four ints digit1, count1, digit2, and count2.
Return the smallest integer that is greater than or equal to N, contains at least count1 occurrences of digit digit1, and at least count2 occurrences of digit digit2.


DEFINITION
Class:FavouriteDigits
Method:findNext
Parameters:long long, int, int, int, int
Returns:long long
Method signature:long long findNext(long long N, int digit1, int count1, int digit2, int count2)


NOTES
-The constraints guarantee that the return value will always fit into a long long.


CONSTRAINTS
-N will be between 1 and 10^15 - 1, inclusive.
-digit1 will be between 0 and 9, inclusive.
-digit2 will be between 0 and 9, inclusive.
-digit1 and digit2 will not be equal.
-count1 will be at least 0.
-count2 will be at least 0.
-count1+count2 will be at most 15.


EXAMPLES

0)
47
1
0
2
0

Returns: 47

As count1=0 and count2=0, Tetka Rapotacka likes all numbers.

1)
47
5
0
9
1

Returns: 49

The number has to contain the digit 9. The next number that contains this digit is 49.

2)
47
5
0
3
1

Returns: 53



3)
47
2
1
0
2

Returns: 200

The correct return value may have more digits than N.

4)
123456789012345
1
2
2
4

Returns: 123456789012422



5)
92
1
1
0
0

Returns: 100



*/

// END CUT HERE
