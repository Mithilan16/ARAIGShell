//
//  Task.cpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-21.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#include "Task.hpp"
namespace termproject{
    
    Task::Task(std::string name){
        taskName = name;
    }
    
    Task::Task(std::string name, std::list <std::shared_ptr<Stimulation>> list){
        taskName = name;
        for(auto i = list.begin(); i != list.end();i++){
            stimulationList.push_back(std::shared_ptr<Stimulation>((*i)->clone()));
        }
    }
    
    
    Task::Task(const Task& source){
        *this = source;
        /*taskName = source.taskName;
        stimulationList.clear();
        for(auto i = (source.stimulationList).begin(); i != (source.stimulationList).end();i++){
            stimulationList.push_back(std::shared_ptr<Stimulation>((*i)->clone()));
        }*/
    }
    
    Task::Task(Task&& source){
        *this = std::move(source);
        /*taskName=source.taskName;
        stimulationList.clear();
        stimulationList = source.stimulationList;
        source.stimulationList.clear();
        source.taskName = " ";*/
    }

    Task& Task::operator=(const Task& source){
        if(this != &source){
            taskName = source.taskName;
            stimulationList.clear();
            for(auto i = (source.stimulationList).begin(); i != (source.stimulationList).end();i++){
                 stimulationList.push_back(std::shared_ptr<Stimulation>((*i)->clone()));
             }
        }
        return *this;
    }

    Task&& Task::operator=(Task&& source){
        if(this != &source){
            taskName=source.taskName;
            stimulationList.clear();
            stimulationList = source.stimulationList;
            source.taskName = " ";
            source.stimulationList.clear();
        }
        return std::move(*this);
    }
    
    void Task::operator+=(std::shared_ptr<Stimulation> stim){
        stimulationList.push_back(stim);
    }
    
    Stimulation& Task::operator[](size_t i)const{
        std::shared_ptr<Stimulation> stim = nullptr;
        size_t counter = 0;
        if(i <= stimulationList.size()){
            for(auto j = stimulationList.begin(); j != stimulationList.end(); j++){
                if( i == counter){
                    stim = *j;
                    break;
                }
            counter++;
            }
        }
        else{
            std::cout<<i<<" is not a valid index"<<std::endl;
        }
        return *stim;
    }
    
    void Task::removeStimulation(std::string name){
        bool found = false;
        std::list<std::shared_ptr<Stimulation>>::iterator i;
            for(i = stimulationList.begin(); i != stimulationList.end(); i++){
                if((*i)->getStimName() == name){
                    stimulationList.erase(i);
                    found =true;
                    break;
                }
            }
        if(found == false){
            std::cout<<"Stimulation: "<<name<<" not found"<<std::endl;
        }
    }
    
    std::ostream& Task::dump(std::ostream& os){
        os<<taskName<<std::endl;
        for(auto i = stimulationList.begin(); i != stimulationList.end(); i++){
            (*i)->display(os);
            os<<std::endl;
        }
        return os;
    }
    
    std::ostream& Task::execute(std::ostream& os){
        for(auto i = stimulationList.begin(); i != stimulationList.end(); i++){
          (*i)->display(os);
            os<<std::endl;
        }
        return os;
    }

    Task::~Task(){
        stimulationList.clear();
    }

}
