#ifndef EXCEPTION_H
#define EXCEPTION_H

class Exception
{
    public:
        int code;
        char* name;
        Exception(int code, char* name) {this->code = code; this->name = name;}

    protected:

    private:
};

#endif // EXCEPTION_H
