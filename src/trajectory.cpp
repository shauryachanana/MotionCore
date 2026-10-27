#include "trajectory.h"


Trajectory::Trajectory(std::string name, std::vector<double> positions) : name_(std::move(name)), positions_(std::move(positions)){
            
};

void Trajectory::addPosition(double position){
    positions_.push_back(position);
};

double Trajectory::positionAt(std::size_t index) const{
    return positions_.at(index);
};

std::size_t Trajectory::size() const{
    return positions_.size();
};

const std::string& Trajectory::name() const{
    return this->name_;
};
