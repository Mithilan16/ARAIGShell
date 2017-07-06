//
//  Profile.hpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-12-04.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#ifndef Profile_hpp
#define Profile_hpp

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "ARAIG_Sensors.hpp"

namespace termproject{
    struct Settings{
        unsigned calMax;
        unsigned calMin;
    };
    
    class Profile{
        std::string sFName;
        std::string sLName;
        std::string iFName;
        std::string iLName;
        Settings settings;
        unsigned studentNo;
        unsigned employeeNo;
        std::vector <std::shared_ptr<Task>> toRun;
        std::vector <std::shared_ptr<Task>> Completed;
    public:
        Profile(std::string, std::ostream&, ARAIG_Sensors&);
        void displayToRun();
        void displayCompleted();
        void displayNextTask();
        void displayLastTask();
        void runTask(std::ostream&);
        ~Profile(); 
    };
}

#endif /* Profile_hpp */
