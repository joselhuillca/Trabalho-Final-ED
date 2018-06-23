#ifndef ASUNTO_H
#define ASUNTO_H

#include <iostream>
using namespace std;

class TipoAsunto
{
private:
    int type;
    string title;
    int urgency;
public:
    TipoAsunto(){}

    TipoAsunto(int type_, string title_, int urgency_) {
        type = type_;
        title = title_;
        urgency = urgency_;
    }

    inline int getType(){return type;}
    inline string getTitle(){return title;}
    inline int getUrgency(){return urgency;}

    inline void setType(int type_){type = type_;}
    inline void setTitle(string title_){title = title_;}
    inline void setUrgency(int urgency_){urgency = urgency_;}
};


class Asunto
{
private:
    TipoAsunto type;
    string description;
    float *providence;
    double durationAttention;
public:
    Asunto(TipoAsunto type_, string description_, float *prov=0, double durationA=0) {
        type = type_;
        description = description_;
        providence = prov;
        durationAttention = durationA;
    }

    inline string getDescription(){return description;}
    inline double getDurationAttention(){return durationAttention;}
    inline float* getProvidence(){return providence;}
    inline TipoAsunto getType(){return type;}

    inline void setDescription(string d){description = d;}
    inline void setDurationAttention(double da){durationAttention = da;}
    inline void setProvidence(float *prov){providence = prov;}

};

#endif // ASUNTO_H
