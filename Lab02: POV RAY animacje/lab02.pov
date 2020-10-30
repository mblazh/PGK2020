#include "colors.inc"
#include "shapes.inc"

#declare Random_1 = seed (1153);

background { 
	rgb <0.6, 0.3, 0.5>
}

camera {
	#if (clock <= 1)
		location <15 , 10 , 15>
	#elseif (clock <= 2)
		#local own_clock = clock - 1;

		location <15 - own_clock * 12, 10 - own_clock * 8, 15 - own_clock * 12> 
	#else
		location <3, 2, 3>
	#end

	look_at <0, 2, 0>

	#if (clock <= 1)
		rotate <0, 20 + 360 * (clock / 2 + 0.5), 0>
	#else
		rotate <0, 20 + 360 * 1, 0>
	#end
}

light_source {
	<10, 30, 20>
	color rgb <0.6, 0.3, 0.3>
	fade_distance 10
	fade_power 1
	#if (clock > 2.1)
		shadowless
	#end
}

plane { // www
	y, -0.25
	pigment { Green }
}

union {
	disc { // Road
		<0, 0, 0>, <0, 1, 0>, 12
		pigment { Gray10 }
	}

	#for (i, 0, 2) // Buildings
		#declare numberOfBuildings = 5 + 5 * i;

		#for (j, 0, numberOfBuildings - 1)
			prism {
				linear_spline
				0, 1, 5,
				<0, 0>, <0, 1>, <1, 1>, <1, 0>, <0, 0> 
				pigment { brick Gray40, Gray60 scale 0.03125}
				scale <0, int(2 + 5 * rand(Random_1)), 0> 
				translate <(1 + i) * 3, 0, 0>
				rotate <0, j * 360 / numberOfBuildings, 0>
			}
		#end
	#end

	#for (i, 0, 10) // Bushes
		#declare numberOfBushes = 10 + 10 * i;

		#for (j, 0, numberOfBushes - 1)
			sphere {
				<3, 0.1, 1>, 0.25
				pigment{ checker rgb <0.1, 0.2 + rand(Random_1), 0.1>, rgb <0.1, 0.2 + rand(Random_1), 0.1> scale 0.03125}
				translate <(1 + i) * 2 - i / 3, 0, 0>
				rotate <0, j * 360 / numberOfBushes, 0>
				scale <1, i / 2 + 4 * rand(Random_1), 1> 
			}
		#end
	#end
}

// Rocket
union { 
	#local own_clock = clock - 2.1;

	object {
		Disk_Y
		scale <0.3, 1.5, 0.3>
		texture{
			pigment{ rgb <0.2, 0.2, 0.7> }
		}
		translate <0, 1.5, 0>
	}

	cone {
		<0, 4, 0>, 0
		<0, 3, 0>, 0.4
		pigment{ rgb <0.1, 0.1, 0.6> }
	}

	#if (clock >= 2.1) 
		light_source {
			<0, 0, 0>
			rgb <1, 0.8, 0.5>
			fade_distance 1
			fade_power 1

			looks_like {
				cone {
					<0, -2, 0>, 0.05
					<0, 0, 0>, 0.2
					pigment { rgbt 1 } hollow
					interior {
						media { 
							emission 1
							density {
								spherical density_map { 
									[0 rgb 0]
									[0.4 rgb <1,0,0>]
									[0.8 rgb <1,1,0>]
									[1 rgb 1]
								}
							}
						}
					}
				}
			}
		}

		translate <0, 10 * own_clock, 0>
	#end
}