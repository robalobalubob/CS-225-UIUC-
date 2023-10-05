#include "./Edge.h"

Edge::Edge() {
    next_ = NULL;
}

Edge::~Edge() {
    if (next_ == NULL) {
        return;
    }
    delete next_;
    next_ = NULL;
}