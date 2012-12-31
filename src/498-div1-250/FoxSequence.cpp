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

class FoxSequence {
	public:
	string isValid(vector <int> seq) {
		int ptr = 0, n = SZ(seq);
        int a,b,c,d,e;
        
        if(ptr+1 == n) return "NO";
        a = seq[ptr+1] - seq[ptr];
        if(a <= 0) return "NO";
        while(1){
            ptr++;
            if(ptr+1 == n) return "NO";
            int next = seq[ptr+1] - seq[ptr];
            if(a != next){
                b = next;
                break;
            }
        }
        
        if(b >= 0) return "NO";
        while(1){
            ptr++;
            if(ptr+1 == n) return "NO";
            int next = seq[ptr+1] - seq[ptr];
            if(b != next){
                c = next;
                break;
            }
        }
        
        if(c < 0) return "NO";
        if(c == 0){
            while(1){
                ptr++;
                if(ptr+1 == n) return "NO";
                int next = seq[ptr+1] - seq[ptr];
                if(c != next){
                    d = next;
                    break;
                }
            }
        }
        else d = c;
        
        if(d <= 0) return "NO";
        while(1){
            ptr++;
            if(ptr+1 == n) return "NO";
            int next = seq[ptr+1] - seq[ptr];
            if(d != next){
                e = next;
                break;
            }
        }
        
        if(e >= 0) return "NO";
        while(1){
            ptr++;
            if(ptr+1 == n) return "YES";
            int next = seq[ptr+1] - seq[ptr];
            if(e != next) return "NO";
        }
        
        return "NO";       
        
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
			int seq[]                 = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1} ;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int seq[]                 = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4} ;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int seq[]                 = {3,6,9,1,9,5,1} ;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int seq[]                 = {1,2,3,2,1,2,3,2,1,2,3,2,1} ;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int seq[]                 = {1,3,4,3,1,1,1,1,3,4,3,1} ;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			int seq[]                 = {6,1,6} ;
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 6: {
			int seq[]                 = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int seq[]                 = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			int seq[]                 = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = FoxSequence().isValid(vector <int>(seq, seq + (sizeof seq / sizeof seq[0])));
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
// Fox Ciel likes sequences.  One day, she invented a new type of sequence and named it the fox sequence.  A sequence seq containing N elements is called a fox sequence if and only if there exist four integers a, b, c and d such that 0 < a < b <= c < d < N-1 and the following five conditions are met:

seq[0], seq[1], ... , seq[a] forms an arithmetic progression with a positive common difference.  An arithmetic progression is a sequence where the difference between successive elements is equal.  The difference between successive elements is called the common difference.  Note that 0 is neither positive nor negative.
seq[a], seq[a+1], ... , seq[b] forms an arithmetic progression with a negative common difference.
seq[b], seq[b+1], ... , seq[c] are all equal.
seq[c], seq[c+1], ... , seq[d] forms an arithmetic progression with a positive common difference.
seq[d], seq[d+1], ... , seq[N-1] forms an arithmetic progression with a negative common difference.


In the following image, the top 3 sequences are fox sequences, while the bottom 3 sequences are not:



You are given a sequence seq.  Return "YES" if it is a fox sequence, or "NO" if it is not (all quotes for clarity).

DEFINITION
Class:FoxSequence
Method:isValid
Parameters:vector <int>
Returns:string
Method signature:string isValid(vector <int> seq)


CONSTRAINTS
-seq will contain between 1 and 50 elements, inclusive.
-Each element of seq will be between 1 and 2,000, inclusive.


EXAMPLES

0)
{1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}


Returns: "YES"

This is the top-left sequence of the image shown in the statement.  The next five examples are also from that image.

1)
{1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}


Returns: "YES"



2)
{3,6,9,1,9,5,1}


Returns: "YES"



3)
{1,2,3,2,1,2,3,2,1,2,3,2,1}


Returns: "NO"



4)
{1,3,4,3,1,1,1,1,3,4,3,1}


Returns: "NO"



5)
{6,1,6}


Returns: "NO"



*/

// END CUT HERE
