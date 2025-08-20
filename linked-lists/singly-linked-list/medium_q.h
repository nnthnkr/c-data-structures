#ifndef MEDIUM_Q_H
#define MEDIUM_Q_H

#include "LL.h"

// Get nth node from the end
//  nth node from end = (length - n - 1)th node from the beginning
//  This would be more convenient in a doubly linked list.
Node* getNthNode(LL *ll, int n);

#endif
