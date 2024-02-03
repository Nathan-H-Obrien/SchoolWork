#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room
{
    private:            //sets the length and width private to ensure that only member function can access them
        const double length;
        const double width;
    public:             //sets the member function public to ensure that the private variables can be altered
        void setWidth(const double);
        void setLength( const double);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};


#endif // ROOM_H_INCLUDED
