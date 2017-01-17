/**
 * @file CensusDataSorts.cpp   Sort functions for census population data.
 * 
 * @brief
 *    Implements several different types of sorts. Data can be sorted
 * by population or by name of town. This file contains all of the sorting
 * functions and their helpers.
 *
 * @author Judy Challinger and Cristian Silva
 * @date 2/22/13
 */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "CensusData.h"
using namespace std;
// formal parameter name commented out to avoid unused variable warning
/* 
 this function takes in an interger and passes it to the member 
 function.
 
 @param int choose
         takes in a int that was be passed to the member function
         or my name.
*/
void CensusData::insertionSort(int choose){
   m_insertionSort(choose, data);
}
/*
 member function sorts through the methods of insertion.
 
 @param int choose 
         value that decideds if its being sorted by 
         population or by name.
 
 @param vector<Record*> &data
         vector of the pointer class "Record" that holds all 
         its private variables, which is the data that is 
         needed to sort i.e name and population.
 */
void CensusData::m_insertionSort(int choose, vector<Record*> &data){
   if (choose == 0)
   {
      for (unsigned int j = 1; j < data.size(); j++)
      {
         Record* key = data[j];
         int i = j - 1;
            while (i >= 0 && data[i]->population > key -> population)
            {
               data[i+1] = data[i];
               i = i - 1;
            }
         data[i+1] = key;
      }
   }
   else if (choose == 1)
   {
      for (unsigned int j = 1; j < data.size(); j++)
      {
         Record* key = data[j];
         int i = j - 1;
            while (i >= 0 && *data[i] -> city > *key -> city)
            {
               data[i + 1] = data [i];
               i = i - 1;
            }
         data[i + 1] = key;
      }
   }
}

// formal parameter name commented out to avoid unused variable warning
/*
 this function takes in an interger and passes it to the member
 function.
 
 @param int choose
         takes in a int that was be passed to the member function
         or my name.
 */
void CensusData::mergeSort(int choose) {
   m_mergeSort(choose, 0, data.size() - 1.0, data);
}
/*
 member function which guides the recursion process of mergesort.
 
 @param int choose
         value that decideds if its being sorted by
         population or by name.
 
 @param int first
         value which is ment to hold the first value of the given
         vector.
 
 @param int last
         value which is ment to hold the last value of the given
         vector.
 
 @param vector<Record*> &data
         vector of the pointer class "Record" that holds all
         its private variables, which is the data that is
         needed to sort i.e name and population.
 */
void CensusData::m_mergeSort(int choose, int first, int last , vector<Record*> &data)
{
   if (first < last)
   {
      int mid = (first + last) / 2;
      m_mergeSort(choose, first, mid, data);
      m_mergeSort(choose, mid + 1, last, data);
      merge(choose,first,mid,last,data);
   }
}
/*
 member function sorts through the methods of merging.
 
 @param int choose
         value that decideds if its being sorted by
         population or by name.
 
 @param int first
         value which is ment to hold the first value of the given
         vector.
 
 @param int mid
         value which is ment to hold the middle value of the 
         given array.
 
 @param int last
         value which is ment to hold the last value of the given
         vector.
 
 @param vector<Record*> &data
         vector of the pointer class "Record" that holds all
         its private variables, which is the data that is
         needed to sort i.e name and population.
 */
void CensusData::merge(int choose, int first, int mid, int last, vector<Record*> &data)
{
   const int n1 = mid - first + 1;
   const int n2 = last - mid;
   vector<Record*> left;
   vector<Record*> right;
   
   for (int i = 0; i < n1; i++)
      left.push_back(data[first+i]);
   for (int j = 1; j <= n2; j++)
      right.push_back(data[mid+j]);
   left.push_back(NULL);
   right.push_back(NULL);
   int i = 0;
   int j = 0;
   if (choose == 0){
      for (int k = first; k <= last ; k++){
         if (left[i] != NULL && right[j] != NULL) {
            if (left[i] -> population <= right[j] -> population){
               data[k] = left[i];
               i = i + 1;
            }
            else{
               data[k] = right[j];
               j = j + 1;
            }
         }
         else if (left [i] == NULL && right[j] != NULL){
            data[k] = right[j];
            j = j + 1;
         }
         else if (left[i] != NULL && right[j] == NULL){
            data[k] = left[i];
            i = i + 1;
         }
      }
   }
   if (choose == 1){
      for (int k = first; k <= last ; k++){
         if (left[i] != NULL && right[j] != NULL) {
            if (*left[i] -> city <= *right[j] -> city){
               data[k] = left[i];
               i = i + 1;
            }
            else{
               data[k] = right[j];
               j = j + 1;
            }
         }
         else if (left [i] == NULL && right[j] != NULL){
            data[k] = right[j];
            j = j + 1;
         }
         else if (left[i] != NULL && right[j] == NULL){
            data[k] = left[i];
            i = i + 1;
         }
      }
   }
}

// formal parameter name commented out to avoid unused variable warning
/*
 this function takes in an interger and passes it to the member
 function.
 
 @param int choose
         takes in a int that was be passed to the member function
         or my name.
 */
void CensusData::quickSort(int choose) {
   m_quickSort( choose, 0, data.size() - 1.0, data);
}

void CensusData::m_quickSort(int choose, int first, int last, vector <Record*> &data){
   if (first < last)
   {
      int mid = randomized_partition(choose, first, last, data);
      m_quickSort(choose, first, mid - 1, data);
      m_quickSort(choose, mid + 1,last, data);
   }
}

/*
 member function sorts through the methods of quicksorting.
 
 @param int choose
         value that decideds if its being sorted by
         population or by name.
 
 @param int first
         value which is ment to hold the first value of the given
         vector.
 

 @param int last
         value which is ment to hold the last value of the given
         vector.
 
 @param vector<Record*> &data
         vector of the pointer class "Record" that holds all
         its private variables, which is the data that is
         needed to sort i.e name and population.
 */
int CensusData::partition(int choose, int first, int last, vector <Record*> &data){
   Record* pivot = data[last];
   int index = first - 1;
   if (choose == 0){
   for (int j = first; j < last; j++){
      if (data[j] -> population <= pivot -> population){
         index = index + 1;
         Record* temp = data[index];
         data[index] = data[j];
         data[j] = temp;
      }
   }
   Record* temp2 = data[index + 1];
   data[index + 1] = data[last];
   data[last] = temp2;
   return index + 1;
   }
   else{
      for (int j = first; j < last; j++){
         if (*data[j] -> city <= *pivot -> city){
            index = index + 1;
            Record* temp3 = data[index];
            data[index] = data[j];
            data[j] = temp3;
         }
      }
      Record* temp = data[index + 1];
      data[index + 1] =data[last];
      data[last] = temp;
      return index + 1;
   }
}
/*
 member function randomly chooses a element from the subarray to use as the pivot.
 
 @param int choose
         value that decideds if its being sorted by
         population or by name.
 
 @param int first
         value which is ment to hold the first value of the given
         vector.
 
 
 @param int last
         value which is ment to hold the last value of the given
         vector.
 
 @param vector<Record*> &data
         vector of the pointer class "Record" that holds all
         its private variables, which is the data that is
         needed to sort i.e name and population.
 */
int CensusData::randomized_partition(int choose, int first, int last,  vector <Record*> &data){
   int index = rand() % (last - first + 1);
   index = index + first;
   Record* temp = data[index];
   data[index] = data[last];
   data[last] = temp;
   return partition(choose, first, last, data);
}
