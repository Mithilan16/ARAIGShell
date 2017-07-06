//
//  ARAIG_Sensors.hpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-30.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#ifndef ARAIG_Sensors_hpp
#define ARAIG_Sensors_hpp

#include <iostream>
#include "Task.hpp"
#include "Stims.hpp"
#include "Exoskeleton.hpp"
#include <sstream>

namespace termproject{
    class ARAIG_Sensors{
        Task** taskList;
        size_t size;
    public:
        ARAIG_Sensors():taskList (nullptr),size(0){};
        ARAIG_Sensors(std::string, std::string);
        std::ostream& dump(std::ostream&);
        size_t getSize(){return size;};
        Task* operator[](size_t);
        ~ARAIG_Sensors();
    };
}

#endif /* ARAIG_Sensors_hpp */
