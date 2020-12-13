//
// Created by acer on 13-12-2020.
//

#include "Todo.h"
#include <vector>
#include <iostream>

Todo::Todo() {
    ++Todo::totalTodos;
}

Todo::Todo(std::string name_val, std::vector<int> dueDates) {
    this->setName(name_val);
    this->setDueDate(dueDates);
}
