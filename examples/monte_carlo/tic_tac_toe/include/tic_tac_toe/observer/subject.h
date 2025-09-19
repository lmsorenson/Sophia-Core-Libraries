#ifndef OBSERVER_H
#define OBSERVER_H
#include <tic_tac_toe/observer/observer.h>
#include <memory>
#include <vector>

namespace sophia::examples::tic_tac_toe::observer
{
    class Subject
    {
    public:
        void add_observer(const std::shared_ptr<Observer>& observer);
        void notify(std::string message) const;

    private:
        std::vector<std::shared_ptr<Observer>> observers_;
    };
}

#endif //OBSERVER_H
