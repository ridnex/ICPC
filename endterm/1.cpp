// erasing from vector
#include <iostream>
#include <vector>

int main ()
{
  std::vector<int> myvector;

  
  for (int i=0; i<10; i++) myvector.push_back(i);

 
  myvector.erase (myvector.end()-2);


  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

  return 0;
}