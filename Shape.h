#ifndef HELLOSDL2_SHAPE_H
#define HELLOSDL2_SHAPE_H


class Shape {
public:
    virtual ~Shape() = default;

    virtual void draw() = 0;

    virtual void update() = 0;
};


#endif //HELLOSDL2_SHAPE_H
