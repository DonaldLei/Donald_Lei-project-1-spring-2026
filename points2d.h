// Filename: points2d.h
// Name: Donald Lei
// Date of creation: 2/20/2026

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>
// ADDING A NEW COMMENT
namespace teaching_project {

//This file contains the class Points2D which contains the implementations to copy or move a sequence of points, 
//as well as add sequences of 2D points.

template<typename Object>
class Points2D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // When Points2D is called with no parameters, a empty sequence will be created with a size of 0.
    // Set size to 0.
    Points2D(){
        sequence_ = new std::array<Object, 2>;
        size_ = 0;
    }

    // Copy-constructor.
    // Copies an object into a new object.
    // @param rhs The object that we want to copy into a new object.
    // Pre-condition: rhs is valid.
    // Post-condition: sequence_ copied all points that rhs has.
    Points2D(const Points2D &rhs){
        size_ = rhs.size_;

        if(size_ == 0){
            sequence_ = nullptr;
        } else {
            sequence_ = new std::array<Object, 2>[size_]; //allocate enough space to fit all points
            //Copy all points in rhs into sequence_
            for(size_t i = 0; i < size_; ++i){
                sequence_[i] = rhs.sequence_[i];
            }
        }
    }

    // Copy-assignment. If you have already written
    // the copy-constructor and the move-constructor
    // you can just use:
    // {
    // Points2D copy = rhs;
    // std::swap(*this, copy);
    // return *this;
    // }
    // Copies an object into another object.
    // @param rhs The object we want to copy into another object.
    // Pre-condition: rhs is valid.
    // Post-condition: The returned object now contains a copy of rhs.
    Points2D& operator=(const Points2D &rhs){
        Points2D copy = rhs;
        std::swap(*this, copy);
        return *this;
    }

    // Move-constructor.
    // Moves all data from rhs into private members. 
    // @param rhs The object that we want to move its data into a new object.
    // Pre-condition: rhs is valid.
    // Post-condition: All data in rhs is now erased because it was moved.
    Points2D(Points2D &&rhs) : sequence_{rhs.sequence_}, size_{rhs.size_}{
        rhs.sequence_ = nullptr;
        rhs.size_ = 0;
    }

    // Move-assignment.
    // Just use std::swap() for all variables.
    // Transfers data into private members.
    // @param rhs The object that we want to move its data into another object
    // Pre-condition: rhs is valid.
    // Post-condition: The returned object now contains the data from rhs.
    Points2D& operator=(Points2D &&rhs){
        std::swap(sequence_, rhs.sequence_);
        std::swap(size_, rhs.size_);
        return *this;
    }

    // Deconstructor
    // Deallocates the memory in sequence_
    ~Points2D(){
        delete[] sequence_;
    }

    // End of big-five.

    // One parameter constructor.
    // Creates an object that represents a point.
    // @param item the object that represents a point.
    // Pre-condition: item is valid.
    // Post-condition: sequence_ now contains the point in item and is a size of 1. 
    Points2D(const std::array<Object, 2>& item) {
        sequence_ = new std::array<Object, 2>(item); 
        size_ = 1;
    }

    // Returns the size of the sequence
    size_t size() const {
        return size_;
    }

    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    // @param location an index in the sequence.
    // Precondition: Location is valid.
    // Postcondition: The point is at that index is returned. 
    const std::array<Object, 2>& operator[](size_t location) const {
        if(location >= size_){ //if the index is greater than how many points there are
            std::cerr << "ERROR";
            std::abort();
        }
        
        return sequence_[location];
    }

    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //    result with the remaining part of the larger sequence.
    // Precondition: c1 and c2 are valid.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
        Points2D sequenceSum;

        //Find the size of sequenceSum by finding whether c1 or c2 is the larger sequence.
        size_t largerSequenceSize = c1.size_;
        if(c1.size_ > c2.size_){
            largerSequenceSize = c1.size_;
        } else {
            largerSequenceSize = c2.size_;
        } 

        sequenceSum.size_ = largerSequenceSize;
        sequenceSum.sequence_ = new std::array<Object, 2>[largerSequenceSize]; //Allocate enough space to fit the number of points in sequenceSum.

        for(size_t i = 0; i < largerSequenceSize; ++i){
            //If the current index is still less than the size of c1 and c2, then we can continue to find the sum of the points in the sequences. 
            if(i < c1.size_ && i < c2.size_){
                sequenceSum.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
                sequenceSum.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
            //If the current index in the sequence is less than the size of c1 and not c2, that means there are still points in c1 that need to be appended to the sequenceSum.
            } else if(i < c1.size_){
                sequenceSum.sequence_[i] = c1.sequence_[i];
            //The rest of the points in c2 are appended to the sequenceSum.
            } else {
                sequenceSum.sequence_[i] = c2.sequence_[i];
            }
        }
        
        return sequenceSum;
    }

    // Overloading the << operator.
    // @param out stores the output.
    // @param some_points the points in the sequence.
    // Precondition: out and some_points are valid.
    // Postcondition: The sequence is outputted.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        //If there are no points, then it is empty
        if(some_points.size_ == 0){
            out << "()";
        } else {
            for(size_t i = 0; i < some_points.size_; ++i){
                out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ") ";
            }
        }
                 
        out << std::endl;
        return out;
    }

    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    // @param in stores the input.
    // @param some_points the points in the sequence.
    // Precondition: in and some_points are valid.
    // Postcondition: The sequence that is inputted are put into some_points.

    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        size_t numberOfPoints;
        in >> numberOfPoints; //Takes in the first input in the sequence of points, which represents how many points there are in the sequence. 

        delete[] some_points.sequence_; //Delete the memory to deal with new points
        some_points.size_ = numberOfPoints;
        some_points.sequence_ = new std::array<Object, 2>[numberOfPoints]; //Create a sequence that contains the amount of objects needed for the points.

        Object xCoordinate, yCoordinate; //Create two objects x and y to represent the inputs for (x, y) for the coordinate point.
        
        for(size_t i = 0; i < numberOfPoints; ++i){
            //Take the inputs for the points and populate them into some_points.
            in >> xCoordinate >> yCoordinate;
            some_points.sequence_[i][0] = xCoordinate;
            some_points.sequence_[i][1] = yCoordinate;
        } 

        std::cout << std::endl;
        return in;
    }

  private:
    // Sequence of points.
    std::array<Object, 2> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
