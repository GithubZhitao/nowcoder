#include<iostream>
#include<vector>
#include<string>

using namespace std;

 class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
      string s = "";
 //quickSort(numbers, 0, numbers.size()-1);
	    sort(numbers.begin() , numbers.end() , smaller);
      for(auto i : numbers)
        s+= to_string(i);
      return s;
}
 void quickSort(vector<int> &a, int l , int r){
     int i = l, j = r;
     if(i < j){
	    int key = a[i];
       while(i < j){
        while(i<j && !smaller(a[j], key))
            j--;
          if(i < j)
            a[i++] = a[j];   
          while(i<j && smaller(a[i], key))
          	i++;
          if(i < j)
            a[j--] = a[i];
      }
	     a[i]= key;
       quickSort(a, l, i);
       quickSort(a, i+1 , r);
     }
       
    }
    
    bool smaller(const int &s1 ,const int &s2){
       string x =to_string(s1)+to_string(s2);
       string y =to_string(s2)+to_string(s1);
       return x<y;
    }
};


int main(){

	vector<int> data = {3,32,321};
	Solution solu;
	cout <<solu.PrintMinNumber(data)<<endl;
	return 0;
}



