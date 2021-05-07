#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>
#include "mergesort.hpp"

#define LIM 50

float elapsed(int, int);
std::list<int> ranInts(int);
std::list<float> ranFloats(int);
std::list<std::string> ranRecords(int);

int main(int argc, char *argv[])
{
   if (argc < 2) {
      std::cerr << "Usage: " << argv[0] << " n" << std::endl;
      return 1;
   }
   const int n = atoi(argv[1]);
   srand(time(NULL));
   // int
   std::list<int>* z = new std::list<int>(ranInts(n));
   std::cout << "int" << std::endl;
   if (n <= LIM) std::cout << *z;
   std::cout << isSorted(*z, lte<int>) << std::endl;
   int t0 = std::clock();
   mergeSort<int>* zsorted = new mergeSort<int>(*z, lte<int>);
   int t1 = std::clock();
   std::cout << "ascending int" << std::endl;
   if (n <= LIM) std::cout << zsorted->getResult();
   std::cout << isSorted(zsorted->getResult(), lte<int>) << std::endl;
   std::cout << "elapsed time = " << elapsed(t0, t1) << " secs." << std::endl;
   delete zsorted;
   delete z;
   z = new std::list<int>(ranInts(n));
   if (n <= LIM) std::cout << *z;
   std::cout << isSorted(*z, gte<int>) << std::endl;
   std::cout << "descending int" << std::endl;
   t0 = std::clock();
   zsorted = new mergeSort<int>(*z, gte<int>);
   t1 = std::clock();
   if (n <= LIM) std::cout << zsorted->getResult();
   std::cout << isSorted(zsorted->getResult(), gte<int>) << std::endl;
   std::cout << "elapsed time = " << elapsed(t0, t1) << " secs." << std::endl;
   delete zsorted;
   delete z;
   // float
   std::list<float>* r = new std::list<float>(ranFloats(n));
   std::cout << "float" << std::endl;
   if (n <= LIM) std::cout << *r;
   std::cout << isSorted(*r, lte<float>) << std::endl;
   t0 = std::clock();
   mergeSort<float>* rsorted = new mergeSort<float>(*r, lte<float>);
   t1 = std::clock();
   std::cout << "ascending float" << std::endl;
   if (n <= LIM) std::cout << rsorted->getResult();
   std::cout << isSorted(rsorted->getResult(), lte<float>) << std::endl;
   std::cout << "elapsed time = " << elapsed(t0, t1) << " secs." << std::endl;
   delete rsorted;
   delete r;
   r = new std::list<float>(ranFloats(n));
   std::cout << "float" << std::endl;
   if (n <= LIM) std::cout << *r;
   std::cout << isSorted(*r, gte<float>) << std::endl;
   std::cout << "descending float" << std::endl;
   t0 = std::clock();
   rsorted = new mergeSort<float>(*r, gte<float>);
   t1 = std::clock();
   if (n <= LIM) std::cout << rsorted->getResult();
   std::cout << isSorted(rsorted->getResult(), gte<float>) << std::endl;
   std::cout << "elapsed time = " << elapsed(t0, t1) << " secs." << std::endl;
   delete rsorted;
   delete r;
   // std::string
   std::list<std::string>* records =
      new std::list<std::string>(ranRecords(n));
   std::cout << "strings" << std::endl;
   if (n <= LIM) std::cout << *records;
   std::cout << isSorted(*records, lte<std::string>) << std::endl;
   t0 = std::clock();
   mergeSort<std::string>* sortedRecords = 
      new mergeSort<std::string>(*records, lte<std::string>);
   t1 = std::clock();
   std::cout << "ascending strings" << std::endl;
   if (n <= LIM) std::cout << sortedRecords->getResult();
   std::cout << isSorted(sortedRecords->getResult(), lte<std::string>);
   std::cout << std::endl;
   std::cout << "elapsed time = " << elapsed(t0, t1) << " secs." << std::endl;
   delete sortedRecords;
   delete records;
   records = new std::list<std::string>(ranRecords(n));
   if (n <= LIM) std::cout << *records;
   std::cout << isSorted(*records, gte<std::string>) << std::endl;
   t0 = std::clock();
   sortedRecords = new mergeSort<std::string>(*records, gte<std::string>);
   t1 = std::clock();
   std::cout << "descending strings" << std::endl;
   if (n <= LIM) std::cout << sortedRecords->getResult();
   std::cout << isSorted(sortedRecords->getResult(), gte<std::string>);
   std::cout << std::endl;
   std::cout << "elapsed time = " << elapsed(t0, t1) << " secs." << std::endl;  
   delete sortedRecords;
   delete records;
   return 0;
}
