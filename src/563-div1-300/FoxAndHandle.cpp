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

class FoxAndHandle {
    string s;
    int cnt1[26];
    
    bool can(string S){
        int cnt2[26], cnt3[26];
        MSET(cnt2, 0);
        MSET(cnt3, 0);
        
        int ptr = 0;
        REP(i, SZ(s)){
            if(S[ptr] == s[i]){
                if(++cnt2[s[i]-'a'] > cnt1[s[i]-'a']/2) return false;
                ptr++;
                if(ptr == SZ(S)) return true;
            }
            else{
                if(++cnt3[s[i]-'a'] > cnt1[s[i]-'a']/2) return false;
            }
        }
        return false;
    }
    
    
	public:
	string lexSmallestName(string S) {
        s = S;
        MSET(cnt1, 0);
        REP(i, SZ(S)) cnt1[S[i]-'a']++;
        
        string res = "";
        REP(i, SZ(S)/2){
            for(char ch = 'a'; ch <= 'z'; ch++){
                if(can(res+ch)){
                    res += ch;
                    break;
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
			string S                  = "foxfox";
			string expected__         = "fox";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string S                  = "ccieliel";
			string expected__         = "ceil";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string S                  = "abaabbab";
			string expected__         = "aabb";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string S                  = "bbbbaaaa";
			string expected__         = "bbaa";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string S                  = "fedcbafedcba";
			string expected__         = "afedcb";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			string S                  = "nodevillivedon";
			string expected__         = "deilvon";

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			string S                  = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxAndHandle().lexSmallestName(S);
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
// We say that a string Z can be obtained by shuffling two strings X and Y together, if it is possible to interleave the letters of X and Y so that Z is obtained. It is not allowed to change the order of letters in X and Y.
For example, you can shuffle the strings X="abcd" and Y="efg" to produce any of the strings "abcdefg", "aebfcgd", "abcefgd", or "eabcfdg", but you cannot produce the string "bacdefg".



Formally, let Shuffle(X,Y) be the set of all strings that can be produced by shuffling X and Y together.
We can define Shuffle inductively as follows:

for any string X: Shuffle("",X) = Shuffle(X,"") = { X }
for any letters a, b and any strings X, Y:
Shuffle(aX,bY) = { aZ : Z belongs to Shuffle(X,bY) } united with { bZ : Z belongs to Shuffle(aX,Y) }.




Fox Ciel wants to register on TopCoder.
In order to do that, she has to pick a handle.
Ciel has a pet cat called S.
As her handle, Ciel wants to use a string H with the following property:
S can be obtained by shuffling H and some permutation of H together.
For example, if S="ceiiclel", one possible handle would be H="ciel":
she can permute H to obtain H'="eicl", and then shuffle these H and H' together to produce S.



You are given the string S.
The constraints guarantee that there is at least one possible handle H with the above property.
Find and return the lexicographically smallest valid H.

DEFINITION
Class:FoxAndHandle
Method:lexSmallestName
Parameters:string
Returns:string
Method signature:string lexSmallestName(string S)


CONSTRAINTS
-S will contain between 2 and 50 characters, inclusive.
-Each character of S will be a lowercase letter ('a'-'z').
-Each letter ('a'-'z') will occur in S an even number of times.


EXAMPLES

0)
"foxfox"

Returns: "fox"

There are five possible handles for Fox Ciel in this test case: "fox", "fxo", "ofx", "oxf", and "xfo".
The lexicographically smallest one is "fox".

1)
"ccieliel"

Returns: "ceil"

Note that "ciel" is also a valid handle, but "ceil" is lexicographically smaller.

2)
"abaabbab"

Returns: "aabb"



3)
"bbbbaaaa"

Returns: "bbaa"



4)
"fedcbafedcba"

Returns: "afedcb"



5)
"nodevillivedon"

Returns: "deilvon"



*/

// END CUT HERE
