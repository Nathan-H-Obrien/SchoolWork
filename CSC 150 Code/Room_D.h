#ifndef ROOM_D_H_INCLUDED
#define ROOM_D_H_INCLUDED


class Room
{
    private:            //sets the length and width private to ensure that only member function can access them
        double length;
        double width;
    public:             //sets the member function public to ensure that the private variables can be altered
        Room();         //Creates a constructor
        void setWidth(double w)
    {   
        if (w >= 0)     //ensures the value passed in is valid
            width = w;
        else
        {
       std::cout << "Invalid width" << std::endl;
       exit(EXIT_FAILURE);      //exits the program if the value is not valid
        }
    };
        void setLength(double len)
    {
        if (len >= 0)     //ensures the value passed in is valid
            length = len;
        else
        {
       std::cout << "Invalid length" << std::endl;
       exit(EXIT_FAILURE);      //exits the program if the value is not valid
        }
    };

        double getWidth() const
        { return width; }

        double getLength() const
        { return length; }

        double getArea() const
        { return length * width; }

        ~Room()         //Creates a destructor
        {

        }
};

#endif // ROOM_D_H_INCLUDED
