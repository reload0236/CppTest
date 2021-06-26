#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "../Include/Tests/UnorderedMapTest.h"


class CustomKey
{
public:
	CustomKey(int a, int b) : a_(a), b_(b)
	{}

	bool operator==(const CustomKey& key) const
	{
		return a_ == key.a_ && b_ == key.b_;
	}

	int a_;
	int b_;
};

namespace std 
{
    template <>
    struct std::hash<CustomKey>
    {
        int operator()(const CustomKey& key) const
        {
			std::hash<int> hasher;
			return hasher(key.a_) + hasher(key.b_);
        }
    };
}


void UnorderedMapTest::Run()
{
	std::unordered_map<CustomKey, int> myMap;
	myMap.insert( {CustomKey(1, 1), 10} );
	myMap.insert( {CustomKey(1, 2), 20} );
	myMap.insert( {CustomKey(1, 3), 30} );

	for (auto it = myMap.cbegin(); it != myMap.cend(); ++it) {
		auto key = it->first;
		std::cout << it->second << std::endl;
	}
	system("pause");
}