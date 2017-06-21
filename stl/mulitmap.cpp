/*************************************************************************
	> File Name: mulitmap.cpp
	> Author: 
	> Mail: 
	> Created Time: Thursday, April 14, 2016 PM04:04:47 HKT
 ************************************************************************/

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    multimap<int, string> map_;
    map_.insert(std::pair<int, string>(2, "22-1"));
    map_.insert(std::pair<int, string>(1, "1-1"));
    map_.insert(std::pair<int, string>(9, "9999999999"));
    map_.insert(std::pair<int, string>(2, "22-2"));
    map_.insert(std::pair<int, string>(3, "333"));
    map_.insert(std::pair<int, string>(2, "22-3"));
    map_.insert(std::pair<int, string>(4, "4444"));

    for (multimap<int, string>::iterator it = map_.begin(); it != map_.end(); ++it)
    {
        std::cout<<it->first<<" "<<it->second<<std::endl;
    }
}

