//
//  A_Star_Node_Priority.h
//  Demo Priority Queue
//
//  Created by Gail Harris on 2020-Oct-11.
//  Copyright © 2020 Gail Harris. All rights reserved.
//

#ifndef A_Star_Node_Priority_h
#define A_Star_Node_Priority_h

#include "node.h"

class A_Star_Node_Priority
{
public:
    
    // member variables
    Node *node;
    float priority;
    
    // constructors
    A_Star_Node_Priority( Node *node_, float priority);
    
    // useful functions
    void print();
};

#endif /* A_Star_Node_Priority_h */
