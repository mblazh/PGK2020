#include "colors.inc"

background { 
    rgb 1
}  
     
camera { 
    location <3, 2, -7> 
    look_at <3, 2, 1> 
}

light_source {
    <-1, 5, -3>
    color White
}

// jest odpowiednikiem operatora logicznego NOT
difference {
    sphere { 
        <1, 4, 1>, 1
        pigment { color Blue }
    }  

    sphere { 
        <2, 4, 0.5>, 0.5
        pigment { color Yellow }
    }
}

// jest odpowiednikiem operatora logicznego AND
intersection {
    sphere { 
        <1, 1, 1>, 1
        pigment { color Red }
    }  

    sphere { 
        <2, 1, 0.5>, 0.5
        pigment { color Green }
    }
}

// czesci elementow ktore sa w srodku innego elementu istnieja
union {
    sphere { 
        <5, 4, 1>, 1
        pigment { color rgbf<1,0,0,0.5> }
    }  

    sphere { 
        <6, 4, 0.5>, 0.5
        pigment { color rgbf<0,1,0,0.5> }
    }
}

// czesci elementow ktore sa w srodku innego elementa nie istnieja
merge {
    sphere { 
        <5, 1, 1>, 1
        pigment { color rgbf<0,0,1,0.5> }
    }  

    sphere { 
        <6, 1, 0.5>, 0.5
        pigment { color rgbf<1,1,0,0.5> }
    }
}

                  
