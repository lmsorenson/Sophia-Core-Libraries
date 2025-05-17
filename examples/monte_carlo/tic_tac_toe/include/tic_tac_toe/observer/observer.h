#ifndef SUBJECT_H
#define SUBJECT_H

namespace sophia::examples::tic_tac_toe::observer
{
    class Observer
    {
    public:
        virtual void Update() = 0;
    };
}

#endif //SUBJECT_H
