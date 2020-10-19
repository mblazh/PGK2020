#include "colors.inc"

background { 
    rgb 1
}  
     
camera { 
    location <13, 10, 50> 
    look_at <13, 5, 0> 
}

light_source {
    <0, 10, 0>
    color White
}

union {
    prism {
        linear_spline
        0, 15, 4,
        <0, 0>, <2, 0>, <1, 1>, <0, 0>
        pigment { color Red }
        translate<0, 0, 0>
    }
    
    prism {
        linear_spline
        0, 15, 4,
        <0, 0>, <2, 0>, <1, 1>, <0, 0>
        pigment { color Green }
        translate<8, 0, 0>
    }
    
    prism {
        linear_spline
        0, 10, 4,
        <0, 0>, <2, 0>, <1, 1>, <0, 0>
        pigment { color Blue }
        rotate<0, 0, 90>      
        translate<10, 0, 0>
    }
    
    prism {
        linear_spline
        0, 10, 4,
        <0, 0>, <2, 0>, <1, 1>, <0, 0>
        pigment { color Yellow }
        rotate<0, 0, 90>
        translate<10, 13, 0>
    }
}

difference {
    prism {
        linear_spline
        0, 2, 5,
        <0, 0>, <0, 1>, <1, 1>, <1, 0>, <0, 0>
        pigment { color Red }
        rotate<90, 0, 0>
        translate<1.5, 1, 0>
        scale<10, 15, 1>
    } 
  
    prism {
        conic_sweep
        0, 5, 5,
        <0, 0>, <0, 1>, <1, 1>, <1, 0>, <0, 0>
        rotate<90, 0, 0>
        translate<4, 2.25, -2>
        scale<4, 6, 1>
    } 
}      