#include "../cs225/catch/catch.hpp"
#include "../include/vertex.h"
#include "../include/graph.h"
#include "../include/edge.h"
#include "../include/bfs.h"
#include "../include/dijkstras.h"

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::pair;

/**
 *    v1 ---1--- v2
 *    |           |
 *    |           2
 *    |           |
 *    -----4---- v3 ---3--- v4
 */
TEST_CASE("V small dijkstra", "[dijkstras]") {
  Graph g;

  Vertex* v1 = g.addVertex("0x1");
  Vertex* v2 = g.addVertex("0x2");
  Vertex* v3 = g.addVertex("0x3");
  Vertex* v4 = g.addVertex("0x4");

  g.addEdge(v1, v2, 1, 1, 2);
  g.addEdge(v1, v3, 1, 4, 12);
  g.addEdge(v2, v3, 1, 2, 3);
  g.addEdge(v3, v4, 1, 3, 2);

  dijkstra(&g, v1);

  REQUIRE( v1->getDistance() == 0 );
  REQUIRE( v2->getDistance() == 1 );
  REQUIRE( v3->getDistance() == 3 );
  REQUIRE( v4->getDistance() == 6 );
 }


 TEST_CASE("dijkstras simple 2, dist only", "[dijkstras]") {
   Graph g;

   Vertex* v1 = g.addVertex("0x1");
   Vertex* v2 = g.addVertex("0x2");
   Vertex* v3 = g.addVertex("0x3");
   Vertex* v4 = g.addVertex("0x4");
   Vertex* v5 = g.addVertex("0x5");
   Vertex* v6 = g.addVertex("0x6");
   Vertex* v7 = g.addVertex("0x7");
   Vertex* v8 = g.addVertex("0x8");

   g.addEdge(v1, v2, 1, 1, 50);
   g.addEdge(v1, v3, 1, 1, 21);
   g.addEdge(v2, v4, 1, 1, 42);
   g.addEdge(v3, v5, 1, 1, 57);
   g.addEdge(v4, v5, 1, 1, 53);
   g.addEdge(v4, v6, 1, 1, 57);
   g.addEdge(v4, v7, 1, 1, 40);
   g.addEdge(v5, v7, 1, 1, 63);
   g.addEdge(v6, v7, 1, 1, 51);
   g.addEdge(v7, v8, 1, 1, 1);

   dijkstra(&g, v1);
   REQUIRE( v8->getDistance() == 4 );
 }

 /**
  * All Edge Weights are 1:
  *
  *     1 ----- 2 ----- 4
  *     |         ____/ | \____
  *     |        /      |      \
  *     3 ----- 5 ----- 7 ----- 6
  *                     |
  *                     8
  *
  *     Potential Shortest Paths from 1 --> 8:
  *         A. 1 --> 2 --> 4 --> 7 --> 8
  *         B. 1 --> 3 --> 5 --> 7 --> 8
  *
  */
 TEST_CASE("Simple dijkstras path is accurate on Graph with 1 Connected Component and 8 nodes", "[dijkstras]") {
   Graph g;

   Vertex* v1 = g.addVertex("0x1");
   Vertex* v2 = g.addVertex("0x2");
   Vertex* v3 = g.addVertex("0x3");
   Vertex* v4 = g.addVertex("0x4");
   Vertex* v5 = g.addVertex("0x5");
   Vertex* v6 = g.addVertex("0x6");
   Vertex* v7 = g.addVertex("0x7");
   Vertex* v8 = g.addVertex("0x8");

   g.addEdge(v1, v2, 1, 1, 50);
   g.addEdge(v1, v3, 1, 1, 21);
   g.addEdge(v2, v4, 1, 1, 42);
   g.addEdge(v3, v5, 1, 1, 57);
   g.addEdge(v4, v5, 1, 1, 53);
   g.addEdge(v4, v6, 1, 1, 57);
   g.addEdge(v4, v7, 1, 1, 40);
   g.addEdge(v5, v7, 1, 1, 63);
   g.addEdge(v6, v7, 1, 1, 51);
   g.addEdge(v7, v8, 1, 1, 1);

   dijkstra(&g, v1);

   vector<Vertex*> correct_path = {v8, v7, v5, v3, v1};
   vector<Vertex*> output_path;

   Vertex* current = v8;
   while(current != NULL) {
     output_path.push_back(current);
     current = current->getParent();
   }

   REQUIRE(correct_path == output_path);
 }
