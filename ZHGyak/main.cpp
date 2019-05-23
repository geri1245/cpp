#include <iostream>

#include "track.hpp"
#include "track.hpp"

bool deq(const double a, const double b) //Equality check for double precision floating point values
{                                        //Not part of the exercise, it's just for correctness testing
    return std::abs(a - b) < 0.1;
}

int main()
{
    int mark = 1;

    //Straight, RightTurn, LeftTurn, RaceCar, car.complete
    Straight s1{500}; //{length of the straight road}
    RightTurn rt1{100, 65}; //{length of the turn, degree of the turn}

    RaceCar car{120};
    const double s_time = car.complete(s1);   // Time = road length / speed
    const double rt_time = car.complete(rt1); // Time = ((90 - degree) / 90) * turn length / speed
    
    if( deq(4.17, s_time) &&
        deq(rt_time, 0.23))
    {
        mark = 2;
    }

   //RaceTrack, Straight + RightTurn, RaceCar.complete(RaceTrack)
    
    Road * s2 = new Straight(600);
    Road * rt2 = new RightTurn(150, 45);

    RaceTrack track = (s1 + rt1);
    const double t_time = car.complete(track);

    delete s2;
    delete rt2;

    const double rtt_time = car.complete(track);

    if(deq(t_time, 4.4) && deq(rtt_time, 4.4))
    {
        mark = 3;
    }

   //RaceTrack.operator+=
    track += new LeftTurn(200, 60);
    RaceTrack track2 = track;
    track += new Straight{650};

    const double t1_time = car.complete(track);
    const double t2_time = car.complete(track2);

    if(deq(t1_time, 10.37) && deq(t2_time, 4.95))
    {
        mark = 4;
    }

    //This is (hopefully) way harder than what you would have to do in the test
    //RaceTrack.operator+, RaceTrack.operator-=
    
    RaceTrack combined_track = track;
    combined_track -= Straight{500};      //This is in track, should be removed
    combined_track -= LeftTurn{400, 25};  //This is not present in combined_track, nothing to remove

    double final_time = car.complete(combined_track);

    if( deq(final_time, 10.37 - 4.17) )
    {
        mark = 5;
    }

    std::cout << "Your mark is " << mark << ".\n";

    return 0;
}