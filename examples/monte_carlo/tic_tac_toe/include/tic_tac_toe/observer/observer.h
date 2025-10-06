#ifndef SUBJECT_H
#define SUBJECT_H
#include <string>

namespace sophia::monte_carlo::tic_tac_toe::observer
{
    /**
     * @class Observer
     * @brief The Observer in an Observer pattern.
     */
    class Observer
    {
    public:
        /**
         * @brief Updates the observer with the given message.
         * @param message The mssage to update the observer with.
         */
        virtual void Update(std::string message) = 0;
    };
}

#endif //SUBJECT_H
