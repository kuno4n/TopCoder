#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
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
#define FIT(it,v) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define OUT(A) cout << #A << " = " << A << endl

class InterestingParty {
	public:
	int bestInvitation(vector <string> first, vector <string> second) {
		set<string> s;
        int N = SZ(first);
        
        REP(i, N){
            s.insert(first[i]);
            s.insert(second[i]);
        }
        
        int res = 0;
        FIT(it, s){
            int tmp = 0;
            REP(i, N){
                tmp += (first[i] == *it || second[i] == *it);
            }
            res = max(res, tmp);
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
			string first[]            = {"fishing", "gardening", "swimming", "fishing"};
			string second[]           = {"hunting", "fishing", "fishing", "biting"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string first[]            = {"variety", "diversity", "loquacity", "courtesy"};
			string second[]           = {"talking", "speaking", "discussion", "meeting"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string first[]            = {"snakes", "programming", "cobra", "monty"};
			string second[]           = {"python", "python", "anaconda", "python"};
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string first[]            = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
 "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
			string second[]           = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", 
 "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string first[]            = ;
			string second[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string first[]            = ;
			string second[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string first[]            = ;
			string second[]           = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = InterestingParty().bestInvitation(vector <string>(first, first + (sizeof first / sizeof first[0])), vector <string>(second, second + (sizeof second / sizeof second[0])));
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
// Mr. White is a very versatile person - absolutely everything is interesting to him. Perhaps this is why he has many friends. Quite unfortunately, however, none of his friends are versatile at all. Each of them is interested only in two topics and refuses to talk about anything else. Therefore, each time Mr. White organizes a party, it's a big problem for him to decide whom to invite so that the party is interesting to everybody. 
Now that Mr. White has a lot of experience in organizing parties, he knows for sure that a party will be interesting if and only if there's a topic interesting to each of the invited friends.

You will be given vector <string>s first and second. The i-th friend of Mr. White is interested in topics first[i] and second[i]. 
Return the largest number of friends that Mr. White can invite to his party so that the party will be interesting.

DEFINITION
Class:InterestingParty
Method:bestInvitation
Parameters:vector <string>, vector <string>
Returns:int
Method signature:int bestInvitation(vector <string> first, vector <string> second)


CONSTRAINTS
-first will contain between 1 and 50 elements, inclusive.
-second will contain the same number of elements as first.
-Each element of first and second will contain between 1 and 15 characters, inclusive.
-Each character in first and second will be a lowercase letter ('a'-'z').
-For each valid i, first[i] will not be the same as second[i].


EXAMPLES

0)
{"fishing", "gardening", "swimming", "fishing"}
{"hunting", "fishing", "fishing", "biting"}

Returns: 4

This is a very easy case since everybody is interested in "fishing".

1)
{"variety", "diversity", "loquacity", "courtesy"}
{"talking", "speaking", "discussion", "meeting"}

Returns: 1

Despite being interested in "talking", "speaking", "meeting" and so on, these people have nothing to talk about with each other.

2)
{"snakes", "programming", "cobra", "monty"}
{"python", "python", "anaconda", "python"}

Returns: 3

Mr. White can invite friends 0, 1, 3 (0-based) and they will have an interesting evening talking about "python" (or at least Mr. White thinks so).

3)
{"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
 "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"}
{"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", 
 "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"}

Returns: 6



*/

// END CUT HERE
