
/* 
 * File:   rectangle.h
 * Author: ie04
 *
 * Created on December 8, 2018, 12:08 PM
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

class rectangle {
public:
    rectangle();
    rectangle(int, int);
    ~rectangle();
    void drawrect() const;
    void drawrect(int, int) const;
private:
    int width;
    int height;
};

#endif /* RECTANGLE_H */

