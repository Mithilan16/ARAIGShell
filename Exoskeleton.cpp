//
//  Exoskeleton.cpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-15.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#include "Exoskeleton.hpp"
namespace termproject{
    
    Exoskeleton::Exoskeleton(std::string n, unsigned i, unsigned d){
        stimName = n;
        setIntensity(i);
        duration = d;
    }
    
    Exoskeleton::Exoskeleton(std::ifstream& fin){
        std::getline(fin,stimName,',');
        fin>>intensity;
        fin.ignore(2000,',');
        fin>>duration;
        fin.ignore(2000,'\n');
    }
    
    
    void Exoskeleton::setIntensity(const unsigned i){
        if(i<= 100){
            intensity = i;
        }
        else{
            throw "intensity must be between 0 and 100";
        }
    }

    std::ostream& Exoskeleton::display(std::ostream& os)const{
        os<<stimName<<std::endl
        <<"     Type: Exoskeleton"<<std::endl
        <<"     Intensity: "<<intensity<<std::endl
        <<"     Duration: "<<duration<<std::endl;
        return os;
    }

    Stimulation* Exoskeleton::read(std::ifstream& fin) const{
        Stimulation* temp;
        std::string name;
        unsigned i,d;
        std::getline(fin,name,',');
        fin>>i;
        fin.ignore(2000,',');
        fin>>d;
        fin.ignore(2000,'\n');
        temp = new Exoskeleton(name,i,d);
        return temp;
    }
}
