#ifndef MERGESORT_HPP
#define MERGESORT_HPP

#include <iostream>
#include <list>
#include <iterator>

// less than or equal
template <class T>
bool lte(T a, T b)
{
   return a <= b;
}

// greater than or equal
template <class T>
bool gte(T a, T b)
{
   return a >= b;
}

template <class T>
std::ostream& operator<<(std::ostream& ostr, const std::list<T>& ls)
{
   typename std::list<T>::const_iterator it;
   for (it = ls.begin(); it != ls.end(); it++)
      ostr << *it << std::endl;
   return ostr;
}

template <class T>
void printRuns(const std::list<std::list<T> >& runs)
{
   std::cout << "[ ";
   typename std::list<std::list<T> >::const_iterator rit;
   for (rit = runs.begin(); rit != runs.end(); rit++)
      std::cout << *rit;
   std::cout << "]" << std::endl << std::endl;
}

template <class T>
bool isSorted(const std::list<T>& ls, bool (&cmp)(T a, T b))
{
   bool result;

   typename std::list<T>::const_iterator curr;
   typename std::list<T>::const_iterator next;
   for (curr = ls.begin(), next = ++ls.begin(); next != ls.end(); 
         ++curr, ++next)
      if (!cmp(*curr, *next)) break;
   if (next == ls.end())
      result = true;
   else
      result = false;
   return result;
}

// class constructs bottom up natural merge sort of lists of lists
template <class T>
class mergeSort {
   public:
      mergeSort(const std::list<T>&, bool (&cmp)(T, T));
      std::list<T> getResult() { return runs.front(); }
   private:
      std::list<std::list<T> > runs;
      void extract_runs(const std::list<T>&, bool (&cmp)(T, T));
      void merge_runs(std::list<std::list<T> >&, bool (&cmp)(T, T));
};

// clas template constructor
template <class T>
mergeSort<T>::mergeSort(const std::list<T>& ls, bool (&cmp)(T a, T b))
{
   extract_runs(ls, cmp);
   while (runs.size() > 1)
      merge_runs(runs, cmp);
}

template <class T>
void mergeSort<T>::extract_runs(const std::list<T>& ls, bool (&cmp)(T a, T b))
{
   std::list<T> current_run;
   T prev;
   
   prev = ls.front();
   typename std::list<T>::const_iterator it;
   for (it = ++ls.begin(); it != ls.end(); it++) {
      if (cmp(prev, *it))
         current_run.push_front(prev);
      else {
         current_run.push_front(prev);
         current_run.reverse();
         runs.push_front(current_run);
         current_run.clear();
      }
      prev = *it;
   }
   current_run.push_front(prev);
   current_run.reverse();
   runs.push_front(current_run);
}

template <class T>
void mergeSort<T>::merge_runs(std::list<std::list<T> >& runs, 
      bool (&cmp)(T a, T b))
{
   typename std::list<std::list<T> >::iterator curr = runs.begin();
   typename std::list<std::list<T> >::iterator next = ++runs.begin();
   while ( curr != runs.end() && next != runs.end() ) {
      (*curr).merge(*next, cmp);
      runs.erase(next);
      ++curr;
      next = curr;
      ++next;
   }
}

#endif
