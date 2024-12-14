#ifndef EXCEPTION_H
#define EXCEPTION_H


class Exception
{
    public:
        int code;
        char* message;
        Exception(int code, char* message) {this->code = code; this->message = message;}

    protected:

    private:
};

#endif // EXCEPTION_H
