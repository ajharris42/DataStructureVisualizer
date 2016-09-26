#include <iostream>
#include <sstream>
#include <string>

#include "BinaryTree.h"
#include "GraphicTreeNode.h"

#include <windows.h>
#include <GL/freeglut.h>
#include "GraphicsDriver.h"


BinaryTree<GraphicNode *> graphic_tree;


void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    LinkedList<GraphicNode *> *list = graphic_tree.preorder();
    LinkedListIterator<GraphicNode *> *itr = list->getIterator();

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);

        while(itr->has_next())
        {
            GraphicNode *next = itr->next();

            glVertex2f(next->draw_rect.left, next->draw_rect.top);
            glVertex2f(next->draw_rect.right, next->draw_rect.top);
            glVertex2f(next->draw_rect.right,  next->draw_rect.bottom);
            glVertex2f(next->draw_rect.left,  next->draw_rect.bottom);
        }
    glEnd();

    itr = list->getIterator();

    while(itr->has_next())
    {
        GraphicNode *node = itr->next();

        std::stringstream ss;
        ss << node->get_value();

        std::string s = ss.str();

        const unsigned char *c = reinterpret_cast<const unsigned char *>(s.c_str());

        glColor3f(0.0f, 0.0f, 0.0f);
        glRasterPos2f(node->get_x() + node->get_w() / 2, node->get_y() + node->get_h() / 2);
        glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }

    glFlush();
}

void display2()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f( 0.5f, -0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f(-0.5f,  0.5f);
    glEnd();

    glFlush();
}

int main(int argc, char **argv)
{
    BinaryTree<int> tree;

    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);

 //   tree.insert(7);

    LinkedList<int> *list = tree.preorder();
    LinkedListIterator<int> *itr = list->getIterator();

    float x = 0.0f;
    float y = 0.5f;

    float node_x_offset = 0.25f;
    float node_y_offset = -0.25f;

    float prev_x = x;
    float prev_y = y;

    float depth = 1.0f;

    int j = 0;

    while(itr->has_next())
    {
        int a = itr->next();
        int b = itr->get_next_value();

        if(b == -1)
            break;

        if(j == 0)
            graphic_tree.insert(new GraphicNode(x, y, a));

        if(b < a)
        {
            x += -node_x_offset;
            y += node_y_offset * depth;
        }
        else if(b > a || b == a)
        {
            x += node_x_offset;
            y += node_y_offset * depth;
        }

        graphic_tree.insert(new GraphicNode(x, y, b));

        ++j;
    }

    glutInit(&argc, argv);

    GraphicsDriver g;

    WindowDriver *window = g.createWindow(50, 50, 640, 480);

   // WindowDriver *window2 = g.createWindow(100, 100, 500, 500);

    g.renderToWindow(window, display);
   // g.renderToWindow(window2, display2);

    glutMainLoop();

    return 0;
}
