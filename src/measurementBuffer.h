#ifndef MEASUREMENT_BUFFER_H
#define MEASUREMENT_BUFFER_H

#include <vector>
#include <cstddef>
#include <utility>
#include <algorithm>
#include <concepts>
#include <stdexcept>

template <typename T>
class MeasurementBuffer{

    private:
        std::vector<T> values_;
        mutable double cachedSum_ = 0.0;
        mutable bool cacheValid_ = false;

    public:
        MeasurementBuffer() = default;

        explicit MeasurementBuffer(std::vector<T> values) : values_(std::move(values)){};

        void add (T value){
            values_.push_back(std::move(value));
            cacheValid_ = false;
        };

        const T& at(std::size_t index) const{
            return values_.at(index);
        };

        std::size_t size() const{
            return values_.size();
        }

        bool contains(const T& target) const{
            return std::find(values_.begin(), values_.end(), target) != values_.end();            
        };

        double average() const requires (std::integral<T> || std::floating_point<T>){
            if (values_.empty()){
                throw std::logic_error("Cannot calculate average of empty buffer");
            }

            if(!cacheValid_){
                double sum = 0.0;
                for(T num : values_){
                    sum += static_cast<double>(num);
                }
                cachedSum_ = sum;
                cacheValid_ = true;
            }
            
            return cachedSum_/static_cast<double>(values_.size());
        };

};

#endif