#include "GraphicNode.h"

GraphicNode::GraphicNode(float x, float y, int value)
{
    this->value = value;
    this->x = x;
    this->y = y;

    w = 0.2f;
    h = 0.2f;

    draw_rect.top = y;
    draw_rect.bottom = y + h;
    draw_rect.left = x;
    draw_rect.right = x + w;

    std::cout << value << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
}

GraphicNode::~GraphicNode()
{

}
