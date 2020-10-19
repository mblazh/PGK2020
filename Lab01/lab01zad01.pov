#include "colors.inc"

background { 
    rgb 1
}  
     
camera { 
    location <3, 1, -5> 
    look_at <1, 1, 1> 
}

light_source {
    <-1, 5, -3>
    color Green
}

light_source {
    <1, 5, 3> 
    color Blue
}

sphere { 
    <1, 1, 1>, 1
    pigment { color Grey }
}  

sphere { 
    <3, 0.5, 1>, 0.5
    pigment { color Green }
}                  

plane {
    y, 0
    pigment { checker Black, White }
}