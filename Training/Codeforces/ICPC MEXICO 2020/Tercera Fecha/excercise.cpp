#include <bits/stdc++.h>

class rectangle{
    int height;
    int width;

    public: int getArea(){
        return height*width;
    }

    int getPerimeter(){
        return 2*height+2*width;
    }

    rectangle(int *h, int *w){
        height=*h;
        width=*w;
    }

};

int main(){
    int *width= new int();
    int *height=new int();
    *width = 3;
    *height = 4;
    auto  example = new rectangle(width,height);
    int width2 =2;
    int height2 = 3;

    delete width;
    delete height;

    rectangle example2 = rectangle(&width2,&height2);
    std::cout<<example->getArea()<<'\n';
    std::cout<<example->getPerimeter()<<'\n';
    std::cout<<example2.getArea()<<'\n';
    std::cout<<example2.getPerimeter()<<'\n';
    return 0;
}