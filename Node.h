#include <iostream>

#ifndef NODE_H
#define NODE_H

class Node {

public:
	enum class STATES {
		N,X,O
	};
	STATES value = STATES::N;
	std::pair<int, int> cord;
	Node(int x, int y);

};
#endif // NODE_H