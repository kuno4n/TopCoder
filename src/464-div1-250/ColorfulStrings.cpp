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

bool isC(string str){
    set<LL> s;
    REP(i, SZ(str)){
        FOR(j, i, SZ(str)){
            LL l = 1;
            FOR(k, i, j+1) l *= str[k]-'0';
            if(s.count(l)) return false;
            s.insert(l);
        }
    }
    return true;
}

class ColorfulStrings {
	public:
	string getKth(int n, int k) {
        if(n>8) return "";
        if(n == 1){
            if(k>10) return "";
            string a = "" ;
            a += (char)(k-1+'0');
            return a;
        }
        
        int cnt = 0;
        string s = "";
        REP(i, 8) s = s+(char)(i+2+'0');
        set <string> ss;
        do{
            string a = s.substr(0,n);
            if(ss.count(a) == 0 && isC(a)){
                ss.insert(a);
                cnt++;
                if(cnt == k) return a;
            }
            reverse(s.begin()+n, s.end());
        }while(next_permutation(ALL(s)));
        
        return "";
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
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
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
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum__) {
		switch (casenum__) {
		case 0: {
			int n                     = 3;
			int k                     = 4;
			string expected__         = "238";

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int n                     = 4;
			int k                     = 2000;
			string expected__         = "";

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int n                     = 5;
			int k                     = 1;
			string expected__         = "23457";

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int n                     = 2;
			int k                     = 22;
			string expected__         = "52";

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int n                     = 6;
			int k                     = 464;
			string expected__         = "257936";

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int n                     = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int n                     = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int n                     = ;
			int k                     = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = ColorfulStrings().getKth(n, k);
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
// The product value of a string is 
the product of all the digits ('0'-'9') in the string. 
For example, the product value of "123" is 1 * 2 * 3 = 6. 
A string is called colorful if it contains only digits 
and the product value of each of its nonempty contiguous substrings is distinct. 

For example, the string "263" has six substrings: "2", "6", "3", "26", "63" and "263". 
The product values of these substrings are: 2, 6, 3, 2 * 6 = 12, 6 * 3 = 18 
and 2 * 6 * 3 = 36, respectively. 
Since all six product values are distinct, "263" is colorful. 
On the other hand, "236" is not colorful 
because two of its substrings, "6" and "23", have the same product value (6 = 2 * 3). 

Return the k-th (1-based) lexicographically smallest 
colorful string of length n. 
If there are less than k colorful strings of length n, 
return an empty string instead. 


DEFINITION
Class:ColorfulStrings
Method:getKth
Parameters:int, int
Returns:string
Method signature:string getKth(int n, int k)


NOTES
-The lexicographically smaller of two strings is the one that has the smaller character ('0' < '1' < ... < '9') at the first position where they differ. 


CONSTRAINTS
-n will be between 1 and 50, inclusive. 
-k will be between 1 and 1,000,000,000, inclusive. 


EXAMPLES

0)
3
4

Returns: "238"

The first four smallest colorful strings of length 3 are "234", "235", "237" and "238".


1)
4
2000

Returns: ""

The number of colorful strings of length 4 is less than 2000.


2)
5
1

Returns: "23457"

3)
2
22

Returns: "52"

4)
6
464

Returns: "257936"



*/

// END CUT HERE
