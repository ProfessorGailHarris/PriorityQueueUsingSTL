//
//  A_Star_Node_Priority.cpp
//  Demo Priority Queue
//
//  Created by Gail Harris on 2020-Oct-11.
//  Copyright © 2020 Gail Harris. All rights reserved.
//

#include <stdio.h>

#include "A_Star_Node_Priority.h"

A_Star_Node_Priority::A_Star_Node_Priority( Node *node_, float priority_ )
{
    node = node_;
    priority = priority_;
}

void A_Star_Node_Priority::print()
{
    printf( "Node: %i, priority: %.2f \n", node->label, priority );
}
