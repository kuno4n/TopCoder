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

class KleofasTail {
    LL cal(LL K, LL A, LL B){
		LL res = 0;
        for(LL cnt=1; K<=B; cnt*=2,K*=2){
            LL plus = 0;
            if(K+cnt-1 >= A) plus += min(cnt, K+cnt-A);
            if(K+cnt-1 >= B) plus -= cnt-(B-K+1);
            res += plus;
        }
        return res;
    }
    
	public:
	long long countGoodSequences(long long K, long long A, long long B) {
		LL res = 0;
        if(K==0 && A==0) res++;
        if(K==0) K++;

        res += cal(K, A, B);
        if(!(K%2)) res += cal(K+1, A, B);

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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			long long K               = 3;
			long long A               = 4;
			long long B               = 8;
			long long expected__      = 2;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			long long K               = 1;
			long long A               = 23457;
			long long B               = 123456;
			long long expected__      = 100000;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			long long K               = 1234567890123456LL;
			long long A               = 10;
			long long B               = 1000000;
			long long expected__      = 0;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			long long K               = 0;
			long long A               = 0;
			long long B               = 2;
			long long expected__      = 3;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 4: {
			long long K               = 2;
			long long A               = 3;
			long long B               = 3;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 5: {
			long long K               = 13;
			long long A               = 12345;
			long long B               = 67890123;
			long long expected__      = 8387584;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
            case 6: {
                long long K               = 0;
                long long A               = 1;
                long long B               = 1000000000000000000;
                long long expected__      = 1000000000000000000;
                
                clock_t start__           = clock();
                long long received__      = KleofasTail().countGoodSequences(K, A, B);
                return verify_case(casenum__, expected__, received__, clock()-start__);
            }

		// custom cases

/*      case 6: {
			long long K               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long K               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 8: {
			long long K               = ;
			long long A               = ;
			long long B               = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = KleofasTail().countGoodSequences(K, A, B);
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
Let X be a nonnegative integer.
The Kleofas tail of X is an infinite sequence of nonnegative integers, defined as follows:


The first element is X.
After an even element Y, the next element of the sequence is Y/2.
After an odd element Z, the next element of the sequence is Z-1.


For example, the Kleofas tail of 60 starts as follows: 60, 30, 15, 14, 7, 6, ...


You are given long longs K, A, and B.
Return the number of integers X between A and B, inclusive, such that the Kleofas tail of X contains at least one occurrence of K.


DEFINITION
Class:KleofasTail
Method:countGoodSequences
Parameters:long long, long long, long long
Returns:long long
Method signature:long long countGoodSequences(long long K, long long A, long long B)


NOTES
-Zero is an even number.


CONSTRAINTS
-K will be between 0 and 10^18, inclusive.
-A will be between 0 and 10^18, inclusive.
-B will be between 0 and 10^18, inclusive.
-A will be less than or equal to B.


EXAMPLES

0)
3
4
8

Returns: 2

The value 3 occurs in the Kleofas tail of 6 and also in the Kleofas tail of 7.

1)
1
23457
123456

Returns: 100000

For each X between 23457 and 123456, inclusive, the Kleofas tail of X contains the value 1.

2)
1234567890123456
10
1000000

Returns: 0

Each Kleofas tail is a nonincreasing sequence.

3)
0
0
2

Returns: 3



4)
2
3
3

Returns: 1

The Kleofas tail of 3 is 3, 2, 1, 0, 0, 0, ...

5)
13
12345
67890123

Returns: 8387584



*/

// END CUT HERE
