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

class FriendScore {
	public:
	int highestScore(vector <string> friends) {
		int res = 0;
        int N = SZ(friends);
        REP(i, N){
            set<int> s;
            REP(j, N){
                if(friends[i][j] == 'Y'){
                    s.insert(j);
                    REP(k, N) if(friends[j][k] == 'Y' && k != i) s.insert(k);
                }
            }
            res = max(res, SZ(s));
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
			string friends[]          = {"NNN",
 "NNN",
 "NNN"};
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string friends[]          = {"NYY",
 "YNY",
 "YYN"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string friends[]          = {"NYNNN",
 "YNYNN", 
 "NYNYN", 
 "NNYNY", 
 "NNNYN"};
			int expected__            = 4;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string friends[]          = {"NNNNYNNNNN",
 "NNNNYNYYNN",
 "NNNYYYNNNN",
 "NNYNNNNNNN",
 "YYYNNNNNNY",
 "NNYNNNNNYN",
 "NYNNNNNYNN",
 "NYNNNNYNNN",
 "NNNNNYNNNN",
 "NNNNYNNNNN"};
			int expected__            = 8;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string friends[]          = {"NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNN",
 "NNNNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNYYNNNNNNNNNNN",
 "NNNNNYNNNNNYNNN",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNN",
 "YNNYYNNNNYNNNNN"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string friends[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string friends[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string friends[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = FriendScore().highestScore(vector <string>(friends, friends + (sizeof friends / sizeof friends[0])));
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
// You want to determine the most popular person in a social network.  To do this, you will count the number of "2-friends" that each person has.  Person A is called a 2-friend of another person B if they are friends with each other or if there exists some person C who is a friend of both A and B.  The most popular person is the person with the highest number of 2-friends.  (There might be more than one if multiple people all have the maximal number of 2-friends.)

You are given a vector <string> friends, where the j-th character of the i-th element is 'Y' if person i and person j are friends, and 'N' otherwise.  Return the number of 2-friends of the most popular person in this social network.

DEFINITION
Class:FriendScore
Method:highestScore
Parameters:vector <string>
Returns:int
Method signature:int highestScore(vector <string> friends)


CONSTRAINTS
-friends will contain between 1 and 50 elements, inclusive. 
-Each element of friends will contain exactly N characters 'Y' or 'N', where N is the number of elements in friends. 
-For each i and j, friends[i][j] will be equal to friends[j][i]. 
-For each i, friends[i][i] will be equal to 'N'. 


EXAMPLES

0)
{"NNN",
 "NNN",
 "NNN"}

Returns: 0

Here, there are 3 people and none of them are friends, so everybody has zero 2-friends.

1)
{"NYY",
 "YNY",
 "YYN"}

Returns: 2

Each person has two 2-friends.

2)
{"NYNNN",
 "YNYNN", 
 "NYNYN", 
 "NNYNY", 
 "NNNYN"}

Returns: 4

Persons 0 and 4 have two 2-friends, persons 1 and 3 have three 2-friends. Person 2 is the most popular one - four 2-friends.

3)
{"NNNNYNNNNN",
 "NNNNYNYYNN",
 "NNNYYYNNNN",
 "NNYNNNNNNN",
 "YYYNNNNNNY",
 "NNYNNNNNYN",
 "NYNNNNNYNN",
 "NYNNNNYNNN",
 "NNNNNYNNNN",
 "NNNNYNNNNN"}

Returns: 8



4)
{"NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNYNNNNNNN",
 "NNNNNNNYNNNNNNY",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNYYNNNNNNNNNNN",
 "NNNNNYNNNNNYNNN",
 "NNNNNNNNNNNNNNY",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNYNNNNNN",
 "NNNNNNNNNNNNNNN",
 "NNNNNNNNNNNNNNN",
 "YNNYYNNNNYNNNNN"}

Returns: 6



*/

// END CUT HERE
