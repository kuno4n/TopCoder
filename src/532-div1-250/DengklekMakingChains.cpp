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

class DengklekMakingChains {
    int check(string s){
        if(s[0]!='.' && s[2]=='.') return 1;
        if(s[0]=='.' && s[2]!='.') return 2;
        if(s[0]!='.' && s[1]=='.' && s[2]!='.'){
            if(s[0]>s[2]) return 1;
            else return 2;
        }
        if(s[0]!='.' && s[1]!='.' && s[2]!='.') return 3;
        return 0;
    }
    
	public:
	int maxBeauty(vector <string> chains) {
        vector <string> none, left, right, all;
        none.clear();
        all.clear();
        right.clear();
        left.clear();
        
        REP(i, SZ(chains)){
            if(check(chains[i]) == 0) none.push_back(chains[i]);
            if(check(chains[i]) == 1) left.push_back(chains[i]);
            if(check(chains[i]) == 2) right.push_back(chains[i]);
            if(check(chains[i]) == 3) all.push_back(chains[i]);
        }
        
        int l = 0;
        REP(i, SZ(left)){
            int cnt = 0;
            REP(j, 3){
                if(left[i][j] == '.') break;
                cnt += (int)left[i][j]-'0';
            }
            l = max(l, cnt);
        }
        
        int r = 0;
        REP(i, SZ(right)){
            int cnt = 0;
            for(int j=2; j>=0; j--){
                if(right[i][j] == '.') break;
                cnt += (int)right[i][j]-'0';
            }
            r = max(r, cnt);
        }
        
        int res = l+r;
        REP(i, SZ(all)){
            REP(j, 3){
                res += (int)all[i][j]-'0';
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
			string chains[]           = {".15", "7..", "402", "..3"};
			int expected__            = 19;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string chains[]           = {"..1", "7..", "567", "24.", "8..", "234"};
			int expected__            = 36;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string chains[]           = {"...", "..."};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string chains[]           = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"};
			int expected__            = 28;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string chains[]           = {"..1", "3..", "2..", ".7."};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string chains[]           = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"};
			int expected__            = 58;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string chains[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DengklekMakingChains().maxBeauty(vector <string>(chains, chains + (sizeof chains / sizeof chains[0])));
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
// Mr. Dengklek lives in the Kingdom of Ducks, where humans and ducks live together in peace and harmony. 



Mr. Dengklek works as a chain maker. Today, he would like to make a beautiful chain as a decoration for one of his lovely ducks. He will produce the chain from leftovers he found in his workshop. Each of the leftovers is a chain piece consisting of exactly 3 links. Each link is either clean or rusty. Different clean links may have different degrees of beauty.



You are given a vector <string> chains describing the leftovers. Each element of chains is a 3-character string describing one of the chain pieces. A rusty link is represented by a period ('.'), whereas a clean link is represented by a digit ('0'-'9'). The value of the digit in the clean link is the beauty of the link. For example, chains = {".15", "7..", "532", "..3"} means that Mr. Dengklek has 4 chain pieces, and only one of these ("532") has no rusty links.



All links have the same shape, which allows Mr. Dengklek to concatenate any two chain pieces. However, the link shape is not symmetric, therefore he may not reverse the chain pieces. E.g., in the above example he is able to produce the chain "532.15" or the chain ".15..37..", but he cannot produce "5323..".



To produce the chain, Mr. Dengklek will follow these steps:

Concatenate all chain pieces in any order.
Pick a contiguous sequence of links that contains no rusty links. Remove and discard all the remaining links.

The beauty of the new chain is the total beauty of all the links picked in the second step. Of course, Mr. Dengklek would like to create the most beautiful chain possible.



Return the largest possible beauty a chain can have according to the above rules.

DEFINITION
Class:DengklekMakingChains
Method:maxBeauty
Parameters:vector <string>
Returns:int
Method signature:int maxBeauty(vector <string> chains)


NOTES
-Mr. Dengklek is not allowed to remove and discard individual links before concatenating the chain pieces.
-If all links in the input are rusty, Mr. Dengklek is forced to select an empty sequence of links. The beauty of an empty sequence is 0.


CONSTRAINTS
-chains will contain between 1 and 50 elements, inclusive.
-Each element of chains will contain exactly 3 characters.
-Each character in each element of chains will be either a '.' or one of '0'-'9'.


EXAMPLES

0)
{".15", "7..", "402", "..3"}

Returns: 19

One possible solution:


In the first step, concatenate the chain pieces in the order "..3", ".15", "402", "7.." to obtain the chain "..3.154027..".
In the second step, pick the subsequence "154027".

The beauty of the chain in this solution is 1+5+4+0+2+7 = 19.

1)
{"..1", "7..", "567", "24.", "8..", "234"}

Returns: 36

One possible solution is to concatenate the chain pieces in this order:

"..1", "234", "567", "8..", "24.", "7.." -> "..12345678..24.7..",

and then to pick the subsequence "12345678". Its beauty is 1+2+3+4+5+6+7+8 = 36.

2)
{"...", "..."}

Returns: 0

Mr. Dengklek cannot pick any links.

3)
{"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}

Returns: 28



4)
{"..1", "3..", "2..", ".7."}

Returns: 7



5)
{"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}

Returns: 58



*/

// END CUT HERE
