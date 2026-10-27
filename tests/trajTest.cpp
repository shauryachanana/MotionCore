#include "trajectory.h"
#include "tests.h"

// Test 1: Constructor

TEST(TrajectoryTest, Construction) {

    Trajectory t1("KUKA", {1.0, 10.5, 0.5});

    EXPECT_EQ(t1.name(), "KUKA");
    EXPECT_EQ(t1.size(), 3U);
    EXPECT_DOUBLE_EQ(t1.positionAt(0), 1.0);
}

TEST(TrajectoryTest, AddPostion){
    Trajectory t1("KUKA", {1.0, 10.5, 0.5});
    t1.addPosition(3.6);

    ASSERT_EQ(t1.size(), 4u);
    EXPECT_DOUBLE_EQ(t1.positionAt(3), 3.6);
}

TEST(TrajectoryTest, CopyIndependence){
    Trajectory t1("KUKA", {1.0, 10.5, 0.5});

    Trajectory t2 = t1;


    ASSERT_EQ(t1.size(), t2.size());

    for(std::size_t i = 0; i < t1.size(); i++){
        EXPECT_EQ(t1.positionAt(i), t2.positionAt(i));
    }

    ASSERT_EQ(t1.name(), t2.name());

    t1.addPosition(4.0);

    EXPECT_EQ(t1.size(), 4u);
    EXPECT_DOUBLE_EQ(t1.positionAt(3), 4.0);

    EXPECT_EQ(t2.size(), 3);
    EXPECT_DOUBLE_EQ(t2.positionAt(2), 0.5);
}

TEST(TrajectoryTest, InvalidIndex){
    Trajectory t1("UR5e", {1.1, 9.5, 6.7});
    EXPECT_THROW(t1.positionAt(100), std::out_of_range);
}