#include <string>
#include <vector>
#include <memory>

#include "../Include/Tests/AllocatorTest.h"


void AllocatorTest::Run()
{
	std::allocator<std::string> a;
	auto p = a.allocate(3);
	auto q = p;
	while (q != p + 3) {
		a.construct(q, "haha1");
		++q;
	}
	--q;
	while (q != (p-1) ) {
		a.destroy(q);
		--q;
	}
	a.deallocate(p, 3);

	system("pause");
}