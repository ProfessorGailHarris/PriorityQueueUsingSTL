//
//  node.h
//  Demo Priority Queue
//
//  Created by Gail Harris on 2020-Oct-11.
//  Copyright © 2020 Gail Harris. All rights reserved.
//

#ifndef NODE_H
#define NODE_H

class Node
{
public:
    // member variables
    int label;
    
    // constructors
    Node();
    Node( int i_ );
    
    // useful functions
    void print();
};

#endif /* NODE_H */
