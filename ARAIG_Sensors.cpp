//
//  ARAIG_Sensors.cpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-30.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#include "ARAIG_Sensors.hpp"
#include <fstream>
#include <list>
#include <string>
#include <memory>

namespace termproject{
    
    ARAIG_Sensors::ARAIG_Sensors(std::string stim, std::string task){
        std::list <std::shared_ptr<Stimulation>> sList;//temporary stimulation list
        std::ifstream fin(stim);//open Stimulation File for reading
        if (fin.is_open()){
            while(fin.good()){
                std::string type;
                std::getline(fin,type,',');//get object type
                
                if(type == "stim"){//create stim object
                    sList.push_back(std::shared_ptr<Stims> (new Stims(fin)));
                }
    
                else if(type == "exoskeleton"){//create exoskeleton object
                    sList.push_back(std::shared_ptr<Exoskeleton> (new Exoskeleton(fin)));
                }
            }
        }
        
        else{
            throw "Stimulation Configuration File Error";
        }
        fin.close();
        
        //Reading Task Configuration File
        fin.open(task);
        if(fin.is_open()){
            std::string line,tLine;
            size_t found,counter = 0,index = 0;
            while(fin.good()){//counting Task Objects for dynamic allocation
                getline(fin,line,'\n');
                found = line.find("TASK");
                if(found != std::string::npos){
                    counter++;
                }
            }
            //std::cout<<"Counter Total: "<<counter<<std::endl;
            size = counter;
            taskList = new Task* [counter];//Create List of Task Pointers
            
            fin.clear();//Reset state of ifstream object state
            fin.seekg(0, std::ios::beg);//go to begining of file
        
            while(fin.good()){//Reading TaskConfig File again for Object creation
                if(index == 0){//getline for first iteration only, line contains "TASK" string for future iterations
                    getline(fin,line);
                    line.erase(line.length() - 1);
                }
                //found = line.find("TASK");
                if(line.find("TASK") != std::string::npos){//if line contains "TASK", use sstream to get Task Name
                    std::stringstream iss(line);
                    iss.ignore(2000,',');
                    std::getline(iss,tLine,'\n');
                    taskList[index] = new Task(tLine);//create new task empty task object
                    //std::cout<<std::endl<<"Creating Task: "<<tLine<<" at index"<<index<<std::endl;
                    getline(fin,line);
                    line.erase(line.length() - 1);
                    //found = line.find("TASK");
                    
                    while(line.find("TASK") == std::string::npos && !fin.eof()){//add Stim object
                        for(auto i = sList.begin();i != sList.end();i++){
                            if(line == (*i)->getStimName()){
                                //std::cout<<"Adding Stim:"<<line<<" to Index: "<<index<<std::endl;
                                *(taskList[index]) += (*i);
                            }
                        }
                        getline(fin,line);
                        if(!fin.eof()){
                            line.erase(line.length() - 1);
                        }
                        found = line.find("TASK");
                    }
                    //std::cout<<"Stimulation List Size: "<<taskList[index]->getSize()<<std::endl;
                    index++;
                }
            }
        }
        else{
            throw "Task Configuration File Error";
        }
    }


    std::ostream& ARAIG_Sensors::dump(std::ostream& os){
        for(auto i =0; i < 30;i++){
            taskList[i]->dump(os);
        }
        return os;
    }

    Task* ARAIG_Sensors::operator[](size_t index){
        return taskList[index];
    }
    
    ARAIG_Sensors::~ARAIG_Sensors(){
        for(size_t i = 0; i<getSize();i++){
            delete taskList[i];
        }
        delete taskList;
        taskList = nullptr;
    }

}
