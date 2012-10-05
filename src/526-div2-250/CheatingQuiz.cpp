
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
#define OUT(A) cout << #A << ' = '<< A << endl

class CheatingQuiz {
public:
   vector <int> howMany( string answers ) {
	   set<char> s;
	   VI res;
	   for(int i=SZ(answers)-1; i>=0; i--){
		   s.insert(answers[i]);
		   res.PB(SZ(s));
	   }
	   sort(ALL(res), greater < int >());
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) { 
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
			string answers            = "AAAAA";
			int expected__[]          = {1, 1, 1, 1, 1 };

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			string answers            = "AAABBB";
			int expected__[]          = {2, 2, 2, 1, 1, 1 };

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			string answers            = "CAAAAAC";
			int expected__[]          = {2, 2, 2, 2, 2, 2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			string answers            = "BBCA";
			int expected__[]          = {3, 3, 2, 1 };

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 4: {
			string answers            = "BACACABCBBBBCAAAAACCCABBCAA";
			int expected__[]          = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1 };

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string answers            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			string answers            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 7: {
			string answers            = ;
			int expected__[]          = ;

			clock_t start__           = clock();
			vector <int> received__   = CheatingQuiz().howMany(answers);
			return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
// Mr. Dengklek is taking part in an online quiz. The quiz consists of N multiple-choice questions, conveniently numbered 0 through N-1. For each question there are three possible answers labeled A, B, and C. For each question, exactly one of the three possible answers is correct. You are given the information on correct answers as a string answers. More precisely, answers[i] is the correct answer to the i-th question. This is of course unknown to Mr. Dengklek.

Mr. Dengklek did not know the answer to any of the quiz questions. Being desperate, he hacked the website of the quiz. However, the only thing he could obtain was aggregate information on the answers that will be used. More precisely, thanks to the hack Mr. Dengklek now knows how many questions have the answer A, how many have the answer B, and how many have the answer C.

When taking the quiz, Mr. Dengklek will be given the questions one at a time, in the same order that is used in answers. For each of the questions, he will use his intuition to pick one of the answers that are still possible. After he picks the answer for a question, the quiz will always show him the correct answer for that question.

Mr. Dengklek has noticed that sometimes he can rule out some of the answers when answering a question. Your method must return a vector <int> containing N elements. The i-th element in this vector <int> must be the number of options Mr. Dengklek will choose from when answering the i-th question.


DEFINITION
Class:CheatingQuiz
Method:howMany
Parameters:string
Returns:vector <int>
Method signature:vector <int> howMany(string answers)


CONSTRAINTS
-answers will contain between 1 and 50 characters, inclusive.
-Each character of answers will be 'A', 'B', or 'C'.


EXAMPLES

0)
"AAAAA"

Returns: {1, 1, 1, 1, 1 }

Mr. Dengklek knows that A is the correct answer to all questions. Therefore, for each question, he only has one choice: answering A.

1)
"AAABBB"

Returns: {2, 2, 2, 1, 1, 1 }

Mr. Dengklek knows that there will be three As and three Bs. For each of the first three questions he has two choices: answering A or B. After answering the third question, he will discover that all As have been used, so for each of the remaining questions he only has one choice: answering B.

2)
"CAAAAAC"

Returns: {2, 2, 2, 2, 2, 2, 1 }



3)
"BBCA"

Returns: {3, 3, 2, 1 }



4)
"BACACABCBBBBCAAAAACCCABBCAA"

Returns: {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 1 }



*/

// END CUT HERE
