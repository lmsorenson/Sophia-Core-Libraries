#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>

namespace sophia::examples::tic_tac_toe::observer
{
    class Observer
    {
    public:
        virtual void Update(std::string message) = 0;
    };
}

#endif //SUBJECT_H
