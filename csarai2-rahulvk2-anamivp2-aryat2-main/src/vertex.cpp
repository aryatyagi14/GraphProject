#include "vertex.h"

Vertex::Vertex() {
    
}

Vertex::Vertex(int id) {
    id_ = id;
    trust_level_ = 0;
}

int Vertex::getId() {
    return id_;
}

string Vertex::getLabel() {
    return label_;
}

int Vertex::getTrustLevel() {
    return trust_level_;
}

void Vertex::setId(int id) {
    id_ = id;
}

void Vertex::setLabel(string s) {
    label_ = s;
}

void Vertex::setTrustLevel(int trust_level) {
    trust_level_ = trust_level;
}