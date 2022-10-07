using System;

namespace practice_10 {
    class Parent {
        public double radius, perimeter, area;

        public Parent (double r) {
            this.radius = r;

            Console.WriteLine($"parent init with r = {r}");
        }
    }
}