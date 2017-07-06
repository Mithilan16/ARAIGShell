//
//  Stims.hpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-15.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#ifndef Stims_hpp
#define Stims_hpp

#include "Stimulation.h"
namespace termproject{
    enum location{abs,front,back,traps};

    class Stims:public Stimulation{
        location Location;
        unsigned intensity;
        unsigned frequency;
        unsigned duration;
        void setLocation(const location);
        void setIntensity(const unsigned );
        
    public:
        Stims(std::string, location l, unsigned i,unsigned f, unsigned d);
        Stims(std::ifstream&);
        Stims* clone()const{return new Stims(*this);};
        std::ostream& display(std::ostream&)const;
        location strLocEnum(std::string);
        
    };

}
#endif /* Stims_hpp */
