#include "Todo.h"

int Todo::totalTodos = 0;

Todo::Todo() {
    ++Todo::totalTodos;
}

Todo::Todo(const std::string &name, const std::vector<int> &dueDate) {
    this->setName(name);
    this->setDueDate(dueDate);
}
