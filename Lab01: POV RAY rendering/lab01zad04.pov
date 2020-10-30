#include "colors.inc"

background { 
    rgb 1
}  
     
camera { 
    location <0, 25, 0> 
    look_at <0, 0, 0> 
}

light_source {
    <0, 20, 0>
    color White
}
                  
plane {
    y, 0
    pigment { checker Grey, White }
}


#for (i, 0, 17)
    prism {
        linear_spline
        0, 1, 7,
        <3, 5>, <-3, 5>, <-5, 0>, <-3, -5>, <3, -5>, <5, 0>, <3, 5> 
        pigment { color Red }
        scale <0.2, 1, 0.2> 
        rotate <i * 360 / 18, 0, 0>
        translate <10, 1, 1>
        rotate <0, i * 360 / 18, 0>
    }
#end      