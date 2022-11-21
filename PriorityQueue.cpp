//
//  main.cpp
//  Demo Priority Queue
//
//  Created by Gail Harris on 2020-Oct-11.
//  Copyright © 2020 Gail Harris. All rights reserved.
//

#include <functional>
#include <queue>
#include <vector>
#include <iostream>
#include "node.h"

// function for printing priority queue when it only contains integers
template<typename T> void print_queue( T& q ) {
    while (!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}


struct NodeAndPriority
{
public:

    // member variables
    Node* node;
    float priority;

    // constructors
    NodeAndPriority(Node* node_, float priority_)
    {
        node = node_;
        priority = priority_;
    }

    // useful functions
    void print()
    {
        printf("Node: %i, priority: %.2f \n", node->label, priority);
    }
};


int main( int argc, const char* argv[] ) {
    // insert code here...

    printf( "Demo of using priority queue from the STL\n" );
    printf( "Part 1 stores integers\n" );
    printf( "Part 2 stores objects\n" );
    printf( "\n" );

    printf( "Demo Part 1.\n\n" );

    // *************************
    // Code from: https://en.cppreference.com/w/cpp/container/priority_queue
    //

    // default is a max queue
    std::priority_queue<int> q;

    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q.push( n );

    print_queue( q );

    // make it be a min queue
    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;

    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q2.push( n );

    print_queue( q2 );

    // Using lambda to compare elements.
    // Do the lambda as a min queue
    auto cmp = []( int left, int right ) { return left > right ; };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3( cmp );

    for (int n : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
        q3.push( n );

    print_queue( q3 );

    // end of copied code
    // *************************

    // demo of priority queue with more complicated structures
    // with help from: https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/

    printf( "\n\nDemo Part 2\n\n" );

    // create struct with one operation, for use in the comparisons needed by the priority queue
    // (might be better to have in a separate file and included?)
    struct ComparePriority
    {
        bool operator()( NodeAndPriority const& lhs, NodeAndPriority const& rhs )
        {
            // make it a min queue
            return lhs.priority > rhs.priority;
        }
    };

    // create the priority queue using the Standard Template Library (STL)
    // I chose double ended queue, rather than vector, for the container class
    // I thought it might be better for performance, particularly for larger graphs
    std::priority_queue<NodeAndPriority, std::deque<NodeAndPriority>, ComparePriority > pq;

    // set up some data for my testing:

    // create SIZE graph nodes and add them to the priority queue
    const int SIZE = 4;

    // the labels for the nodes are:
    int labels[SIZE] ={ 2, 5, 6, 3 };

    // the priorities for the nodes are:
    float priorities[SIZE] ={ 5.5f, 7.1f, 1.8f, 3.4f };

    // add the above nodes and priorities into the priority queue

    // declare some pointers for creating nodes and the objects to be put in the queue
    Node* n;
    NodeAndPriority* c;

    printf( "Load up the priority queue...\n" );
    for (int i=0; i<SIZE; i++)
    {
        n = new Node( labels[i] );
        c = new NodeAndPriority( n, priorities[i] );
        printf( "add " );
        c->print();

        // pushing the object, not the pointer, onto the priority queue
        pq.push( *c );
        printf( "new top is: " );
        NodeAndPriority d = pq.top();
        d.print();
    }

    // Notice that the order of objects as they pop off the queue are
    // lowest priority first.
    // Change the comparison in the ComparePriority struct if you want to reverse the order
    printf( "\n" );
    printf( "Contents of Priority Queue:\n" );
    while (!pq.empty())
    {
        // get the top item and print it
        NodeAndPriority c = pq.top();
        c.print();
        // remove top item from the priority queue
        pq.pop();
    }

    return 0;
}
