#ifndef GRAPHICNODE_H
#define GRAPHICNODE_H

#include <iostream>
#include "Globals.h"

struct Rect
{
    float left, top;
    float right, bottom;
};

//ToDo: Finish operator overloads
class GraphicNode
{
    public:
        GraphicNode(float x, float y, int value);
        virtual ~GraphicNode();

        bool operator <(const GraphicNode &b) const
        {
            return this->value < b.value;
        }

        bool operator >(const GraphicNode &b) const
        {
            return this->value > b.value;
        }

        bool operator ==(const GraphicNode &b) const
        {
            return this->value == b.value;
        }


        Rect draw_rect;

        int get_value(){return value;}
        float get_x(){return x;}
        float get_y(){return y;}
        float get_w(){return w;}
        float get_h(){return h;}
    protected:

        float x, y;
        float w, h;

        //TODO: Template this
        int value;
    private:

};

#endif // GRAPHICNODE_H
