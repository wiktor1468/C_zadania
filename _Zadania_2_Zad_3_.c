//
// Created by wikto on 04.03.2024.
//
#include "stdio.h"
#include "math.h"
typedef struct {
    int x;
    int y;
} Point;

typedef struct{
    Point w1;
    Point w2;
    Point w3;
    Point w4;

} Rectangle;


void addtwo(Point *p) {
    (*p).x+=2;
    (*p).y+=2;
}

int calculateDistance(Point p1, Point p2) {
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

void analiza(Rectangle *rec) {
    int obw = 0;
    Point vertices[4] = {rec->w1, rec->w2, rec->w3, rec->w4};//aby moc uzyc forloop

    for (int i = 0; i < 4; ++i) {
        obw += calculateDistance(vertices[i], vertices[(i + 1) % 4]); // %4 aby dostac pare(w4,w1)
    }
    int a,b, pole =0;
    a= calculateDistance(rec->w1, rec->w2);
    b= calculateDistance(rec->w2, rec->w3);
    pole =a*b;
    printf("obw: %d i pole: %d",obw, pole);

}
int main(){
    Point p;  //initalizacji struct
    p.x=4;
    p.y=2;

    addtwo(&p);
    printf("(%d, %d)\n",p.x,p.y);
    //rectangle
    Rectangle rec;
    rec.w1.x=1;
    rec.w1.y=1;

    rec.w2.x=3;
    rec.w2.y=1;

    rec.w3.x=3;
    rec.w3.y=7;
    rec.w4.x=1;
    rec.w4.y=7;

    analiza(&rec);


    return 0;
}