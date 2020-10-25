1) accumulate
#include <numeric>
#include <functional>

1.1)
	int init = 100;
	int numbers[] = {10,20,30};

	std::cout << "using default accumulate: ";
	std::cout << std::accumulate(numbers,numbers+3,init);

1.2)
	int myfunction (int x, int y) {return x+2*y;}
	std::cout << "using functional's minus: ";
	std::cout << std::accumulate (numbers, numbers+3, init, std::minus<int>());
	std::cout << '\n';

1.3)
	
	struct myclass {
		int operator()(int x, int y) {return x+3*y;}
	} myobject;

	std::cout << std::accumulate (numbers, numbers+3, init, myfunction);

1.4) lambda

1.5) уникальное значение из пар

2)
#include <numeric>

	int init = 0;
	int series1[] = {10,20,30};
	int series2[] = {1,2,3};

	std::cout << "using default inner_product: ";
	std::cout << std::inner_product(series1,series1+3,series2,init);
	std::cout << '\n';

3) Слияние

int first[] = {5,10,15,20,25};
int second[] = {50,40,30,20,10};
std::vector<int> v(10);

3.1)
std::sort (first,first+5);
std::sort (second,second+5);
std::merge (first,first+5,second,second+5,v.begin());

3.2) мержим разные контейнеры
3.3) рассказать про back_inserter
std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(c));

4) пересечения упорядоченных множеств
std::set_union(in_a.begin(), in_a.end(), in_b.begin(), in_b.end(), std::back_inserter(out_a));
std::set_intersection (in_a.begin(), in_a.end(), in_b.begin(), in_b.end(), std::back_inserter(out_a));
std::set_difference (in_a.begin(), in_a.end(), in_b.begin(), in_b.end(), std::back_inserter(out_a));

5) std::reverse

5) minmax. Показать на разных типах и контейнерах
auto result = std::minmax({1,2,3,4,5});

5.1)
int myints[] = {3,7,2,5,6,4,9};
// using default comparison:
std::cout << "The smallest element is " << *std::min_element(myints,myints+7) << '\n';
std::cout << "The largest element is "  << *std::max_element(myints,myints+7) << '\n';

5.2)
std::cout << "minmax({1,2,3,4,5}): ";
std::cout << result.first << ' ' << result.second << '\n'

6)
sort
stable_sort 

6.1)
int myints[] = {9,8,7,6,5,4,3,2,1};
std::vector<int> myvector (myints, myints+9);
std::partial_sort (myvector.begin(), myvector.begin()+5, myvector.end());

6.2) is sorted

  std::array<int,4> foo {2,4,1,3};

  do {
    // try a new permutation:
    std::prev_permutation(foo.begin(),foo.end());

    // print range:
    std::cout << "foo:";
    for (int& x:foo) std::cout << ' ' << x;
    std::cout << '\n';

  } while (!std::is_sorted(foo.begin(),foo.end()));


7)
int myints[]={10,20,30,40,50,60,70};
std::vector<int> myvector (7);
std::copy ( myints, myints+7, myvector.begin() );

8)
int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };
std::vector<int> myvector (myints, myints+8);            // 10 20 30 30 20 10 10 20
std::replace (myvector.begin(), myvector.end(), 20, 99);

9)
bool IsOdd (int i) { return ((i%2)==1); }

  std::vector<int> myvector;
  for (int i=1; i<10; i++) myvector.push_back(i);               // 1 2 3 4 5 6 7 8 9
  std::replace_if (myvector.begin(), myvector.end(), IsOdd, 0);

10)
count
count_if
find
find_if
std::transform (foo.begin(), foo.end(), bar.begin(), op_increase);

remove
remove_if

11)
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand

// random generator function:
int myrandom (int i) { return std::rand()%i;}

int main () {
  std::srand ( unsigned ( std::time(0) ) );
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

  // using built-in random generator:
  std::random_shuffle ( myvector.begin(), myvector.end() );

  // using myrandom:
  std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}