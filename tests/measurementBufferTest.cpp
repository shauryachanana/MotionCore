#include <stdexcept>
#include "tests.h"
#include "measurementBuffer.h"

TEST(MeasurementBufferTest, fractionalAverage){
    MeasurementBuffer<int> buffer;
    buffer.add(10);
    buffer.add(15);

    EXPECT_DOUBLE_EQ(buffer.average(), 12.5);
}

TEST(MeasurementBufferTest, emptyBuffer){
    MeasurementBuffer<double> buffer;
    EXPECT_THROW(buffer.average(), std::logic_error);
}

TEST(MeasurementBufferTest, averageAfterModification) {
    MeasurementBuffer<int> buffer;

    buffer.add(10);
    buffer.add(20);

    EXPECT_DOUBLE_EQ(buffer.average(), 15.0);

    buffer.add(30);

    EXPECT_DOUBLE_EQ(buffer.average(), 20.0);
}
