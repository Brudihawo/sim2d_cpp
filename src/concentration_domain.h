#pragma once 
#include "container.h"
#include "simulation_domain.h"
#include <vector>
#include <iostream>

class ConcentrationDomain : public SimulationDomain {
    private: 
        std::vector<double>& c; // Concentration scalar field
        std::vector<double>& old_c; // Previous timestep concentration values;
        double D; // Diffusion Coefficient
    
    public:
        ConcentrationDomain(SimParams& p, std::vector<double> additional_params);
        ~ConcentrationDomain();
        bool timestep(long t) override;
};