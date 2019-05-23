#ifndef TRACK_HPP
#define TRACK_HPP

#include <vector>
#include <algorithm>

class Road{
public:
    Road(double length_) : length{length_} {}
    virtual double complete(double speed) const = 0;
    virtual ~Road() {}

protected:
    double length;
};

class Straight : public Road
{
public:
    Straight(double length_) : Road{ length_ } { }
    virtual double complete(double speed) const override {
        return length / speed;
    }

    bool operator==(const Straight & s){
        return length == s.length;
    }
    
private:
};

class LeftTurn : public Road
{
public:
    LeftTurn(double length_, double angle_) : 
        Road{ length_ }, angle{ angle_ } 
    { }
    virtual double complete(double speed) const override {
        return ((90 - angle) / 90) * length / speed;
    }

    bool operator==(const LeftTurn & l){
        return length == l.length && angle == l.angle;
    }
    
private:
    double angle;
};

class RightTurn : public Road
{
public:
    RightTurn(double length_, double angle_) : 
        Road{ length_ }, angle{ angle_ } 
    { }
    virtual double complete(double speed) const override {
        return ((90 - angle) / 90) * length / speed;
    }

    bool operator==(const RightTurn & l){
        return length == l.length && angle == l.angle;
    }

    
private:
    double angle;
};

template <class T>
struct UnaryPred{
    UnaryPred(const T & member_) : member{member_} {}
    bool operator()(Road * r)
    {
        bool ret_val = false;
        if(T* t = dynamic_cast<T*>(r))
        {
            ret_val = member == *t;
        }

        return ret_val;
    }

    T member;
};

class RaceTrack {
public:
    RaceTrack() {}
    RaceTrack(const std::vector<Road*> & v) : track{v} { }

    ~RaceTrack(){
        for(Road * r : track)
        {
            delete r;
        }
    }

    RaceTrack(const RaceTrack & other)
    {
        for(Road * r : other.track)
        {
            if(Straight* s = dynamic_cast<Straight*>(r))
            {
                track.push_back(new Straight(*s));
            }
            else if(LeftTurn* l = dynamic_cast<LeftTurn*>(r))
            {
                track.push_back(new LeftTurn(*l));
            }
            else if(RightTurn* t = dynamic_cast<RightTurn*>(r))
            {
                track.push_back(new RightTurn(*t));
            }
        }
    }

    template <class T>
    RaceTrack & operator-=(const T & param){
        std::vector<Road*>::iterator it = 
            std::find_if(track.begin(), track.end(), UnaryPred<T>{param});
        
        if(it != track.end()){
            track.erase(it);
        }

        return *this;
    }

    double complete(double speed) const {
        double sum = 0;
        for(Road * r : track)
        {
            sum += r->complete(speed);
        }
        
        return sum;
    }

    RaceTrack & operator+=(Road * r)
    {
        track.push_back(r);

        return *this;
    }
    RaceTrack operator+(const RaceTrack & other)
    {
        RaceTrack ret_val;
    }

private:
    std::vector<Road*> track;
};

RaceTrack operator+(const Straight& a, const RightTurn & b)
{
    std::vector<Road*> v;
    v.push_back(new Straight(a));
    v.push_back(new RightTurn(b));

    return RaceTrack(v);
}

class RaceCar{
public:
    RaceCar(double speed_) : speed{ speed_ } {}

    template <class T>
    double complete(const T & t) const {
        return t.complete(speed);
    }

private:
    double speed;
};

#endif