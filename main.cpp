//
//  main.cpp
//  FunctorExample
//
//  Created by Mike Allison on 8/24/14.
//  Copyright (c) 2014 Mike Allison. All rights reserved.
//

#include <iostream>

///Generic calling function
template< typename FunctionType>
float doAnything( const float& arg1, const float& arg2, FunctionType fn ){
    
    return fn( arg1, arg2 );
    
}

///functors overload the () function call operator with some sort of implementation, giving you flexiblity in processing data

struct FunctorPlus{
    float operator()( const float& a1, const float& a2 ){
        
        return a1 + a2;
        
    }
};

struct FunctorMinus{
    float operator()( const float& a1, const float& a2 ){
        
        return a1 - a2;
        
    }
};


struct FunctorMultConst{
    //create a constructor that takes optional paramterers as long as you overload the function call operator with the same signiture as the other types.
    FunctorMultConst( const float& constant ):mConstant(constant){}
    
    float operator()( const float& a1, const float& a2 ){
        
        return (a1 + a2)*mConstant;
        
    }
    
    float mConstant;
};


int main(int argc, const char * argv[])
{

    std::cout<< doAnything( 2, 2, FunctorPlus() ) <<std::endl;
    std::cout<< doAnything( 2, 2, FunctorMinus() ) <<std::endl;
    std::cout<< doAnything( 2, 2, FunctorMultConst( 50 ) ) <<std::endl;
    
    //outputs:
    //4
    //0
    //200

    return 0;
}

