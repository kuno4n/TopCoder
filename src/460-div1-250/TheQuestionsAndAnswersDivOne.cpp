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

#define EPS 1e-9

LL fact(int n){
    LL res = 1;
    while(n!=1){
        res *= n;
        n--;
    }
    return res;
}

LL c(int n, int k){
    if(k == 0 || n==k) return 1;
    return fact(n)/fact(n-k)/fact(k);
}

LL h(int nn, int n){
    if(n == 0) return 1;
    LL res = 0;
    REP(i, nn){
        LL tmp = c(nn, nn-i) * pow(nn-i, (double)n);
        res += i%2 ? -tmp : tmp;
    }
    return res;
}

class TheQuestionsAndAnswersDivOne {
	public:
	int find(int questions, vector <string> answers) {
        int y = 0, n = 0;
        REP(i, SZ(answers)){
            if(answers[i] == "Yes") y++;
            else n++;
        }
        int res = 0;
		REP(mask, (1<<questions)){
            int yy = 0, nn = 0;
            REP(j, questions){
                if(mask & (1<<j)) yy++;
                else nn++;
            }
            if(yy > y || nn > n) continue;
            if(yy == 0 && y > 0) continue;
            if(nn == 0 && n > 0) continue;
            res += h(yy,y) * h(nn,n);
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
			int questions             = 2;
			string answers[]          = {"No", "Yes"};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int questions             = 2;
			string answers[]          = {"No", "No", "No"};
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int questions             = 3;
			string answers[]          = {"Yes", "No", "No", "Yes"};
			int expected__            = 12;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int questions             = 3;
			string answers[]          = {"Yes", "Yes", "Yes", "No"};
			int expected__            = 18;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int questions             = ;
			string answers[]          = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = TheQuestionsAndAnswersDivOne().find(questions, vector <string>(answers, answers + (sizeof answers / sizeof answers[0])));
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
John and Brus have become very famous people all over the world, especially in Bolivia.
A man in Bolivia decided to write a story about them.
To make the story more truthful, he set up an interview with John.
He prepared a list of distinct simple "Yes" or "No" questions and he enlisted the help of two friends to transcribe the interview.
Each time he asked a question, one friend wrote down the question while the other friend wrote down the answer.
He was very nervous when conducting the interview, so he might have asked some of the questions multiple times.
However, John's answers always remained the same for the same questions.



Unfortunately, the friend who was writing down the questions lost his list.
In a desperate attempt to remember the order in which he asked the questions, the Bolivian has decided to write down all the possible ways that he might have asked them.
He knows for sure that he asked every question from his list at least once.
You are given an int questions, which is the number of questions that were in his list, and a vector <string> answers, the i-th element of which is the answer to the i-th question he asked.
Return the total number of ways in which he might have asked the questions.



DEFINITION
Class:TheQuestionsAndAnswersDivOne
Method:find
Parameters:int, vector <string>
Returns:int
Method signature:int find(int questions, vector <string> answers)


CONSTRAINTS
-questions will be between 2 and 9, inclusive.
-answers will contain between questions and 9 elements, inclusive.
-Each element of answers will be either "Yes" or "No".


EXAMPLES

0)
2
{"No", "Yes"}

Returns: 2

The two possible ways are: the first question followed by the second question, or vice versa.

1)
2
{"No", "No", "No"}

Returns: 6

2)
3
{"Yes", "No", "No", "Yes"}

Returns: 12



3)
3
{"Yes", "Yes", "Yes", "No"}

Returns: 18

*/

// END CUT HERE
