//
//  main.cpp
//  FinalProject
//
//  Created by Mithilan Sivanesan on 2016-11-15.
//  Copyright © 2016 Mithilan Sivanesan. All rights reserved.
//

#include <iostream>
#include "Stimulation.h"
#include "Exoskeleton.hpp"
#include "Stims.hpp"
#include "Task.hpp"
#include "ARAIG_Sensors.hpp"
#include "Profile.hpp"
#include <fstream>
using namespace termproject;

int main(int argc, char* argv[]){
    if (argc != 5) {
        std::cerr << argv[0] <<
        ": incorrect number of arguments\n";
        std::cerr << "Usage: " << argv[0] << "file_name\n";
        return 1;
    }
    else{
        try{
            //Load Stimulations and Task Objects
            ARAIG_Sensors a = ARAIG_Sensors(argv[2], argv[3]);
            std::ofstream fout(argv[4]);
            //Load Profile
            Profile profile = Profile(argv[1], fout, a);
            profile.displayToRun();
            
            //Execute the flight plan (Run Tasks).
            profile.runTask(fout);
            profile.displayNextTask();
            profile.displayCompleted();
        }
        catch (std::exception& e) { // called by std::bad_alloc also
            std::cout << "Standard Exception: "<<e.what()<< std::endl;
        }
        catch (std::bad_alloc) { // UNREACHABLE!
            std::cout << "Insufficient memory " << std::endl;
        }
        catch(const char* msg) {
            std::cout << msg << std::endl;
        }
        return 0;
    }
        

    }
