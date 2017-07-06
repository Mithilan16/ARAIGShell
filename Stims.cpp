//
//  Stims.cpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-15.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#include "Stims.hpp"

namespace termproject{
    
    Stims::Stims(std::string n, location l, unsigned i,unsigned f, unsigned d){
        
        stimName = n;
        setLocation(l);
        setIntensity(i);
        frequency = f;
        duration = d;
    }

    Stims::Stims(std::ifstream& fin){
        std::string loc;
        std::getline(fin,stimName,',');
        std::getline(fin,loc,',');
        Location = strLocEnum(loc);
        fin>>intensity;
        fin.ignore(2000,',');
        fin>>frequency ;
        fin.ignore(2000,',');
        fin>>duration;
        fin.ignore(2000,'\n');
    }
    
    void Stims::setLocation(location ltype){
        if(ltype >= abs && ltype <= traps)
            Location = ltype;
    
        else{
            throw "invalid location";
        }
    }


    void Stims::setIntensity(const unsigned i){
        if(i<= 100){
            intensity = i;
        }
        else{
            throw "intensity must be between 0 and 100";
        }
    }

    std::ostream& Stims::display(std::ostream& os)const{
        os<<stimName<<std::endl
        <<"     Type = stim"<<std::endl
        <<"     Location = "<<Location<<std::endl
        <<"     Intensity = "<<intensity<<std::endl
        <<"     Frequency = "<<frequency<<std::endl
        <<"     Duration = "<<duration<<std::endl;
        return os;
    }

    location Stims::strLocEnum(std::string loc){
        location conversion;
        if(loc == "abs"){
            conversion = abs;
        }
        
        else if(loc == "front"){
            conversion = front;
        }
        else if(loc == "back"){
            conversion = back;
        }
        else if(loc == "traps"){
            conversion = traps;
        }
        else{
            throw "Corrupt File: Invalid Enum";
        }
        return conversion;
    }
}
