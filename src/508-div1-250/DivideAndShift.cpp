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

bool isPrime(long long l){
    if(l < 2) return false;
    for(LL i=2; i*i<=l; i++)
        if(l%i == 0 )
            return false;
    return true;
}

int pcnt(int i){
    int cnt = 0;
    while(i!=1){
//        if(isPrime(i)) return cnt+1;
        FOR(j, 2, i+1) {
            if(i%j == 0){
                i /= j;
                cnt++;
                break;
            }
        }
    }
    return cnt;
}

class DivideAndShift {
	public:
	int getLeast(int N, int M) {
        int res = 1000000;
        M--;
		FOR(i, 1, N+1){
            if(N%i) continue;
            int x = N/i;
            res = min(res, M%x + pcnt(i));
            res = min(res, (x-M%x) + pcnt(i));
            if(res == 1){OUT(x); OUT(i);return res;};
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
			int N                     = 56;
			int M                     = 14;
			int expected__            = 3;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			int N                     = 49;
			int M                     = 5;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			int N                     = 256;
			int M                     = 7;
			int expected__            = 6;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			int N                     = 6;
			int M                     = 1;
			int expected__            = 0;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			int N                     = 77777;
			int M                     = 11111;
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			int N                     = ;
			int M                     = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = DivideAndShift().getLeast(N, M);
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
// Manao is playing a game called "Divide and Shift". There is a sequence of N slots in the game numbered from 1 to N. Initially each of them contains an object. Manao's goal is to obtain the object which is initially in slot M. At any time of the game, he can only obtain an object that is in slot 1 at that time. 

Manao can perform two types of moves. The first is choosing a prime number p which divides N and dividing the sequence of the slots in p contiguous subsequences, namely the slots from 1 to N/p, the slots from N/p+1 to 2N/p, etc. Then, Manao keeps the subsequence which contains the desired object and gets rid of the remaining slots. The length of the chosen subsequence is then assigned to N and the slots in it are renumbered from 1 to the new value of N.

The second type of move is shifting the objects in the slots. Manao can perform a left shift and a right shift. After a left shift, for each i &gt 1 the object in slot i is moved to slot i-1 and the object in slot 1 is moved to the last slot of the sequence. After a right shift, each object is moved to the slot to the right and the object in the last slot is moved to slot 1.

Determine the least number of moves in which Manao can reach the goal. Taking the object from slot 1 is not considered a move.

DEFINITION
Class:DivideAndShift
Method:getLeast
Parameters:int, int
Returns:int
Method signature:int getLeast(int N, int M)


NOTES
-A positive integer number is called prime if it has exactly two divisors - 1 and itself. For example, 2, 3, 5 and 7 are prime numbers, and 4, 6, 8 and 9 are not prime. By convention, 1 is not considered to be a prime number.
-A prime number p divides N if the ratio N/p is an integer.


CONSTRAINTS
-N will be between 1 and 1,000,000, inclusive.
-M will be between 1 and N, inclusive.


EXAMPLES

0)
56
14

Returns: 3

One possible way to obtain the object in slot 14 is to perform the following operations:
1. Divide by 2. N becomes equal to 28 now.
2. Shift right. The object moves to slot 15.
3.?Divide?by?2?again.?The?sequence?15..28?is?kept,?renumbered?as?1..14?and?the?object?appears?in?slot?1.


1)
49
5

Returns: 2

Manao divides by 7 twice and gets a single slot.

2)
256
7

Returns: 6

Shift?left?until?the?object?is?in?slot?1.

3)
6
1

Returns: 0

The object may be in slot 1 right in the beginning.

4)
77777
11111

Returns: 2



*/

// END CUT HERE
