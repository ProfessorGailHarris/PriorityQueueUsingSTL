//
//  node.cpp
//  Demo Priority Queue
//
//  Created by Gail Harris on 2020-Oct-11.
//  Copyright © 2020 Gail Harris. All rights reserved.
//

#include <stdio.h>
#include "node.h"

Node::Node()
{
    label = 0;
}

Node::Node( int i_ )
{
    label = i_;
}

void Node::print()
{
    printf ("%i ", label );
}
