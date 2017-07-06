//
//  Exoskeleton.hpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-15.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#ifndef Exoskeleton_hpp
#define Exoskeleton_hpp
#include "Stimulation.h"

namespace termproject{
    
    class Exoskeleton:public Stimulation{
        unsigned intensity;
        unsigned duration;
        void setIntensity(const unsigned );
    
    public:
        Exoskeleton(std::string, unsigned, unsigned);
        Exoskeleton(std::ifstream& fin);
        Exoskeleton* clone()const{return new Exoskeleton(*this);};
        std::ostream& display(std::ostream&)const;
        Stimulation* read(std::ifstream&)const;
    };
}
#endif /* Exoskeleton_hpp */
