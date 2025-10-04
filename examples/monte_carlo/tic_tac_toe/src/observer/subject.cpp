#include <tic_tac_toe/observer/subject.h>

using sophia::monte_carlo::tic_tac_toe::observer::Subject;
using sophia::monte_carlo::tic_tac_toe::observer::Observer;

void Subject::add_observer(const std::shared_ptr<Observer> &observer)
{
    observers_.push_back(observer);
}

void Subject::notify(std::string message) const
{
    for (const auto& observer : observers_)
        observer->Update(message);
}
