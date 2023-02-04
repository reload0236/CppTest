#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <unordered_map>
#include <initializer_list>

#include "Version.h"
#include "Runnable.h"
#include "Tests/DebugSymbolTest.h"
#include "Tests/AllocatorTest.h"
#include "Tests/RightReferenceTest.h"
#include "Tests/FunctionTest.h"
#include "Tests/UnorderedMapTest.h"

#include "Practice/LengthOfLongestSubstring.h"


int main()
{
	std::cout << CPP_TESTS_VERSION << std::endl;

	std::unordered_map<std::string, std::shared_ptr<Runnable>> runnables;
	runnables.insert( {"DebugSymbolTest", std::make_shared<DebugSymbolTest>()} );
	runnables.insert( {"AllocatorTest", std::make_shared<AllocatorTest>()} );
	runnables.insert( {"RightReferenceTest", std::make_shared<RightReferenceTest>()} );
	runnables.insert( {"FunctionTest", std::make_shared<FunctionTest>()} );
	runnables.insert( {"UnorderedMapTest", std::make_shared<UnorderedMapTest>()} );
    
    runnables.insert( {"LengthOfLongestSubstring", std::make_shared<LengthOfLongestSubstring>()} );
    
	runnables["LengthOfLongestSubstring"]->Run();

	return 0;
}
