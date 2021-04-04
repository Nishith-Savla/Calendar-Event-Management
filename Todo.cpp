#include <algorithm>
#include "Todo.h"

int Todo::totalTodos = 0;

Todo::Todo() {
    ++Todo::totalTodos;
    this->dueDate.reserve(3); // create 3 blocks of space in memory
}

Todo::Todo(vector<string> event) : Todo() {
    this->setName(event[0]);
    this->setHasCompleted(event[1] == "true");
    vector<int> date;
    vector<string> dateSplit = Functions::split(event[2], "/");
    for (const auto &i : dateSplit) {
        date.push_back(stoi(i));
    }
    this->setDueDate(date);
}

Todo::Todo(const string &name, vector<int> dueDate) : Todo() {
    this->setName(name);
    this->setDueDate(dueDate);
}

string Todo::dumpToString() {
    string todo;
    todo.append(this->name).append(",");
    todo.append(this->hasCompleted ? "true" : "false").append(",");
    for (auto date = dueDate.begin(); date != dueDate.end(); ++date) {
        todo.append(to_string(*date));
        if (date + 1 != dueDate.end())
            todo.append("/");
    }
    return todo;
}

// Add todo

Todo Todo::addTodo() {
    string name, date;
    cout << "Enter todo name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter todo due date: ";
    getline(cin, date);
    return Todo(vector<string> {name, "false", date});
}

void Todo::showTodo(Todo todo) {
    cout << "Id: " << todo.getId() << endl;
    cout << "Name: " << todo.getName() << endl;
    cout << "Date: ";
    vector<int> dueDate = todo.getDueDate();
    for (auto date = dueDate.begin(); date != dueDate.end(); ++date) {
        cout << *date;
        if (date + 1 != dueDate.end())
            cout << "/";
    }
    cout << endl;
    cout << "Has completed: " <<  todo.isCompleted() << endl;
}

void Todo::updateTodo(vector<Todo> &todolist) {
    int Id;
    string fieldToChange, newValue;
    cout << "Enter the Id of the todo you want to update: ";
    cin >> Id;
    Todo& todo = todolist[Id - 1];
    cout << "Enter the field you want to change: ";
    cin.ignore();
    getline(cin, fieldToChange);
    transform(fieldToChange.begin(), fieldToChange.end(), fieldToChange.begin(), ::tolower);
    if (fieldToChange == "name") {
        cout << "Enter new " << fieldToChange << " for the event: ";
        getline(cin, newValue);
        todo.setName(newValue);
    }else if (fieldToChange == "date") {
        cout << "Enter new " << fieldToChange << " for the event: ";
        getline(cin, newValue);
        todo.setDueDate(Functions::split(newValue));
    }else if (fieldToChange == "status") {
        cout << "Enter new " << fieldToChange << " for the event(true/false): ";
        getline(cin, newValue);
        todo.setHasCompleted(newValue == "true");
    } else {
        cerr << "Please enter a valid field (name/date/status):" << endl;
        updateTodo(todolist);
    }
}

void Todo::deleteTodo(vector<Todo> &todolist) {
    int Id;
    cout << "Enter the Id of the event you want to delete: ";
    cin >> Id;
    if(todolist.size() > Id-1) {
        todolist.erase(todolist.begin() + Id - 1);
    }
}
