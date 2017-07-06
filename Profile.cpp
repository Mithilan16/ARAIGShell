//
//  Profile.cpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-12-04.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#include "Profile.hpp"
namespace termproject{
    
    Profile::Profile(std::string fname, std::ostream& os, ARAIG_Sensors& ar){
        std::string line;
        std::ifstream fin(fname);
        if(fin.is_open()){
            getline(fin,sFName,',');
            getline(fin,sLName,',');
            fin>>studentNo;
            fin.ignore(2000,'\n');
            getline(fin,iFName,',');
            
            getline(fin,iLName,',');
            fin>>employeeNo;
            fin.ignore(2000,'\n');
            fin>>settings.calMax;
            fin.ignore(2000,',');
            fin>>settings.calMin;
            fin.ignore(2000,'\n');
            while(getline(fin,line,'\n')){
                line.erase(line.length() - 1);
                for(auto i = 0;i < ar.getSize();i++){
                    if(ar[i]->getTaskName()== line){
                        toRun.push_back(std::shared_ptr<Task>(new Task(*ar[i])));
                    }
                }
            }
            os<<"Profile Created"<<std::endl
            <<"=============================================="<<std::endl
            <<"Student: "<<sFName<<" "<<sLName<<" - "<<studentNo<<std::endl
            <<"Instructor: "<<iFName<<" "<<iLName<<" - "<<employeeNo<<std::endl
            <<"Student Calibration:"<<std::endl
            <<"MAX = "<<settings.calMax<<std::endl
            <<"MIN = "<<settings.calMin<<std::endl;
            for(auto i = toRun.begin();i < toRun.end();i++){
                (*i)->dump(os)<<std::endl;
            }
            os<<std::endl;
        }
        fin.close();
    }

    void Profile::displayToRun(){
        std::cout<<"Tasks To Run:"<<std::endl;
        std::cout<<"=============="<<std::endl;
        for(auto i = toRun.begin();i < toRun.end();i++){
            std::cout<<(*i)->getTaskName()<<std::endl;
        }
        std::cout<<std::endl;
    }
    
    void Profile::displayCompleted(){
        std::cout<<"Completed Tasks:"<<std::endl;
        std::cout<<"================"<<std::endl;
        for(auto i = Completed.begin();i < Completed.end();i++){
            std::cout<<(*i)->getTaskName()<<std::endl;
        }
        std::cout<<std::endl;
    }

    void Profile::displayNextTask(){
        if(!toRun.empty()){
            std::cout<<"Next Task: "<<toRun.front()->getTaskName()<<std::endl;
        }
       
        else{
            std::cout<<"No more Tasks!"<<std::endl;
        }
    }

    void Profile::displayLastTask(){
        if(Completed.empty()){
            std::cout<<"Last Completed Task: "<<Completed.back()->getTaskName()<<std::endl;
        }
        else{
            std::cout<<"No Tasks have been completed!"<<std::endl;
        }
    }

    void Profile::runTask(std::ostream& os){
        std::string input ="r";
        while(input == "r"){
            if(toRun.empty()){
                std::cout<< "There are no more Tasks to run"<<std::endl;
                break;
            }
            os<<"Running "<<toRun.front()->getTaskName()<<"..."<<std::endl;
            std::cout<<"Running "<<toRun.front()->getTaskName()<<"..."<<std::endl;
            toRun.front()->execute(std::cout);
            Completed.push_back(std::shared_ptr<Task>(new Task(std::move(*toRun.front()))));
            toRun.erase(toRun.begin());
            os<<Completed.back()->getTaskName()<<" completed!"<<std::endl<<std::endl;
            displayNextTask();
            std::cout<<"Type r to run next or e to exit: ";
            std::cin>>input;
            while(input != "r" && input != "e"){
                std::cin.ignore(2000,'\n');
                std::cout<<"Invalid Input!"<<std::endl;
                std::cout<<"Type r to run next or e to exit: ";
                std::cin>>input;
            }
            if(input == "e"){
                break;
            }
        }
    }
    
    Profile::~Profile(){
        toRun.clear();
        Completed.clear();
    }
}
