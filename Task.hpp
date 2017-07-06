//
//  Task.hpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-21.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#ifndef Task_hpp
#define Task_hpp

#include <list>
#include <memory>
#include "Stimulation.h"
#include "Stims.hpp"
#include "Exoskeleton.hpp"
namespace termproject{
class Task{
    std::list <std::shared_ptr<Stimulation>> stimulationList;
    std::string taskName;
public:
    Task(std::string);
    Task(std::string, std::list <std::shared_ptr<Stimulation>>);
    Task(const Task&);
    Task(Task&&);
    Task& operator=(const Task&);
    Task&& operator=(Task&&);
    void operator+=(std::shared_ptr<Stimulation>);
    Stimulation& operator[](size_t i)const;
    void removeStimulation(std::string name);
    std::ostream& dump(std::ostream&);
    std::ostream& execute(std::ostream&);
    std::string getTaskName(){return taskName;};
    size_t getSize(){return stimulationList.size();};
    ~Task();
};


}
#endif /* Task_hpp */
