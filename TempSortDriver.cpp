#include <iostream>
//#include <cmath>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

///////////////////start of template stuff

template <typename ItemType>
void swap(ItemType & x, ItemType & y)
{
    ItemType t = x;
    x = y;
    y = t;
    return;
}

template <size_t N>
void swap(char (&a)[N], char (&b)[N])
{
    cerr<<"my non-type template swap...'"<<a
        <<"' ("<<sizeof(a)<<") & '"<<b<<"' ("<<sizeof(b)<<")\n";
    char c[N];
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
    return;
}



template <size_t A, size_t B>
struct Max_of
{
    enum { value = (A > B ? A : B) };
};

template <size_t N, size_t M>
void swap(char (&a)[N], char (&b)[M])
{
    cerr<<"my non-type template swap...'"<<
        a<<"' ("<<sizeof(a)<<") & '"<<b
        <<"' ("<<sizeof(b)<<")\n";
    char c[Max_of<N,M>::value];
    strcpy(c, a);
    strncpy(a, b, N-1);
    a[N-1] = '\0';
    strncpy(b, c, M-1);
    b[M-1] = '\0';
    return;
}

//// end of swap stuff

template <typename ArrayType, typename CompareType>
void sort1(ArrayType & array, const size_t & low,
           const size_t & high,//inc
           const CompareType & f )
{
    size_t done_thru, position;
    bool did_swap;
    did_swap = true;
    done_thru = high;
    while ((done_thru >= low) && (did_swap))
    {
        did_swap = false;
        for (position = low; position < done_thru; position++)
        {
            if (f(array[position],array[position+1]))
            {
                ::swap(array[position], array[position+1]);
                did_swap = true;
            }
        }
        done_thru--;
    }
    return;
}


////start of compare functions
template <typename T>
bool ascend(const T& a,const T& b)
{

    bool returnVal = false;

    if(a > b)
    {
        returnVal = true;
    }
    return returnVal;


}

template <typename T>
bool descend(const T& a,const T& b)
{

    bool returnVal = false;

    if(a < b)
    {
        returnVal = true;
    }
    return returnVal;


}


template <size_t N>
bool ascend(const char(&a)[N],const char(&b)[N])
{

    bool returnVal = false;

    if(std::strcmp(a,b) > 0)
    {
        returnVal = true;
    }
    return returnVal;


}

template <size_t N>
bool descend(const char(&a)[N],const char(&b)[N])
{

    bool returnVal = false;

    if(std::strcmp(a,b) < 0)
    {
        returnVal = true;
    }
    return returnVal;


}
//////////////////////////////////////end of template stuff



int main(void)
{

    short t[5] = {1,2,7,4,6};

    double a[5] = {1.6,2.9,3.1,4.2,6.4};

    char b [5] = {'a','b','c','d','g'};


    std::vector<std::string> colour1 = { "Blue",
                                         "Red",
                                         "Orange",
                                         "Yellow"
                                       };

    //array of c_strs
    const size_t colour3len = 4;


    char colour3[colour3len][8] = { "Blue2",
                                    "Red2",
                                    "Orange2",
                                    "Yellow2"
                                  };

    sort1(a,static_cast<size_t>(0),
          static_cast<size_t>(4),
          ascend<double>);
    sort1(b,static_cast<size_t>(0),
          static_cast<size_t>(4),
          ascend<char>);

    sort1(t,static_cast<size_t>(0),
          static_cast<size_t>(4),
          ascend<short>);

    sort1(colour1,static_cast<size_t>(0),
          static_cast<size_t>(3),
          ascend<std::string>);

    sort1(colour3,static_cast<size_t>(0),
          static_cast<size_t>(3),
          ascend<8>);


    //sort1(c,static_cast<size_t>(0),clen, ascend);

    for(size_t i = 0; i < 5; i++)
    {
        std::cout << a[i] <<" ";
    }

    std::cout << "\n";

    for(size_t i = 0; i < 5; i++)
    {
        std::cout << t[i] <<" ";
    }

    std::cout << "\n";

    for(size_t i = 0; i < 5; i++)
    {
        std::cout << b[i] << " ";
    }

    std::cout << "\n";
    std::cout << "\n";

    for(size_t i = 0; i < 4; i++)
    {
        std::cout << colour1[i];
        std::cout << "\n";
    }

    std::cout << "\n";



    for(size_t i = 0; i < 4; i++)
    {
        std::cout << colour3[i];
        std::cout << "\n";
    }

    std::cout << "\n";


    sort1(a,static_cast<size_t>(0),
          static_cast<size_t>(5),
          descend<double>);

    sort1(b,static_cast<size_t>(0),
          static_cast<size_t>(5),
          descend<char>);

    sort1(t,static_cast<size_t>(0),
          static_cast<size_t>(4),
          descend<short>);

    sort1(colour1,static_cast<size_t>(0),
          static_cast<size_t>(3),
          descend<std::string>);


    sort1(colour3,static_cast<size_t>(0),
          static_cast<size_t>(3),
          descend<8>);


    for(size_t i = 0; i < 5; i++)
    {
        std::cout << a[i] << " ";
    }

    std::cout << "\n";

    for(size_t i = 0; i < 5; i++)
    {
        std::cout << t[i] <<" ";
    }

    std::cout << "\n";

    for(size_t i = 0; i < 5; i++)
    {
        std::cout << b[i] << " ";
    }

    std::cout << "\n";


    std::cout << "\n";

    for(size_t i = 0; i < 4; i++)
    {
        std::cout << colour1[i];
        std::cout << "\n";
    }

    std::cout << "\n";

    for(size_t i = 0; i < 4; i++)
    {
        std::cout << colour3[i];
        std::cout << "\n";
    }


    return 0;
}















