#include "edge.h"

Edge::Edge() {

}

Edge::Edge(int from, int to, int weight) {
    to_ = to;
    from_ = from;
    weight_ = weight;
}

int Edge::getFrom() {
    return from_;
}

int Edge::getTo() {
    return to_;
}

int Edge::getWeight() {
    return weight_;
}

std::string Edge::getLabel() {
    return label_;
}

void Edge::setFrom(int from) {
    from_ = from;
}

void Edge::setTo(int to) {
    to_ = to;
}

void Edge::setWeight(int weight) {
    weight_ = weight;
}

void Edge::setLabel(string label) {
    label_ = label;
}