using System;

namespace practice_10 {
    class Child: Parent {
        public double diameter;

        public Child (doule r) {
            this.diameter = r * 2;
            Console.WriteLine($"child init with r = {r}");
        }
    }
}