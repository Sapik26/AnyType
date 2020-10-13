#include <iostream>
#include <variant>
#include <typeinfo>
#include <string>

using namespace std;

using variant_type = variant<char, bool, int, float, double>;

class AnyType
{
private:
    variant_type data;
    string typeInfo;

public:
    AnyType()
    {
        data = 0;
        typeInfo = typeid(int).name();
    }

    template<typename T>
    AnyType(T value)
    {
        data = value;
        typeInfo = typeid(value).name();
    }

    AnyType(const AnyType& objValue) 
    {
        data = objValue.data;
        typeInfo = objValue.typeInfo;
    }

    template <typename T>
    AnyType& operator= (T value) 
    {
        data = value;
        typeInfo = typeid(value).name();
        return *this;
    }
   
    AnyType& operator=(const AnyType objValue)
    {
        data = objValue.data;
        typeInfo = typeid(objValue.data).name();
        return *this;
    }

    inline char toChar()
    {
        if(holds_alternative<char>(data))
        {
            return get<char>(data);
        }
        else
        {
            throw std::bad_cast();
        }
    }

    inline bool toBool()
    {
        if(holds_alternative<bool>(data))
        {
            return get<bool>(data);
        }
        else
        {
            throw std::bad_cast();
        }
    }

    inline int toInt()
    {
        if(holds_alternative<int>(data))
        {
            return get<int>(data);
        }
        else
        {
            throw std::bad_cast();
        }
    }

    inline float toFloat()
    {
        if(holds_alternative<float>(data))
        {
            return get<float>(data);
        }
        else
        {
            throw std::bad_cast();
        }
    }

    inline double toDouble()
    {
        if(holds_alternative<double>(data))
        {
            return get<double>(data);
        }
        else
        {
            throw std::bad_cast();
        }
    }

    void Swap(AnyType& objValue)
    {
        AnyType temp; 

        temp.data = this->data;
        this->data = objValue.data;
        objValue.data = temp.data;

        temp.typeInfo = this->typeInfo;
        this->typeInfo = objValue.typeInfo;
        objValue.typeInfo = temp.typeInfo;
    }

    inline string getType()
    {
        return typeInfo;
    }
};

int main()
{
    AnyType anyType = 1;
    anyType = true;
    anyType = 1.7;


    try
    {
        int storedValue = anyType.toInt();
    }
    catch (const std::bad_cast& ex)
    {
        cout << ex.what();
    }

}