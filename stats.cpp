#include <iostream>
#include <vector>
#include "statistician.h"
using std::vector;

namespace main_savitch_2C {
    statistician::statistician() {
        total = 0;
        count = 0;
        tinyest = 0;
        largest = 0;
    }

    void statistician::next(double r){
        total += r;
        count += 1;
        if (count > 1){
            if(r < tinyest){
                tinyest = r;
            }
            if(r > largest){
                largest = r;
            }
        }
        else if (count == 1){
            r = tinyest = largest;
        }
    }

    void statistician::reset() {
        total = 0;
        count = 0;
        tinyest = 0;
        largest = 0;
    }

    int statistician::length() const{
        return count;
    }
    double statistician::sum() const{
        return total;
    }
    double statistician::mean() const{
        if (count > 0 && total > 0){
            return total/count;
        }
        else {
            return 0;
        }
    }
    double statistician::minimum() const {
        if (length() > 0) {
            return tinyest;
        }
        else {
            return 0;
        }
    }
    double statistician::maximum() const {
        if(length() > 0) {
            return largest;
        }
        else {
            return 0;
        }
    }

    //Combines two vectors
    statistician operator +(const statistician& s1, const statistician& s2){
        statistician s3;
        if(s1.length() == 0){ return s2; }
        if(s2.length() == 0) { return s1; }
        if(s1.length() > 0 && s2.length() > 0) {
            s3.total = s1.sum() + s2.sum();
            s3.count = s1.length() + s2.length();
            if (s1.minimum() < s2.minimum()) {
                s3.tinyest = s1.minimum();
            }
            else {
                s3.tinyest = s2.minimum();
            }
            if (s1.maximum() > s2.maximum()) {
                s3.largest = s1.maximum();
            }
            else {
                s3.largest = s2.maximum();
            }
        }
            return s3;
    }

    //Multiplies two vectors by a scalar
    statistician operator *(double scale, const statistician& s){
        statistician s3;
        if(s.length() == 0) { return s; }
        else if(scale >= 0){
            s3.tinyest = scale * s.minimum();
            s3.largest = scale * s.maximum();
            s3.total = scale * s.sum();
            s3.count = s.length();
        }
        else {
            s3.tinyest = scale * s.maximum();
            s3.largest = scale * s.minimum();
            s3.total = scale * s.sum();
            s3.count = s.length();
        }
        return s3;
    }

    //Check for Equality between two vectors
    bool operator ==(const statistician& s1, const statistician& s2) {
       if (s1.length() == s2.length()) {
            if (s1.sum() == s2.sum()) {
                if (s1.mean() == s2.mean()) {
                    if (s1.minimum() == s2.minimum()) {
                        if (s1.maximum() == s2.maximum()) {
                            return true;
                        }
                    }
                }
            }
        }
       else { return false; }
    }
};