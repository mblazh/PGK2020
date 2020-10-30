#include "colors.inc"

background { 
    rgb 1
}  
     
camera { 
    location <0, 15, 10> 
    look_at <0, 0, 0> 
}

light_source {
    <0, 20, 0>
    color White
}
                  
plane {
    y, 1.5
    pigment { checker Grey, White }
}


#for (i, 0, 9)
    prism {
        linear_spline
        0, 1, 7,
        <3, 5>, <-3, 5>, <-5, 0>, <-3, -5>, <3, -5>, <5, 0>, <3, 5>
        pigment { color Violet }
        scale <0.1, 1, 0.1>
        translate <-7 + i * 1.5, 1, 1>
    }
#end      