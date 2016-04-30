#include <boost/simd/pack.hpp>
#include <boost/simd/function/divfix.hpp>
#include <iostream>

using std::cout;
using std::endl;

using namespace boost::simd;

int main()
{
  typedef pack<long long, 2> p_l_t;

  p_l_t a(123, 178);
  p_l_t b(10, 10);

  auto c = divfix(a, b) * b;
  cout << a << endl;
  cout << b << endl;
  cout << c << endl;

  return 0;
}
