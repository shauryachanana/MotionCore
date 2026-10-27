#ifndef TRAJECTORY_H
#define TRAJECTORY_H

#include <vector>
#include <string>

class Trajectory{

    private:
        std::string name_;
        std::vector<double> positions_; 

    public:
        Trajectory(std::string name, std::vector<double> positions);
        void addPosition(double position);
        double positionAt(std::size_t index) const;
        std::size_t size() const;
        const std::string& name() const;

};

#endif