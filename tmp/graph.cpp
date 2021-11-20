#include "graph.h"

using std::string;

Graph::Graph() { }

Graph::~Graph() {
  for (std::pair<string, Vertex*> v : vertices_) {
    delete v.second;
  }

  for (Edge* e : edges_) {
    delete e;
  }
}

void Graph::addEdge(Edge* e) {
  edges_.push_back(e);

  if (vertices_.find(e->getSource()->getAddress()) == vertices_.end()) {
    vertices_.insert(
      std::make_pair(e->getSource()->getAddress(), e->getSource())
    );
  }

  if (vertices_.find(e->getDestination()->getAddress()) == vertices_.end()) {
    vertices_.insert(
      std::make_pair(e->getDestination()->getAddress(), e->getDestination())
    );
  }
}