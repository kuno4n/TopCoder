
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

LL str2int(string s){
    LL res = 0;
    REP(i, SZ(s)){
        res *= 10;
        res += s[i]-'0';
    }
    return res;
}

int n;
int st_l, st_r;
int s[3000], t[3000];	
int dl[3000], dr[3000];

class ShoutterDiv1 {
public:
   int count( vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1 ) {
	n = 0;
	REP(i, SZ(s1)) REP(j, SZ(s1[i])){
		string ss = "", tt = "";
		ss += s1000[i][j];
		ss += s100[i][j];
		ss += s10[i][j];
		ss += s1[i][j];
		tt += t1000[i][j];
		tt += t100[i][j];
		tt += t10[i][j];
		tt += t1[i][j];
		s[n] = str2int(ss);
		t[n] = str2int(tt);
		n++;
	}
	st_l = 10000, st_r = -1;
	REP(i, n){
		st_l = min(st_l, t[i]);
		st_r = max(st_r, s[i]);
	}
	REP(i, n) dl[i] = i, dr[i] = i;
	REP(i, n) REP(j, n){
		if(s[i] <= t[j] && s[j] < s[dl[i]]) dl[i] = j;
		if(s[j] <= t[i] && t[dr[i]] < t[j]) dr[i] = j;
	}
	int cnt = 0;
	REP(i, n){
		
	}
	return cnt;
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
			string s1000[]            = {"22", "2"};
			string s100[]             = {"00", "0"};
			string s10[]              = {"11", "1"};
			string s1[]               = {"21", "4"};
			string t1000[]            = {"22", "2"};
			string t100[]             = {"00", "0"};
			string t10[]              = {"11", "1"};
			string t1[]               = {"43", "6"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string s1000[]            = {"00"};
			string s100[]             = {"00"};
			string s10[]              = {"00"};
			string s1[]               = {"13"};
			string t1000[]            = {"00"};
			string t100[]             = {"00"};
			string t10[]              = {"00"};
			string t1[]               = {"24"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string s1000[]            = {"0000"};
			string s100[]             = {"0000"};
			string s10[]              = {"0000"};
			string s1[]               = {"1234"};
			string t1000[]            = {"0000"};
			string t100[]             = {"0000"};
			string t10[]              = {"0000"};
			string t1[]               = {"2345"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string s1000[]            = {"0000000000"};
			string s100[]             = {"0000000000"};
			string s10[]              = {"0000000000"};
			string s1[]               = {"7626463146"};
			string t1000[]            = {"0000000000"};
			string t100[]             = {"0000000000"};
			string t10[]              = {"0000000000"};
			string t1[]               = {"9927686479"};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			string s1000[]            = {"00000000000000000000000000000000000000000000000000"};
			string s100[]             = {"00000000000000000000000000000000000000000000000000"};
			string s10[]              = {"50353624751857130208544645495168271486083954769538"};
			string s1[]               = {"85748487990028258641117783760944852941545064635928"};
			string t1000[]            = {"00000000000000000000000000000000000000000000000000"};
			string t100[]             = {"00000000000000000000000000000000000000000000000000"};
			string t10[]              = {"61465744851859252308555855596388482696094965779649"};
			string t1[]               = {"37620749792666153778227385275518278477865684777411"};
			int expected__            = 333;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string s1000[]            = ;
			string s100[]             = ;
			string s10[]              = ;
			string s1[]               = ;
			string t1000[]            = ;
			string t100[]             = ;
			string t10[]              = ;
			string t1[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string s1000[]            = ;
			string s100[]             = ;
			string s10[]              = ;
			string s1[]               = ;
			string t1000[]            = ;
			string t100[]             = ;
			string t10[]              = ;
			string t1[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string s1000[]            = ;
			string s100[]             = ;
			string s10[]              = ;
			string s1[]               = ;
			string t1000[]            = ;
			string t100[]             = ;
			string t10[]              = ;
			string t1[]               = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = ShoutterDiv1().count(vector <string>(s1000, s1000 + (sizeof s1000 / sizeof s1000[0])), vector <string>(s100, s100 + (sizeof s100 / sizeof s100[0])), vector <string>(s10, s10 + (sizeof s10 / sizeof s10[0])), vector <string>(s1, s1 + (sizeof s1 / sizeof s1[0])), vector <string>(t1000, t1000 + (sizeof t1000 / sizeof t1000[0])), vector <string>(t100, t100 + (sizeof t100 / sizeof t100[0])), vector <string>(t10, t10 + (sizeof t10 / sizeof t10[0])), vector <string>(t1, t1 + (sizeof t1 / sizeof t1[0])));
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
A group of freshman rabbits has recently joined the Eel club.
No two of the rabbits knew each other.
Yesterday, each of the rabbits went to the club for the first time.
For each i, rabbit number i entered the club at the time s[i] and left the club at the time t[i].


Each pair of rabbits that was in the club at the same time got to know each other, and they became friends on the social network service Shoutter.
This is also the case for rabbits who just met for a single moment (i.e., one of them entered the club exactly at the time when the other one was leaving).


In Shoutter, each user can post a short message at any time.
The message can be read by the user's friends.
The friends can also repost the message, making it visible to their friends that are not friends with the original poster.
In turn, those friends can then repost the message again, and so on.
Each message can be reposted in this way arbitrarily many times. 
If a rabbit wants to repost multiple messages, he must repost each of them separately.


Today, each of the rabbits posted a self-introduction to Shoutter.
Each rabbit would now like to read the self-introductions of all other rabbits (including those that are currently not his friends).
Compute and return the minimal number of reposts necessary to reach this goal.
If it is impossible to reach the goal, return -1 instead.


As the number of rabbits can be greater than what the TopCoder arena supports, you are given the times s[i] and t[i] encoded in the following form:
You are given vector <string>s s1000, s100, s10, and s1.
Concatenate all elements of s1000 to obtain a string S1000.
In the same way obtain the strings S100, S10, and S1.
Character i of each of these strings corresponds to the rabbit number i.
More precisely, these characters are the digits of s[i]:
we obtain s[i] by converting the string S1000[i]+S100[i]+S10[i]+S1[i] to an integer.
For example, if S1000[4]='0', S100[4]='1', S10[4]='4', and S1[4]='7', then s[4]=to_integer("0147")=147.
You are also given vector <string>s t1000, t100, t10, and t1.
These encode the times t[i] in the same way.


DEFINITION
Class:ShoutterDiv1
Method:count
Parameters:vector <string>, vector <string>, vector <string>, vector <string>, vector <string>, vector <string>, vector <string>, vector <string>
Returns:int
Method signature:int count(vector <string> s1000, vector <string> s100, vector <string> s10, vector <string> s1, vector <string> t1000, vector <string> t100, vector <string> t10, vector <string> t1)


CONSTRAINTS
-s1000, s100, s10, s1, t1000, t100, t10 and t1 will each contain between 1 and 50 elements, inclusive.
-s1000, s100, s10, s1, t1000, t100, t10 and t1 will contain the same number of elements.
-Each element of s1000, s100, s10, s1, t1000, t100, t10 and t1 will contain between 1 and 50 characters, inclusive.
-For each i, the i-th elements of all input variables will all contain the same number of characters.
-Each character in the input variables will be a digit ('0'-'9').
-For each i, t[i] will be greater than or equal to s[i].


EXAMPLES

0)
{"22", "2"}
{"00", "0"}
{"11", "1"}
{"21", "4"}
{"22", "2"}
{"00", "0"}
{"11", "1"}
{"43", "6"}

Returns: 2

After parsing the input, you will get the following information: Rabbit 0 will enter the room at 2012 and leave the room at 2014. Rabbit 1 will enter the room at 2011 and leave the room at 2013. Rabbit 2 will enter the room at 2014 and leave the room at 2016. Therefore, Rabbit 0 and Rabbit 1 will be friends, and Rabbit 0 and Rabbit 2 will be friends too, but Rabbit 1 and Rabbit 2 won't be friends.


Rabbit 0 can already see the self-introductions of all rabbits, but rabbits 1 and 2 cannot see each other's self-introduction.
Two actions are needed: First, Rabbit 0 reposts the self-introduction of Rabbit 1, and then Rabbit 0 reposts the self-introduction of Rabbit 2.
Now everybody can read everything.

1)
{"00"}
{"00"}
{"00"}
{"13"}
{"00"}
{"00"}
{"00"}
{"24"}

Returns: -1

If it is impossible to achieve the goal, return -1.

2)
{"0000"}
{"0000"}
{"0000"}
{"1234"}
{"0000"}
{"0000"}
{"0000"}
{"2345"}

Returns: 6

The following pairs will be friends: Rabbit 0 and 1, 1 and 2, and 2 and 3. One of the optimal strategies is as follows:

Rabbit 1 shares introductions of Rabbit 0 and 2.
Rabbit 2 shares introductions of Rabbit 1 and 3.
Rabbit 1 shares introduction of Rabbit 3 (this is possible because now Rabbit 3's introduction is shared by Rabbit 2, who is a Rabbit 1's friend).
Rabbit 2 shares introduction of Rabbit 0 (this is possible because now Rabbit 0's introduction is shared by Rabbit 1, who is a Rabbit 2's friend).


3)
{"0000000000"}
{"0000000000"}
{"0000000000"}
{"7626463146"}
{"0000000000"}
{"0000000000"}
{"0000000000"}
{"9927686479"}

Returns: 18



4)
{"00000000000000000000000000000000000000000000000000"}
{"00000000000000000000000000000000000000000000000000"}
{"50353624751857130208544645495168271486083954769538"}
{"85748487990028258641117783760944852941545064635928"}
{"00000000000000000000000000000000000000000000000000"}
{"00000000000000000000000000000000000000000000000000"}
{"61465744851859252308555855596388482696094965779649"}
{"37620749792666153778227385275518278477865684777411"}

Returns: 333



*/

// END CUT HERE
