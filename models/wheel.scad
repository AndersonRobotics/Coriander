/**
 * Copyright (C) 2018, Shmish <shmish90@gmail.com>
 *
 * This code is licensed under the MIT licence
 * found in the LICENCE file in the root directory
 * of this source tree.
 */

module wheel () {
  color ([0.25, 0.25, 0.25]) {
    union () {
      translate([0, 0, 4])
      cylinder(1, 10, 10);
      cylinder(10, 9, 9, center = true);
      translate([0, 0, -5])
      cylinder(1, 10, 10);
    }
  }
}

wheel();