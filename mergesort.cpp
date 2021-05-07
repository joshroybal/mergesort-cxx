#include <fstream>
#include <list>
#include <cstdlib>
#include <climits>
#include <ctime>

#define RECSIZ 80
#define NORECS 456995

float elapsed(int t0, int t1)
{
   return (t1-t0)/float(CLOCKS_PER_SEC);
}

std::list<int> ranInts(int n)
{
   std::list<int> z;
   for (int i = 0; i < n; i++) z.push_front(rand());
   return z;
}

std::list<float> ranFloats(int n)
{
   std::list<float> r;
   for (int i = 0; i < n; i++) r.push_front(rand()/float(RAND_MAX));
   return r;
}

std::list<std::string> ranRecords(int n)
{
   std::list<std::string> records;
   // function prototype
   std::string readRecord(int, std::ifstream&);

   std::ifstream directFile;
   directFile.open("/home/slacker/dat/data.dat", 
         std::ifstream::in | std::ifstream::binary);
   for (int i = 0; i < n; i++) {
      int recno = int(NORECS * (rand()/float(RAND_MAX)));
      records.push_front(readRecord(recno, directFile));
   }
   directFile.close();
   return(records);
}

std::string readRecord(int n, std::ifstream& ifstr)
{
   char buf[RECSIZ+1];
   int pos = RECSIZ * n;
   ifstr.seekg(pos);
   ifstr.read(buf, RECSIZ);
   int j = RECSIZ;
   while (j > 0 && buf[--j] == ' ');
   buf[++j] = '\0';
   return buf;
} 
