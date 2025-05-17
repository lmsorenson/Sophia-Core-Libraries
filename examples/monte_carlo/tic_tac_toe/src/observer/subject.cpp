#include <tic_tac_toe/observer/subject.h>

using sophia::examples::tic_tac_toe::observer::Subject;
using sophia::examples::tic_tac_toe::observer::Observer;

void Subject::add_observer(const std::shared_ptr<Observer> &observer)
{
    observers_.push_back(observer);
}

void Subject::notify() const
{
    for (const auto& observer : observers_)
        observer->Update();
}
