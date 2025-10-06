#ifndef OBSERVER_H
#define OBSERVER_H
#include <tic_tac_toe/observer/observer.h>
#include <memory>
#include <vector>

namespace sophia::monte_carlo::tic_tac_toe::observer
{
    /**
     * @class Subject
     * @brief The subject in an observer pattern.
     */
    class Subject
    {
    public:
        /**
         * @brief Adds an observer to the subject.
         * @param observer The observer to add.
         */
        void add_observer(const std::shared_ptr<Observer>& observer);

        /**
         * @brief Notifies the Subject's Observers with a given message.
         * @param message The message to send to the Observers.
         */
        void notify(std::string message) const;

    private:
        std::vector<std::shared_ptr<Observer>> observers_;
    };
}

#endif //OBSERVER_H
