#include "colors.inc"

background { 
    rgb 1
}  
     
camera { 
    location <10, 10, -10> 
    look_at <0, 0, 0> 
}

light_source {
    <0, 5, 0>
    color White
}
                  
plane {
    y, -2
    pigment { checker Grey, White }
}


prism {
    linear_sweep
    0, 1, 7,
    <3, 5>, <-3, 5>, <-5, 0>, <-3, -5>, <3, -5>, <5, 0>, <3, 5>
    pigment { color Violet }
    rotate <-10, -10, -10>
}      

prism {
    linear_spline
    0, 1, 7,
    <3, 5>, <-3, 5>, <-5, 0>, <-3, -5>, <3, -5>, <5, 0>, <3, 5>
    pigment { color Green }
    scale <0.5, 0.5, 0.5>
    translate <1, 3, 1>
}

prism {
    conic_sweep
    0, 1, 7,
    <3, 5>, <-3, 5>, <-5, 0>, <-3, -5>, <3, -5>, <5, 0>, <3, 5>
    pigment { color Red }
    scale <0.2, 0.2, 0.2>
    translate <-1, -2, -6>
    rotate <1, 1, 100>
}