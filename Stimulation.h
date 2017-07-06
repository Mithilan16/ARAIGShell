//
//  Header.h
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-15.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#ifndef Header_h
#define Header_h
#include <string>
#include <iostream>
#include <fstream>
namespace termproject{
class Stimulation{
protected:
    std::string stimName;
public:
    virtual std::ostream& display(std::ostream&) const = 0;
    std::string getStimName()const {return stimName;}
    virtual Stimulation* clone() const = 0;
};
}
#endif /* Header_h */
